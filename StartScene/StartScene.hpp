//
//  StartScene.hpp
//  MyGame
//
//  Created by Alexandr.B on 09.07.2022.
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include "cocos2d.h"

namespace MergeGame {
    namespace State {
        class StateController;
    }
}

namespace MergeGame {
    namespace SettingsScene {

        class StartScene : public cocos2d::Scene
        {
        public:
            using StateControllerPtr = std::shared_ptr<MergeGame::State::StateController>;
        public:
            static cocos2d::Scene* createScene();
            
            virtual bool init();
            
            // a selector callback
            void menuCloseCallback(cocos2d::Ref* pSender);
            
            // implement the "static create()" method manually
            CREATE_FUNC(StartScene);
        };

    }
}

#endif /* StartScene_hpp */
