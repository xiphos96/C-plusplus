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

#include <cassert>

#include "log.h"
#include "resource.h"
#include "resourcemanager.h"

#include "utils/stringutils.h"

Resource::~Resource()
{
}

void Resource::incRef()
{
    mRefCount++;
}

void Resource::decRef()
{
    // Reference may not already have reached zero
    if (mRefCount == 0)
        logger->error(strprintf("mRefCount may not be zero for %s", mIdPath.c_str()));

    mRefCount--;

    if (mRefCount == 0)
    {
        // Warn the manager that this resource is no longer used.
        ResourceManager *resman = ResourceManager::getInstance();
        resman->release(this);
    }
}
