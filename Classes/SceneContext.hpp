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
        void InitNewGame();
    private:
        GamePtr _game;
    };
}

#endif /* SceneContext_hpp */
