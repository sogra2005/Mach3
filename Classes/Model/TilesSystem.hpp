//
//  TilesSystem.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef TilesSystem_hpp
#define TilesSystem_hpp

#include "cocos2d.h"

namespace Match3Game::Model
{
    class ITileItem;

    class ITilesSystem
    {
    public:
        using ItemPtr = std::shared_ptr<ITileItem>;
    public:
        virtual void Init(std::size_t xSize, std::size_t ySize) = 0;
    public:
        virtual ItemPtr GetItem(std::size_t idx) const = 0;
    };
}

#endif /* TilesSystem_hpp */
