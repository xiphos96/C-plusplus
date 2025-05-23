/*
 * video_out_sdl.c
 *
 * Copyright (C) 2000-2003 Ryan C. Gordon <icculus@lokigames.com> and
 *                         Dominik Schnitzer <aeneas@linuxvideo.org>
 *
 * SDL info, source, and binaries can be found at http://www.libsdl.org/
 *
 * This file is part of mpeg2dec, a free MPEG-2 video stream decoder.
 * See http://libmpeg2.sourceforge.net/ for updates.
 *
 * mpeg2dec is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * mpeg2dec is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "config.h"

#ifdef LIBVO_SDL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <fileio.h>
#include <SDL.h>
#include <inttypes.h>

#include "video_out.h"
#include <getenv.h>

extern FILE* stderr;

typedef struct {
	vo_instance_t vo;
	int width;
	int height;
	SDL_Surface * surface;
	Uint32 sdlflags;
	Uint8 bpp;
} sdl_instance_t;

static void sdl_setup_fbuf(vo_instance_t * _instance,
	uint8_t ** buf, void ** id)
{
	sdl_instance_t * instance = (sdl_instance_t *)_instance;

	SDL_Texture* bmp = SDL_CreateTexture(SDL_GetRenderer(ASK), SDL_PIXELFORMAT_YV12, SDL_TEXTUREACCESS_STREAMING, instance->width, instance->height);
	SDL_Overlay * overlay;

	*id = overlay = SDL_CreateYUVOverlay(instance->width, instance->height,
		SDL_YV12_OVERLAY, instance->surface);
	buf[0] = overlay->pixels[0];
	buf[1] = overlay->pixels[2];
	buf[2] = overlay->pixels[1];
	if (((long)buf[0] & 15) || ((long)buf[1] & 15) || ((long)buf[2] & 15)) {
		fprintf(stderr, "Unaligned buffers. Anyone know how to fix this ?\n");
		exit(1);
	}
}

static void sdl_start_fbuf(vo_instance_t * instance,
	uint8_t * const * buf, void * id)
{
	SDL_LockYUVOverlay((SDL_Overlay *)id);
}

static void sdl_draw_frame(vo_instance_t * _instance,
	uint8_t * const * buf, void * id)
{
	sdl_instance_t * instance = (sdl_instance_t *)_instance;
	SDL_Overlay * overlay = (SDL_Overlay *)id;
	SDL_Event event;

	while (SDL_PollEvent(&event))
		if (event.type == SDL_VIDEORESIZE)
			instance->surface =
			SDL_SetVideoMode(event.resize.w, event.resize.h,
				instance->bpp, instance->sdlflags);
	SDL_DisplayYUVOverlay(overlay, &(instance->surface->clip_rect));
}

static void sdl_discard(vo_instance_t * _instance,
	uint8_t * const * buf, void * id)
{
	SDL_UnlockYUVOverlay((SDL_Overlay *)id);
}

#if 0
static void sdl_close(vo_instance_t * _instance)
{
	sdl_instance_t * instance;
	int i;

	instance = (sdl_instance_t *)_instance;
	for (i = 0; i < 3; i++)
		SDL_FreeYUVOverlay(instance->frame[i].overlay);
	SDL_FreeSurface(instance->surface);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}
#endif

static int sdl_setup(vo_instance_t * _instance, unsigned int width,
	unsigned int height, unsigned int chroma_width,
	unsigned int chroma_height, vo_setup_result_t * result)
{
	sdl_instance_t * instance;

	instance = (sdl_instance_t *)_instance;

	instance->width = width;
	instance->height = height;
	instance->surface = SDL_SetVideoMode(width, height, instance->bpp,
		instance->sdlflags);
	if (!(instance->surface)) {
		fprintf(stderr, "sdl could not set the desired video mode\n");
		return 1;
	}

	result->convert = NULL;
	return 0;
}

vo_instance_t * vo_sdl_open(void)
{
	sdl_instance_t * instance;
	const SDL_VideoInfo * vidInfo;

	instance = (sdl_instance_t *)malloc(sizeof(sdl_instance_t));
	if (instance == NULL)
		return NULL;

	instance->vo.setup = sdl_setup;
	instance->vo.setup_fbuf = sdl_setup_fbuf;
	instance->vo.set_fbuf = NULL;
	instance->vo.start_fbuf = sdl_start_fbuf;
	instance->vo.discard = sdl_discard;
	instance->vo.draw = sdl_draw_frame;
	instance->vo.close = NULL; /* sdl_close; */
	instance->sdlflags = SDL_HWSURFACE | SDL_RESIZABLE;

	putenv("SDL_VIDEO_YUV_HWACCEL=1");
	putenv("SDL_VIDEO_X11_NODIRECTCOLOR=1");

	if (SDL_Init(SDL_INIT_VIDEO)) {
		fprintf(stderr, "sdl video initialization failed.\n");
		return NULL;
	}

	SDL_DisplayMode current;
	for (int i = 0; i < SDL_GetNumVideoDisplays(); ++i) {

		int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);

		if (should_be_zero != 0)
			// In case of error...
			SDL_Log("Could not get display mode for video display #%d: %s", i, SDL_GetError());

		else
		{
			// On success, print the current display mode.
			SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz.", i, current.w, current.h, current.refresh_rate);
			//instance->bpp = vidInfo->vfmt->BitsPerPixel;
			instance->sdlflags = SDL_RESIZABLE;
			instance->bpp = 16;
			break;
		}
		

	}

	return (vo_instance_t *)instance;
}
#endif
