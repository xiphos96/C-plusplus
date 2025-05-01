/* 
 * OpenTyrian Classic: A modern cross-platform port of Tyrian
 * Copyright (C) 2007-2009  The OpenTyrian Development Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include "config.h"
#include "joystick.h"
#include "keyboard.h"
#include "network.h"
#include "opentyr.h"
#include "video.h"
#include "video_scale.h"

#include <SDL2/SDL.h>
#include "SDLSingleton.h"


JE_boolean ESCPressed;

JE_boolean newkey, newmouse, keydown, mousedown;
SDL_Keycode lastkey_sym;
SDL_Keymod lastkey_mod;
unsigned char lastkey_char;
Uint8 lastmouse_but;
Uint16 lastmouse_x, lastmouse_y;
JE_boolean mouse_pressed[3] = {false, false, false};
Uint16 mouse_x, mouse_y;

int numkeys;
Uint8 *keysactive;

#ifdef NDEBUG
bool input_grab_enabled = true,
#else
bool input_grab_enabled = false,
#endif
       input_grabbed = false;


void flush_events_buffer( void )
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev));
}

void wait_input( JE_boolean keyboard, JE_boolean mouse, JE_boolean joystick )
{
	service_SDL_events(false);
	while (!((keyboard && keydown) || (mouse && mousedown) || (joystick && joydown)))
	{
		SDL_Delay(SDL_POLL_INTERVAL);
		push_joysticks_as_keyboard();
		service_SDL_events(false);
		
		if (isNetworkGame)
			network_check();
	}
}

void wait_noinput( JE_boolean keyboard, JE_boolean mouse, JE_boolean joystick )
{
	service_SDL_events(false);
	while ((keyboard && keydown) || (mouse && mousedown) || (joystick && joydown))
	{
		SDL_Delay(SDL_POLL_INTERVAL);
		poll_joysticks();
		service_SDL_events(false);
		
		if (isNetworkGame)
			network_check();
	}
}

void init_keyboard( void )
{
//20140530
	keysactive = (Uint8*)SDL_GetKeyboardState(&numkeys);
#ifndef ANDROID
	//SDL_EnableKeyRepeat(500, 60);
#endif

	newkey = newmouse = false;
	keydown = mousedown = false;

	//SDL_EnableUNICODE(1);
}

void input_grab( void )
{
#if defined(TARGET_GP2X) || defined(TARGET_DINGUX) || defined(ANDROID)
	input_grabbed = true;
#else
	input_grabbed = input_grab_enabled || fullscreen_enabled;
#endif
	
	SDL_ShowCursor(input_grabbed ? SDL_DISABLE : SDL_ENABLE);
#ifdef NDEBUG
	//SDL_WM_GrabInput(input_grabbed ? SDL_GRAB_ON : SDL_GRAB_OFF);
	SDL_SetRelativeMouseMode(SDL_TRUE);
#endif
}

JE_word JE_mousePosition( JE_word *mouseX, JE_word *mouseY )
{
	service_SDL_events(false);
	*mouseX = mouse_x;
	*mouseY = mouse_y;
	return mousedown ? lastmouse_but : 0;
}

void set_mouse_position( int x, int y )
{
	if (input_grabbed)
	{
		SDL_WarpMouseInWindow(SDLSingleton::GetInstance()->GetWindow(), x * scalers[scaler].width / vga_width, y * scalers[scaler].height / vga_height);
		mouse_x = x;
		mouse_y = y;
	}
}

JE_boolean handle_pause_key = true;

void JE_pauseGame( void );

void service_SDL_events( JE_boolean clear_new )
{
	SDL_Event ev;
	
	if (clear_new)
		newkey = newmouse = false;
	
	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
			case SDL_MOUSEMOTION:
#ifdef _WIN32
				mouse_x = ev.motion.x;
				mouse_y = ev.motion.y;
#else
				mouse_x = SDL_REVERSE_RATIO_X(ev.motion.x);
				mouse_y = SDL_REVERSE_RATIO_Y(ev.motion.y);
#endif
				break;
			case SDL_KEYDOWN:
				if (handle_pause_key && ev.key.keysym.sym == SDLK_PAUSE)
				{
					JE_boolean superPause_save = superPause;
					superPause = true;
					JE_pauseGame();
					superPause = superPause_save;
					break;
				}
				if (ev.key.keysym.mod & KMOD_CTRL)
				{
					/* <ctrl><bksp> emergency kill */
					if (ev.key.keysym.sym == SDLK_BACKSPACE)
					{
						puts("\n\n\nCtrl+Backspace pressed. Doing emergency quit.\n");
						SDL_Quit();
						exit(1);
					}
					
					/* <ctrl><f10> toggle input grab */
					if (ev.key.keysym.sym == SDLK_F10)
					{
						input_grab_enabled = !input_grab_enabled;
						input_grab();
						break;
					}
				}
				
				if (ev.key.keysym.mod & KMOD_ALT)
				{
					/* <alt><enter> toggle fullscreen */
					if (ev.key.keysym.sym == SDLK_RETURN)
					{
						if (!init_scaler(scaler, !fullscreen_enabled) && // try new fullscreen state
						    !init_any_scaler(!fullscreen_enabled) &&     // try any scaler in new fullscreen state
						    !init_scaler(scaler, fullscreen_enabled))    // revert on fail
						{
							exit(EXIT_FAILURE);
						}
						break;
					}
					
					/* <alt><tab> disable input grab and fullscreen */
					if (ev.key.keysym.sym == SDLK_TAB)
					{
						input_grab_enabled = false;
						input_grab();
						
						if (!init_scaler(scaler, false) &&             // try windowed
						    !init_any_scaler(false) &&                 // try any scaler windowed
						    !init_scaler(scaler, fullscreen_enabled))  // revert on fail
						{
							exit(EXIT_FAILURE);
						}
						break;
					}
				}
				
				newkey = true;
				lastkey_sym = ev.key.keysym.sym;
//20140530
				lastkey_mod = (SDL_Keymod)ev.key.keysym.mod;
				lastkey_char = ev.key.keysym.sym;
				keydown = true;
				return;
			case SDL_KEYUP:
				keydown = false;
				return;
			case SDL_MOUSEBUTTONDOWN:
				if (!input_grabbed)
				{
					input_grab_enabled = !input_grab_enabled;
					input_grab();
					break;
				}
			case SDL_MOUSEBUTTONUP:
				if (ev.type == SDL_MOUSEBUTTONDOWN)
				{
					newmouse = true;
					mousedown = true;
					
					

	
					ev.button.x = SDL_REVERSE_RATIO_X(ev.motion.x);
					ev.button.y = SDL_REVERSE_RATIO_X(ev.motion.y);

					lastmouse_x = ev.button.x;
					lastmouse_y = ev.button.y;
					lastmouse_but = ev.button.button;

				}
				else
				{
					mousedown = false;
				}
				switch (ev.button.button)
				{
					case SDL_BUTTON_LEFT:
						mouse_pressed[0] = mousedown; break;
					case SDL_BUTTON_RIGHT:
						mouse_pressed[1] = mousedown; break;
					case SDL_BUTTON_MIDDLE:
						mouse_pressed[2] = mousedown; break;
				}
				break;
			case SDL_QUIT:
				/* TODO: Call the cleanup code here. */
				exit(0);
				break;
		}
	}
}

void JE_clearKeyboard( void )
{
	// /!\ Doesn't seems important. I think. D:
}

// kate: tab-width 4; vim: set noet:
