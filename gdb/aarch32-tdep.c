/* Copyright (C) 2019-2025 Free Software Foundation, Inc.

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

#include "aarch32-tdep.h"

#include "gdbsupport/common-regcache.h"
#include "arch/aarch32.h"

static struct target_desc *tdesc_aarch32_list[2];

/* See aarch32-tdep.h.  */

const target_desc *
aarch32_read_description (bool tls)
{
  struct target_desc *tdesc = tdesc_aarch32_list[tls];

  if (tdesc == nullptr)
    {
      tdesc = aarch32_create_target_description (tls);
      tdesc_aarch32_list[tls] = tdesc;
    }

  return tdesc;
}
