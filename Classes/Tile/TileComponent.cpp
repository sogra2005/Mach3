//
//  TileComponent.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#include "TileComponent.hpp"

namespace Match3Game::Tile
{
    using namespace cocos2d;

    TileComponent::TileComponent()
    : _pos(Vec2(0,0)), _sprite(nullptr) {}

    void TileComponent::onAdd()
    {
        Component::onAdd();
        
        
    }

    void TileComponent::onRemove()
    {
        Component::onRemove();
    }

    cocos2d::Sprite *TileComponent::GetSprite() const
    {
        return _sprite;
    }

    void TileComponent::SetSprite(cocos2d::Sprite *sprite)
    {
        _sprite = sprite;
    }

    cocos2d::Vec2 TileComponent::GetPosition() const
    {
        return _pos;
    }

    void TileComponent::SetPosition(cocos2d::Vec2 pos)
    {
        _pos = pos;
    }
}
