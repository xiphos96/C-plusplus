// ConanGame.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "SDL.h"

#include "Game.h"
#include <iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

#ifdef WIN32
#include <tchar.h>
#endif


#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{
	Uint32 frameStart, frameTime;

	std::cout << "game init attempt...\n";

#ifndef WIN32 
	if (TheGame::Instance()->init("BomberMan", 0, 0, 0, 0, false))
#else
	if (TheGame::Instance()->init("BomberMan", 100, 100, DESIGNED_SCREEN_SIZE_X, DESIGNED_SCREEN_SIZE_Y, false))
#endif
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->Update();
			TheGame::Instance()->Render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "game closing...\n";
	TheGame::Instance()->Clean();

	return 0;
}