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

#if SDL_VIDEO_DRIVER_DUMMY

/* Being a null driver, there's no event stream. We just define stubs for
   most of the API. */

#include "../../events/SDL_events_c.h"

#include "SDL_nullvideo.h"
#include "SDL_nullevents_c.h"
#include "SDL_skyosmouse.h"
#include "SDL_skyoskeyboard.h"
#include <winapi2.h>

void
DUMMY_PumpEvents(_THIS)
{		
	EVENT stReceivedEvent;
	MOUSEEVENT* pstMouseEvent;
	KEYEVENT* pstKeyEvent;
	WINDOWEVENT* pstWindowEvent;

	// �̺�Ʈ ť���� �̺�Ʈ�� ����
	if (ReceiveEventFromWindowQueue(0, &stReceivedEvent) == TRUE)
	{
		// ���ŵ� �̺�Ʈ�� Ÿ�Կ� ���� ������ ó��
		switch (stReceivedEvent.qwType)
		{
			// ���콺 �̺�Ʈ ó��
		case EVENT_MOUSE_MOVE:
		case EVENT_MOUSE_LBUTTONDOWN:
		case EVENT_MOUSE_LBUTTONUP:
		case EVENT_MOUSE_RBUTTONDOWN:
		case EVENT_MOUSE_RBUTTONUP:
		case EVENT_MOUSE_MBUTTONDOWN:
		case EVENT_MOUSE_MBUTTONUP:
		{
			// ���⿡ ���콺 �̺�Ʈ ó�� �ڵ� �ֱ�
			pstMouseEvent = &(stReceivedEvent.stMouseEvent);

			//20191024
			//SDL_Window* focusWindow = SDL_GetWindowFromID(0);
			//SDL_Window* focusWindow = SDL_GetMouseFocus();
			SKYOS_OnMouse(_this->windows, stReceivedEvent.qwType, pstMouseEvent->stPoint.iX, pstMouseEvent->stPoint.iY - WINDOW_TITLEBAR_HEIGHT);
		}
		break;

		// Ű �̺�Ʈ ó��
		case EVENT_KEY_DOWN:
		{
			SDL_SetKeyboardFocus(_this->windows);
			pstKeyEvent = &(stReceivedEvent.stKeyEvent);			
			SkyOS_OnKeyDown(pstKeyEvent->bASCIICode);
		}
		break;
		case EVENT_KEY_UP:
		{
			SDL_SetKeyboardFocus(_this->windows);
			// ���⿡ Ű���� �̺�Ʈ ó�� �ڵ� �ֱ�
			pstKeyEvent = &(stReceivedEvent.stKeyEvent);			
			SkyOS_OnKeyUp(pstKeyEvent->bASCIICode);
		}
		break;

			// ������ �̺�Ʈ ó��
		case EVENT_WINDOW_SELECT:
		case EVENT_WINDOW_DESELECT:
		case EVENT_WINDOW_MOVE:
		case EVENT_WINDOW_RESIZE:
		case EVENT_WINDOW_CLOSE:
			// ���⿡ ������ �̺�Ʈ ó�� �ڵ� �ֱ�
			pstWindowEvent = &(stReceivedEvent.stWindowEvent);

			//------------------------------------------------------------------
			// ������ �ݱ� �̺�Ʈ�̸� �����츦 �����ϰ� ������ �������� �½�ũ�� ����
			//------------------------------------------------------------------
			if (stReceivedEvent.qwType == EVENT_WINDOW_CLOSE)
			{
				// ������ ����
				DeleteWindow(0);
				SDL_Quit();
				ExitThread(0);
				
				return;
			}
			break;

			// �� �� ����
		default:
			// ���⿡ �� �� ���� �̺�Ʈ ó�� �ڵ� �ֱ�
			break;
		}
	}
}


#endif /* SDL_VIDEO_DRIVER_DUMMY */

/* vi: set ts=4 sw=4 expandtab: */
