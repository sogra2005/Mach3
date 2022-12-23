//
//  FieldController.cpp
//  Mach3Game
//
//  Created by Александр Брославский on 22.12.2022.
//

#include "FieldController.hpp"

#include "Model/TilesSystem.hpp"
#include "Model/TileItem.hpp"
#include "../Tile/TileComponent.hpp"
#include "../Utils/ComponentHelper.hpp"

namespace Match3Game::GameField
{
    using namespace cocos2d;
    using namespace Utils;

    FieldController::FieldController(cocos2d::Node *layer, const TilesSystemPtr& system)
    : _layer(layer), _tilesSystem(system), _selectItem(nullptr), _selectComponent(nullptr)
    {
        BindListener();
    }

    void FieldController::BindListener()
    {
        _fieldListener = EventListenerTouchOneByOne::create();
        _fieldListener->setSwallowTouches(true);
        
        _fieldListener->onTouchBegan = [this](Touch* touch, Event* event)
        {
            auto target = static_cast<Sprite*>(event->getCurrentTarget());

            Point locationInNode = target->convertToNodeSpace(touch->getLocation());
            Rect rect = Rect(0, 0, target->getContentSize().width, target->getContentSize().height);
            
            if (rect.containsPoint(locationInNode))
            {
                CheckSelect(target);
                return true;
            }
            return false;
        };
        AddEventListener();
    }

    void FieldController::AddEventListener()
    {
        if (_fieldListener)
        {
            auto eventDispatcher = _layer->getEventDispatcher();
            auto sprites = _layer->getChildren();
            eventDispatcher->addEventListenerWithSceneGraphPriority(_fieldListener, *sprites.begin());
            for (auto i = 1; i < sprites.size(); i++)
                eventDispatcher->addEventListenerWithSceneGraphPriority(_fieldListener->clone(), *(sprites.begin() + i));
        }
    }

    void FieldController::CheckSelect(cocos2d::Sprite *sprite)
    {
        auto component = GetComponent<Tile::TileComponent>(sprite, "TileComponent");
        auto item = _tilesSystem->GetItem(component->GetNumber());
        if (item->GetSpriteType() == Tile::SpriteType::End) return;

        if (component->IsSelected())
        {
            UnSelect(component);
        }
        else if (!component->IsSelected() && _selectItem == nullptr)
        {
            Select(component, item);
        }
        else if (IsAdjacent(item))
        {
            Swap(component, item);
            
            std::pair<std::vector<Tile::TileComponent*>,std::vector<Tile::TileComponent*>> pairVectorF, pairVectorS;
            FieldAnalysis(pairVectorF, component, true);
            FieldAnalysis(pairVectorF, component, false);
            FieldAnalysis(pairVectorS, _selectComponent, true);
            FieldAnalysis(pairVectorS, _selectComponent, false);
            
            auto handler = [this, cmp = component](auto component, auto item, auto vector)
            {
                UnSelect(_selectComponent);
                DelSprites(vector);
                auto children = _layer->getChildren();
                for (auto sprite : children)
                    if (auto component = GetComponent<Tile::TileComponent>(sprite, "TileComponent"); component)
                        component->Update();
                FallingBlocks();
                
            };
            
            if (pairVectorF.first.size() >= 2 || pairVectorF.second.size() >= 2)
            {
                handler(component, item, pairVectorF);
            }
            else if (pairVectorS.first.size() >= 2 || pairVectorS.second.size() >= 2)
            {
                handler(_selectComponent, item, pairVectorS);
            }
            else
            {
                Swap(component, item);
                UnSelect(_selectComponent);
                Select(component, item);
            }
        }
        else
        {
            UnSelect(_selectComponent);
            Select(component, item);
        }
    }

    void FieldController::Select(Tile::TileComponent *component, const TileItemPtr& item)
    {
        _selectItem = item;
        _selectComponent = component;
        component->Select();
    }

    void FieldController::UnSelect(Tile::TileComponent *component)
    {
        _selectItem = nullptr;
        _selectComponent = nullptr;
        if (component)
        {
            component->UnSelect();
        }
    }

    void FieldController::Swap(Tile::TileComponent *component, const TileItemPtr& item)
    {
        if (_selectItem->GetSpriteType() == item->GetSpriteType())
            return;
        
        auto tmpSprite = _selectItem->GetSpriteType();
        _selectItem->SetSprite(item->GetSpriteType());
        item->SetSprite(tmpSprite);
        component->Update();
        _selectComponent->Update();
    }

    bool FieldController::IsAdjacent(const TileItemPtr& item) const
    {
        auto xSize = _tilesSystem->GetXSize();
        
        int selectNumber = (int) _selectItem->GetNumber();
        int thisNumber = (int) item->GetNumber();
        
        return (selectNumber == thisNumber - 1 || selectNumber == thisNumber + 1 ||
                selectNumber == thisNumber - xSize || selectNumber == thisNumber + xSize);
    }

    void FieldController::FieldAnalysis(std::pair<std::vector<Tile::TileComponent*>,std::vector<Tile::TileComponent*>>& vector,
                                        const Tile::TileComponent *component, bool isY)
    {
        auto children = _layer->getChildren();
        auto xSize = _tilesSystem->GetXSize();
        auto ySize = _tilesSystem->GetYSize();
        
        if (component->GetNumber() < xSize * ySize - 2)
        {
            if (component->GetNumber() % xSize != 0 && !isY)
            {
                if (auto cmp = GetComponent<Tile::TileComponent>(*(children.begin() + component->GetNumber() + 1), "TileComponent"); cmp)
                    SpriteComparison(vector, cmp, _tilesSystem->GetItem(component->GetNumber())->GetSpriteType(), isY);
            }
            if (component->GetNumber() + xSize <= (xSize * ySize - 1) && isY)
            {
                if (auto cmp = GetComponent<Tile::TileComponent>(*(children.begin() + component->GetNumber() + xSize), "TileComponent"); cmp)
                    SpriteComparison(vector,cmp,_tilesSystem->GetItem(component->GetNumber())->GetSpriteType(), isY);
            }
        }
        if (component->GetNumber() > 0)
        {
            if (component->GetNumber() % xSize != 1 && !isY)
            {
                if (auto cmp = GetComponent<Tile::TileComponent>(*(children.begin() + component->GetNumber() - 1), "TileComponent"); cmp)
                    SpriteComparison(vector, cmp, _tilesSystem->GetItem(component->GetNumber())->GetSpriteType(), isY);
            }
            if (component->GetNumber() > (xSize- 1) && isY)
            {
                if (auto cmp = GetComponent<Tile::TileComponent>(*(children.begin() + component->GetNumber() - xSize), "TileComponent"); cmp)
                    SpriteComparison(vector, cmp, _tilesSystem->GetItem(component->GetNumber())->GetSpriteType(), isY);
            }
        }
    }

    void FieldController::SpriteComparison(std::pair<std::vector<Tile::TileComponent*>,std::vector<Tile::TileComponent*>>& vector,
                                           Tile::TileComponent *component, Tile::SpriteType type, bool isY)
    {
        if (_tilesSystem->GetItem(component->GetNumber())->GetSpriteType() == type &&
            std::find((isY ? vector.second : vector.first).begin(),
                      (isY ? vector.second : vector.first).end(), component) == (isY ? vector.second : vector.first).end())
        {
            (isY ? vector.second : vector.first).push_back(component);
            FieldAnalysis(vector, component, isY);
        }
    }

    void FieldController::DelSprites(std::pair<std::vector<Tile::TileComponent*>,std::vector<Tile::TileComponent*>>& vector)
    {
        if (vector.first.size() >= 2)
            for (auto item : vector.first)
                _tilesSystem->GetItem(item->GetNumber())->SetSprite(Tile::SpriteType::End);
        if (vector.second.size() >= 2)
            for (auto item : vector.second)
                _tilesSystem->GetItem(item->GetNumber())->SetSprite(Tile::SpriteType::End);
    }

    void FieldController::FallingBlocks()
    {
        auto children = _layer->getChildren();
        for (auto item : children)
            if (auto component = GetComponent<Tile::TileComponent>(item, "TileComponent"); component)
                if (auto itemTile = _tilesSystem->GetItem(component->GetNumber()); itemTile)
                    if (itemTile->GetSpriteType() == Tile::SpriteType::End &&
                        (itemTile->GetNumber() + _tilesSystem->GetXSize() <= _tilesSystem->Count() - 1))
                    {
                        itemTile->SetSprite(_tilesSystem->GetItem(itemTile->GetNumber() + _tilesSystem->GetXSize())->GetSpriteType());
                        _tilesSystem->GetItem(itemTile->GetNumber() + _tilesSystem->GetXSize())->SetSprite(Tile::SpriteType::End);
                    }
        
        for (auto i = _tilesSystem->GetXSize() * _tilesSystem->GetYSize() - _tilesSystem->GetXSize();
             i < _tilesSystem->GetXSize() * _tilesSystem->GetYSize(); i++)
            if (auto component = GetComponent<Tile::TileComponent>(*(children.begin() + i), "TileComponent"); component)
                if (auto itemTile = _tilesSystem->GetItem(component->GetNumber()))
                    if (itemTile->GetSpriteType() == Tile::SpriteType::End)
                        _tilesSystem->ReInit(component->GetNumber());
        
        int count = 0;
        for (auto item : children)
            if (auto component = GetComponent<Tile::TileComponent>(item, "TileComponent"); component)
            {
                if (auto itemTile = _tilesSystem->GetItem(component->GetNumber()))
                    if (itemTile->GetSpriteType() == Tile::SpriteType::End)
                        count++;
                component->Update();
            }
        if (count != 0)
            FallingBlocks();
    }
}
