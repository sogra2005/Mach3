//
//  SlidersController.hpp
//  MyGame
//
//  Created by Alexandr.B on 09.07.2022.
//

#ifndef SlidersController_hpp
#define SlidersController_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

namespace MergeGame { namespace SettingsScene {
    
    class SliderController;

    class SlidersController
    {
    public:
        using SliderControllerPtr = std::shared_ptr<SliderController>;
    public:
        SlidersController();
    public:
        void CreateSliders();
    public:
        cocos2d::ui::Slider *GetSliderWidth() const;
        cocos2d::ui::Slider *GetSliderHeigth() const;
        cocos2d::ui::Slider *GetSliderColors() const;
    private:
        void CreateSliderWidth();
        void CreateSliderHeigth();
        void CreateSliderColors();
        void SetMaxAndMinValues(const SliderControllerPtr& _slider, int max, int min);
    private:
        SliderControllerPtr _sliderWidth, _sliderHeigth, _sliderColors;
        cocos2d::Size _visibleSize;
        cocos2d::Vec2 _origin;
    };
    
}}

#endif /* SlidersController_hpp */
