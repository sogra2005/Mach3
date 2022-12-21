//
//  TileComponent.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef TileComponent_hpp
#define TileComponent_hpp

#include "cocos2d.h"

namespace Match3Game::Tile
{
    class TileComponent : public cocos2d::Component
    {
    public:
        TileComponent();
    public:
        void onAdd() override;
        void onRemove() override;
    public:
        cocos2d::Sprite *GetSprite() const;
        void SetSprite(cocos2d::Sprite *sprite);
    public:
        cocos2d::Vec2 GetPosition() const;
        void SetPosition(cocos2d::Vec2 pos);
    private:
        cocos2d::Vec2 _pos;
        cocos2d::Sprite *_sprite;
    };
}

#endif /* TileComponent_hpp */
