//
//  ComponentHelper.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 21.12.2022.
//

#ifndef ComponentHelper_hpp
#define ComponentHelper_hpp

#include <new>
#include <utility>
#include <type_traits>
#include <functional>
#include <cassert>
#include <memory>

#include "cocos2d.h"

namespace Match3Game::Utils
{
    using namespace cocos2d;

    template<class T, class... Args>
    T* CreateComponent(Args&&... args)
    {
        T *component = new (std::nothrow) T(std::forward<Args>(args)...);
        if(component && component->init()) component->autorelease();
        else if(component) component->autorelease();
        return component;
    }

    template<typename E, typename T>
    auto Convert(T* component)
    {
        using C = std::conditional_t<std::is_const_v<std::remove_pointer_t<std::remove_reference_t<decltype(component)>>>,const E,E>;
        return static_cast<C*>(component);
    }

    template<typename T>
    T* GetComponent(cocos2d::Node *node, const std::string& componentName)
    {
        return Convert<T>(node->getComponent(componentName));
    }
}

#endif /* ComponentHelper_hpp */
