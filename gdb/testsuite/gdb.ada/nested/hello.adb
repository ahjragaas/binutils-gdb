--  Copyright 2007-2025 Free Software Foundation, Inc.
--
--  This program is free software; you can redistribute it and/or modify
--  it under the terms of the GNU General Public License as published by
--  the Free Software Foundation; either version 3 of the License, or
--  (at your option) any later version.
--
--  This program is distributed in the hope that it will be useful,
--  but WITHOUT ANY WARRANTY; without even the implied warranty of
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--  GNU General Public License for more details.
--
--  You should have received a copy of the GNU General Public License
--  along with this program.  If not, see <http://www.gnu.org/licenses/>.

procedure Hello is

   procedure First is
   begin
      null;
   end First;

   procedure Second is
   begin
      First;
   end Second;

   procedure Third is
   begin
      Second;
   end Third;

begin
   declare
      procedure Fourth is
      begin
         Third;
         declare
            procedure Fifth is
            begin
               Second;
            end Fifth;
         begin
            Fifth;
         end;
      end Fourth;
   begin
      Fourth;
   end;
end Hello;
