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

#include "SpriteSheet.h"

#include "NEngine/Exceptions/ItemNotFoundException.h"

bool CE::SpriteSheet::exists(const std::string& spriteName)
{
    if ( sprites.find(spriteName) != sprites.end() )
    {
        return true;
    }

    return false;
}

void CE::SpriteSheet::addSprite(const std::string& spriteName, const IVec2& origine, const USize2& size)
{
    if ( this->exists(spriteName) )
    {
        NEWarning << "CE::SpriteSheet : '" << spriteName << "' is already in the Bank (not overwrittin)\n";
        return;
    }

    sprites[spriteName] = NE::Sprite(this->pImage,origine,size);
}

const NE::Sprite& CE::SpriteSheet::getSprite(const std::string& spriteName)
{
    if (this->exists(spriteName))
    {
        return sprites[spriteName];
    }
    throw ItemNotFoundException(spriteName);
}
