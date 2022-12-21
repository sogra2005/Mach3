//
//  Game.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef Game_hpp
#define Game_hpp

#include <memory>

namespace Match3Game::Model
{
    class ITilesSystem;

    class Game
    {
    public:
        using TilesSystemPtr = std::shared_ptr<ITilesSystem>;
    public:
        Game();
    public:
        TilesSystemPtr GetTilesSystemPtr() const;
    private:
        TilesSystemPtr _tilesSystem;
    };
}

#endif /* Game_hpp */
