//
//  GlobalVar.hpp
//  MyGame
//
//  Created by Alexandr.B on 07.07.2022.
//

#ifndef GlobalVar_hpp
#define GlobalVar_hpp

#include "cocos2d.h"

namespace MergeGame { namespace BuildField {

    USING_NS_CC;

    static const int PIXIL_SIZE_BLOCK = 25;

    static const int MAX_BLOCK_COLORS = 7;
    static const int MIN_BLOCK_COLORS = 3;

    static const int WIDTH = 7;
    static const int MAX_WIDTH = 7;
    static const int MIN_WIDTH = 3;

    static const int HEIGHT = 10;
    static const int MAX_HEIGHT = 10;
    static const int MIN_HEIGHT = 5;

    static const float SCALE_BLOCK = 1.0;

    static const Color3B GetColorSettings(int colorNum) {
        std::map<int, Color3B> _colorMap {
            { 1,    Color3B(255, 0,   0)   }, // red
            { 2,    Color3B(0,   255, 0)   }, // green
            { 3,    Color3B(0,   0,   255) }, // blue
            { 4,    Color3B(186, 85,  211) }, // MediumOrchid
            { 5,    Color3B(255, 105, 180) }, // HotPink
            { 6,    Color3B(0,   255, 255) }, // aqua
            { 7,    Color3B(210, 105, 30)  }  // Chocolate
        };
        return _colorMap[colorNum];
    }
}}

#endif /* GlobalVar_hpp */
