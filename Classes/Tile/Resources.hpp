//
//  Resources.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef Resources_hpp
#define Resources_hpp

#include <optional>

namespace Match3Game::Tile
{
    enum class SpriteType
    {
        Crystal0,
        Crystal1,
        Crystal2,
        Crystal3,
        Crystal4,
        Crystal5,
        End
    };

    static const char* GetName(SpriteType type);
    std::optional<SpriteType> GetType(const char* name);
}

#endif /* Resources_hpp */
