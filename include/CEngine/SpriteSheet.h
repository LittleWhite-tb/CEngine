#ifndef __SPRITESHEET_H__
#define __SPRITESHEET_H__

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

#include "NEngine/Sprite.h"

namespace NE { class Image; }

namespace CE
{
    class SpriteSheet
    {
    private:
        const NE::Image* pImage;
        std::map<std::string, NE::Sprite> sprites;

        bool exists(const std::string& spriteName);
    public:
        SpriteSheet(const NE::Image* pImage)
            :pImage(pImage) {}

        void addSprite(const std::string& spriteName, const IVec2& origine, const USize2& size);

        const NE::Sprite& getSprite(const std::string& spriteName);
    };
}

#endif
