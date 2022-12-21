//
//  RandomGenerator.cpp
//  Mach3Game
//
//  Created by Alexandr.B on 22.12.2022.
//

#include "RandomGenerator.hpp"

#include <cstdlib>
#include <random>

namespace Match3Game::Utils
{
    const int RandomGenerator::GetRandomInt(int start, int end)
    {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(start, end);
        int x = distribution(generator);
        return x;
    }
}
