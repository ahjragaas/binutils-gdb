/* The IGEN simulator generator for GDB, the GNU Debugger.

   Copyright 2002-2025 Free Software Foundation, Inc.

   Contributed by Andrew Cagney.

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

#ifndef IGEN_GEN_MODEL_H
#define IGEN_GEN_MODEL_H

extern void gen_model_h (lf *file, const insn_table *isa);

extern void gen_model_c (lf *file, const insn_table *isa);

#endif /* IGEN_GEN_MODEL_H */
