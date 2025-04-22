/*
 *  Aethyra
 *  Copyright (C) 2004  The Mana World Development Team
 *
 *  This file is part of Aethyra based on original code
 *  from The Mana World.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ambientoverlay.h"

#include "../image/image.h"

#include "../../bindings/guichan/graphics.h"

AmbientOverlay::AmbientOverlay(Image *img, const float parallax,
                               const float speedX, const float speedY):
    mImage(img), mParallax(parallax),
    mPosX(0), mPosY(0),
    mSpeedX(speedX), mSpeedY(speedY)
{
    mImage->incRef();
}

AmbientOverlay::~AmbientOverlay()
{
    mImage->decRef();
}

void AmbientOverlay::update(const int timePassed, const float dx,
                            const float dy)
{
    // Self scrolling of the overlay
    mPosX -= mSpeedX * timePassed / 10;
    mPosY -= mSpeedY * timePassed / 10;

    // Parallax scrolling
    mPosX += dx * mParallax;
    mPosY += dy * mParallax;

    int imgW = mImage->getWidth();
    int imgH = mImage->getHeight();

    // Wrap values
    while (mPosX > imgW)
        mPosX -= imgW;
    while (mPosX < 0)
        mPosX += imgW;

    while (mPosY > imgH)
        mPosY -= imgH;
    while (mPosY < 0)
        mPosY += imgH;
}

void AmbientOverlay::draw(Graphics *graphics, const int x, const int y)
{
    graphics->drawImagePattern(mImage, (int) -mPosX, (int) -mPosY, x +
                              (int) mPosX, y + (int) mPosY);
}
