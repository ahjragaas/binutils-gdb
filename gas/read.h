/* read.h - of read.c
   Copyright (C) 1986-2025 Free Software Foundation, Inc.

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

extern char *input_line_pointer;	/* -> char we are parsing now.  */
extern bool input_from_string;

/* Define to make whitespace be allowed in many syntactically
   unnecessary places.  Normally undefined.  For compatibility with
   ancient GNU cc.  */
/* #undef PERMIT_WHITESPACE */
#define PERMIT_WHITESPACE

#ifdef PERMIT_WHITESPACE
#define SKIP_WHITESPACE()			\
  (is_whitespace (*input_line_pointer) ? ++input_line_pointer : 0)
#define SKIP_ALL_WHITESPACE()			\
  while (is_whitespace (*input_line_pointer)) ++input_line_pointer
#else
#define SKIP_WHITESPACE() know (!is_whitespace (*input_line_pointer))
#define SKIP_ALL_WHITESPACE() SKIP_WHITESPACE()
#endif

#define LEX_NAME	(1)	/* may continue a name */
#define LEX_BEGIN_NAME	(2)	/* may begin a name */
#define LEX_END_NAME	(4)	/* ends a name */
#define LEX_WHITE	(8)	/* whitespace */
#define LEX_EOS	(0x10)  /* end of statement */
#define LEX_EOL	(0x20)  /* end of line */

#define is_name_beginner(c) \
  ( lex_type[(unsigned char) (c)] & LEX_BEGIN_NAME )
#define is_part_of_name(c) \
  ( lex_type[(unsigned char) (c)] & LEX_NAME       )
#define is_name_ender(c) \
  ( lex_type[(unsigned char) (c)] & LEX_END_NAME   )
#define is_whitespace(c) \
  ( lex_type[(unsigned char) (c)] & LEX_WHITE      )

/* Don't allow safe-ctype.h's counterparts to be used.  */
#undef ISSPACE
#undef ISBLANK

/* The distinction of "line" and "statement" sadly is blurred by unhelpful
   naming in a few places.  Most users really mean "end of statement".  */
#define is_end_of_stmt(c) \
  ( lex_type[(unsigned char) (c)] & (LEX_EOS | LEX_EOL) )
#define is_end_of_line(c) \
  ( lex_type[(unsigned char) (c)] & LEX_EOL )

#ifndef is_a_char
#define CHAR_MASK	(0xff)
#define NOT_A_CHAR	(CHAR_MASK+1)
#define is_a_char(c)	(((unsigned) (c)) <= CHAR_MASK)
#endif /* is_a_char() */

extern char lex_type[];

extern int is_it_end_of_statement (void);
extern char *find_end_of_line (char *, int);

extern int target_big_endian;

/* These are initialized by the CPU specific target files (tc-*.c).  */
extern const char comment_chars[];
extern const char line_comment_chars[];
extern const char line_separator_chars[];

/* Table of -I directories.  */
extern const char **include_dirs;
extern size_t include_dir_count;
extern size_t include_dir_maxlen;

/* The offset in the absolute section.  */
extern addressT abs_section_offset;

/* The label on a line, used by some of the pseudo-ops.  */
extern symbolS *line_label;

/* This is used to support MRI common sections.  */
extern symbolS *mri_common_symbol;

/* True if a stabs line debug statement is currently being emitted.  */
extern int outputting_stabs_line_debug;

/* Possible arguments to .linkonce.  */
enum linkonce_type {
  LINKONCE_UNSET = 0,
  LINKONCE_DISCARD,
  LINKONCE_ONE_ONLY,
  LINKONCE_SAME_SIZE,
  LINKONCE_SAME_CONTENTS
};

#ifndef TC_CASE_SENSITIVE
extern char original_case_string[];
#endif

#ifndef TC_PARSE_CONS_RETURN_TYPE
#define TC_PARSE_CONS_RETURN_TYPE bfd_reloc_code_real_type
#define TC_PARSE_CONS_RETURN_NONE BFD_RELOC_NONE
#endif

extern void pop_insert (const pseudo_typeS *);
extern unsigned int get_stab_string_offset (const char *, segT);
extern void aout_process_stab (int, const char *, int, int, int);
extern char *demand_copy_string (int *lenP);
extern char *demand_copy_C_string (int *len_pointer);
extern char get_absolute_expression_and_terminator (long *val_pointer);
extern offsetT get_absolute_expression (void);
extern unsigned int next_char_of_string (void);
extern void s_mri_sect (char *);
extern char *mri_comment_field (char *);
extern void mri_comment_end (char *, int);
extern void init_include_dir (void);
extern void add_include_dir (char *);
extern FILE *search_and_open (const char *, char *);
extern void cons (int nbytes);
extern void demand_empty_rest_of_line (void);
extern void emit_expr (expressionS *exp, unsigned int nbytes);
extern void emit_expr_with_reloc (expressionS *exp, unsigned int nbytes,
				  TC_PARSE_CONS_RETURN_TYPE);
extern void emit_expr_fix (expressionS *, unsigned int, fragS *, char *,
			   TC_PARSE_CONS_RETURN_TYPE);
extern void emit_leb128_expr (expressionS *, int);
extern void equals (char *, int);
extern void float_cons (int);
extern void ignore_rest_of_line (void);
#define discard_rest_of_line ignore_rest_of_line
extern unsigned output_leb128 (char *, valueT, int);
extern void pseudo_set (symbolS * symbolP);
extern void read_a_source_file (const char *name);
extern void read_begin (void);
extern void read_end (void);
extern void read_print_statistics (FILE *);
extern char *read_symbol_name (void);
extern unsigned sizeof_leb128 (valueT, int);
extern void stabs_generate_asm_file (void);
extern void stabs_generate_asm_lineno (void);
extern void stabs_generate_asm_func (const char *, const char *);
extern void stabs_generate_asm_endfunc (const char *, const char *);
extern void stabs_begin (void);
extern void stabs_end (void);
extern void do_repeat (size_t, const char *, const char *, const char *);
extern void end_repeat (int);
extern TC_PARSE_CONS_RETURN_TYPE do_parse_cons_expression (expressionS *, int);
extern void generate_lineno_debug (void);
extern void do_align (unsigned int align, char *fill, unsigned int length,
		      unsigned int max);
extern void bss_alloc (symbolS *, addressT, unsigned);
extern offsetT parse_align (int);
extern symbolS *s_comm_internal (int, symbolS *(*) (int, symbolS *, addressT));
extern symbolS *s_lcomm_internal (int, symbolS *, addressT);
extern void temp_ilp (char *);
extern void restore_ilp (void);
extern void evaluate_deferred_diags (void);
extern void s_file_string (char *);

extern void s_abort (int) ATTRIBUTE_NORETURN;
extern void s_align_bytes (int);
extern void s_align_ptwo (int);
extern void s_base64 (int);
extern void s_bundle_align_mode (int);
extern void s_bundle_lock (int);
extern void s_bundle_unlock (int);
extern void s_comm (int);
extern void s_data (int);
extern void s_desc (int);
extern void s_else (int);
extern void s_elseif (int);
extern void s_end (int);
extern void s_endif (int);
extern void s_err (int);
extern void s_errwarn (int);
extern void s_fail (int);
extern void s_file (int);
extern void s_fill (int);
extern void s_float_space (int);
extern void s_func (int);
extern void s_globl (int);
extern void s_if (int);
extern void s_ifb (int);
extern void s_ifc (int);
extern void s_ifdef (int);
extern void s_ifeqs (int);
extern void s_ignore (int);
extern void s_incbin (int);
extern void s_include (int);
extern void s_irp (int);
extern void s_lcomm (int);
extern void s_lcomm_bytes (int);
extern void s_leb128 (int);
extern void s_linefile (int);
extern void s_linkonce (int);
extern void s_lsym (int);
extern void s_macro (int);
extern void s_mexit (int);
extern void s_mri (int);
extern void s_mri_common (int);
extern void s_nop (int);
extern void s_nops (int);
extern void s_org (int);
extern void s_print (int);
extern void s_purgem (int);
extern void s_rept (int);
extern void s_rva (int);
extern void s_set (int);
extern void s_space (int);
extern void s_stab (int);
extern void s_struct (int);
extern void s_text (int);
extern void s_weakref (int);
extern void s_xstab (int);
extern void stringer (int);
