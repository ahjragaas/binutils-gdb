/* Architecture independent code for ABI 'none' (bare-metal).

   Copyright (C) 2021-2025 Free Software Foundation, Inc.

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

#ifndef GDB_ELF_NONE_TDEP_H
#define GDB_ELF_NONE_TDEP_H

struct gdbarch;

/* Initialize support for cross-architecture features applicable for the
   GDB_OSABI_NONE ABI, that is bare-metal targets.  */

void elf_none_init_abi (struct gdbarch *gdbarch);

#endif /* GDB_ELF_NONE_TDEP_H */
