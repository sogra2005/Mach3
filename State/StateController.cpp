//
//  StateController.cpp
//  MyGame
//
//  Created by Alexandr.B on 23.07.2022.
//

#include "StateController.hpp"

namespace MergeGame {
    namespace State {

        StateController::StateController() {
            _stateWrite = std::make_shared<StateWrite>();
            _stateRead = std::make_shared<StateRead>();
        }
    
    }
}
