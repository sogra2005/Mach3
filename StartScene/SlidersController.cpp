//
//  SlidersController.cpp
//  MyGame
//
//  Created by Alexandr.B on 09.07.2022.
//

#include "SlidersController.hpp"
#include "SliderController.hpp"
#include "../Settings/GlobalVar.hpp"

#include <map>

namespace MergeGame {
    namespace SettingsScene {

    USING_NS_CC;

    SlidersController::SlidersController()
    : _visibleSize(Director::getInstance()->getVisibleSize()),
    _origin(Director::getInstance()->getVisibleOrigin())
    {
        CreateSliders();
    }

    void SlidersController::CreateSliders() {
        CreateSliderWidth();
        CreateSliderHeigth();
        CreateSliderColors();
    }
        
    void SlidersController::CreateSliderWidth() {
        _sliderWidth = std::make_shared<SliderController>(SliderType::Width);
        _sliderWidth->CreateSlider(Vec2(_visibleSize.width / 2 + _origin.x,
                                        _visibleSize.height / 2 + _origin.y + 50));
        _sliderWidth->SetString("Width:");
        SetMaxAndMinValues(_sliderWidth, BuildField::MAX_WIDTH, BuildField::MIN_WIDTH);
    }
        
    void SlidersController::CreateSliderHeigth() {
        _sliderHeigth = std::make_shared<SliderController>(SliderType::Height);
        _sliderHeigth->CreateSlider(Vec2(_visibleSize.width / 2 + _origin.x,
                                         _visibleSize.height / 2 + _origin.y));
        _sliderHeigth->SetString("Height:");
        SetMaxAndMinValues(_sliderHeigth, BuildField::MAX_HEIGHT, BuildField::MIN_HEIGHT);
    }
        
    void SlidersController::CreateSliderColors() {
        _sliderColors = std::make_shared<SliderController>(SliderType::Color);
        _sliderColors->CreateSlider(Vec2(_visibleSize.width / 2 + _origin.x,
                                         _visibleSize.height / 2 + _origin.y - 50));
        _sliderColors->SetString("Number of colors:");
        SetMaxAndMinValues(_sliderColors, BuildField::MAX_BLOCK_COLORS, BuildField::MIN_BLOCK_COLORS);
    }
        
    cocos2d::ui::Slider* SlidersController::GetSliderWidth() const {
        return _sliderWidth->GetSlider();
    }
        
    cocos2d::ui::Slider* SlidersController::GetSliderHeigth() const {
        return _sliderHeigth->GetSlider();
    }
        
    cocos2d::ui::Slider* SlidersController::GetSliderColors() const {
        return _sliderColors->GetSlider();
    }
        
    void SlidersController::SetMaxAndMinValues(const SliderControllerPtr& _slider, int max, int min) {
        _slider->SetMaxValue(max - min);
        _slider->SetMinValue(min);
    }
    
}}
