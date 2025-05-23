/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2016 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#ifndef _SDL_nullvideo_h
#define _SDL_nullvideo_h

#include "../SDL_sysvideo.h"

typedef struct tag_Sky_Data
{
	SDL_Surface *surface;
	QWORD windowId;
	SDL_Window* pWindow;
	int threadId;
}Sky_Data;

struct _SDL_DATA
{
	Sky_Data * data;	
};

struct _SDL_DATA;
typedef struct _SDL_DATA SDL_DATA;

void sky_add_data(Sky_Data * data); 
Sky_Data*  sky_find_data(int threadId);

#endif /* _SDL_nullvideo_h */

/* vi: set ts=4 sw=4 expandtab: */
