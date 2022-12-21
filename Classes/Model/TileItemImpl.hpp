//
//  TileItemImpl.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef TileItemImpl_hpp
#define TileItemImpl_hpp

#include "TileItem.hpp"

namespace Match3Game::Tile
{
enum class SpriteType;
}

namespace Match3Game::Model
{
    using namespace cocos2d;

    class TileItem : public ITileItem
    {
    public:
        TileItem(Vec2 pos, Tile::SpriteType type);
    public:
        SpriteType GetSpriteType() const;
        void SetSprite(SpriteType sprite);
    public:
        cocos2d::Vec2 GetPosition() const;
        void SetPosition(cocos2d::Vec2 pos);
    private:
        Vec2 _pos;
        SpriteType _sprite;
    };
}

#endif /* TileItemImpl_hpp */
