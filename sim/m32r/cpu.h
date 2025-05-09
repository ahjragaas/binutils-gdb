/* CPU family header for m32rbf.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 1996-2025 Free Software Foundation, Inc.

This file is part of the GNU simulators.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#ifndef CPU_M32RBF_H
#define CPU_M32RBF_H

/* Maximum number of instructions that are fetched at a time.
   This is for LIW type instructions sets (e.g. m32r).  */
#define MAX_LIW_INSNS 2

/* Maximum number of instructions that can be executed in parallel.  */
#define MAX_PARALLEL_INSNS 1

/* The size of an "int" needed to hold an instruction word.
   This is usually 32 bits, but some architectures needs 64 bits.  */
typedef CGEN_INSN_INT CGEN_INSN_WORD;

#include "cgen-engine.h"

/* CPU state information.  */
typedef struct {
  /* Hardware elements.  */
  struct {
  /* program counter */
  USI h_pc;
#define GET_H_PC() CPU (h_pc)
#define SET_H_PC(x) (CPU (h_pc) = (x))
  /* general registers */
  SI h_gr[16];
#define GET_H_GR(a1) CPU (h_gr)[a1]
#define SET_H_GR(a1, x) (CPU (h_gr)[a1] = (x))
  /* control registers */
  USI h_cr[16];
#define GET_H_CR(index) m32rbf_h_cr_get_handler (current_cpu, index)
#define SET_H_CR(index, x) \
do { \
m32rbf_h_cr_set_handler (current_cpu, (index), (x));\
;} while (0)
  /* accumulator */
  DI h_accum;
#define GET_H_ACCUM() m32rbf_h_accum_get_handler (current_cpu)
#define SET_H_ACCUM(x) \
do { \
m32rbf_h_accum_set_handler (current_cpu, (x));\
;} while (0)
  /* condition bit */
  BI h_cond;
#define GET_H_COND() CPU (h_cond)
#define SET_H_COND(x) (CPU (h_cond) = (x))
  /* psw part of psw */
  UQI h_psw;
#define GET_H_PSW() m32rbf_h_psw_get_handler (current_cpu)
#define SET_H_PSW(x) \
do { \
m32rbf_h_psw_set_handler (current_cpu, (x));\
;} while (0)
  /* backup psw */
  UQI h_bpsw;
#define GET_H_BPSW() CPU (h_bpsw)
#define SET_H_BPSW(x) (CPU (h_bpsw) = (x))
  /* backup bpsw */
  UQI h_bbpsw;
#define GET_H_BBPSW() CPU (h_bbpsw)
#define SET_H_BBPSW(x) (CPU (h_bbpsw) = (x))
  /* lock */
  BI h_lock;
#define GET_H_LOCK() CPU (h_lock)
#define SET_H_LOCK(x) (CPU (h_lock) = (x))
  } hardware;
#define CPU_CGEN_HW(cpu) (& M32R_SIM_CPU (cpu)->cpu_data.hardware)
} M32RBF_CPU_DATA;

/* Cover fns for register access.  */
USI m32rbf_h_pc_get (SIM_CPU *);
void m32rbf_h_pc_set (SIM_CPU *, USI);
SI m32rbf_h_gr_get (SIM_CPU *, UINT);
void m32rbf_h_gr_set (SIM_CPU *, UINT, SI);
USI m32rbf_h_cr_get (SIM_CPU *, UINT);
void m32rbf_h_cr_set (SIM_CPU *, UINT, USI);
DI m32rbf_h_accum_get (SIM_CPU *);
void m32rbf_h_accum_set (SIM_CPU *, DI);
BI m32rbf_h_cond_get (SIM_CPU *);
void m32rbf_h_cond_set (SIM_CPU *, BI);
UQI m32rbf_h_psw_get (SIM_CPU *);
void m32rbf_h_psw_set (SIM_CPU *, UQI);
UQI m32rbf_h_bpsw_get (SIM_CPU *);
void m32rbf_h_bpsw_set (SIM_CPU *, UQI);
UQI m32rbf_h_bbpsw_get (SIM_CPU *);
void m32rbf_h_bbpsw_set (SIM_CPU *, UQI);
BI m32rbf_h_lock_get (SIM_CPU *);
void m32rbf_h_lock_set (SIM_CPU *, BI);

/* These must be hand-written.  */
extern CPUREG_FETCH_FN m32rbf_fetch_register;
extern CPUREG_STORE_FN m32rbf_store_register;

typedef struct {
  UINT h_gr;
} MODEL_M32R_D_DATA;

typedef struct {
  int empty;
} MODEL_TEST_DATA;

/* Instruction argument buffer.  */

union sem_fields {
  struct { /* no operands */
    int empty;
  } sfmt_empty;
  struct { /*  */
    UINT f_uimm8;
  } sfmt_clrpsw;
  struct { /*  */
    UINT f_uimm4;
  } sfmt_trap;
  struct { /*  */
    IADDR i_disp24;
    unsigned char out_h_gr_SI_14;
  } sfmt_bl24;
  struct { /*  */
    IADDR i_disp8;
    unsigned char out_h_gr_SI_14;
  } sfmt_bl8;
  struct { /*  */
    SI* i_dr;
    UINT f_hi16;
    UINT f_r1;
    unsigned char out_dr;
  } sfmt_seth;
  struct { /*  */
    ADDR i_uimm24;
    SI* i_dr;
    UINT f_r1;
    unsigned char out_dr;
  } sfmt_ld24;
  struct { /*  */
    SI* i_sr;
    UINT f_r2;
    unsigned char in_sr;
    unsigned char out_h_gr_SI_14;
  } sfmt_jl;
  struct { /*  */
    SI* i_sr;
    INT f_simm16;
    UINT f_r2;
    UINT f_uimm3;
    unsigned char in_sr;
  } sfmt_bset;
  struct { /*  */
    SI* i_dr;
    UINT f_r1;
    UINT f_uimm5;
    unsigned char in_dr;
    unsigned char out_dr;
  } sfmt_slli;
  struct { /*  */
    SI* i_dr;
    INT f_simm8;
    UINT f_r1;
    unsigned char in_dr;
    unsigned char out_dr;
  } sfmt_addi;
  struct { /*  */
    SI* i_src1;
    SI* i_src2;
    UINT f_r1;
    UINT f_r2;
    unsigned char in_src1;
    unsigned char in_src2;
    unsigned char out_src2;
  } sfmt_st_plus;
  struct { /*  */
    SI* i_src1;
    SI* i_src2;
    INT f_simm16;
    UINT f_r1;
    UINT f_r2;
    unsigned char in_src1;
    unsigned char in_src2;
  } sfmt_st_d;
  struct { /*  */
    SI* i_dr;
    SI* i_sr;
    UINT f_r1;
    UINT f_r2;
    unsigned char in_sr;
    unsigned char out_dr;
    unsigned char out_sr;
  } sfmt_ld_plus;
  struct { /*  */
    IADDR i_disp16;
    SI* i_src1;
    SI* i_src2;
    UINT f_r1;
    UINT f_r2;
    unsigned char in_src1;
    unsigned char in_src2;
  } sfmt_beq;
  struct { /*  */
    SI* i_dr;
    SI* i_sr;
    UINT f_r1;
    UINT f_r2;
    UINT f_uimm16;
    unsigned char in_sr;
    unsigned char out_dr;
  } sfmt_and3;
  struct { /*  */
    SI* i_dr;
    SI* i_sr;
    INT f_simm16;
    UINT f_r1;
    UINT f_r2;
    unsigned char in_sr;
    unsigned char out_dr;
  } sfmt_add3;
  struct { /*  */
    SI* i_dr;
    SI* i_sr;
    UINT f_r1;
    UINT f_r2;
    unsigned char in_dr;
    unsigned char in_sr;
    unsigned char out_dr;
  } sfmt_add;
#if WITH_SCACHE_PBB
  /* Writeback handler.  */
  struct {
    /* Pointer to argbuf entry for insn whose results need writing back.  */
    const struct argbuf *abuf;
  } write;
  /* x-before handler */
  struct {
    /*const SCACHE *insns[MAX_PARALLEL_INSNS];*/
    int first_p;
  } before;
  /* x-after handler */
  struct {
    int empty;
  } after;
  /* This entry is used to terminate each pbb.  */
  struct {
    /* Number of insns in pbb.  */
    int insn_count;
    /* Next pbb to execute.  */
    SCACHE *next;
    SCACHE *branch_target;
  } chain;
#endif
};

/* The ARGBUF struct.  */
struct argbuf {
  /* These are the baseclass definitions.  */
  IADDR addr;
  const IDESC *idesc;
  char trace_p;
  char profile_p;
  /* ??? Temporary hack for skip insns.  */
  char skip_count;
  char unused;
  /* cpu specific data follows */
  union sem semantic;
  int written;
  union sem_fields fields;
};

/* A cached insn.

   ??? SCACHE used to contain more than just argbuf.  We could delete the
   type entirely and always just use ARGBUF, but for future concerns and as
   a level of abstraction it is left in.  */

struct scache {
  struct argbuf argbuf;
};

/* Macros to simplify extraction, reading and semantic code.
   These define and assign the local vars that contain the insn's fields.  */

#define EXTRACT_IFMT_EMPTY_VARS \
  unsigned int length;
#define EXTRACT_IFMT_EMPTY_CODE \
  length = 0; \

#define EXTRACT_IFMT_ADD_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  unsigned int length;
#define EXTRACT_IFMT_ADD_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

#define EXTRACT_IFMT_ADD3_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  INT f_simm16; \
  unsigned int length;
#define EXTRACT_IFMT_ADD3_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_simm16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_AND3_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  UINT f_uimm16; \
  unsigned int length;
#define EXTRACT_IFMT_AND3_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_uimm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_OR3_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  UINT f_uimm16; \
  unsigned int length;
#define EXTRACT_IFMT_OR3_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_uimm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_ADDI_VARS \
  UINT f_op1; \
  UINT f_r1; \
  INT f_simm8; \
  unsigned int length;
#define EXTRACT_IFMT_ADDI_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_simm8 = EXTRACT_MSB0_SINT (insn, 16, 8, 8); \

#define EXTRACT_IFMT_ADDV3_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  INT f_simm16; \
  unsigned int length;
#define EXTRACT_IFMT_ADDV3_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_simm16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_BC8_VARS \
  UINT f_op1; \
  UINT f_r1; \
  SI f_disp8; \
  unsigned int length;
#define EXTRACT_IFMT_BC8_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_disp8 = ((((EXTRACT_MSB0_SINT (insn, 16, 8, 8)) * (4))) + (((pc) & (-4)))); \

#define EXTRACT_IFMT_BC24_VARS \
  UINT f_op1; \
  UINT f_r1; \
  SI f_disp24; \
  unsigned int length;
#define EXTRACT_IFMT_BC24_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_disp24 = ((((EXTRACT_MSB0_SINT (insn, 32, 8, 24)) * (4))) + (pc)); \

#define EXTRACT_IFMT_BEQ_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  SI f_disp16; \
  unsigned int length;
#define EXTRACT_IFMT_BEQ_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_disp16 = ((((EXTRACT_MSB0_SINT (insn, 32, 16, 16)) * (4))) + (pc)); \

#define EXTRACT_IFMT_BEQZ_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  SI f_disp16; \
  unsigned int length;
#define EXTRACT_IFMT_BEQZ_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_disp16 = ((((EXTRACT_MSB0_SINT (insn, 32, 16, 16)) * (4))) + (pc)); \

#define EXTRACT_IFMT_CMP_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  unsigned int length;
#define EXTRACT_IFMT_CMP_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

#define EXTRACT_IFMT_CMPI_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  INT f_simm16; \
  unsigned int length;
#define EXTRACT_IFMT_CMPI_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_simm16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_DIV_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  INT f_simm16; \
  unsigned int length;
#define EXTRACT_IFMT_DIV_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_simm16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_JL_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  unsigned int length;
#define EXTRACT_IFMT_JL_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

#define EXTRACT_IFMT_LD24_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_uimm24; \
  unsigned int length;
#define EXTRACT_IFMT_LD24_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_uimm24 = EXTRACT_MSB0_UINT (insn, 32, 8, 24); \

#define EXTRACT_IFMT_LDI16_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  INT f_simm16; \
  unsigned int length;
#define EXTRACT_IFMT_LDI16_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_simm16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_MVFACHI_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  unsigned int length;
#define EXTRACT_IFMT_MVFACHI_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

#define EXTRACT_IFMT_MVFC_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  unsigned int length;
#define EXTRACT_IFMT_MVFC_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

#define EXTRACT_IFMT_MVTACHI_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  unsigned int length;
#define EXTRACT_IFMT_MVTACHI_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

#define EXTRACT_IFMT_MVTC_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  unsigned int length;
#define EXTRACT_IFMT_MVTC_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

#define EXTRACT_IFMT_NOP_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  unsigned int length;
#define EXTRACT_IFMT_NOP_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

#define EXTRACT_IFMT_SETH_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  UINT f_hi16; \
  unsigned int length;
#define EXTRACT_IFMT_SETH_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_hi16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_SLLI_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_shift_op2; \
  UINT f_uimm5; \
  unsigned int length;
#define EXTRACT_IFMT_SLLI_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_shift_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 3); \
  f_uimm5 = EXTRACT_MSB0_UINT (insn, 16, 11, 5); \

#define EXTRACT_IFMT_ST_D_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_r2; \
  INT f_simm16; \
  unsigned int length;
#define EXTRACT_IFMT_ST_D_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_simm16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_TRAP_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_op2; \
  UINT f_uimm4; \
  unsigned int length;
#define EXTRACT_IFMT_TRAP_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_uimm4 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

#define EXTRACT_IFMT_CLRPSW_VARS \
  UINT f_op1; \
  UINT f_r1; \
  UINT f_uimm8; \
  unsigned int length;
#define EXTRACT_IFMT_CLRPSW_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4); \
  f_uimm8 = EXTRACT_MSB0_UINT (insn, 16, 8, 8); \

#define EXTRACT_IFMT_BSET_VARS \
  UINT f_op1; \
  UINT f_bit4; \
  UINT f_uimm3; \
  UINT f_op2; \
  UINT f_r2; \
  INT f_simm16; \
  unsigned int length;
#define EXTRACT_IFMT_BSET_CODE \
  length = 4; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 32, 0, 4); \
  f_bit4 = EXTRACT_MSB0_UINT (insn, 32, 4, 1); \
  f_uimm3 = EXTRACT_MSB0_UINT (insn, 32, 5, 3); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 32, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4); \
  f_simm16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16); \

#define EXTRACT_IFMT_BTST_VARS \
  UINT f_op1; \
  UINT f_bit4; \
  UINT f_uimm3; \
  UINT f_op2; \
  UINT f_r2; \
  unsigned int length;
#define EXTRACT_IFMT_BTST_CODE \
  length = 2; \
  f_op1 = EXTRACT_MSB0_UINT (insn, 16, 0, 4); \
  f_bit4 = EXTRACT_MSB0_UINT (insn, 16, 4, 1); \
  f_uimm3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3); \
  f_op2 = EXTRACT_MSB0_UINT (insn, 16, 8, 4); \
  f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4); \

/* Collection of various things for the trace handler to use.  */

typedef struct trace_record {
  IADDR pc;
  /* FIXME:wip */
} TRACE_RECORD;

#endif /* CPU_M32RBF_H */
