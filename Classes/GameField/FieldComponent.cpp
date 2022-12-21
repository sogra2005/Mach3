//
//  FieldComponent.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 22.12.2022.
//

#include "FieldComponent.hpp"

#include "../Model/TilesSystem.hpp"
#include "../Utils/ComponentHelper.hpp"
#include "../Tile/TileComponent.hpp"

namespace Match3Game::GameField
{
    GameFieldComponent::GameFieldComponent()
    : _sprite(nullptr)
    {
        
    }

    void GameFieldComponent::onAdd()
    {
        Component::onAdd();
        
        if (_items)
        {
            for (auto i = 0; i < _items->Count(); i++)
            {
                auto item = _items->GetItem(i);
                if (_owner)
                {
                    auto sprite = cocos2d::Sprite::create();
                    auto component = Utils::Create<Tile::TileComponent>(sprite);
                    component->Set(_items->GetItem(i));
                    _owner->addChild(sprite);
                    sprite->addComponent(component);
                    
                }
            }
        }
        
    }
    
    void GameFieldComponent::onRemove()
    {
        Component::onRemove();
    }

    void GameFieldComponent::Set(const ItemsPtr& items)
    {
        _items = items;
    }
}
