/* Header for skipping over uninteresting files and functions when debugging.

   Copyright (C) 2011-2025 Free Software Foundation, Inc.

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

#ifndef GDB_SKIP_H
#define GDB_SKIP_H

struct symtab_and_line;

/* Returns true if the given FUNCTION_NAME is marked for skip and
   shouldn't be stepped into.  Otherwise, returns false.  */
bool function_name_is_marked_for_skip (const char *function_name,
				       const symtab_and_line &function_sal);

#endif /* GDB_SKIP_H */
