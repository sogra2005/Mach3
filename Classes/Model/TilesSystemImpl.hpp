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
        std::size_t Count() const override;
        std::size_t GetXSize() const override;
        std::size_t GetYSize() const override;
    public:
        void ReInit(std::size_t idx) override;
    private:
        std::vector<ItemPtr> _items;
        std::size_t _xSize, _ySize;
    };
}

#endif /* TilesSystemImpl_hpp */
