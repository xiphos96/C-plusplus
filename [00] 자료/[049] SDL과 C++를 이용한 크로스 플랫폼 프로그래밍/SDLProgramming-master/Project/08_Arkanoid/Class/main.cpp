﻿#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#endif

#include "Game.h"

#ifdef WIN32
//int main(int argc, char **argv)
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{	
	srand(SDL_GetTicks()); // Initializing random seed
	Game game; // Creating game
	return game.Loop();    // Starting game
}

