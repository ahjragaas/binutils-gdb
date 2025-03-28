#!/bin/sh

# file_in_many_sections.sh -- test

# Copyright (C) 2016-2025 Free Software Foundation, Inc.
# Written by Tristan Gingold <gingold@adacore.com>

# This file is part of gold.

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
# MA 02110-1301, USA.

# The goal of this program is to verify if .text sections are grouped
# according to prefix.  .text.unlikely, .text.startup and .text.hot should
# be grouped and placed together.

set -e

grep file_in_many_sections.c file_in_many_sections.stdout
