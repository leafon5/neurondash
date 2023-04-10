#pragma once
#include "../includes.h"
#include <vector>

#include "../playerproperties.hpp"

class Player {
    public:
        Player(gd::PlayerObject* player, bool isMain);
        static GJGameMode gamemode;
        static GJPlayerGravity gravity;
        static GJPlayerSize size;
        static std::vector<float*> position;
        static int frame;
        static bool isGrounded;
        static bool isHolding;
        static bool isDead;

        void GamemodeChange();
        void GravityChange();
        void SizeChange();
        void getPos();
    private:
        static gd::PlayerObject* playerobj;
        static bool isMain;
        static float* y;
        static float* x;
        static float* y_acc;
        static float* unk6A4[200];
}