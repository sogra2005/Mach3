//
//  TilesSystemImpl.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#include "TilesSystemImpl.hpp"
#include "TileItemImpl.hpp"
#include "TileItem.hpp"

#include "../Tile/Resources.hpp"
#include "../Utils/RandomGenerator.hpp"

#define PIXIL_SIZE_BLOCK 72
#define SCALE_BLOCK 1

namespace Match3Game::Model
{
    TilesSystem::TilesSystem()
    {
        
    }

    void TilesSystem::Init(std::size_t xSize, std::size_t ySize)
    {
        _items.clear();
        
        
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        for (int y = 1, count = 0; y < ySize + 1; y++)
        {
            
            int local_y = origin.y + (visibleSize.height - PIXIL_SIZE_BLOCK * SCALE_BLOCK *
                                      (ySize + 1)) / 2  + PIXIL_SIZE_BLOCK * SCALE_BLOCK * y;
            
            for (int x = 1; x < xSize + 1; x++, count++)
            {
                
                int local_x = origin.x + (visibleSize.width - PIXIL_SIZE_BLOCK * SCALE_BLOCK *
                                        (xSize + 1)) / 2 + PIXIL_SIZE_BLOCK * SCALE_BLOCK * x;
                
                Vec2 pos = Vec2(local_x, local_y);
                auto sprite = Tile::SpriteType(Utils::RandomGenerator::GetRandomInt(0, 5));
                _items.push_back(std::make_shared<TileItem>(pos, sprite));
            }
        }
    }

    auto TilesSystem::GetItem(std::size_t idx) const -> ItemPtr
    {
        return _items[idx];
    }
}
