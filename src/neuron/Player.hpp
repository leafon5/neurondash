#pragma once

#include "../includes.h"

#include "./playerproperties.hpp"

namespace neuron {
class Player {
    public:
            Player();
            GJGameMode gamemode;
            GJPlayerGravity gravity;
            GJPlayerSize size;
            cocos2d::CCPoint* position;
            float speed;
            int frame;
            bool* isGrounded;
            bool* isHolding;
            bool* isDead;
            void init(gd::PlayerObject* player, gd::PlayLayer* layer, bool isMain);
            void update();
            void GamemodeChange();
            void GravityChange();
            void SizeChange();
            void getPos();
            void onClick();
            void onRelease();
            void click();
            void release();
        private:
            gd::PlayLayer* playlayer;
            gd::PlayerObject* playerobj;
            bool isMain;
            float y;
            float x;
            double* y_acc;
                         //             float* unk6A4[200];
    };
}