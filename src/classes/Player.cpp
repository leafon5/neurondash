#include "Player.hpp"


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


Player::Player(gd::PlayerObject* player, bool isMain) {
    this->playerobj = player;
    this->gamemode = checkMode(player);
    this->x = &player->m_position.x;
    this->y = &player->m_position.y;
    this->position = {x, y};
}
// Define member functions
void Player::GamemodeChange() {
    this->gamemode = checkMode(this->playerobj);
}

void Player::GravityChange() {
    if(this->playerobj->m_isUpsideDown) {
        this->gravity = gUPSIDE_DOWN;
        return;
    }
    this->gravity = gNORMAL;
    return;
}

void Player::SizeChange() {
    // Implementation
}

void Player::getPos() {
    // Implementation
}