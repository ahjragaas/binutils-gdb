/* symbols.h -
   Copyright (C) 1987-2025 Free Software Foundation, Inc.

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

#ifndef GAS_SYMBOLS_H
#define GAS_SYMBOLS_H

extern struct obstack notes;	/* eg FixS live here.  */

extern struct obstack cond_obstack;	/* this is where we track .ifdef/.endif
				       (if we do that at all).  */

extern symbolS *symbol_rootP;	/* all the symbol nodes */
extern symbolS *symbol_lastP;	/* last struct symbol we made, or NULL */

extern symbolS abs_symbol;
extern symbolS dot_symbol;

extern int symbol_table_frozen;

/* This is non-zero if symbols are case sensitive, which is the
   default.  */
extern int symbols_case_sensitive;

extern void *notes_alloc (size_t);
extern void *notes_calloc (size_t, size_t);
extern void *notes_memdup (const void *, size_t, size_t);
extern char *notes_strdup (const char *);
extern char *notes_concat (const char *, ...);
extern void notes_free (void *);

static inline char *
notes_memdup0 (const char *in, size_t len)
{
  return notes_memdup (in, len, len + 1);
}

char * symbol_relc_make_expr  (expressionS *);
char * symbol_relc_make_sym   (symbolS *);
char * symbol_relc_make_value (offsetT);
const char *decode_local_label_name (const char *);
symbolS *symbol_find (const char *name);
symbolS *symbol_find_noref (const char *name, int noref);
symbolS *symbol_find_exact (const char *name);
symbolS *symbol_find_exact_noref (const char *name, int noref);
symbolS *symbol_find_or_make (const char *name);
symbolS *symbol_make (const char *name);
symbolS *symbol_new (const char *, segT, fragS *, valueT);
symbolS *symbol_create (const char *, segT, fragS *, valueT);
struct local_symbol *local_symbol_make (const char *, segT, fragS *, valueT);
symbolS *symbol_clone (symbolS *, int);
#undef symbol_clone_if_forward_ref
symbolS *symbol_clone_if_forward_ref (symbolS *, int);
#define symbol_clone_if_forward_ref(s) symbol_clone_if_forward_ref (s, 0)
symbolS *symbol_temp_new (segT, fragS *, valueT);
symbolS *symbol_temp_new_now (void);
symbolS *symbol_temp_new_now_octets (void);
symbolS *symbol_temp_make (void);

symbolS *colon (const char *sym_name);
void local_colon (int n);
void symbol_begin (void);
void symbol_end (void);
void dot_symbol_init (void);
void symbol_print_statistics (FILE *);
void symbol_table_insert (symbolS * symbolP);
valueT resolve_symbol_value (symbolS *);
void resolve_local_symbol_values (void);
int snapshot_symbol (symbolS **, valueT *, segT *, fragS **);

void print_symbol_value (symbolS *);
void print_expr (expressionS *);
void print_expr_1 (FILE *, expressionS *);
void print_symbol_value_1 (FILE *, symbolS *);

int dollar_label_defined (unsigned int);
void dollar_label_clear (void);
void define_dollar_label (unsigned int);
char *dollar_label_name (unsigned int, unsigned int);

void fb_label_instance_inc (unsigned int);
char *fb_label_name (unsigned int, unsigned int);

extern void copy_symbol_attributes (symbolS *, symbolS *);

/* Get and set the values of symbols.  These used to be macros.  */
extern valueT S_GET_VALUE (symbolS *);
extern valueT S_GET_VALUE_WHERE (symbolS *, const char *, unsigned int);
extern void S_SET_VALUE (symbolS *, valueT);

extern int S_IS_FUNCTION (const symbolS *);
extern int S_IS_EXTERNAL (const symbolS *);
extern int S_IS_WEAK (const symbolS *);
extern int S_IS_WEAKREFR (const symbolS *);
extern int S_IS_WEAKREFD (const symbolS *);
extern int S_IS_COMMON (const symbolS *);
extern int S_IS_DEFINED (const symbolS *);
extern int S_FORCE_RELOC (const symbolS *, int);
extern int S_IS_DEBUG (const symbolS *);
extern int S_IS_LOCAL (const symbolS *);
extern int S_IS_STABD (const symbolS *);
extern int S_CAN_BE_REDEFINED (const symbolS *);
extern int S_IS_VOLATILE (const symbolS *);
extern int S_IS_FORWARD_REF (const symbolS *);
extern const char *S_GET_NAME (const symbolS *);
extern segT S_GET_SEGMENT (const symbolS *);
extern void S_SET_SEGMENT (symbolS *, segT);
extern void S_SET_EXTERNAL (symbolS *);
extern void S_SET_NAME (symbolS *, const char *);
extern void S_CLEAR_EXTERNAL (symbolS *);
extern void S_SET_WEAK (symbolS *);
extern void S_SET_WEAKREFR (symbolS *);
extern void S_CLEAR_WEAKREFR (symbolS *);
extern void S_SET_WEAKREFD (symbolS *);
extern void S_CLEAR_WEAKREFD (symbolS *);
extern void S_SET_THREAD_LOCAL (symbolS *);
extern void S_SET_VOLATILE (symbolS *);
extern void S_CLEAR_VOLATILE (symbolS *);
extern void S_SET_FORWARD_REF (symbolS *);

#ifndef WORKING_DOT_WORD
struct broken_word
  {
    /* Linked list -- one of these structures per ".word x-y+C"
       expression.  */
    struct broken_word *next_broken_word;
    /* Segment and subsegment for broken word.  */
    segT seg;
    subsegT subseg;
    /* Which frag is this broken word in?  */
    fragS *frag;
    /* Where in the frag is it?  */
    char *word_goes_here;
    /* Where to add the break.  */
    fragS *dispfrag;		/* where to add the break */
    /* Operands of expression.  */
    symbolS *add;
    symbolS *sub;
    offsetT addnum;

    int added;			/* nasty thing happened yet? */
    /* 1: added and has a long-jump */
    /* 2: added but uses someone elses long-jump */

    /* Pointer to broken_word with a similar long-jump.  */
    struct broken_word *use_jump;
  };
extern struct broken_word *broken_words;
#endif /* ifdef WORKING_DOT_WORD */

/*
 * Current means for getting from symbols to segments and vice verse.
 * This will change for infinite-segments support (e.g. COFF).
 */
extern const segT N_TYPE_seg[];	/* subseg.c */

#define	SEGMENT_TO_SYMBOL_TYPE(seg)  ( seg_N_TYPE [(int) (seg)] )
extern const short seg_N_TYPE[];/* subseg.c */

#define	N_REGISTER	30	/* Fake N_TYPE value for SEG_REGISTER */

void symbol_clear_list_pointers (symbolS * symbolP);

void symbol_insert (symbolS * addme, symbolS * target,
		    symbolS ** rootP, symbolS ** lastP);
void symbol_remove (symbolS * symbolP, symbolS ** rootP,
		    symbolS ** lastP);

extern int symbol_on_chain (symbolS *s, symbolS *rootPP, symbolS *lastPP);

void verify_symbol_chain (symbolS * rootP, symbolS * lastP);

void symbol_append (symbolS * addme, symbolS * target,
		    symbolS ** rootP, symbolS ** lastP);

extern symbolS *symbol_previous (const symbolS *);
extern symbolS *symbol_next (const symbolS *);

extern expressionS *symbol_get_value_expression (symbolS *);
extern void symbol_set_value_expression (symbolS *, const expressionS *);
extern offsetT *symbol_X_add_number (const symbolS *);
extern void symbol_set_value_now (symbolS *);
extern void symbol_set_frag (symbolS *, fragS *);
extern fragS *symbol_get_frag (const symbolS *);
extern fragS *symbol_get_frag_and_value (const symbolS *, addressT *);
extern void symbol_mark_used (symbolS *);
extern void symbol_clear_used (symbolS *);
extern int symbol_used_p (const symbolS *);
extern void symbol_mark_used_in_reloc (symbolS *);
extern void symbol_clear_used_in_reloc (symbolS *);
extern int symbol_used_in_reloc_p (const symbolS *);
extern void symbol_mark_mri_common (symbolS *);
extern void symbol_clear_mri_common (symbolS *);
extern int symbol_mri_common_p (const symbolS *);
extern void symbol_mark_written (symbolS *);
extern void symbol_clear_written (symbolS *);
extern int symbol_written_p (const symbolS *);
extern void symbol_mark_removed (symbolS *);
extern int symbol_removed_p (const symbolS *);
extern void symbol_mark_resolved (symbolS *);
extern int symbol_resolved_p (const symbolS *);
extern void symbol_mark_resolving (symbolS *);
extern void symbol_clear_resolving (symbolS *);
extern int symbol_resolving_p (const symbolS *);
extern int symbol_section_p (const symbolS *);
extern int symbol_equated_p (const symbolS *);
extern int symbol_equated_reloc_p (const symbolS *);
extern int symbol_constant_p (const symbolS *);
extern int symbol_shadow_p (const symbolS *);
extern symbolS *symbol_symbolS (symbolS *);
extern asymbol *symbol_get_bfdsym (symbolS *);
extern void symbol_set_bfdsym (symbolS *, asymbol *);
extern int symbol_same_p (const symbolS *, const symbolS *);

#ifdef OBJ_SYMFIELD_TYPE
OBJ_SYMFIELD_TYPE *symbol_get_obj (symbolS *);
void symbol_set_obj (symbolS *, OBJ_SYMFIELD_TYPE *);
#endif

#ifdef TC_SYMFIELD_TYPE
TC_SYMFIELD_TYPE *symbol_get_tc (symbolS *);
void symbol_set_tc (symbolS *, TC_SYMFIELD_TYPE *);
#endif

#endif /* GAS_SYMBOLS_H */
