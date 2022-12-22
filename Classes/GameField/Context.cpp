//
//  Context.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 22.12.2022.
//

#include "Context.hpp"
#include "FieldController.hpp"
#include "FieldComponent.hpp"

#include "Model/TilesSystem.hpp"
#include "../Utils/ComponentHelper.hpp"

namespace Match3Game::GameField
{
    Context::Context(cocos2d::Node *layer, const TilesSystemPtr& tilesSystem)
    : _tilesSystem(tilesSystem)
    {
        InitGameField(layer);
    }

    void Context::InitGameField(cocos2d::Node *layer)
    {
        _tilesSystem->Init(5, 10);
        
        auto node = cocos2d::Node::create();
        node->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
        node->setPosition(cocos2d::Vec2(0.0, 0.0));
        layer->addChild(node, 5);
        
        auto component = Utils::CreateComponent<GameFieldComponent>();
        component->Set(_tilesSystem);
        component->setName("GameFieldComponent");
        node->addComponent(component);
        
        _fieldController = std::make_shared<FieldController>(node, _tilesSystem);
    }
}
