//
//  Context.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 22.12.2022.
//

#ifndef Context_hpp
#define Context_hpp

#include "cocos2d.h"

namespace Match3Game::Model
{
    class ITilesSystem;
}

namespace Match3Game::GameField
{
    class Context
    {
    public:
        using TilesSystemPtr = std::shared_ptr<Model::ITilesSystem>;
    public:
        Context(cocos2d::Node *layer, const TilesSystemPtr& tilesSystem);
    private:
        void InitGameField(cocos2d::Node *layer);
    private:
        TilesSystemPtr _tilesSystem;
    };
}

#endif /* Context_hpp */
