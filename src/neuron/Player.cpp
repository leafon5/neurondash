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

void Player::init(gd::PlayerObject* player, bool isMain) {
    this->isMain = isMain;
    this->playerobj = player;
    this->gamemode = checkMode(player);
    this->gravity = checkGrav(player);
    this->size = checkSize(player);
    this->speed = player->m_playerSpeed;
    this->x = &player->m_position.x;
    this->y = &player->m_position.y;
    this->position = {x, y};
}
// Define member functions

void Player::update() {
    GJGameMode currentGM = checkMode(this->playerobj);
    GJPlayerGravity currentGV = checkGrav(this->playerobj);
    GJPlayerSize currentSZ = checkSize(this->playerobj);
    float currentSP = this->playerobj->m_playerSpeed;
    if(this->gamemode != currentGM) {
        this->gamemode = currentGM;
        std::cout << "Gamemode changed to: " << GMToString(currentGM) << std::endl;
    }
    if(this->gravity != currentGV) {
        this->gravity = currentGV;
        std::cout << "Gravity Changed to " << GVToString(currentGV) << std::endl;
    }
    if(this->size != currentSZ) {
        this->size = currentSZ;
        std::cout << "Size changed to " << SZToString(currentSZ) << std::endl;
    }
    if(this->speed != currentSP) {
        this->speed = currentSP;
        std::cout << "Speed changed to " << currentSP << std::endl; 
    }
}

void Player::getPos() {
    // Implementation
}


}