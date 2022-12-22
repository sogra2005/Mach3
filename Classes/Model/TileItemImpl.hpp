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
        TileItem(Vec2 pos, Tile::SpriteType type, std::size_t number);
    public:
        SpriteType GetSpriteType() const override;
        void SetSprite(SpriteType sprite) override;
    public:
        cocos2d::Vec2 GetPosition() const override;
        void SetPosition(cocos2d::Vec2 pos) override;
    public:
        std::size_t GetNumber() const override;
    private:
        Vec2 _pos;
        SpriteType _sprite;
        std::size_t _number;
    };
}

#endif /* TileItemImpl_hpp */
