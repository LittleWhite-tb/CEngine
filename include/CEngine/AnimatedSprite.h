#ifndef __ANIMATEDSPRITE_H__
#define __ANIMATEDSPRITE_H__

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
#include <utility>

#include "NEngine/Types/Vec2.h"
#include "NEngine/Types/Size2.h"
#include "NEngine/Types/Rect.h"

namespace NE { class Renderer; }
namespace NE { class Sprite; }

struct Colour;

namespace CE
{
    class AnimatedSprite
    {
        typedef std::pair<const NE::Sprite*, unsigned int> TimedSprite;

    private:        
        std::vector<TimedSprite> sprites;

        unsigned int animationCounter;          /*!< number of the current animation */
        unsigned int lastUpdate;                /*!< last time that the animated sprite has been updated */

        // Disallow the copy
        AnimatedSprite(const AnimatedSprite& as);
        void operator= (const AnimatedSprite& as);

        void update(const unsigned int time);

    public:
        AnimatedSprite()
            :animationCounter(0),lastUpdate(0) {}
        ~AnimatedSprite(void);

        void addSprite(const NE::Sprite* pSprite, unsigned int timeToDisplay);

        unsigned int nbSprites()const { return sprites.size(); }

        bool draw(const NE::Renderer& r, const IVec2& position, const unsigned int time=0);
        bool draw(const NE::Renderer& r, const IVec2& position, const Colour& mask, const unsigned int time=0);
    };
}

/*! \class CE::AnimatedSprite AnimatedSprite.h "Engine/AnimatedSprite.h"
 *  \brief Animated sprite management class
 *
 * Handle the case of set of sprites for animation
 */

/*! \fn void CE::AnimatedSprite::update(const unsigned int time)
 * \brief Updates the instance to change the sprite to show if needed
 * \param time the actual time
 */

/*! \fn CE::AnimatedSprite::AnimatedSprite(NE::Sprite* pSprite, const USize2& spriteSize, const unsigned int msInterval);
 * Do an animation using a Sprite. The animated sprite size is given by spriteSize.
 * \param pSprite the Sprite to use for the animation
 * \param spriteSize the size of the sprite
 * \param msInterval interval between two sprite in milliseconds
 */

/*! \fn CE::AnimatedSprite::~AnimatedSprite(void)
 */

/*! \fn void CE::AnimatedSprite::addSprite(const NE::Sprite* pSprite, unsigned int timeToDisplay)
 * Add a sprite to the animation
 * \param pSprite the sprite to add
 * \param timeToDisplay the time this sprite should stay on screen
 */

/*! \fn bool CE::AnimatedSprite::draw(const NE::Renderer& r, const IVec2& position, const unsigned int time=0)
 * \brief Draw the Sprite at position
 * \param r the NE::Renderer to use to draw the AnimatedSprite
 * \param position where to draw the sprite
 * \param time time of the animation
 * \return true if all goes right
 */

/*! \fn bool CE::AnimatedSprite::draw(const NE::Renderer& r, const IVec2& position, const Colour& mask, const unsigned int time=0)
 * \brief Draw the Sprite at position
 * \param r the NE::Renderer to use to draw the AnimatedSprite
 * \param position where to draw the sprite
 * \param mask mask to use when drawing the sprite
 * \param time time of the animation
 * \return true if all goes right
 */

#endif
