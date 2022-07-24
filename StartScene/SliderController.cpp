//
//  SliderController.cpp
//  MyGame
//
//  Created by Alexandr.B on 09.07.2022.
//

#include "SliderController.hpp"

#include "../State/StateController.hpp"
#include "../State/State.hpp"

#include "ui/CocosGUI.h"
#include "cocos2d.h"


namespace MergeGame { namespace SettingsScene {

    using namespace State;

    USING_NS_CC;
    
    SliderController::SliderController(SliderType type)
    : _visibleSize(Director::getInstance()->getVisibleSize()),
    _origin(Director::getInstance()->getVisibleOrigin()),
    _type(type), _nameSlider(GetNameSlider(type)),
    _stateWriter(std::make_shared<StateWrite>()) {}
    
    void SliderController::Save(int value, SliderType type) {
        if (type == SliderType::Height)
            _stateWriter->WriteSliderHeight(value);
        else if (type == SliderType::Width)
            _stateWriter->WriteSliderWidth(value);
        else if (type == SliderType::Color)
            _stateWriter->WriteSliderColor(value);
    }
    
    void SliderController::CreateSlider(cocos2d::Vec2 position) {
        _slider = ui::Slider::create();
        
        LoadImages();
        AddListener();
        Settings(position);
    }
    
    void SliderController::AddListener() {
        Save(_minValue, _type);
        _slider->addTouchEventListener([&,category=_type](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
            
            auto _sliderControl = dynamic_cast<ui::Slider*>(sender);
            
            _textLabel = _sliderControl->getChildByName<cocos2d::Label*>("TextLabel");
            _progressLabel = _textLabel->getChildByName<cocos2d::Label*>("ProgressLabel");
            _nameSlider = _progressLabel->getChildByName<cocos2d::Label*>("nameSlider")->getString();
            auto max = _progressLabel->getChildByName<cocos2d::Label*>("MinValue")->getString();
            std::stringstream(max) >> _minValue;
            _value = _sliderControl->getPercent() + _minValue;
            _progressLabel->setString(std::to_string(_value));
            Save(_value, category);
            UpdatePositionProgressLabel();
            
            UpdatePositionProgressLabel();
            
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN: break;
                case ui::Widget::TouchEventType::ENDED: break;
                default: break;
            }
        });
    }
    
    void SliderController::LoadImages() {
        _slider->loadBarTexture("SliderBG.png");
        _slider->loadSlidBallTextures("SliderE.png", "SliderP.png", "SliderD.png");
    }
    
    void SliderController::Settings(cocos2d::Vec2 position) {
        _slider->setPosition(position);
        _slider->setScale(0.7);
        CreateTextLabel();
        CreateProgressLabel();
        UpdatePositionProgressLabel();
    }
    
    void SliderController::CreateTextLabel() {
        _textLabel = Label::createWithTTF("", "fonts/Marker Felt.ttf", 17);
        _textLabel->setName("TextLabel");
        if (_textLabel) _slider->addChild(_textLabel);
        if (_textLabel) _textLabel->setPosition(Vec2(_visibleSize.width/10, 35));
        _textLabel->setAnchorPoint(Vec2(0,0));
    }
    
    void SliderController::CreateProgressLabel() {
        _progressLabel = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 17);
        _progressLabel->setName("ProgressLabel");
        _progressLabel->setAnchorPoint(Vec2(0,0.5));
        if (_textLabel && _progressLabel) _textLabel->addChild(_progressLabel);
        CreateMaxAndMin();
        CreateName();
    }
    
    void SliderController::UpdatePositionProgressLabel() {
        if (_textLabel && _progressLabel) _progressLabel->setPosition(Vec2(_textLabel->getContentSize().width + 10,
                                                                           _textLabel->getContentSize().height/2));
    }
    
    void SliderController::SetString(std::string str) {
        _textLabel->setString(str);
        UpdatePositionProgressLabel();
    }
    
    void SliderController::SetMinValue(int min) {
        _minValue = min;
        _value = min;
        _progressLabel->setString(std::to_string(_minValue));
        _minV->setString(std::to_string(_minValue));
        Save(_minValue, _type);
    }
    void SliderController::SetMaxValue(int max) {
        _maxValue = max;
        _slider->setMaxPercent(max);
        _maxV->setString(std::to_string(_maxValue));
    }
    
    void SliderController::CreateMaxAndMin() {
        _maxV = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 1);
        _maxV->setName("MaxValue");
        _maxV->setVisible(false);
        if (_progressLabel) _progressLabel->addChild(_maxV);
        _minV = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 1);
        _minV->setName("MinValue");
        _minV->setVisible(false);
        if (_progressLabel) _progressLabel->addChild(_minV);
    }
    
    void SliderController::CreateName() {
        _name = Label::createWithTTF("", "fonts/Marker Felt.ttf", 1);
        _name->setName("nameSlider");
        _name->setString(_nameSlider);
        _name->setVisible(false);
        if (_progressLabel) _progressLabel->addChild(_name);
    }
    
    std::string SliderController::GetNameSlider(SliderType slider) const {
        static std::map<SliderType, std::string> _map {
            { SliderType::Height,  "Height"   },
            { SliderType::Width,   "Width"    },
            { SliderType::Color,   "Color"    },
            { SliderType::End,     "End"      }
        };
        return _map[slider];
    }

}}
