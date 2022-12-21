//
//  FieldComponent.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 22.12.2022.
//

#ifndef FieldComponent_hpp
#define FieldComponent_hpp

#include "cocos2d.h"

#include <memory>

namespace Match3Game::Model
{
    class ITilesSystem;
}

namespace Match3Game::GameField
{
    class GameFieldComponent : public cocos2d::Component
    {
    public:
        GameFieldComponent();
    public:
        void onAdd() override;
        void onRemove() override;
    public:
        using ItemsPtr = std::shared_ptr<Model::ITilesSystem>;
        void Set(const ItemsPtr& items);
    private:
        ItemsPtr _items;
        cocos2d::Sprite *_sprite;
    };
}

#endif /* FieldComponent_hpp */
