#ifndef __ANIMATION_H__
#define __ANIMATION_H__

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

#include <vector>

namespace NE { class Sprite; }

namespace CE
{
    class Animation
    {
        typedef std::pair<NE::Sprite, unsigned int> TimedSprite;

    private:
        std::vector<TimedSprite> sprites;

        // Disallow the copy
        Animation(const Animation& as);
        void operator= (const Animation& as);
    public:
        Animation() {}
        ~Animation();

        void addSprite(const NE::Sprite& pSprite, unsigned int timeToDisplay);

        unsigned int nbSprites()const;
        const TimedSprite& getSprite(std::size_t index)const;
    };
}

#endif
