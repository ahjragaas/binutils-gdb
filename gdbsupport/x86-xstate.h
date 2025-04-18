/* Common code for x86 XSAVE extended state.

   Copyright (C) 2010-2025 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef GDBSUPPORT_X86_XSTATE_H
#define GDBSUPPORT_X86_XSTATE_H

/* The extended state feature IDs in the state component bitmap.  */
#define X86_XSTATE_X87_ID	0
#define X86_XSTATE_SSE_ID	1
#define X86_XSTATE_AVX_ID	2
#define X86_XSTATE_K_ID		5
#define X86_XSTATE_ZMM_H_ID	6
#define X86_XSTATE_ZMM_ID	7
#define X86_XSTATE_PKRU_ID	9

/* The extended state feature bits.  */
#define X86_XSTATE_X87		(1ULL << X86_XSTATE_X87_ID)
#define X86_XSTATE_SSE		(1ULL << X86_XSTATE_SSE_ID)
#define X86_XSTATE_AVX		(1ULL << X86_XSTATE_AVX_ID)

/* AVX 512 adds three feature bits.  All three must be enabled.  */
#define X86_XSTATE_K		(1ULL << X86_XSTATE_K_ID)
#define X86_XSTATE_ZMM_H	(1ULL << X86_XSTATE_ZMM_H_ID)
#define X86_XSTATE_ZMM		(1ULL << X86_XSTATE_ZMM_ID)
#define X86_XSTATE_AVX512	(X86_XSTATE_K | X86_XSTATE_ZMM_H \
				 | X86_XSTATE_ZMM)

#define X86_XSTATE_PKRU		(1ULL << X86_XSTATE_PKRU_ID)

/* Total size of the XSAVE area extended region and offsets of
   register states within the region.  Offsets are set to 0 to
   indicate the absence of the associated registers.  */

struct x86_xsave_layout
{
  int sizeof_xsave = 0;
  int avx_offset = 0;
  int k_offset = 0;
  int zmm_h_offset = 0;
  int zmm_offset = 0;
  int pkru_offset = 0;
};

constexpr bool operator== (const x86_xsave_layout &lhs,
			   const x86_xsave_layout &rhs)
{
  return lhs.sizeof_xsave == rhs.sizeof_xsave
    && lhs.avx_offset == rhs.avx_offset
    && lhs.k_offset == rhs.k_offset
    && lhs.zmm_h_offset == rhs.zmm_h_offset
    && lhs.zmm_offset == rhs.zmm_offset
    && lhs.pkru_offset == rhs.pkru_offset;
}

constexpr bool operator!= (const x86_xsave_layout &lhs,
			   const x86_xsave_layout &rhs)
{
  return !(lhs == rhs);
}


/* Supported mask and size of the extended state.  */
#define X86_XSTATE_X87_MASK	X86_XSTATE_X87
#define X86_XSTATE_SSE_MASK	(X86_XSTATE_X87 | X86_XSTATE_SSE)
#define X86_XSTATE_AVX_MASK	(X86_XSTATE_SSE_MASK | X86_XSTATE_AVX)
#define X86_XSTATE_AVX_AVX512_MASK	(X86_XSTATE_AVX_MASK | X86_XSTATE_AVX512)
#define X86_XSTATE_AVX_AVX512_PKU_MASK 	(X86_XSTATE_AVX_MASK\
					| X86_XSTATE_AVX512 | X86_XSTATE_PKRU)

#define X86_XSTATE_ALL_MASK		(X86_XSTATE_AVX_AVX512_PKU_MASK)


#define X86_XSTATE_SSE_SIZE	576
#define X86_XSTATE_AVX_SIZE	832


#define HAS_AVX(XCR0) (((XCR0) & X86_XSTATE_AVX) != 0)
#define HAS_AVX512(XCR0) (((XCR0) & X86_XSTATE_AVX512) != 0)
#define HAS_PKRU(XCR0) (((XCR0) & X86_XSTATE_PKRU) != 0)

/* Initial value for fctrl register, as defined in the X86 manual, and
   confirmed in the (Linux) kernel source.  When the x87 floating point
   feature is not enabled in an inferior we use this as the value of the
   fcrtl register.  */

#define I387_FCTRL_INIT_VAL 0x037f

/* Initial value for mxcsr register.  When the avx and sse floating point
   features are not enabled in an inferior we use this as the value of the
   mxcsr register.  */

#define I387_MXCSR_INIT_VAL 0x1f80

/* Format of XSAVE extended state is:
	struct
	{
	  fxsave_bytes[0..463]
	  sw_usable_bytes[464..511]
	  xstate_hdr_bytes[512..575]
	  extended state regions (AVX, MPX, AVX512, PKRU, etc.)
	};

  Same memory layout will be used for the coredump NT_X86_XSTATE
  representing the XSAVE extended state registers.

  The first 8 bytes of the sw_usable_bytes[464..467] is the OS enabled
  extended state mask, which is the same as the extended control register
  0 (the XFEATURE_ENABLED_MASK register), XCR0.  We can use this mask
  together with the mask saved in the xstate_hdr_bytes to determine what
  states the processor/OS supports and what state, used or initialized,
  the process/thread is in.  */
#define I386_LINUX_XSAVE_XCR0_OFFSET 464

#endif /* GDBSUPPORT_X86_XSTATE_H */
