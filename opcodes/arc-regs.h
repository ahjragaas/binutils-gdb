/* ARC Auxiliary register definitions
   Copyright (C) 2015-2025 Free Software Foundation, Inc.

   Contributed by Claudiu Zissulescu (claziss@synopsys.com)

   This file is part of libopcodes.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

DEF (0x0,   ARC_OPCODE_ARCV1,   NONE, status)
DEF (0x1,   ARC_OPCODE_ARCV1,   NONE, semaphore)
DEF (0x2,   ARC_OPCODE_ARCALL,  NONE, lp_start)
DEF (0x3,   ARC_OPCODE_ARCALL,  NONE, lp_end)
DEF (0x4,   ARC_OPCODE_ARCALL,  NONE, identity)
DEF (0x5,   ARC_OPCODE_ARCALL,  NONE, debug)
DEF (0x6,   ARC_OPCODE_ARCALL,  NONE, pc)
DEF (0x7,   ARC_OPCODE_ARCv2HS, NONE, memseg)
DEF (0x7,   ARC_OPCODE_ARCV1,   NONE, adcr)
DEF (0x8,   ARC_OPCODE_ARCV1,   NONE, apcr)
DEF (0x9,   ARC_OPCODE_ARCV1,   NONE, acr)
DEF (0x9,   ARC_OPCODE_ARCv2EM, NONE, sec_stat)
DEF (0xa,   ARC_OPCODE_ARCALL,  NONE, status32)
DEF (0xb,   ARC_OPCODE_ARCV1,   NONE, status32_l1)
DEF (0xb,   ARC_OPCODE_ARCV2,   NONE, status32_p0)
DEF (0xc,   ARC_OPCODE_ARCV1,   NONE, status32_l2)
DEF (0xc,   ARC_OPCODE_ARCv2EM, NONE, sec_extra)
DEF (0xd,   ARC_OPCODE_ARCV2,   NONE, aux_user_sp)
DEF (0xe,   ARC_OPCODE_ARCV2,   NONE, aux_irq_ctrl)
DEF (0xe,   ARC_OPCODE_ARC700,  NONE, clk_enable)
DEF (0xf,   ARC_OPCODE_ARC700,  NONE, bpu_flush)
DEF (0xf,   ARC_OPCODE_ARCv2HS, NONE, debugi)
DEF (0x10,  ARC_OPCODE_ARCV1,   NONE, ivic)
DEF (0x10,  ARC_OPCODE_ARCALL,  NONE, ic_ivic)
DEF (0x11,  ARC_OPCODE_ARCV1,   NONE, che_mode)
DEF (0x11,  ARC_OPCODE_ARCALL,  NONE, ic_ctrl)
DEF (0x12,  ARC_OPCODE_ARC600,  NONE, mulhi)
DEF (0x12,  ARC_OPCODE_ARCv2HS, NONE, ic_startr_ext)
DEF (0x13,  ARC_OPCODE_ARCV1,   NONE, lockline)
DEF (0x13,  ARC_OPCODE_ARCV2,   NONE, ic_lil)
DEF (0x14,  ARC_OPCODE_ARC600,  NONE, dmc_code_ram)
DEF (0x15,  ARC_OPCODE_ARCV1,   NONE, tag_addr_mask)
DEF (0x16,  ARC_OPCODE_ARCV1,   NONE, tag_data_mask)
DEF (0x16,  ARC_OPCODE_ARCv2HS, NONE, ic_ivir)
DEF (0x17,  ARC_OPCODE_ARCV1,   NONE, line_length_mask)
DEF (0x17,  ARC_OPCODE_ARCv2HS, NONE, ic_endr)
DEF (0x18,  ARC_OPCODE_ARC600,  NONE, aux_ldst_ram)
DEF (0x18,  ARC_OPCODE_NONE,    NONE, aux_dccm)
DEF (0x19,  ARC_OPCODE_ARCV1,   NONE, unlockline)
DEF (0x19,  ARC_OPCODE_ARCALL,  NONE, ic_ivil)
DEF (0x1a,  ARC_OPCODE_ARCALL,  NONE, ic_ram_address)
DEF (0x1b,  ARC_OPCODE_ARCALL,  NONE, ic_tag)
DEF (0x1c,  ARC_OPCODE_ARCALL,  NONE, ic_wp)
DEF (0x1d,  ARC_OPCODE_ARCALL,  NONE, ic_data)
DEF (0x1e,  ARC_OPCODE_ARCALL,  NONE, ic_ptag)
DEF (0x1f,  ARC_OPCODE_ARCv2EM, NONE, debugi)
DEF (0x1f,  ARC_OPCODE_ARCv2HS, NONE, ic_endr_ext)
DEF (0x20,  ARC_OPCODE_ARC600,  NONE, sram_seq)
DEF (0x21,  ARC_OPCODE_ARCALL,  NONE, count0)
DEF (0x22,  ARC_OPCODE_ARCALL,  NONE, control0)
DEF (0x23,  ARC_OPCODE_ARCALL,  NONE, limit0)
DEF (0x24,  ARC_OPCODE_ARCV1,   NONE, pcport)
DEF (0x25,  ARC_OPCODE_ARCALL,  NONE, int_vector_base)
DEF (0x26,  ARC_OPCODE_ARC600,  NONE, aux_vbfdw_mode)
DEF (0x27,  ARC_OPCODE_ARC600,  NONE, aux_vbfdw_bm0)
DEF (0x28,  ARC_OPCODE_ARC600,  NONE, aux_vbfdw_bm1)
DEF (0x29,  ARC_OPCODE_ARC600,  NONE, aux_vbfdw_accu)
DEF (0x2a,  ARC_OPCODE_ARC600,  NONE, aux_vbfdw_ofst)
DEF (0x2b,  ARC_OPCODE_ARC600,  NONE, aux_vbfdw_intstat)
DEF (0x2c,  ARC_OPCODE_ARC600,  NONE, aux_xmac0_24)
DEF (0x2d,  ARC_OPCODE_ARC600,  NONE, aux_xmac1_24)
DEF (0x2e,  ARC_OPCODE_ARC600,  NONE, aux_xmac2_24)
DEF (0x2f,  ARC_OPCODE_ARC600,  NONE, aux_fbf_store_16)
DEF (0x30,  ARC_OPCODE_ARCv2EM, NONE, acg_ctrl)
DEF (0x30,  ARC_OPCODE_NONE,    NONE, ax0)
DEF (0x31,  ARC_OPCODE_NONE,    NONE, ax1)
DEF (0x32,  ARC_OPCODE_NONE,    NONE, aux_crc_poly)
DEF (0x33,  ARC_OPCODE_NONE,    NONE, aux_crc_mode)
DEF (0x34,  ARC_OPCODE_NONE,    NONE, mx0)
DEF (0x35,  ARC_OPCODE_NONE,    NONE, mx1)
DEF (0x36,  ARC_OPCODE_NONE,    NONE, my0)
DEF (0x37,  ARC_OPCODE_NONE,    NONE, my1)
DEF (0x38,  ARC_OPCODE_NONE,    NONE, xyconfig)
DEF (0x38,  ARC_OPCODE_ARCv2EM, NONE, aux_kernel_sp)
DEF (0x39,  ARC_OPCODE_NONE,    NONE, scratch_a)
DEF (0x39,  ARC_OPCODE_ARCv2EM, NONE, aux_sec_u_sp)
DEF (0x3a,  ARC_OPCODE_NONE,    NONE, burstsys)
DEF (0x3a,  ARC_OPCODE_NONE,    NONE, tsch)
DEF (0x3a,  ARC_OPCODE_ARCv2EM, NONE, aux_sec_k_sp)
DEF (0x3b,  ARC_OPCODE_NONE,    NONE, burstxym)
DEF (0x3c,  ARC_OPCODE_NONE,    NONE, burstsz)
DEF (0x3d,  ARC_OPCODE_NONE,    NONE, burstval)
DEF (0x3e,  ARC_OPCODE_ARCv2EM, NONE, aux_sec_ctrl)
DEF (0x3f,  ARC_OPCODE_ARCv2EM, NONE, erp_control)
DEF (0x40,  ARC_OPCODE_ARCv2EM, NONE, rferp_status0)
DEF (0x41,  ARC_OPCODE_ARCv2EM, NONE, rferp_status1)
DEF (0x40,  ARC_OPCODE_ARC600,  NONE, xtp_newval)
DEF (0x41,  ARC_OPCODE_ARCV1,   NONE, aux_macmode)
DEF (0x42,  ARC_OPCODE_ARC600,  NONE, lsp_newval)
DEF (0x43,  ARC_OPCODE_ARCV1,   NONE, aux_irq_lv12)
DEF (0x43,  ARC_OPCODE_ARCV2,   NONE, aux_irq_act)
DEF (0x44,  ARC_OPCODE_ARCV1,   NONE, aux_xmac0)
DEF (0x45,  ARC_OPCODE_ARCV1,   NONE, aux_xmac1)
DEF (0x46,  ARC_OPCODE_ARCV1,   NONE, aux_xmac2)
DEF (0x47,  ARC_OPCODE_ARCALL,  NONE, dc_ivdc)
DEF (0x48,  ARC_OPCODE_ARCALL,  NONE, dc_ctrl)
DEF (0x49,  ARC_OPCODE_ARCALL,  NONE, dc_ldl)
DEF (0x4a,  ARC_OPCODE_ARCALL,  NONE, dc_ivdl)
DEF (0x4b,  ARC_OPCODE_ARCALL,  NONE, dc_flsh)
DEF (0x4c,  ARC_OPCODE_ARCALL,  NONE, dc_fldl)
DEF (0x50,  ARC_OPCODE_NONE,    NONE, hexdata)
DEF (0x51,  ARC_OPCODE_NONE,    NONE, hexctrl)
DEF (0x52,  ARC_OPCODE_NONE,    NONE, led)
DEF (0x56,  ARC_OPCODE_NONE,    NONE, dilstat)
DEF (0x57,  ARC_OPCODE_ARC600,  NONE, swstat)
DEF (0x58,  ARC_OPCODE_ARCALL,  NONE, dc_ram_addr)
DEF (0x59,  ARC_OPCODE_ARCALL,  NONE, dc_tag)
DEF (0x5a,  ARC_OPCODE_ARCALL,  NONE, dc_wp)
DEF (0x5b,  ARC_OPCODE_ARCALL,  NONE, dc_data)
DEF (0x61,  ARC_OPCODE_ARCALL,  NONE, dccm_base_build)
DEF (0x62,  ARC_OPCODE_ARCALL,  NONE, crc_build)
DEF (0x63,  ARC_OPCODE_ARCALL,  NONE, bta_link_build)
DEF (0x64,  ARC_OPCODE_ARCALL,  NONE, vbfdw_build)
DEF (0x65,  ARC_OPCODE_ARCALL,  NONE, ea_build)
DEF (0x66,  ARC_OPCODE_ARCALL,  NONE, dataspace)
DEF (0x67,  ARC_OPCODE_ARCALL,  NONE, memsubsys)
DEF (0x68,  ARC_OPCODE_ARCALL,  NONE, vecbase_ac_build)
DEF (0x69,  ARC_OPCODE_ARCALL,  NONE, p_base_addr)
DEF (0x6a,  ARC_OPCODE_ARCALL,  NONE, data_uncached_build)
DEF (0x6b,  ARC_OPCODE_ARCALL,  NONE, fp_build)
DEF (0x6c,  ARC_OPCODE_ARCALL,  NONE, dpfp_build)
DEF (0x6d,  ARC_OPCODE_ARCALL,  NONE, mpu_build)
DEF (0x6e,  ARC_OPCODE_ARCALL,  NONE, rf_build)
DEF (0x6f,  ARC_OPCODE_ARCALL,  NONE, mmu_build)
DEF (0x70,  ARC_OPCODE_ARCv2EM, NONE, sec_vecbase_build)
DEF (0x71,  ARC_OPCODE_ARCALL,  NONE, vecbase_build)
DEF (0x72,  ARC_OPCODE_ARCALL,  NONE, d_cache_build)
DEF (0x73,  ARC_OPCODE_ARCALL,  NONE, madi_build)
DEF (0x74,  ARC_OPCODE_ARCALL,  NONE, dccm_build)
DEF (0x75,  ARC_OPCODE_ARCALL,  NONE, timer_build)
DEF (0x76,  ARC_OPCODE_ARCALL,  NONE, ap_build)
DEF (0x77,  ARC_OPCODE_ARCALL,  NONE, i_cache_build)
DEF (0x78,  ARC_OPCODE_ARCALL,  NONE, iccm_build)
DEF (0x79,  ARC_OPCODE_ARCALL,  NONE, dspram_build)
DEF (0x7a,  ARC_OPCODE_ARCALL,  NONE, mac_build)
DEF (0x7b,  ARC_OPCODE_ARCALL,  NONE, multiply_build)
DEF (0x7c,  ARC_OPCODE_ARCALL,  NONE, swap_build)
DEF (0x7d,  ARC_OPCODE_ARCALL,  NONE, norm_build)
DEF (0x7e,  ARC_OPCODE_ARCALL,  NONE, minmax_build)
DEF (0x7f,  ARC_OPCODE_ARCALL,  NONE, barrel_build)
DEF (0x80,  ARC_OPCODE_ARCALL,  NONE, ax0)
DEF (0x81,  ARC_OPCODE_ARCALL,  NONE, ax1)
DEF (0x82,  ARC_OPCODE_ARCALL,  NONE, ax2)
DEF (0x83,  ARC_OPCODE_ARCALL,  NONE, ax3)
DEF (0x84,  ARC_OPCODE_ARCALL,  NONE, ay0)
DEF (0x85,  ARC_OPCODE_ARCALL,  NONE, ay1)
DEF (0x86,  ARC_OPCODE_ARCALL,  NONE, ay2)
DEF (0x87,  ARC_OPCODE_ARCALL,  NONE, ay3)
DEF (0x88,  ARC_OPCODE_ARCALL,  NONE, mx00)
DEF (0x89,  ARC_OPCODE_ARCALL,  NONE, mx01)
DEF (0x8a,  ARC_OPCODE_ARCALL,  NONE, mx10)
DEF (0x8b,  ARC_OPCODE_ARCALL,  NONE, mx11)
DEF (0x8c,  ARC_OPCODE_ARCALL,  NONE, mx20)
DEF (0x8d,  ARC_OPCODE_ARCALL,  NONE, mx21)
DEF (0x8e,  ARC_OPCODE_ARCALL,  NONE, mx30)
DEF (0x8f,  ARC_OPCODE_ARCALL,  NONE, mx31)
DEF (0x90,  ARC_OPCODE_ARCALL,  NONE, my00)
DEF (0x91,  ARC_OPCODE_ARCALL,  NONE, my01)
DEF (0x92,  ARC_OPCODE_ARCALL,  NONE, my10)
DEF (0x93,  ARC_OPCODE_ARCALL,  NONE, my11)
DEF (0x94,  ARC_OPCODE_ARCALL,  NONE, my20)
DEF (0x95,  ARC_OPCODE_ARCALL,  NONE, my21)
DEF (0x96,  ARC_OPCODE_ARCALL,  NONE, my30)
DEF (0x97,  ARC_OPCODE_ARCALL,  NONE, my31)
DEF (0x98,  ARC_OPCODE_ARCALL,  NONE, xyconfig)
DEF (0x99,  ARC_OPCODE_ARCALL,  NONE, burstsys)
DEF (0x9a,  ARC_OPCODE_ARCALL,  NONE, burstxym)
DEF (0x9b,  ARC_OPCODE_ARCALL,  NONE, burstsz)
DEF (0x9c,  ARC_OPCODE_ARCALL,  NONE, burstval)
DEF (0x9d,  ARC_OPCODE_ARCALL,  NONE, xylsbasex)
DEF (0x9e,  ARC_OPCODE_ARCALL,  NONE, xylsbasey)
DEF (0x9f,  ARC_OPCODE_ARCALL,  NONE, aux_xmaclw_h)
DEF (0xa0,  ARC_OPCODE_ARCALL,  NONE, aux_xmaclw_l)
DEF (0xa1,  ARC_OPCODE_ARCALL,  NONE, se_ctrl)
DEF (0xa2,  ARC_OPCODE_ARCALL,  NONE, se_stat)
DEF (0xa3,  ARC_OPCODE_ARCALL,  NONE, se_err)
DEF (0xa4,  ARC_OPCODE_ARCALL,  NONE, se_eadr)
DEF (0xa5,  ARC_OPCODE_ARCALL,  NONE, se_spc)
DEF (0xa6,  ARC_OPCODE_ARCALL,  NONE, sdm_base)
DEF (0xa7,  ARC_OPCODE_ARCALL,  NONE, scm_base)
DEF (0xa8,  ARC_OPCODE_ARCALL,  NONE, se_dbg_ctrl)
DEF (0xa9,  ARC_OPCODE_ARCALL,  NONE, se_dbg_data0)
DEF (0xaa,  ARC_OPCODE_ARCALL,  NONE, se_dbg_data1)
DEF (0xab,  ARC_OPCODE_ARCALL,  NONE, se_dbg_data2)
DEF (0xac,  ARC_OPCODE_ARCALL,  NONE, se_dbg_data3)
DEF (0xad,  ARC_OPCODE_ARCALL,  NONE, se_watch)
DEF (0xc0,  ARC_OPCODE_ARCALL,  NONE, bpu_build)
DEF (0xc1,  ARC_OPCODE_ARC600,  NONE, arc600_build_config)
DEF (0xc1,  ARC_OPCODE_ARC700,  NONE, isa_config)
DEF (0xc1,  ARC_OPCODE_ARCV2,   NONE, isa_config)
DEF (0xf4,  ARC_OPCODE_ARCALL,  NONE, hwp_build)
DEF (0xf5,  ARC_OPCODE_ARCALL,  NONE, pct_build)
DEF (0xf6,  ARC_OPCODE_ARCALL,  NONE, cc_build)
DEF (0xf7,  ARC_OPCODE_ARCALL,  NONE, pm_bcr)
DEF (0xf8,  ARC_OPCODE_ARCALL,  NONE, scq_switch_build)
DEF (0xf9,  ARC_OPCODE_ARCALL,  NONE, vraptor_build)
DEF (0xfa,  ARC_OPCODE_ARCALL,  NONE, dma_config)
DEF (0xfb,  ARC_OPCODE_ARCALL,  NONE, simd_config)
DEF (0xfc,  ARC_OPCODE_ARCALL,  NONE, vlc_build)
DEF (0xfd,  ARC_OPCODE_ARCALL,  NONE, simd_dma_build)
DEF (0xfe,  ARC_OPCODE_ARCALL,  NONE, ifetch_queue_build)
DEF (0xff,  ARC_OPCODE_ARCALL,  NONE, smart_build)
DEF (0x100, ARC_OPCODE_ARCALL,  NONE, count1)
DEF (0x101, ARC_OPCODE_ARCALL,  NONE, control1)
DEF (0x102, ARC_OPCODE_ARCALL,  NONE, limit1)
DEF (0x103, ARC_OPCODE_ARCALL,  NONE, timer_xx)
DEF (0x200, ARC_OPCODE_ARCV1,   NONE, aux_irq_lev)
DEF (0x200, ARC_OPCODE_ARCV2,   NONE, irq_priority_pending)
DEF (0x201, ARC_OPCODE_ARCALL,  NONE, aux_irq_hint)
DEF (0x202, ARC_OPCODE_ARC600,  NONE, aux_inter_core_interrupt)
DEF (0x206, ARC_OPCODE_ARCV2,   NONE, irq_priority)
DEF (0x210, ARC_OPCODE_ARC700,  NONE, aes_aux_0)
DEF (0x211, ARC_OPCODE_ARC700,  NONE, aes_aux_1)
DEF (0x212, ARC_OPCODE_ARC700,  NONE, aes_aux_2)
DEF (0x213, ARC_OPCODE_ARC700,  NONE, aes_crypt_mode)
DEF (0x214, ARC_OPCODE_ARC700,  NONE, aes_auxs)
DEF (0x215, ARC_OPCODE_ARC700,  NONE, aes_auxi)
DEF (0x216, ARC_OPCODE_ARC700,  NONE, aes_aux_3)
DEF (0x217, ARC_OPCODE_ARC700,  NONE, aes_aux_4)
DEF (0x218, ARC_OPCODE_ARC700,  NONE, arith_ctl_aux)
DEF (0x219, ARC_OPCODE_ARC700,  NONE, des_aux)
DEF (0x220, ARC_OPCODE_ARCALL,  NONE, ap_amv0)
DEF (0x221, ARC_OPCODE_ARCALL,  NONE, ap_amm0)
DEF (0x222, ARC_OPCODE_ARCALL,  NONE, ap_ac0)
DEF (0x223, ARC_OPCODE_ARCALL,  NONE, ap_amv1)
DEF (0x224, ARC_OPCODE_ARCALL,  NONE, ap_amm1)
DEF (0x225, ARC_OPCODE_ARCALL,  NONE, ap_ac1)
DEF (0x226, ARC_OPCODE_ARCALL,  NONE, ap_amv2)
DEF (0x227, ARC_OPCODE_ARCALL,  NONE, ap_amm2)
DEF (0x228, ARC_OPCODE_ARCALL,  NONE, ap_ac2)
DEF (0x229, ARC_OPCODE_ARCALL,  NONE, ap_amv3)
DEF (0x22a, ARC_OPCODE_ARCALL,  NONE, ap_amm3)
DEF (0x22b, ARC_OPCODE_ARCALL,  NONE, ap_ac3)
DEF (0x22c, ARC_OPCODE_ARCALL,  NONE, ap_amv4)
DEF (0x22d, ARC_OPCODE_ARCALL,  NONE, ap_amm4)
DEF (0x22e, ARC_OPCODE_ARCALL,  NONE, ap_ac4)
DEF (0x22f, ARC_OPCODE_ARCALL,  NONE, ap_amv5)
DEF (0x230, ARC_OPCODE_ARCALL,  NONE, ap_amm5)
DEF (0x231, ARC_OPCODE_ARCALL,  NONE, ap_ac5)
DEF (0x232, ARC_OPCODE_ARCALL,  NONE, ap_amv6)
DEF (0x233, ARC_OPCODE_ARCALL,  NONE, ap_amm6)
DEF (0x234, ARC_OPCODE_ARCALL,  NONE, ap_ac6)
DEF (0x235, ARC_OPCODE_ARCALL,  NONE, ap_amv7)
DEF (0x236, ARC_OPCODE_ARCALL,  NONE, ap_amm7)
DEF (0x237, ARC_OPCODE_ARCALL,  NONE, ap_ac7)
DEF (0x268, ARC_OPCODE_ARCv2EM, NONE, nsc_table_top)
DEF (0x269, ARC_OPCODE_ARCv2EM, NONE, nsc_table_base)
DEF (0x290, ARC_OPCODE_ARCV2,   NONE, jli_base)
DEF (0x291, ARC_OPCODE_ARCV2,   NONE, ldi_base)
DEF (0x292, ARC_OPCODE_ARCV2,   NONE, ei_base)
DEF (0x300, ARC_OPCODE_ARCFPX,  DPX,  fp_status)
DEF (0x301, ARC_OPCODE_ARCFPX,  DPX,  aux_dpfp1l)
DEF (0x301, ARC_OPCODE_ARCFPX,  DPX,  d1l)
DEF (0x302, ARC_OPCODE_ARCFPX,  DPX,  aux_dpfp1h)
DEF (0x302, ARC_OPCODE_ARCFPX,  DPX,  d1h)
DEF (0x302, ARC_OPCODE_ARCv2EM, DPA,  d1l)
DEF (0x303, ARC_OPCODE_ARCFPX,  DPX,  aux_dpfp2l)
DEF (0x303, ARC_OPCODE_ARCFPX,  DPX,  d2l)
DEF (0x303, ARC_OPCODE_ARCv2EM, DPA,  d1h)
DEF (0x304, ARC_OPCODE_ARCFPX,  DPX,  aux_dpfp2h)
DEF (0x304, ARC_OPCODE_ARCFPX,  DPX,  d2h)
DEF (0x304, ARC_OPCODE_ARCv2EM, DPA,  d2l)
DEF (0x305, ARC_OPCODE_ARCFPX,  DPX,  dpfp_status)
DEF (0x305, ARC_OPCODE_ARCv2EM, DPA,  d2h)
DEF (0x400, ARC_OPCODE_ARCALL,  NONE, eret)
DEF (0x401, ARC_OPCODE_ARCALL,  NONE, erbta)
DEF (0x402, ARC_OPCODE_ARCALL,  NONE, erstatus)
DEF (0x403, ARC_OPCODE_ARCALL,  NONE, ecr)
DEF (0x404, ARC_OPCODE_ARCALL,  NONE, efa)
DEF (0x405, ARC_OPCODE_ARC700,  NONE, tlbpd0)
DEF (0x406, ARC_OPCODE_ARC700,  NONE, tlbpd1)
DEF (0x406, ARC_OPCODE_ARCv2EM, NONE, ersec_stat)
DEF (0x407, ARC_OPCODE_ARCv2EM, NONE, aux_sec_except)
DEF (0x407, ARC_OPCODE_ARC700,  NONE, tlbindex)
DEF (0x408, ARC_OPCODE_ARC700,  NONE, tlbcommand)
DEF (0x409, ARC_OPCODE_ARC700,  NONE, pid)
DEF (0x409, ARC_OPCODE_ARCALL,  NONE, mpuen)
DEF (0x40a, ARC_OPCODE_ARCALL,  NONE, icause1)
DEF (0x40b, ARC_OPCODE_ARCALL,  NONE, icause2)
DEF (0x40c, ARC_OPCODE_ARCALL,  NONE, aux_ienable)
DEF (0x40d, ARC_OPCODE_ARCALL,  NONE, aux_itrigger)
DEF (0x410, ARC_OPCODE_ARCALL,  NONE, xpu)
DEF (0x412, ARC_OPCODE_ARCALL,  NONE, bta)
DEF (0x413, ARC_OPCODE_ARC700,  NONE, bta_l1)
DEF (0x414, ARC_OPCODE_ARC700,  NONE, bta_l2)
DEF (0x415, ARC_OPCODE_ARCALL,  NONE, aux_irq_pulse_cancel)
DEF (0x416, ARC_OPCODE_ARCALL,  NONE, aux_irq_pending)
DEF (0x418, ARC_OPCODE_ARC700,  NONE, scratch_data0)
DEF (0x420, ARC_OPCODE_ARCALL,  NONE, mpuic)
DEF (0x421, ARC_OPCODE_ARCALL,  NONE, mpufa)
DEF (0x422, ARC_OPCODE_ARCALL,  NONE, mpurdb0)
DEF (0x423, ARC_OPCODE_ARCALL,  NONE, mpurdp0)
DEF (0x424, ARC_OPCODE_ARCALL,  NONE, mpurdb1)
DEF (0x425, ARC_OPCODE_ARCALL,  NONE, mpurdp1)
DEF (0x426, ARC_OPCODE_ARCALL,  NONE, mpurdb2)
DEF (0x427, ARC_OPCODE_ARCALL,  NONE, mpurdp2)
DEF (0x428, ARC_OPCODE_ARCALL,  NONE, mpurdb3)
DEF (0x429, ARC_OPCODE_ARCALL,  NONE, mpurdp3)
DEF (0x42a, ARC_OPCODE_ARCALL,  NONE, mpurdb4)
DEF (0x42b, ARC_OPCODE_ARCALL,  NONE, mpurdp4)
DEF (0x42c, ARC_OPCODE_ARCALL,  NONE, mpurdb5)
DEF (0x42d, ARC_OPCODE_ARCALL,  NONE, mpurdp5)
DEF (0x42e, ARC_OPCODE_ARCALL,  NONE, mpurdb6)
DEF (0x42f, ARC_OPCODE_ARCALL,  NONE, mpurdp6)
DEF (0x430, ARC_OPCODE_ARCALL,  NONE, mpurdb7)
DEF (0x431, ARC_OPCODE_ARCALL,  NONE, mpurdp7)
DEF (0x432, ARC_OPCODE_ARCALL,  NONE, mpurdb8)
DEF (0x433, ARC_OPCODE_ARCALL,  NONE, mpurdp8)
DEF (0x434, ARC_OPCODE_ARCALL,  NONE, mpurdb9)
DEF (0x435, ARC_OPCODE_ARCALL,  NONE, mpurdp9)
DEF (0x436, ARC_OPCODE_ARCALL,  NONE, mpurdb10)
DEF (0x437, ARC_OPCODE_ARCALL,  NONE, mpurdp10)
DEF (0x438, ARC_OPCODE_ARCALL,  NONE, mpurdb11)
DEF (0x439, ARC_OPCODE_ARCALL,  NONE, mpurdp11)
DEF (0x43a, ARC_OPCODE_ARCALL,  NONE, mpurdb12)
DEF (0x43b, ARC_OPCODE_ARCALL,  NONE, mpurdp12)
DEF (0x43c, ARC_OPCODE_ARCALL,  NONE, mpurdb13)
DEF (0x43d, ARC_OPCODE_ARCALL,  NONE, mpurdp13)
DEF (0x43e, ARC_OPCODE_ARCALL,  NONE, mpurdb14)
DEF (0x43f, ARC_OPCODE_ARCALL,  NONE, mpurdp14)
DEF (0x440, ARC_OPCODE_ARCALL,  NONE, mpurdb15)
DEF (0x441, ARC_OPCODE_ARCALL,  NONE, mpurdp15)
DEF (0x450, ARC_OPCODE_ARC600,  NONE, pm_status)
DEF (0x451, ARC_OPCODE_ARC600,  NONE, wake)
DEF (0x452, ARC_OPCODE_ARC600,  NONE, dvfs_performance)
DEF (0x453, ARC_OPCODE_ARC600,  NONE, pwr_ctrl)
DEF (0x460, ARC_OPCODE_ARCv2HS, NONE, tlbpd0)
DEF (0x461, ARC_OPCODE_ARCv2HS, NONE, tlbpd1)
DEF (0x464, ARC_OPCODE_ARCv2HS, NONE, tlbindex)
DEF (0x465, ARC_OPCODE_ARCv2HS, NONE, tlbcommand)
DEF (0x468, ARC_OPCODE_ARCv2HS, NONE, pid)
DEF (0x46c, ARC_OPCODE_ARCv2HS, NONE, scratch_data0)
DEF (0x500, ARC_OPCODE_ARC700,  NONE, aux_vlc_buf_idx)
DEF (0x501, ARC_OPCODE_ARC700,  NONE, aux_vlc_read_buf)
DEF (0x502, ARC_OPCODE_ARC700,  NONE, aux_vlc_valid_bits)
DEF (0x503, ARC_OPCODE_ARC700,  NONE, aux_vlc_buf_in)
DEF (0x504, ARC_OPCODE_ARC700,  NONE, aux_vlc_buf_free)
DEF (0x505, ARC_OPCODE_ARC700,  NONE, aux_vlc_ibuf_status)
DEF (0x506, ARC_OPCODE_ARC700,  NONE, aux_vlc_setup)
DEF (0x507, ARC_OPCODE_ARC700,  NONE, aux_vlc_bits)
DEF (0x508, ARC_OPCODE_ARC700,  NONE, aux_vlc_table)
DEF (0x509, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_symbol)
DEF (0x50a, ARC_OPCODE_ARC700,  NONE, aux_vlc_read_symbol)
DEF (0x510, ARC_OPCODE_ARC700,  NONE, aux_ucavlc_setup)
DEF (0x511, ARC_OPCODE_ARC700,  NONE, aux_ucavlc_state)
DEF (0x512, ARC_OPCODE_ARC700,  NONE, aux_cavlc_zero_left)
DEF (0x514, ARC_OPCODE_ARC700,  NONE, aux_uvlc_i_state)
DEF (0x51c, ARC_OPCODE_ARC700,  NONE, aux_vlc_dma_ptr)
DEF (0x51d, ARC_OPCODE_ARC700,  NONE, aux_vlc_dma_end)
DEF (0x51e, ARC_OPCODE_ARC700,  NONE, aux_vlc_dma_esc)
DEF (0x51f, ARC_OPCODE_ARC700,  NONE, aux_vlc_dma_ctrl)
DEF (0x520, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_0bit)
DEF (0x521, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_1bit)
DEF (0x522, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_2bit)
DEF (0x523, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_3bit)
DEF (0x524, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_4bit)
DEF (0x525, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_5bit)
DEF (0x526, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_6bit)
DEF (0x527, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_7bit)
DEF (0x528, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_8bit)
DEF (0x529, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_9bit)
DEF (0x52a, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_10bit)
DEF (0x52b, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_11bit)
DEF (0x52c, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_12bit)
DEF (0x52d, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_13bit)
DEF (0x52e, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_14bit)
DEF (0x52f, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_15bit)
DEF (0x530, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_16bit)
DEF (0x531, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_17bit)
DEF (0x532, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_18bit)
DEF (0x533, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_19bit)
DEF (0x534, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_20bit)
DEF (0x535, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_21bit)
DEF (0x536, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_22bit)
DEF (0x537, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_23bit)
DEF (0x538, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_24bit)
DEF (0x539, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_25bit)
DEF (0x53a, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_26bit)
DEF (0x53b, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_27bit)
DEF (0x53c, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_28bit)
DEF (0x53d, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_29bit)
DEF (0x53e, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_30bit)
DEF (0x53f, ARC_OPCODE_ARC700,  NONE, aux_vlc_get_31bit)
DEF (0x540, ARC_OPCODE_ARC700,  NONE, aux_cabac_ctrl)
DEF (0x541, ARC_OPCODE_ARC700,  NONE, aux_cabac_ctx_state)
DEF (0x542, ARC_OPCODE_ARC700,  NONE, aux_cabac_cod_param)
DEF (0x543, ARC_OPCODE_ARC700,  NONE, aux_cabac_misc0)
DEF (0x544, ARC_OPCODE_ARC700,  NONE, aux_cabac_misc1)
DEF (0x545, ARC_OPCODE_ARC700,  NONE, aux_cabac_misc2)
DEF (0x700, ARC_OPCODE_ARCALL,  NONE, smart_control)
DEF (0x701, ARC_OPCODE_ARC700,  NONE, smart_data_0)
DEF (0x701, ARC_OPCODE_ARC600,  NONE, smart_data)
DEF (0x701, ARC_OPCODE_ARC700,  NONE, smart_data_2)
DEF (0x701, ARC_OPCODE_ARC700,  NONE, smart_data_3)
