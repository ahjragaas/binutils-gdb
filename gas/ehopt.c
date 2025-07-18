/* ehopt.c--optimize gcc exception frame information.
   Copyright (C) 1998-2025 Free Software Foundation, Inc.
   Written by Ian Lance Taylor <ian@cygnus.com>.

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

#include "as.h"
#include "subsegs.h"

/* We include this ELF file, even though we may not be assembling for
   ELF, since the exception frame information is always in a format
   derived from DWARF.  */

#include "dwarf2.h"

/* Try to optimize gcc 2.8 exception frame information.

   Exception frame information is emitted for every function in the
   .eh_frame or .debug_frame sections.  Simple information for a function
   with no exceptions looks like this:

__FRAME_BEGIN__:
	.4byte	.LLCIE1	/ Length of Common Information Entry
.LSCIE1:
#if .eh_frame
	.4byte	0x0	/ CIE Identifier Tag
#elif .debug_frame
	.4byte	0xffffffff / CIE Identifier Tag
#endif
	.byte	0x1	/ CIE Version
	.byte	0x0	/ CIE Augmentation (none)
	.byte	0x1	/ ULEB128 0x1 (CIE Code Alignment Factor)
	.byte	0x7c	/ SLEB128 -4 (CIE Data Alignment Factor)
	.byte	0x8	/ CIE RA Column
	.byte	0xc	/ DW_CFA_def_cfa
	.byte	0x4	/ ULEB128 0x4
	.byte	0x4	/ ULEB128 0x4
	.byte	0x88	/ DW_CFA_offset, column 0x8
	.byte	0x1	/ ULEB128 0x1
	.align 4
.LECIE1:
	.set	.LLCIE1,.LECIE1-.LSCIE1	/ CIE Length Symbol
	.4byte	.LLFDE1	/ FDE Length
.LSFDE1:
	.4byte	.LSFDE1-__FRAME_BEGIN__	/ FDE CIE offset
	.4byte	.LFB1	/ FDE initial location
	.4byte	.LFE1-.LFB1	/ FDE address range
	.byte	0x4	/ DW_CFA_advance_loc4
	.4byte	.LCFI0-.LFB1
	.byte	0xe	/ DW_CFA_def_cfa_offset
	.byte	0x8	/ ULEB128 0x8
	.byte	0x85	/ DW_CFA_offset, column 0x5
	.byte	0x2	/ ULEB128 0x2
	.byte	0x4	/ DW_CFA_advance_loc4
	.4byte	.LCFI1-.LCFI0
	.byte	0xd	/ DW_CFA_def_cfa_register
	.byte	0x5	/ ULEB128 0x5
	.byte	0x4	/ DW_CFA_advance_loc4
	.4byte	.LCFI2-.LCFI1
	.byte	0x2e	/ DW_CFA_GNU_args_size
	.byte	0x4	/ ULEB128 0x4
	.byte	0x4	/ DW_CFA_advance_loc4
	.4byte	.LCFI3-.LCFI2
	.byte	0x2e	/ DW_CFA_GNU_args_size
	.byte	0x0	/ ULEB128 0x0
	.align 4
.LEFDE1:
	.set	.LLFDE1,.LEFDE1-.LSFDE1	/ FDE Length Symbol

   The immediate issue we can address in the assembler is the
   DW_CFA_advance_loc4 followed by a four byte value.  The value is
   the difference of two addresses in the function.  Since gcc does
   not know this value, it always uses four bytes.  We will know the
   value at the end of assembly, so we can do better.  */

struct cie_info
{
  fragS *f;
  unsigned code_alignment;
  int z_augmentation;
};

/* Extract information from the CIE.  */

static bool
get_cie_info (struct cie_info *info)
{
  fragS *f;
  unsigned int offset;
  char CIE_id;
  char augmentation[10];
  int iaug;
  int code_alignment = 0;

  /* We should find the CIE at the start of the section.  */

  f = seg_info (now_seg)->frchainP->frch_root;
  while (f != NULL && f->fr_fix == 0)
    f = f->fr_next;
  if (f != info->f)
    return false;

  /* First make sure that the CIE Identifier Tag is 0/-1.  */

  if (startswith (segment_name (now_seg), ".debug_frame"))
    CIE_id = (char)0xff;
  else
    CIE_id = 0;

  offset = 4;
  while (f != NULL && offset >= f->fr_fix)
    {
      offset -= f->fr_fix;
      f = f->fr_next;
    }
  if (f == NULL
      || f->fr_fix - offset < 4
      || f->fr_literal[offset] != CIE_id
      || f->fr_literal[offset + 1] != CIE_id
      || f->fr_literal[offset + 2] != CIE_id
      || f->fr_literal[offset + 3] != CIE_id)
    return false;

  /* Next make sure the CIE version number is 1.  */

  offset += 4;
  while (f != NULL && offset >= f->fr_fix)
    {
      offset -= f->fr_fix;
      f = f->fr_next;
    }
  if (f == NULL
      || f->fr_fix - offset < 1
      || f->fr_literal[offset] != 1)
    return false;

  /* Skip the augmentation (a null terminated string).  */

  iaug = 0;
  ++offset;
  while (1)
    {
      while (f != NULL && offset >= f->fr_fix)
	{
	  offset -= f->fr_fix;
	  f = f->fr_next;
	}
      if (f == NULL)
	return false;

      while (offset < f->fr_fix && f->fr_literal[offset] != '\0')
	{
	  if ((size_t) iaug < (sizeof augmentation) - 1)
	    {
	      augmentation[iaug] = f->fr_literal[offset];
	      ++iaug;
	    }
	  ++offset;
	}
      if (offset < f->fr_fix)
	break;
    }
  ++offset;
  while (f != NULL && offset >= f->fr_fix)
    {
      offset -= f->fr_fix;
      f = f->fr_next;
    }
  if (f == NULL)
    return false;

  augmentation[iaug] = '\0';
  if (augmentation[0] == '\0')
    {
      /* No augmentation.  */
    }
  else if (strcmp (augmentation, "eh") == 0)
    {
      /* We have to skip a pointer.  Unfortunately, we don't know how
	 large it is.  We find out by looking for a matching fixup.  */
      fixS *fix = seg_info (now_seg)->frchainP->fix_root;
      while (fix != NULL
	     && (fix->fx_frag != f || fix->fx_where != offset))
	fix = fix->fx_next;
      if (fix == NULL)
	offset += 4;
      else
	offset += fix->fx_size;
      while (f != NULL && offset >= f->fr_fix)
	{
	  offset -= f->fr_fix;
	  f = f->fr_next;
	}
      if (f == NULL)
	return false;
    }
  else if (augmentation[0] != 'z')
    return false;

  /* We're now at the code alignment factor, which is a ULEB128.  If
     it isn't a single byte, forget it.  */

  code_alignment = f->fr_literal[offset] & 0xff;
  if ((code_alignment & 0x80) != 0)
    code_alignment = 0;

  info->code_alignment = code_alignment;
  info->z_augmentation = (augmentation[0] == 'z');

  return true;
}

enum frame_state
{
  state_idle,
  state_saw_size,
  state_saw_cie_offset,
  state_saw_pc_begin,
  state_seeing_aug_size,
  state_skipping_aug,
  state_wait_loc4,
  state_saw_loc4,
  state_error,
};

struct frame_data
{
  enum frame_state state;

  bool cie_info_ok;
  struct cie_info cie_info;

  symbolS *size_end_sym;
  fragS *loc4_frag;
  int loc4_fix;

  int aug_size;
  int aug_shift;
};

static struct eh_state
{
  struct frame_data eh_data;
  struct frame_data debug_data;
} frame;

/* This function is called from emit_expr.  It looks for cases which
   we can optimize.

   Rather than try to parse all this information as we read it, we
   look for a single byte DW_CFA_advance_loc4 followed by a 4 byte
   difference.  We turn that into a rs_cfa_advance frag, and handle
   those frags at the end of the assembly.  If the gcc output changes
   somewhat, this optimization may stop working.

   This function returns non-zero if it handled the expression and
   emit_expr should not do anything, or zero otherwise.  It can also
   change *EXP and *PNBYTES.  */

int
check_eh_frame (expressionS *exp, unsigned int *pnbytes)
{
  struct frame_data *d;

  /* Don't optimize.  */
  if (flag_traditional_format)
    return 0;

#ifdef md_allow_eh_opt
  if (! md_allow_eh_opt)
    return 0;
#endif

  /* Select the proper section data.  */
  if (startswith (segment_name (now_seg), ".eh_frame")
      && segment_name (now_seg)[9] != '_')
    d = &frame.eh_data;
  else if (startswith (segment_name (now_seg), ".debug_frame"))
    d = &frame.debug_data;
  else
    return 0;

  if (d->state >= state_saw_size && S_IS_DEFINED (d->size_end_sym))
    {
      /* We have come to the end of the CIE or FDE.  See below where
         we set saw_size.  We must check this first because we may now
         be looking at the next size.  */
      d->state = state_idle;
    }

  switch (d->state)
    {
    case state_idle:
      if (*pnbytes == 4)
	{
	  /* This might be the size of the CIE or FDE.  We want to know
	     the size so that we don't accidentally optimize across an FDE
	     boundary.  We recognize the size in one of two forms: a
	     symbol which will later be defined as a difference, or a
	     subtraction of two symbols.  Either way, we can tell when we
	     are at the end of the FDE because the symbol becomes defined
	     (in the case of a subtraction, the end symbol, from which the
	     start symbol is being subtracted).  Other ways of describing
	     the size will not be optimized.  */
	  if ((exp->X_op == O_symbol || exp->X_op == O_subtract)
	      && ! S_IS_DEFINED (exp->X_add_symbol))
	    {
	      d->state = state_saw_size;
	      d->size_end_sym = exp->X_add_symbol;
	      if (!d->cie_info.f)
		d->cie_info.f = frag_now;
	    }
	}
      break;

    case state_saw_size:
    case state_saw_cie_offset:
      if (!(*pnbytes == 4 || *pnbytes == 8))
	/* Stop scanning if we don't see the expected FDE fields.  */
	d->state = state_error;
      else
	d->state++;
      break;

    case state_saw_pc_begin:
      /* Decide whether we should see an augmentation.  */
      if (!(*pnbytes == 4 || *pnbytes == 8))
	d->state = state_error;
      else if (!d->cie_info_ok
	       && !(d->cie_info_ok = get_cie_info (&d->cie_info)))
	d->state = state_error;
      else if (d->cie_info.z_augmentation)
	{
	  d->state = state_seeing_aug_size;
	  d->aug_size = 0;
	  d->aug_shift = 0;
	}
      else
	d->state = state_wait_loc4;
      break;

    case state_seeing_aug_size:
      /* Bytes == -1 means this comes from an leb128 directive.  */
      if ((int) *pnbytes == -1 && exp->X_op == O_constant)
	{
	  d->aug_size = exp->X_add_number;
	  d->state = state_skipping_aug;
	}
      else if (*pnbytes == 1 && exp->X_op == O_constant)
	{
	  unsigned char byte = exp->X_add_number;
	  d->aug_size |= (byte & 0x7f) << d->aug_shift;
	  d->aug_shift += 7;
	  if ((byte & 0x80) == 0)
	    d->state = state_skipping_aug;
	}
      else
	d->state = state_error;
      if (d->state == state_skipping_aug && d->aug_size == 0)
	d->state = state_wait_loc4;
      break;

    case state_skipping_aug:
      if ((int) *pnbytes < 0)
	d->state = state_error;
      else
	{
	  int left = (d->aug_size -= *pnbytes);
	  if (left == 0)
	    d->state = state_wait_loc4;
	  else if (left < 0)
	    d->state = state_error;
	}
      break;

    case state_wait_loc4:
      if (*pnbytes == 1
	  && exp->X_op == O_constant
	  && exp->X_add_number == DW_CFA_advance_loc4)
	{
	  /* This might be a DW_CFA_advance_loc4.  Record the frag and the
	     position within the frag, so that we can change it later.  */
	  frag_grow (1 + 4);
	  d->state = state_saw_loc4;
	  d->loc4_frag = frag_now;
	  d->loc4_fix = frag_now_fix ();
	}
      break;

    case state_saw_loc4:
      d->state = state_wait_loc4;
      if (*pnbytes != 4)
	break;
      if (exp->X_op == O_constant)
	{
	  /* This is a case which we can optimize.  The two symbols being
	     subtracted were in the same frag and the expression was
	     reduced to a constant.  We can do the optimization entirely
	     in this function.  */
	  if (exp->X_add_number < 0x40)
	    {
	      d->loc4_frag->fr_literal[d->loc4_fix]
		= DW_CFA_advance_loc | exp->X_add_number;
	      /* No more bytes needed.  */
	      return 1;
	    }
	  else if (exp->X_add_number < 0x100)
	    {
	      d->loc4_frag->fr_literal[d->loc4_fix] = DW_CFA_advance_loc1;
	      *pnbytes = 1;
	    }
	  else if (exp->X_add_number < 0x10000)
	    {
	      d->loc4_frag->fr_literal[d->loc4_fix] = DW_CFA_advance_loc2;
	      *pnbytes = 2;
	    }
	}
      else if (exp->X_op == O_subtract && d->cie_info.code_alignment == 1)
	{
	  /* This is a case we can optimize.  The expression was not
	     reduced, so we can not finish the optimization until the end
	     of the assembly.  We set up a variant frag which we handle
	     later.  */
	  frag_var (rs_cfa, 4, 0, 1 << 3, make_expr_symbol (exp),
		    d->loc4_fix, (char *) d->loc4_frag);
	  return 1;
	}
      else if ((exp->X_op == O_divide
		|| exp->X_op == O_right_shift)
	       && d->cie_info.code_alignment > 1)
	{
	  if (symbol_symbolS (exp->X_add_symbol)
	      && symbol_constant_p (exp->X_op_symbol)
	      && S_GET_SEGMENT (exp->X_op_symbol) == absolute_section
	      && ((exp->X_op == O_divide
		   ? *symbol_X_add_number (exp->X_op_symbol)
		   : (offsetT) 1 << *symbol_X_add_number (exp->X_op_symbol))
		  == (offsetT) d->cie_info.code_alignment))
	    {
	      expressionS *symval;

	      symval = symbol_get_value_expression (exp->X_add_symbol);
	      if (symval->X_op == O_subtract)
		{
		  /* This is a case we can optimize as well.  The
		     expression was not reduced, so we can not finish
		     the optimization until the end of the assembly.
		     We set up a variant frag which we handle later.  */
		  frag_var (rs_cfa, 4, 0, d->cie_info.code_alignment << 3,
			    make_expr_symbol (symval),
			    d->loc4_fix, (char *) d->loc4_frag);
		  return 1;
		}
	    }
	}
      break;

    case state_error:
      /* Just skipping everything.  */
      break;
    }

  return 0;
}

/* The function estimates the size of a rs_cfa variant frag based on
   the current values of the symbols.  It is called before the
   relaxation loop.  We set fr_subtype{0:2} to the expected length.  */

int
eh_frame_estimate_size_before_relax (fragS *frag)
{
  offsetT diff;
  int ca = frag->fr_subtype >> 3;
  int ret;

  diff = resolve_symbol_value (frag->fr_symbol);

  gas_assert (ca > 0);
  diff /= ca;
  if (diff == 0)
    ret = -1;
  else if (diff < 0x40)
    ret = 0;
  else if (diff < 0x100)
    ret = 1;
  else if (diff < 0x10000)
    ret = 2;
  else
    ret = 4;

  frag->fr_subtype = (frag->fr_subtype & ~7) | (ret & 7);

  return ret;
}

/* This function relaxes a rs_cfa variant frag based on the current
   values of the symbols.  fr_subtype{0:2} is the current length of
   the frag.  This returns the change in frag length.  */

int
eh_frame_relax_frag (fragS *frag)
{
  int oldsize, newsize;

  oldsize = frag->fr_subtype & 7;
  if (oldsize == 7)
    oldsize = -1;
  newsize = eh_frame_estimate_size_before_relax (frag);
  return newsize - oldsize;
}

/* This function converts a rs_cfa variant frag into a normal fill
   frag.  This is called after all relaxation has been done.
   fr_subtype{0:2} will be the desired length of the frag.  */

void
eh_frame_convert_frag (fragS *frag)
{
  offsetT diff;
  fragS *loc4_frag;
  int loc4_fix, ca;

  loc4_frag = (fragS *) frag->fr_opcode;
  loc4_fix = frag->fr_offset;

  diff = resolve_symbol_value (frag->fr_symbol);

  ca = frag->fr_subtype >> 3;
  gas_assert (ca > 0);
  diff /= ca;
  switch (frag->fr_subtype & 7)
    {
    case 0:
      gas_assert (diff < 0x40);
      loc4_frag->fr_literal[loc4_fix] = DW_CFA_advance_loc | diff;
      break;

    case 1:
      gas_assert (diff < 0x100);
      loc4_frag->fr_literal[loc4_fix] = DW_CFA_advance_loc1;
      frag->fr_literal[frag->fr_fix] = diff;
      break;

    case 2:
      gas_assert (diff < 0x10000);
      loc4_frag->fr_literal[loc4_fix] = DW_CFA_advance_loc2;
      md_number_to_chars (frag->fr_literal + frag->fr_fix, diff, 2);
      break;

    case 4:
      md_number_to_chars (frag->fr_literal + frag->fr_fix, diff, 4);
      break;

    case 7:
      gas_assert (diff == 0);
      frag->fr_fix -= 8;
      break;

    default:
      abort ();
    }

  frag->fr_fix += frag->fr_subtype & 7;
  frag->fr_type = rs_fill;
  frag->fr_subtype = 0;
  frag->fr_offset = 0;
}

void
eh_begin (void)
{
  memset (&frame, 0, sizeof (frame));
}
