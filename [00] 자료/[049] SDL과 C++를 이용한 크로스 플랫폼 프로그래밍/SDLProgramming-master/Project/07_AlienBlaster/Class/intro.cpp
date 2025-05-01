/*************************************************************************** 
  alienBlaster 
  Copyright (C) 2004 
  Paul Grathwohl, Arne Hormann, Daniel Kuehn, Soenke Schwardt

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
***************************************************************************/
using namespace std;

#ifdef ANDROID
#include <android/log.h>
#endif

#include "intro.h"
#include "global.h"
#include "surfaceDB.h"
#include "mixer.h"
#include "video.h"
#include "font.h"
#include "settings.h"
#include "infoscreen.h"

Intro::Intro( SdlCompat_AcceleratedSurface *scr ) {
 // __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 1");
  screen = scr;
 // __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 2");
  introSprite = surfaceDB.loadSurface( FN_ALIENBLASTER_INTRO );
 // __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 3");
  activeChoiceSprite = surfaceDB.loadSurface( FN_INTRO_SHOW_CHOICE );
 // __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 4");
  font = new Font( FN_FONT_INTRO );
//  __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 5");
  fontHighlighted = new Font( FN_FONT_INTRO_HIGHLIGHTED );
 // __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 6");
  activeChoice = 0;
  //__android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 7");
  choose = Mixer::mixer().loadSample( FN_SOUND_INTRO_CHOOSE, 100 );
//  __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 8");
  confirm = Mixer::mixer().loadSample( FN_SOUND_INTRO_CONFIRM, 100 );
 // __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 9");
  infoscreen = new Infoscreen( screen );
 // __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "Intro() 10");
}

Intro::~Intro() {}

void Intro::run( GameStates &gameState ) {

  if ( playMusicOn && Mixer::mixer().whichMusicPlaying() != MUSIC_INTRO ) {
    Mixer::mixer().playMusic( MUSIC_INTRO, -1, 1000 );
  }

  draw();
  while ( gameState == GS_INTRO ) {
    handleEvents( gameState );
    draw();
    SDL_Delay( 50 );
  }
}

void Intro::draw() {
  videoserver->clearScreen();
  SDL_Rect r;
  r.x = screen->w / 2 - introSprite->w / 2;
  r.y = 0;
  r.w = introSprite->w;
  r.h = introSprite->h;  
  SDL_BlitSurface( introSprite, 0, screen, &r );

  for ( int i = 0; i < NR_INTRO_CHOICES; i++ ) {
    if ( activeChoice == i ) {
      r.x = 230 - activeChoiceSprite->w - 8;
      r.y = 258 + i * 35;
      r.w = activeChoiceSprite->w;
      r.h = activeChoiceSprite->h;
      SDL_BlitSurface(activeChoiceSprite, 0, screen, &r );
      fontHighlighted->drawStr( screen, 230, 260 + i * 35, INTRO_CHOICES[ i ] );
    } else {
      font->drawStr( screen, 230, 260 + i * 35, INTRO_CHOICES[ i ] );
    }
  }
  SDL_Flip( screen );
}

void Intro::handleEvents( GameStates &gameState ) {
  SDL_Event event;
  
  while (SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN: {
        switch(event.key.keysym.sym) {
	case SDLK_F5: {
	  videoserver->toggleFullscreen();
	  break;
	}
	case SDLK_F7: {
	  if ( playMusicOn ) {
	    playMusicOn = false;
	    Mixer::mixer().stopMusic();
	  } else {
	    playMusicOn = true;
	    Mixer::mixer().playMusic( MUSIC_INTRO, -1, 1000 );
	  }
	  break;
	}	    
	case SDLK_UP: {
	  Mixer::mixer().playSample( choose, 0 );
	  activeChoice--;
	  if ( activeChoice < 0 ) activeChoice = NR_INTRO_CHOICES - 1;
	  break;
	}
	case SDLK_DOWN: {
	  Mixer::mixer().playSample( choose, 0 );
	  activeChoice = (activeChoice + 1) % NR_INTRO_CHOICES;
	  break;
	}
	case SDLK_ESCAPE: {
	  gameState = GS_QUIT;
	  break;
	}
	case SDLK_RETURN: {
	  Mixer::mixer().playSample( confirm, 0 );
	  switch (activeChoice) {
	  case ONE_PLAYER_GAME: {
	    onePlayerGame = true;
	    arcadeGame = false;
	    gameState = GS_SET_DIFFICULTY;
	    break;
	  }
	  case TWO_PLAYER_GAME: {
	    onePlayerGame = false;
	    arcadeGame = false;
	    gameState = GS_SET_DIFFICULTY;
	    break;
	  }
	  case ARCADE_GAME: {
	    onePlayerGame = true;
	    arcadeGame = true;
	    gameState = GS_ARCADE_MODE_SETUP;
	    break;
	  }
	  case CONFIGURE_KEYS: {
	    settings->settingsDialog(screen);
	    draw();
	    break;
	  }
	  case INFOSCREEN: {
	    infoscreen->run();
	    break;
	  }
	  case QUIT_AND_DIE: {
	    gameState = GS_QUIT;
	    break;
	  }
	  }
	  break;
	}
	default: break;
        }
        break;
      }
    case SDL_QUIT: {
      gameState = GS_QUIT;
      break;
    }
    default: break;
    }
  }
}


void Intro::showScreenshots() {
  if ( playMusicOn && Mixer::mixer().whichMusicPlaying() != MUSIC_INTRO ) {
    Mixer::mixer().playMusic( MUSIC_INTRO, -1, 1000 );
  }

  // TODO: Too lazy to fix that
  /*
  SdlCompat_AcceleratedSurface *surfS = SDL_LoadBMP( FN_ALIENBLASTER_INTRO.c_str() );
  SdlCompat_AcceleratedSurface *surf0 = SDL_LoadBMP( FN_SCREENSHOT0.c_str() );
  SdlCompat_AcceleratedSurface *surf1 = SDL_LoadBMP( FN_SCREENSHOT1.c_str() );
  SdlCompat_AcceleratedSurface *surf2 = SDL_LoadBMP( FN_SCREENSHOT2.c_str() );
  SdlCompat_AcceleratedSurface *surf3 = SDL_LoadBMP( FN_SCREENSHOT3.c_str() );
  SdlCompat_AcceleratedSurface *surf4 = SDL_LoadBMP( FN_SCREENSHOT4.c_str() );
  SdlCompat_AcceleratedSurface *surf5 = SDL_LoadBMP( FN_SCREENSHOT5.c_str() );
  SdlCompat_AcceleratedSurface *surf6 = SDL_LoadBMP( FN_SCREENSHOT6.c_str() );
  SdlCompat_AcceleratedSurface *surf7 = SDL_LoadBMP( FN_SCREENSHOT7.c_str() );
  SdlCompat_AcceleratedSurface *surf8 = SDL_LoadBMP( FN_SCREENSHOT8.c_str() );
  SdlCompat_AcceleratedSurface *surf9 = SDL_LoadBMP( FN_SCREENSHOT9.c_str() );

  SDL_BlitSurface( surfS, 0, screen, 0 );
  SDL_Flip(screen);
  SDL_Delay(3000);
  int sps = 50; // steps per second
  if (blendImages( screen, surfS, 0, surf0, 0, sps )) 
   if (blendImages( screen, surf0, 0, surf1, 0, sps )) 
    if (blendImages( screen, surf1, 0, surf2, 0, sps ))
      if (blendImages( screen, surf2, 0, surf3, 0, sps ))
	if (blendImages( screen, surf3, 0, surf4, 0, sps ))
	  if (blendImages( screen, surf4, 0, surf5, 0, sps ))
	    if (blendImages( screen, surf5, 0, surf6, 0,sps ))
	      if (blendImages( screen, surf6, 0, surf7, 0, sps ))
		if (blendImages( screen, surf7, 0, surf8, 0, sps ))
		  blendImages( screen, surf8, 0, surf9, 0, sps );
  */
}

// TODO: Too lazy to fix that
/*
bool Intro::blendImages( SdlCompat_AcceleratedSurface *screen, SdlCompat_AcceleratedSurface *surf0, SDL_Rect *r1, SdlCompat_AcceleratedSurface *surf1, SDL_Rect *r2, int sps ) {
  SDL_Event event;
  
  int i = 0;
  int t = SDL_GetTicks();
  while (i < 255) {
    if (i>255) i=255;
    
    SDL_SetAlpha( surf0, SDL_SRCALPHA, 255-i );
    SDL_SetAlpha( surf1, SDL_SRCALPHA, i );
    SDL_BlitSurface( surf0, 0, screen, r1 );
    SDL_BlitSurface( surf1, 0, screen, r2 );
    SDL_Flip( screen );
    int t2 = SDL_GetTicks();
    int dt= SDL_GetTicks() - t;
    t = t2;
    i += (dt * sps / 1000);

    while (SDL_PollEvent(&event)) {
      switch(event.type) {
      case SDL_KEYDOWN: {
	return false;
      }
      default:
	break;
      }
    }
  }
  return true;
}
*/
