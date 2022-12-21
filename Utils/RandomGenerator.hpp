//
//  RandomGenerator.hpp
//  Mach3Game
//
//  Created by Alexandr.B on 22.12.2022.
//

#ifndef RandomGenerator_hpp
#define RandomGenerator_hpp

namespace Match3Game::Utils
{
    class RandomGenerator
    {
    public:
        static const int GetRandomInt(int start, int end);
    };
}

#endif /* RandomGenerator_hpp */
