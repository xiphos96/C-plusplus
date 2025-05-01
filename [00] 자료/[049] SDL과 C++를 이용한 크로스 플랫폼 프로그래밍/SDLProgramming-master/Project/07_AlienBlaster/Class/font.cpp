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

#include "font.h"
#include "global.h"
#include "surfaceDB.h"
#include <iostream>

Font::Font(string fn) {
  sprites[0] = surfaceDB.loadSurface( fn + "-1.bmp" );
  sprites[1] = surfaceDB.loadSurface( fn + "-2.bmp" );
  sprites[2] = surfaceDB.loadSurface( fn + "-3.bmp" );
  //charset = " ABCDEFGHIJKLMNOPQRSTUVWXYZ��?bcdefghijklmnopqrstuvwxyz����0123456789!\"?%&/()=?*+'#,.-;:_@?\";
	charset = " ABCDEFGHIJKLMNOPQRSTUVWXYZ��?bcdefghijklmnopqrstuvwxyz����0123456789!\"?%&";
  // 94 Zeichen
  charWidth = sprites[0]->w / MAX_CHARS_PER_TEXTURE;
  charHeight = sprites[0]->h;
}

Font::~Font() {
  ;
}

void Font::setCharWidth(int width) {
  charWidth = width;
}

int Font::getCharWidth() {
  return charWidth;
}

int Font::getCharHeight() {
  return sprites[0]->h;
}

void Font::drawInt(SdlCompat_AcceleratedSurface *screen, int posx, int posy, int val, int alignDigitCnt, int flags) {
  int indent = 0;
  int digitCnt = 1;
  int i=1;
  while ( val >= i*10 ) {
    digitCnt++;
    i *= 10;
  }

//   cout << endl << "drawInt.val=" << val << endl;
//   cout << "drawInt.digitCnt=" << digitCnt << endl;
//   cout << "drawInt.alignDigitCnt-old=" << alignDigitCnt << endl;

  if (alignDigitCnt < digitCnt) {
    alignDigitCnt = digitCnt;
  }
//   cout << "drawInt.alignDigitCnt-new=" << alignDigitCnt << endl;
  
  if (flags & FONT_ALIGN_CENTERED) {
    indent = -(alignDigitCnt * charWidth) / 2;
  }
  if (flags & FONT_ALIGN_RIGHT) {
    indent = -(alignDigitCnt * charWidth);
  }

  SDL_Rect destR;
  SDL_Rect srcR;
  while (alignDigitCnt > 0) {
    if ((digitCnt > 0) ||
	((flags & FONT_ALIGN_FILL_ZERO) != 0)) {
      
      destR.x = indent + posx + (alignDigitCnt-1) * charWidth;
      destR.y = posy;
      destR.w = charWidth;
      destR.h = charHeight;
      
      unsigned int charsetpos = charset.find( (char)((val % 10) + '0') );
      if (charsetpos == string::npos )
        charsetpos = 0; // Space
      srcR.x = (charsetpos % MAX_CHARS_PER_TEXTURE) * charWidth;

      //      srcR.x = (1 + 2*26 + (val % 10)) * charWidth;
      srcR.y = 0;
      srcR.w = charWidth;
      srcR.h = charHeight;
      
      SDL_BlitSurface( sprites[charsetpos / MAX_CHARS_PER_TEXTURE], &srcR, screen, &destR );
    }
    val /= 10;
    digitCnt--;
    alignDigitCnt--;
  }
}


  
void Font::drawStr(SdlCompat_AcceleratedSurface *screen, int posx, int posy, const string &text, int flags) {

  int indent = 0;
  if ( flags & (FONT_ALIGN_CENTERED | FONT_ALIGN_RIGHT) ) {
    for(unsigned int i=0; i < text.size(); ++i) {
      if (!(flags & FONT_MONOSPACE) && text[i] == ' ') {
	indent += ((charWidth * 2) / 3);
      } else {
	indent += charWidth;
      }
    }
    if (flags & FONT_ALIGN_CENTERED) {
      indent = -indent / 2;
    } else {
      indent = -indent;
    }
  }

  SDL_Rect destR;
  SDL_Rect srcR;
  
  int x = 0;
  unsigned int charsetpos;
  for(unsigned int i=0; i < text.size(); ++i) {
    x = 0;
    charsetpos = charset.find(text[i]);
    if (charsetpos == string::npos )
      charsetpos = 0; // Space
    x = (charsetpos % MAX_CHARS_PER_TEXTURE) * charWidth;
    
    destR.x = posx + indent;
    destR.y = posy;
    destR.w = charWidth;
    destR.h = sprites[0]->h;
      
    srcR.x = x;
    srcR.y = 0;
    srcR.w = charWidth;
    srcR.h = sprites[0]->h;
      
    SDL_BlitSurface( sprites[charsetpos / MAX_CHARS_PER_TEXTURE], &srcR, screen, &destR );

    if (!(flags & FONT_MONOSPACE) && text[i] == ' ') {
      posx += ((charWidth * 2) / 3);
    } else {
      posx += charWidth;
    }
  }
}

