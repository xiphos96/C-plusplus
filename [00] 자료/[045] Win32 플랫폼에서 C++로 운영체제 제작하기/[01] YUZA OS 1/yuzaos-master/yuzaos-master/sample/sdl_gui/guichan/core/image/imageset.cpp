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

#include "image.h"
#include "imageset.h"

#include "../../core/log.h"

#include "../../core/utils/dtor.h"

ImageSet::ImageSet(Image *img, const int width, const int height)
{
    for (int y = 0; y + height <= img->getHeight(); y += height)
    {
        for (int x = 0; x + width <= img->getWidth(); x += width)
        {
            mImages.push_back(img->getSubImage(x, y, width, height));
        }
    }
    mWidth = width;
    mHeight = height;
}

ImageSet::~ImageSet()
{
    delete_all(mImages);
}

SubImage* ImageSet::get(const size_type &i) const
{
    if (i >= mImages.size())
    {
        logger->log("Warning: No sprite %d in this image set", (int) i);
        return NULL;
    }
    else
        return mImages[i];
}
