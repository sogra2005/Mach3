//
//  TileComponent.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef TileComponent_hpp
#define TileComponent_hpp

#include "cocos2d.h"

#include <memory>

namespace Match3Game::Model
{
    class ITileItem;
}

namespace Match3Game::Tile
{
    class TileComponent : public cocos2d::Component
    {
    public:
        TileComponent(cocos2d::Sprite *sprite);
    public:
        void onAdd() override;
        void onRemove() override;
    public:
        using ItemPtr = std::shared_ptr<Model::ITileItem>;
        void Set(const ItemPtr& item);
    private:
        cocos2d::Sprite *_sprite;
        ItemPtr _item;
    };
}

#endif /* TileComponent_hpp */
