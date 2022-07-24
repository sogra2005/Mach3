//
//  BuildGameField.hpp
//  MyGame
//
//  Created by Alexandr.B on 07.07.2022.
//

#ifndef BuildGameField_hpp
#define BuildGameField_hpp

#include "cocos2d.h"
#include "../Settings/GlobalVar.hpp"
#include "../State/StateController.hpp"

namespace MergeGame {

    namespace State {
        class StateController;
    }

    namespace BuildField {

        USING_NS_CC;
        
        class BuildGameField : public cocos2d::Scene
        {
        public:
            using StateControllerPtr = std::shared_ptr<State::StateController>;
            BuildGameField(Ref* pSender, cocos2d::Node *node);
        public:
            std::vector<Sprite*> GetSprites() { return _sprites; }
        private:
            int Get_Random_Number(int min, int max);
        private:
            void LoadValues();
        private:
            int GetHeight() const;
            int GetWidth() const;
            int GetNumbersOfColors() const;
        private:
            void SetSpriteColor(int number);
            Color3B GetSpriteColor(int num) const;
        private:
            StateControllerPtr _stateController;
            std::vector<Sprite*> _sprites;
            cocos2d::Ref* _pSender;
            cocos2d::Node *_node;
            int _height, _width, _colors;
        };

    }
}
#endif /* BuildGameField_hpp */
