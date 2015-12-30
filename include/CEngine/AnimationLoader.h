#ifndef __ANIMATIONLOADER_H__
#define __ANIMATIONLOADER_H__

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

#include <string>

#include <NEngine/Bank.h>

#include "CEngine/Animation.h"

namespace NE { class ImageLoader; }

namespace CE
{
    class SpriteSheetLoader;

    class AnimationLoader
    {
    private:
        NE::Bank<const Animation> m_bank;

    public:
        AnimationLoader() {}

        void loadFromFile(const std::string& filename, CE::SpriteSheetLoader* pSSL, NE::ImageLoader* pIL);
        const Animation* getAnimation(const std::string& name)const;
    };
}

#endif
