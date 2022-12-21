//
//  Game.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#include "Game.hpp"

#include "TilesSystemImpl.hpp"
#include "TileItem.hpp"

namespace Match3Game::Model
{
    Game::Game()
    {
        auto tilesSystem = std::make_shared<TilesSystem>();
        _tilesSystem = tilesSystem;
    }

    auto Game::GetTilesSystemPtr() const -> TilesSystemPtr
    {
        return _tilesSystem;
    }
}
