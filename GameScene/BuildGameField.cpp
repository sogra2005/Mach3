//
//  BuildGameField.cpp
//  MyGame
//
//  Created by Alexandr.B on 07.07.2022.
//

#include "BuildGameField.hpp"
#include "../Settings/GlobalVar.hpp"
#include "../State/StateController.hpp"
#include "../State/State.hpp"
#include <cstdlib>
#include <random>
#include "cocos2d.h"

namespace MergeGame { namespace BuildField {

    using namespace State;
    USING_NS_CC;

    BuildGameField::BuildGameField(Ref* pSender, cocos2d::Node *node)
    : _pSender(pSender), _node(node), _stateController(std::make_shared<StateController>())
    {
        LoadValues();
        
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        
        for (int j = 1, count = 0, teg_init = 1; j < _height + 1; j++) {
            
            int local_y = origin.y + (visibleSize.height - PIXIL_SIZE_BLOCK * SCALE_BLOCK *
                                    (_height + 1)) / 2  + PIXIL_SIZE_BLOCK * SCALE_BLOCK * j;
            
            for (int i = 1; i < _width + 1; i++, teg_init++, count++) {
                
                int local_x = origin.x + (visibleSize.width - PIXIL_SIZE_BLOCK * SCALE_BLOCK *
                                        (_width + 1)) / 2 + PIXIL_SIZE_BLOCK * SCALE_BLOCK * i;
                
                auto aaa = Sprite::create("PixilBlock.png");
                _sprites.push_back(aaa);
                _sprites[count]->setPosition(Vec2(local_x, local_y));
                
                SetSpriteColor(count);
                
                _sprites[count]->setScale(SCALE_BLOCK);
                _sprites[count]->setTag(teg_init);
                _node ->addChild(_sprites[count]);
            }
        }
    }
    
    void BuildGameField::SetSpriteColor(int number) {
        _sprites[number]->setColor(GetSpriteColor(Get_Random_Number(1, _colors)));
    }

    Color3B BuildGameField::GetSpriteColor(int num) const {
        return GetColorSettings(num);
    }
    
    int BuildGameField::Get_Random_Number(int min, int max) {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(min, max);
        int x = distribution(generator);
        return x;
    }
    
    void BuildGameField::LoadValues() {
        _width = GetWidth();
        _height = GetHeight();
        _colors = GetNumbersOfColors();
    }
    
    int BuildGameField::GetHeight() const {
        return _stateController->GetStateReadPtr()->ReadSliderHeight();
    }
    
    int BuildGameField::GetWidth() const {
        return _stateController->GetStateReadPtr()->ReadSliderWidth();
    }
    
    int BuildGameField::GetNumbersOfColors() const {
        return _stateController->GetStateReadPtr()->ReadSliderColor();
    }
    
}}
