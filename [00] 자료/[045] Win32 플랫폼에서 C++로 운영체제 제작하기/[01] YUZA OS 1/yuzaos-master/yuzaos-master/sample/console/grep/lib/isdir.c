/* isdir.c -- determine whether a directory exists
   Copyright (C) 1990, 1998 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <sys/types.h>
#include <stat_def.h>
#include <stdio.h>
#include <unistd.h>
//#define stat _stati64

#if STAT_MACROS_BROKEN
# undef S_ISDIR
#endif

/*#if !defined S_ISDIR && defined S_IFDIR
# define S_ISDIR(Mode) (((Mode) & S_IFMT) == S_IFDIR)
#endif*/

/* If PATH is an existing directory or symbolic link to a directory,
   return nonzero, else 0.  */

int isdir(const char* path)
{
	struct stat stats = { 0, };

	//return fstat(path, &stats) == 0 && S_ISDIR(stats.st_mode);
	return stat (path, &stats) == 0 && S_ISDIR (stats.st_mode);
}
