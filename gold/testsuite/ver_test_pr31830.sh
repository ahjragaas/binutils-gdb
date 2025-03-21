#!/bin/sh

# ver_test_pr31830.sh -- a test case for version scripts

# Copyright (C) 2024-2025 Free Software Foundation, Inc.

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

# This test verifies that linker-generated symbols (e.g., _end)
# get correct version information even in the presence of
# a shared library that provides those symbols with different
# versions.

check()
{
    if ! grep -q "$2" "$1"
    then
	echo "Did not find expected symbol in $1:"
	echo "   $2"
	echo ""
	echo "Actual output below:"
	cat "$1"
	exit 1
    fi
}

check_missing()
{
    if grep -q "$2" "$1"
    then
	echo "Found unexpected symbol in $1:"
	echo "   $2"
	echo ""
	echo "Actual output below:"
	cat "$1"
	exit 1
    fi
}

check ver_test_pr31830_a.syms "foo@GLIBC_2.2.5$"
check ver_test_pr31830_b.syms "foo@GLIBC_2.2.5$"

check_missing ver_test_pr31830_a.syms "foo@@GLIBC_2.2.5$"
check_missing ver_test_pr31830_b.syms "foo@@GLIBC_2.2.5$"

exit 0
