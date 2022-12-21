//
//  SceneContext.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef SceneContext_hpp
#define SceneContext_hpp

#include "cocos2d.h"

namespace Match3Game::Model
{
    class Game;
}

namespace Match3Game::GameField
{
    class Context;
}

namespace Match3Game::SceneContext
{
    class SceneContext : public cocos2d::Component
    {
    public:
        SceneContext();
    public:
        void onAdd() override;
        void onRemove() override;
    private:
        using GamePtr = std::shared_ptr<Model::Game>;
        void CreateGame();
    private:
        using GameFieldContextPtr = std::shared_ptr<GameField::Context>;
        void CreateGameFieldContext();
    private:
        GamePtr _game;
        GameFieldContextPtr _gameFieldContext;
    };
}

#endif /* SceneContext_hpp */
