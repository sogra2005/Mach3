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

#include "HelloWorldScene.h"
#include "../GameScene/BuildGameField.hpp"
#include "../Settings/GlobalVar.hpp"
#include "../StartScene/StartScene.hpp"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    _width = UserDefault::getInstance()->getIntegerForKey("WidthKey");
    _height = UserDefault::getInstance()->getIntegerForKey("HeightKey");

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (!(closeItem == nullptr || closeItem->getContentSize().width <= 0 || closeItem->getContentSize().height <= 0))
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width;
        float y = origin.y + closeItem->getContentSize().height;
        closeItem->setScale(2);
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    _scoreTextLabel = Label::createWithTTF("SCORE:", "fonts/Marker Felt.ttf", 22);
    if (!(_scoreTextLabel == nullptr))
    {
        // position the label on the center of the screen
        _scoreTextLabel->setPosition(Vec2(origin.x + visibleSize.width/4,
                                          origin.y + visibleSize.height - _scoreTextLabel->getContentSize().height));
        // add the label as a child to this layer
        this->addChild(_scoreTextLabel, 1);
    }
    _scoreLabel = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 22);
    if (_scoreLabel)
    {
        _scoreTextLabel->addChild(_scoreLabel,1);
        UpdateScoreText();
    }

    auto _buildGameField = std::make_shared<MergeGame::BuildField::BuildGameField>(this, this);
    _sprites = _buildGameField->GetSprites();
    
    /* Создаем прослушиватель событий OneByOne для однократного касания */
    _myListener = EventListenerTouchOneByOne::create();
    /* Устанавливаем, следует ли проглотить событие, проглотить его, когда метод onTouchBegan возвращает true */
    _myListener->setSwallowTouches(true);

    /* функция обратного вызова события onTouchBegan */
    _myListener->onTouchBegan = [=](Touch* touch, Event* event) {
        /* Получаем цель, привязанную к событию */
        auto target = static_cast<Sprite*>(event->getCurrentTarget());

        /* Получаем координаты положения кнопки относительно текущей точки щелчка */
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Rect rect = Rect(0, 0, target->getContentSize().width, target->getContentSize().height);

        /* Массив для записи спрайтов на "удаление" и переменная для количества записаных элементов в массив */
        int list_blocks[_height * _width], sum_sprites = 0;
        for (int i = 0; i < _width * _height; list_blocks[i] = 0, i++);

        int *pSum_sprites = &sum_sprites;
        /* Определение диапазона щелчков, определение того, содержит ли переданная координата объект, по которому щелкнули */
        if (rect.containsPoint(locationInNode)) {
            list_blocks[0] = target->getTag();
            sum_sprites += 1;
            Fiel_Analysis(target->getTag(), list_blocks, pSum_sprites, target->getColor());
            Change_color(list_blocks, pSum_sprites);
            FallingBlocks();
            _scoreGame += sum_sprites;
            UpdateScoreText();
            return true;
        }
        return false;
    };
    AddEventListener();
    return true;
}

void HelloWorld::AddEventListener() {
    if (_myListener) {
        /* Связываем событие для прослушивателя событий, чтобы определить, кто реагирует */
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_myListener, _sprites[0]);
        for (int block = 1; block < _height * _width; block++)
            _eventDispatcher->addEventListenerWithSceneGraphPriority(_myListener->clone(), _sprites[block]);
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    auto scene = MergeGame::SettingsScene::StartScene::create();
    
    // run
    Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5, scene));
}

/* Функция для определения возможности анализа соседних спрайтов */
void HelloWorld::Fiel_Analysis(int TagSprite, int list_blocks[], int *pSum_sprites, Color3B color_1) {
    
    /* Определение возможности анализа спрайтов справа и сверху */
    if (TagSprite < _height * _width - 2) {
        /* Определение возможности анализа спрайта справа */
        if (TagSprite % _width != 0)
            Sprite_Comparison(color_1, getChildByTag(TagSprite + 1)->getColor(),
                              list_blocks, pSum_sprites, (TagSprite + 1));
        /* Определение возможности анализа спрайта сверху */
        if (_width * _height - TagSprite >= _width)
            Sprite_Comparison(color_1, getChildByTag(TagSprite + _width)->getColor(),
                              list_blocks, pSum_sprites, (TagSprite + _width));
    }
    /* Определение возможности анализа спрайтов слева и снизу */
    if (TagSprite > 0) {
        /* Определение возможности анализа спрайта слева */
        if (TagSprite % _width != 1)
            Sprite_Comparison(color_1, getChildByTag(TagSprite - 1)->getColor(),
                              list_blocks, pSum_sprites, (TagSprite - 1));
        /* Определение возможности анализа спрайта снизу */
        if (TagSprite > _width)
            Sprite_Comparison(color_1, getChildByTag(TagSprite - _width)->getColor(),
                              list_blocks, pSum_sprites, (TagSprite - _width));
    }
}

/* Функция для сравнения цвета спрайтов */
void HelloWorld::Sprite_Comparison(Color3B color_1, Color3B color_2,
                                    int *list_blocks, int *pSum_sprites, int tag_sprite) {
    
    if (color_1 == color_2 && Existence(list_blocks, pSum_sprites, tag_sprite) == false) {
        /* Добавление тега спрайта в список на "удаление" */
        list_blocks[*pSum_sprites] = tag_sprite;
        Fiel_Analysis(tag_sprite, list_blocks, &(*pSum_sprites += 1), color_2);
    }
}

/* Функция для проверки спрайта на предмет того был ли он найден раньше */
bool HelloWorld::Existence(int listBlocks[], int *pSum_sprites, int Search) {
    
    for( int i = 0; i < *pSum_sprites; i++)
            if(listBlocks[i] == Search) return true;
    return false;
}

/* Функция для изменения цвета у спрайтов */
void HelloWorld::Change_color(int listBlocks[], int *pSum_sprites) {
    
    /* Изменение на черный цвет найденой последовательности из спрайтов */
    if (*pSum_sprites > 2)
        for (int i = 0; i < *pSum_sprites; i++)
            getChildByTag(listBlocks[i])->setColor(Color3B(0, 0, 0));
    FallingBlocks();
}

void HelloWorld::FallingBlocks() {
    /* Создание иллюзии падающих спрайтов путем изменения их цвета */
    for (int i = 0; i < _width / 2; i++)
        for (int j = 1; j <= _width * _height - _width; j++) {
            Color3B color_1 = getChildByTag(j)->getColor();
            if (color_1 == Color3B(0, 0, 0)) {
                Color3B color_2 = getChildByTag(j + _width)->getColor();
                getChildByTag(j)->setColor(Color3B(color_2));
                getChildByTag(j + _width)->setColor(Color3B(color_1));
            }
        }
}

void HelloWorld::UpdateScoreText() {
    _scoreLabel->setString(std::to_string(_scoreGame));
    _scoreLabel->setPosition(Vec2(_scoreTextLabel->getContentSize().width + _scoreLabel->getContentSize().width,
                                  _scoreTextLabel->getContentSize().height/2));
}
