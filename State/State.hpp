//
//  State.hpp
//  MyGame
//
//  Created by Alexandr.B on 23.07.2022.
//

#ifndef State_hpp
#define State_hpp

#include "cocos2d.h"

namespace MergeGame {
    namespace State {

        class StateWrite {
        public:
            void WriteSliderHeight(int value);
            void WriteSliderWidth(int value);
            void WriteSliderColor(int value);
        private:
            void WriteIntValue(int value, const char *key);
        };
        
        class StateRead {
        public:
            int ReadSliderHeight() const;
            int ReadSliderWidth() const;
            int ReadSliderColor() const;
        private:
            int ReadIntValue(const char *key) const;
        };

    }
}

#endif /* State_hpp */
