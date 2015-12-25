#ifndef DOXYGEN_IGNORE_TAG
/**
CEngine gives tools to easily build 2D games
Copyright (C) 2015-2015  Alexandre LAURENT

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

website: https://github.com/LittleWhite-tb/CEngine
e-mail: lw.demoscene@gmail.com
**/
#endif

#include "AnimatedSprite.h"

#include <cassert>

#include "NEngine/NEngine.h"
#include "NEngine/Sprite.h"

#include "NEngine/Types/Colour.h"
#include "NEngine/Types/Rect.h"

CE::AnimatedSprite::~AnimatedSprite(void)
{
    NEDebug << "AnimatedSprite deleted\n";
}

void CE::AnimatedSprite::update(const unsigned int time)
{
    // LDebug << "AnimatedSprite :: update (" << time << ")";

    if ( time - lastUpdate > sprites[animationCounter].second )
    {
        animationCounter++;

        if ( animationCounter >= nbSprites() )
        {
            animationCounter=0;
        }

        lastUpdate = time;
    }
}

void CE::AnimatedSprite::addSprite(const NE::Sprite& pSprite, unsigned int timeToDisplay)
{
    sprites.push_back(TimedSprite(pSprite,timeToDisplay));
}

bool CE::AnimatedSprite::draw(const NE::Renderer& r, const IVec2& position, const unsigned int time)
{
    if (sprites.empty() )
        return true;

    this->update(time);
    return sprites[animationCounter].first.draw(r,position);
}

bool CE::AnimatedSprite::draw(const NE::Renderer& r, const IVec2& position, const Colour& mask, const unsigned int time)
{
    if (sprites.empty() )
        return true;

    this->update(time);
    return sprites[animationCounter].first.draw(r,position,mask);
}
