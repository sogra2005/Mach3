//
//  TilesSystemImpl.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef TilesSystemImpl_hpp
#define TilesSystemImpl_hpp

#include "TilesSystem.hpp"

#include <vector>

namespace Match3Game::Model
{
    class TilesSystem : public ITilesSystem
    {
    public:
        TilesSystem();
    public:
        void Init(std::size_t xSize, std::size_t ySize) override;
    public:
        ItemPtr GetItem(std::size_t idx) const override;
    private:
        std::vector<ItemPtr> _items;
    };
}

#endif /* TilesSystemImpl_hpp */
