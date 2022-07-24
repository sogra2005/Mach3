//
//  StateController.hpp
//  MyGame
//
//  Created by Alexandr.B on 23.07.2022.
//

#ifndef StateController_hpp
#define StateController_hpp

#include "cocos2d.h"
#include "State.hpp"

namespace MergeGame {
    namespace State {
    
        class StateWrite;
        class StateRead;
        
        class StateController {
        public:
            using StateWritePtr = std::shared_ptr<StateWrite>;
            using StateReadPtr = std::shared_ptr<StateRead>;
        public:
            StateController();
        public:
            StateWritePtr GetStateWritePtr() const { return _stateWrite; }
            StateReadPtr GetStateReadPtr() const { return _stateRead; }
        private:
            StateWritePtr _stateWrite;
            StateReadPtr _stateRead;
        };
    
    }
}

#endif /* StateController_hpp */
