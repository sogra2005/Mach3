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
#include "../Tile/Resources.hpp"
#include "../Utils/ComponentHelper.hpp"

namespace Match3Game::GameField
{
    using namespace cocos2d;

    FieldController::FieldController(cocos2d::Node *layer, const TilesSystemPtr& system)
    : _layer(layer), _tilesSystem(system), _selectItem(nullptr), _selectComponent(nullptr)
    {
        BindListener();
    }

    FieldController::~FieldController()
    {
        
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

//            /* Массив для записи спрайтов на "удаление" и переменная для количества записаных элементов в массив */
//            int list_blocks[_height * _width], sum_sprites = 0;
//            for (int i = 0; i < _width * _height; list_blocks[i] = 0, i++);
//
//            int *pSum_sprites = &sum_sprites;
//            /* Определение диапазона щелчков, определение того, содержит ли переданная координата объект, по которому щелкнули */
//            if (rect.containsPoint(locationInNode)) {
//                list_blocks[0] = target->getTag();
//                sum_sprites += 1;
//                Fiel_Analysis(target->getTag(), list_blocks, pSum_sprites, target->getColor());
//                Change_color(list_blocks, pSum_sprites);
//                FallingBlocks();
//                _scoreGame += sum_sprites;
//                UpdateScoreText();
//                return true;
//            }
//            return false;
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
        auto component = Utils::GetComponent<Tile::TileComponent>(sprite, "TileComponent");
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
        else
        {
            Swap(component, item);
            UnSelect(_selectComponent);
        }
//        else if (Adjacent().Contains(tile))
//        {
//            Swap(tile);
//            FindAllMatch(tile);
//            UnSelectTile(oldSelected);
//        }
//        else
//        {
//            UnSelect(_selectComponent);
//            Select(component, item);
//        }
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

//private List<Tile> Adjacent()
//{
//    List<Tile> tmpList = new List<Tile>();
//    for (var i = 0; i < dirRay.Length; i++)
//    {
//        var hit = Physics2D.Raycast(oldSelected.transform.position, dirRay[i]);
//        if (hit.collider)
//        {
//            tmpList.Add(hit.collider.gameObject.GetComponent<Tile>());
//        }
//    }
//    return tmpList;
//}
//
//private List<Tile> GetMatch(Tile tile, Vector2 vec)
//{
//    List<Tile> tmpList = new List<Tile>();
//    RaycastHit2D raycast = Physics2D.Raycast(tile.transform.position, vec);
//    while (raycast.collider && raycast.collider.gameObject.GetComponent<Tile>().spriteRenderer.sprite == tile.spriteRenderer.sprite)
//    {
//        tmpList.Add(raycast.collider.gameObject.GetComponent<Tile>());
//        raycast = Physics2D.Raycast(raycast.collider.gameObject.transform.position, vec);
//    }
//
//    return tmpList;
//}
//
//private void DelSprites(Tile tile, Vector2[] array)
//{
//    List<Tile> tmpList = new List<Tile>();
//
//    for (int i = 0; i < array.Length; i++)
//    {
//        tmpList.AddRange(GetMatch(tile, array[i]));
//    }
//
//    if (tmpList.Count >= 2)
//    {
//        for (var i = 0; i < tmpList.Count; i++)
//        {
//            tmpList[i].spriteRenderer.sprite = null;
//        }
//        isMatch = true;
//    }
//}
//
//private void FindAllMatch(Tile tile)
//{
//    if (!tile.spriteRenderer.sprite) return;
//
//    DelSprites(tile, new Vector2[] { Vector2.up, Vector2.down });
//    DelSprites(tile, new Vector2[] { Vector2.left, Vector2.right });
//
//    if (isMatch)
//    {
//        isMatch = false;
//        tile.spriteRenderer.sprite = null;
//    }
//}

}
