//
//  Resources.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#include "Resources.hpp"

#include <map>

namespace Match3Game::Tile
{

    const char* Resources::GetName(SpriteType type)
    {
        std::map<SpriteType, const char*> _map
        {
            { SpriteType::Crystal0, "crystal0" },
            { SpriteType::Crystal1, "crystal1" },
            { SpriteType::Crystal2, "crystal2" },
            { SpriteType::Crystal3, "crystal3" },
            { SpriteType::Crystal4, "crystal4" },
            { SpriteType::End,      "end"      }
        };
        return _map[type];
    }

    const std::optional<SpriteType> Resources::GetType(const char* name)
    {
        std::map<const char*, SpriteType> _map
        {
            { "crystal0", SpriteType::Crystal0 },
            { "crystal1", SpriteType::Crystal1 },
            { "crystal2", SpriteType::Crystal2 },
            { "crystal3", SpriteType::Crystal3 },
            { "crystal4", SpriteType::Crystal4 },
            { "end",      SpriteType::End      }
        };
        return _map[name];
    }
}
