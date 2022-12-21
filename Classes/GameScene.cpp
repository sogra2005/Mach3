//
//  GameScene.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#include "GameScene.hpp"

#include "SceneContext.hpp"
#include "ComponentHelper.hpp"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();

//    auto closeItem = MenuItemImage::create("CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
//
//    if (closeItem || closeItem->getContentSize().width > 0 || closeItem->getContentSize().height > 0)
//    {
//        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
//        float y = origin.y + closeItem->getContentSize().height/2;
//        closeItem->setPosition(Vec2(x,y));
//    }
//
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);

//    if (auto label = Label::createWithTTF("Game Scene", "fonts/Marker Felt.ttf", 24); label)
//    {
//        label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                                origin.y + visibleSize.height - label->getContentSize().height));
//
//        this->addChild(label, 1);
//    }

//    if (auto sprite = Sprite::create("crystal0.png"); sprite)
//    {
//        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//        this->addChild(sprite, 0);
//    }
    
    this->addComponent(Match3Game::Component::Create<Match3Game::SceneContext::SceneContext>());
    
    return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
