//
//  SliderController.hpp
//  MyGame
//
//  Created by Alexandr.B on 09.07.2022.
//

#ifndef SliderController_hpp
#define SliderController_hpp

#include "SliderController.hpp"

#include "cocos2d.h"
#include "ui/CocosGUI.h"

namespace MergeGame {

namespace State {
    class StateWrite;
}

    namespace SettingsScene {
    
    enum class SliderType {
        Width,
        Height,
        Color,
        //..
        End
    };

    class SliderController
    {
    public:
        
        using StateWritewPtr = std::shared_ptr<State::StateWrite>;
    public:
        SliderController(SliderType type);
    public:
        void CreateSlider(cocos2d::Vec2 position);
        cocos2d::ui::Slider *GetSlider() const { return _slider; }
        void SetString(std::string str);
    public:
        void SetMinValue(int min);
        void SetMaxValue(int max);
    private:
        void LoadImages();
        void Settings(cocos2d::Vec2 position);
        void AddListener();
        void CreateTextLabel();
        void CreateProgressLabel();
    private:
        void UpdatePositionProgressLabel();
    private:
        void CreateMaxAndMin();
        void CreateName();
    private:
        void Save(int value, SliderType type);
    private:
        std::string GetNameSlider(SliderType slider) const;
    private:
        StateWritewPtr _stateWriter;
        cocos2d::ui::Slider *_slider;
        cocos2d::Label *_textLabel, *_progressLabel, *_maxV, *_minV, *_name;
        cocos2d::Size _visibleSize;
        cocos2d::Vec2 _origin;
        int _maxValue = 100, _minValue = 0;
        int _value = 0;
        std::string _nameSlider;
        SliderType _type;
    };

}}

#endif /* SliderController_hpp */
