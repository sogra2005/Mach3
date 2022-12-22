//
//  FieldController.hpp
//  Mach3Game
//
//  Created by Александр Брославский on 22.12.2022.
//

#ifndef FieldController_hpp
#define FieldController_hpp

#include "cocos2d.h"

namespace Match3Game::Model
{
    class ITilesSystem;
    class ITileItem;
}

namespace Match3Game::Tile
{
    class TileComponent;
}

namespace Match3Game::GameField
{
    class FieldController
    {
    public:
        using TilesSystemPtr = std::shared_ptr<Model::ITilesSystem>;
        using TileItemPtr = std::shared_ptr<Model::ITileItem>;
    public:
        FieldController(cocos2d::Node *layer, const TilesSystemPtr& system);
        ~FieldController();
    private:
        void BindListener();
        void AddEventListener();
    private:
        void CheckSelect(cocos2d::Sprite *sprite);
        void Select(Tile::TileComponent *component, const TileItemPtr& item);
        void UnSelect(Tile::TileComponent *component);
        void Swap(Tile::TileComponent *component, const TileItemPtr& item);
        bool IsAdjacent(const TileItemPtr& item) const;
    private:
        cocos2d::Node *_layer;
        cocos2d::EventListenerTouchOneByOne* _fieldListener;
        TileItemPtr _selectItem;
        Tile::TileComponent *_selectComponent;
        TilesSystemPtr _tilesSystem;
    };
}

#endif /* FieldController_hpp */
