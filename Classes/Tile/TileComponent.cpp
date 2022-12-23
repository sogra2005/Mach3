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
    :  _sprite(sprite), _item(nullptr), _isSelected(false)
    {
        
    }

    void TileComponent::onAdd()
    {
        Component::onAdd();
        
        if (!_item) return;
        
        _sprite->setTexture("end.png");
        _sprite->setPosition(_item->GetPosition());
        Update();
    }

    void TileComponent::onRemove()
    {
        Component::onRemove();
    }

    void TileComponent::Update()
    {
        _sprite->setTexture(std::string(std::string(Resources::GetName(_item->GetSpriteType())) + std::string(".png")));
    }

    void TileComponent::Set(const ItemPtr& item)
    {
        _item = item;
    }

    std::size_t TileComponent::GetNumber() const
    {
        return _item->GetNumber();
    }

    void TileComponent::Select()
    {
        _isSelected = true;
        _sprite->setColor(Color3B(150, 150, 150));
    }

    void TileComponent::UnSelect()
    {
        _isSelected = false;
        _sprite->setColor(Color3B(255, 255, 255));
    }

    bool TileComponent::IsSelected() const
    {
        return _isSelected;
    }

}
