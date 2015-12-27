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

#include "CEngine/SpriteSheetLoader.h"

#include "NEngine/Exceptions/FileNotFoundException.h"

#include "NEngine/ImageLoader.h"
#include "NEngine/Image.h"

#include "CEngine/SpriteSheet.h"

#include "pugixml.hpp"

#include "CEngine/utils.h"

const CE::SpriteSheet* CE::SpriteSheetLoader::loadFromFile(const std::string& filename, NE::ImageLoader* pIL)
{
    const CE::SpriteSheet* pSpriteSheet = m_bank.get(filename);
    if ( pSpriteSheet == NULL ) // It was not in the bank
    {
        pugi::xml_document doc;
        if (doc.load_file(filename.c_str()))
        {
            pugi::xml_node imgNode = doc.child("img");
            if (imgNode && imgNode.attribute("name") &&
                imgNode.child("definitions"))
            {
                const NE::Image* pImage = pIL->loadImageFromFile(CE::Utils::dirname(filename) + imgNode.attribute("name").value());
                if (pImage)
                {
                    CE::SpriteSheet* pNewSpriteSheet = new CE::SpriteSheet(pImage);

                    // Parse all directories
                    pugi::xml_node definitionsNode = imgNode.child("definitions");
                    if ( definitionsNode )
                    {
                        for (pugi::xml_node dirNode = definitionsNode.child("dir") ; dirNode ; dirNode = dirNode.next_sibling("dir"))
                        {
                            // Parse all sprite in directory
                            for (pugi::xml_node spriteNode = dirNode.child("spr") ; spriteNode ; spriteNode = spriteNode.next_sibling("spr"))
                            {
                                pugi::xml_attribute name = spriteNode.attribute("name");
                                pugi::xml_attribute x = spriteNode.attribute("x");
                                pugi::xml_attribute y = spriteNode.attribute("y");
                                pugi::xml_attribute w = spriteNode.attribute("w");
                                pugi::xml_attribute h = spriteNode.attribute("h");
                                if (name && x && y && w && h)
                                {
                                    pNewSpriteSheet->addSprite(name.value(),IVec2(x.as_int(),y.as_int()),USize2(w.as_int(),h.as_int()));
                                }
                            }
                        }
                    }
                    m_bank.add(filename,pNewSpriteSheet);
                    return pNewSpriteSheet;
                }
            }
            else
            {
                NEError << "Invalid SpriteSheet file: img/spr node not found\n";
            }
        }
        else
        {
            NEError << "Fail to load spritesheet '" << filename << "'\n";
            throw FileNotFoundException(filename);
        }
    }

    return pSpriteSheet;
}
