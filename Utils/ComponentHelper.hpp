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

namespace Match3Game::Utils
{
    template<class T, class... Args>
    T* Create(Args&&... args)
    {
        T *instance = new (std::nothrow) T(std::forward<Args>(args)...);
        if(instance && instance->init()) instance->autorelease();
        else if(instance) instance->autorelease();
        else CC_SAFE_DELETE(instance);
        return instance;
    }
}

#endif /* ComponentHelper_hpp */
