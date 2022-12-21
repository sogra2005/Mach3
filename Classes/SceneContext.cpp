//
//  SceneContext.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#include "SceneContext.hpp"

#include "Model/Game.hpp"
#include "Model/TilesSystem.hpp"

namespace Match3Game::SceneContext
{
    using namespace cocos2d;

    SceneContext::SceneContext()
    {
        CreateGame();
    }

    void SceneContext::onAdd()
    {
        Component::onAdd();
        
    }

    void SceneContext::onRemove()
    {
        Component::onRemove();
    }

    void SceneContext::CreateGame()
    {
        _game = std::make_shared<Model::Game>();
    }

    void SceneContext::InitNewGame()
    {
        _game->GetTilesSystemPtr()->Init(5, 5);
    }
}
