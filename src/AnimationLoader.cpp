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

#include "CEngine/AnimationLoader.h"

#include "NEngine/Exceptions/FileNotFoundException.h"
#include "NEngine/ImageLoader.h"

#include "CEngine/SpriteSheetLoader.h"
#include "CEngine/SpriteSheet.h"
#include "CEngine/Animation.h"

#include "CEngine/utils.h"

#include <cassert>

#include "pugixml.hpp"

void CE::AnimationLoader::loadFromFile(const std::string& filename, CE::SpriteSheetLoader* pSSL, CE::SpriteSheetBank* pBank, NE::ImageLoader* pIL, NE::ImageBank* pImageBank)
{
    assert(pSSL);
    assert(pIL);

    pugi::xml_document doc;
    if (doc.load_file(filename.c_str()))
    {
        pugi::xml_node animationsNode = doc.child("animations");
        if (animationsNode && animationsNode.attribute("spriteSheet"))
        {
            const CE::SpriteSheet* pSpriteSheet = pSSL->loadFromFile(CE::Utils::dirname(filename) + animationsNode.attribute("spriteSheet").value(),
                                                                     pBank,
                                                                     pIL,pImageBank);
            if (pSpriteSheet)
            {
                for (pugi::xml_node animNode = animationsNode.child("anim") ; animNode ; animNode = animNode.next_sibling("anim"))
                {
                    CE::Animation* pNewAnim = new CE::Animation();
                    for (pugi::xml_node cellNode = animNode.child("cell") ; cellNode ; cellNode = cellNode.next_sibling("cell"))
                    {
                        pugi::xml_node sprNode = cellNode.child("spr");
                        if ( sprNode )
                        {
                            pNewAnim->addSprite(pSpriteSheet->getSprite(sprNode.attribute("name").value()),cellNode.attribute("delay").as_int());
                        }
                    }

                    m_bank.add(animNode.attribute("name").value(),pNewAnim);
                }
            }
            else
            {
                NEError << "The animations '" << filename << "' links to a sprite sheet file not found\n";
            }
        }
        else
        {
            NEError << "Invalid animations file: animations node not found\n";
        }
    }
    else
    {
        NEError << "Fail to load animation file '" << filename << "'\n";
        throw FileNotFoundException(filename);
    }
}

const CE::Animation* CE::AnimationLoader::getAnimation(const std::string& name)const
{
    return m_bank.get(name);
}
