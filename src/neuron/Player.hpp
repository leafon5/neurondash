#pragma once
#include <vector>

#include "../includes.h"

#include "./playerproperties.hpp"

namespace neuron {
class Player {
    public:
             Player();
             GJGameMode gamemode;
             GJPlayerGravity gravity;
             GJPlayerSize size;
             std::vector<float*> position;
             float speed;
             int frame;
             bool isGrounded;
             bool isHolding;
             bool isDead;
            void init(gd::PlayerObject* player, bool isMain);
            void update();
            void GamemodeChange();
            void GravityChange();
            void SizeChange();
            void getPos();
        private:
             gd::PlayerObject* playerobj;
             bool isMain;
             float* y;
             float* x;
             float* y_acc;
                         //             float* unk6A4[200];
    };
}