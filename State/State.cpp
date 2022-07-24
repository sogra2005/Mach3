//
//  State.cpp
//  MyGame
//
//  Created by Alexandr.B on 23.07.2022.
//

#include "State.hpp"

namespace MergeGame { namespace State {

    const char *SliderHeightKey = "SliderHeight";
    const char *SliderWidthKey = "SliderWidth";
    const char *SliderColorKey = "SliderColor";


    void StateWrite::WriteSliderHeight(int value) {
        WriteIntValue(value, SliderHeightKey);
    }

    void StateWrite::WriteSliderWidth(int value) {
        WriteIntValue(value, SliderWidthKey);
    }

    void StateWrite::WriteSliderColor(int value) {
        WriteIntValue(value, SliderColorKey);
    }


    void StateWrite::WriteIntValue(int value, const char *key) {
        cocos2d::UserDefault::getInstance()->setIntegerForKey(key, value);
    }



    int StateRead::ReadSliderHeight() const {
        return ReadIntValue(SliderHeightKey);
    }

    int StateRead::ReadSliderWidth() const {
        return ReadIntValue(SliderWidthKey);
    }

    int StateRead::ReadSliderColor() const {
        return ReadIntValue(SliderColorKey);
    }


    int StateRead::ReadIntValue(const char *key) const {
        return cocos2d::UserDefault::getInstance()->getIntegerForKey(key);
    }


} }
