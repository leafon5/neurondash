#pragma once

#include "../includes.h"

#include "./playerproperties.hpp"
#include "utils.hpp"


namespace neuron {
class GameLevel {
    public:
        GameLevel(gd::GJGameLevel* level, bool isOfficial);
        std::string level;
        void decodeLevel(gd::string levelString);
    private:
        bool isOfficial;

        GJGameMode gamemode; // kA2
        bool isMini; // kA3
        float speed; // kA4
        bool isDual; // kA8
        bool flipGravity; // kA11
};
}