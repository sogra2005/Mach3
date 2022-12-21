//
//  TileItem.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef TileItem_hpp
#define TileItem_hpp

#include "cocos2d.h"

namespace Match3Game::Tile
{
    enum class SpriteType;
}

namespace Match3Game::Model
{
    class ITileItem
    {
    public:
        using SpriteType = Tile::SpriteType;
    public:
        virtual SpriteType GetSpriteType() const = 0;
        virtual void SetSprite(SpriteType sprite) = 0;
    public:
        virtual cocos2d::Vec2 GetPosition() const = 0;
        virtual void SetPosition(cocos2d::Vec2 pos) = 0;
    };
}

#endif /* TileItem_hpp */
