//
//  TileComponent.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#include "TileComponent.hpp"

#include "../Model/TileItem.hpp"
#include "Resources.hpp"

#include <string>

namespace Match3Game::Tile
{
    using namespace cocos2d;

    TileComponent::TileComponent(cocos2d::Sprite *sprite)
    :  _sprite(sprite), _item(nullptr)
    {
        
    }

    void TileComponent::onAdd()
    {
        Component::onAdd();
        
        if (!_item) return;
        
        _sprite->setTexture(std::string(std::string(Resources::GetName(_item->GetSpriteType())) + std::string(".png")));
        _sprite->setPosition(_item->GetPosition());
    }

    void TileComponent::onRemove()
    {
        Component::onRemove();
    }

    void TileComponent::Set(const ItemPtr& item)
    {
        _item = item;
    }
}
