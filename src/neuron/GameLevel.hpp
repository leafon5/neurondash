#pragma once


#include "../includes.h"
#include <codecvt>
#include <locale>

#include "./playerproperties.hpp"


namespace neuron {
class GameLevel {
    public:
        void init(gd::GJGameLevel* level, bool isOfficial);
        std::string level;
        std::string decodeLevel(gd::string levelString)
    private:
        gd::string* levelString;
        bool isOfficial;

        GJGameMode gamemode; // kA2
        bool isMini; // kA3
        float speed; // kA4
        bool isDual; // kA8
        bool flipGravity; // kA11
};
}