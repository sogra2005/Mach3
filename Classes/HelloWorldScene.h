/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
public:
    void Fiel_Analysis(int TagSprite, int list_blocks[],
                       int *pSum_sprites, cocos2d::Color3B color_sprite);
    void Sprite_Comparison(cocos2d::Color3B color_1, cocos2d::Color3B color_2,
                           int *list_blocks, int *pSum_sprites, int tag_sprite);
    bool Existence(int listBlocks[], int *pSum_sprites, int Search);
    void Change_color(int listBlocks[], int *pSum_sprites);
private:
    void FallingBlocks();
    void AddEventListener();
private:
    void UpdateScoreText();
private:
    std::vector<cocos2d::Sprite*> _sprites;
    cocos2d::EventListenerTouchOneByOne* _myListener;
    int _scoreGame = 0;
    cocos2d::Label *_scoreTextLabel, *_scoreLabel;
private:
    int _width, _height;
private:
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
