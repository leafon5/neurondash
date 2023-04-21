#include "Player.hpp"

namespace neuron {

GJGameMode checkMode(gd::PlayerObject* player) {
    if (player->m_isShip) {
        return mSHIP;
    } else if (player->m_isBall) {
        return mBALL;
    } else if (player->m_isBird) {
        return mUFO;
    } else if (player->m_isDart) {
        return mWAVE;
    } else if (player->m_isRobot) {
        return mROBOT;
    } else if (player->m_isSpider) {
        return mSPIDER;
    } else {
        // default value if none of the conditions are true
        return mCUBE;
    }
}
GJPlayerGravity checkGrav(gd::PlayerObject* player) {
    if(player->m_isUpsideDown) {
        return gUPSIDE_DOWN;
    }
    return gNORMAL;
}   
GJPlayerSize checkSize(gd::PlayerObject* player) {
    if(player->m_vehicleSize == 1) {
        return sNORMAL;
    } 
    return sMINI;
}



// Define static member variables
// GJGameMode Player::gamemode;
// GJPlayerGravity Player::gravity;
// GJPlayerSize Player::size;
// std::vector<float*> Player::position;
// int Player::frame;
// bool Player::isGrounded;
// bool Player::isHolding;
// bool Player::isDead;
// gd::PlayerObject* Player::playerobj = nullptr;


Player::Player() {
}

void Player::init(gd::PlayerObject* player, gd::PlayLayer* layer, bool isMain) {
// i will optimize this i promise you
    this->playlayer = layer;
    this->isMain = isMain;
    this->isDead = &this->playlayer->m_isDead;
    this->playerobj = player;
    this->gamemode = checkMode(player);
    this->gravity = checkGrav(player);
    this->size = checkSize(player);
    this->speed = player->m_playerSpeed;
    this->y_acc = &player->m_yAccel;
    this->isGrounded = &player->m_isOnGround;
    this->isHolding = &player->m_isHolding;
    this->frame = 0;
}

void Player::update() {
    GJGameMode currentGM = checkMode(this->playerobj);
    GJPlayerGravity currentGV = checkGrav(this->playerobj);
    GJPlayerSize currentSZ = checkSize(this->playerobj);
    this->x = this->playerobj->m_position.x;
    this->y = this->playerobj->m_position.y;
    float currentSP = this->playerobj->m_playerSpeed;
    if(this->gamemode != currentGM) {
        this->gamemode = currentGM;
        // std::cout << "Gamemode changed to: " << GMToString(currentGM) << std::endl;
    }
    if(this->gravity != currentGV) {
        this->gravity = currentGV;
        // std::cout << "Gravity Changed to " << GVToString(currentGV) << std::endl;
    }
    if(this->size != currentSZ) {
        this->size = currentSZ;
        // std::cout << "Size changed to " << SZToString(currentSZ) << std::endl;
    }
    if(this->speed != currentSP) {
        this->speed = currentSP;
        // std::cout << "Speed changed to " << currentSP << std::endl; 
    }
    this->frame++;
}

void Player::onClick() {
    if(!this->isDead) {
        // ...
    }
}
void Player::onRelease() {
    if(!this->isDead) {
        // ...
    }
}

void Player::click() {
    this->playerobj->pushButton(1);
}
void Player::release() {
    this->playerobj->releaseButton(1);
}
}