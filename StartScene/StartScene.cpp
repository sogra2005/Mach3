//
//  StartScene.cpp
//  MyGame
//
//  Created by Alexandr.B on 09.07.2022.
//

#include "StartScene.hpp"
#include "HelloWorldScene.h"
#include "SlidersController.hpp"

#include "ui/CocosGUI.h"

namespace MergeGame {
namespace SettingsScene {

USING_NS_CC;

Scene* StartScene::createScene()
{
    return StartScene::create();
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("ButtonStart.png",
                                           "ButtonStartP.png",
                                           CC_CALLBACK_1(StartScene::menuCloseCallback, this));
    
    if (!(closeItem == nullptr || closeItem->getContentSize().width <= 0 || closeItem->getContentSize().height <= 0))
    {
        closeItem->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 7 + origin.y));
        closeItem->setScale(0.6);
    }
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("SETTINGS", "fonts/Marker Felt.ttf", 24);
    if (!(label == nullptr))
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));
        // add the label as a child to this layer
        this->addChild(label, 1);
    }
    
    auto slidersController = std::make_shared<SlidersController>();
    
    this->addChild(slidersController->GetSliderWidth());
    this->addChild(slidersController->GetSliderHeigth());
    this->addChild(slidersController->GetSliderColors());
    
    return true;
}


void StartScene::menuCloseCallback(Ref* pSender)
{
    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();
    
    // run
    Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5, scene));
}

} }
