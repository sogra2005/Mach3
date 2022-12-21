//
//  TileItemImpl.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#include "TileItemImpl.hpp"

#include "../Tile/Resources.hpp"

namespace Match3Game::Model
{
    TileItem::TileItem(Vec2 pos, Tile::SpriteType type)
    : _pos(pos), _sprite(type)
    {
        
    }

    auto TileItem::GetSpriteType() const -> SpriteType
    {
        return _sprite;
    }

    void TileItem::SetSprite(SpriteType sprite)
    {
        _sprite = sprite;
    }

    cocos2d::Vec2 TileItem::GetPosition() const
    {
        return _pos;
    }

    void TileItem::SetPosition(cocos2d::Vec2 pos)
    {
        _pos = pos;
    }
}
