#include "hookmain.hpp"

#include <matdash/minhook.hpp>

#include "classes/Player.hpp"
#include "playerproperties.hpp"

gd::GJGameLevel* gjlevel = nullptr;
gd::PlayLayer* playlayer = nullptr;
gd::PlayerObject* player_1 = nullptr;
gd::PlayerObject* player_2 = nullptr; 



const char* GJGameModeStrings[] = {"mCUBE", "mSHIP", "mBALL", "mUFO", "mWAVE", "mROBOT", "mSPIDER"};

bool inGame = false;
GJGameMode mode;
GJPlayerSize size;
GJPlayerGravity gravity;

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

bool PlayLayer_init(gd::PlayLayer* self, gd::GJGameLevel* level) {
    if (!matdash::orig<&PlayLayer_init>(self, level)) return false;
    inGame = true;
    std::cout << "PlayLayer on" << std::endl;
    gjlevel = level;
    playlayer = self;
    player_1 = self->m_player1;
    player_2 = self->m_player2;
    return true;
}

void PlayLayer_onQuit(gd::PlayLayer* self) {
    matdash::orig<&PlayLayer_onQuit, matdash::Thiscall>(self);
    inGame = false;
    std::cout << "PlayLayer off" << std::endl;
    gjlevel = nullptr;
    playlayer = nullptr;
    player_1 = nullptr;
    player_2 = nullptr;
}
//void PlayLayer_update_(gd::PlayLayer* self, float dt) {
    // another way of specifying the calling convention
//    matdash::orig<&PlayLayer_update_, matdash::Thiscall>(self, dt);
    // std::cout << "i pooped" << std::endl;
//}

void PlayerObject_toggleFlyMode(gd::PlayerObject* self, bool* toggle) {
    if(inGame) {
        mode = checkMode(player_1);
        std::cout << GJGameModeStrings[mode] << std::endl;
    }
    matdash::orig<&PlayerObject_toggleFlyMode, matdash::Thiscall>(self, toggle);
}
// void PlayerObject_toggleBirdMode(gd::PlayerObject* self, bool* toggle) {
//     matdash::orig<&PlayerObject_toggleBirdMode, matdash::Thiscall>(self, toggle);
//     if(toggle) {
//         std::cout << "Gamemode changed to UFO!" << std::endl;
//         mode = "UFO";
//     }
// }

// void PlayerObject_toggleRollMode(gd::PlayerObject* self, bool* toggle) {
//     matdash::orig<&PlayerObject_toggleRollMode, matdash::Thiscall>(self, toggle);
//     if(toggle) {
//         std::cout << "Gamemode changed to Ball!" << std::endl;
//         mode = "Ball";
//     }
// }
// void PlayerObject_toggleDartMode(gd::PlayerObject* self, bool* toggle) {
//     matdash::orig<&PlayerObject_toggleDartMode, matdash::Thiscall>(self, toggle);
//     if(toggle) {
//         std::cout << "Gamemode changed to Wave!" << std::endl;
//         mode = "Wave";
//     }
// }
// void PlayerObject_toggleRobotMode(gd::PlayerObject* self, bool* toggle) {
//     matdash::orig<&PlayerObject_toggleRobotMode, matdash::Thiscall>(self, toggle);
//     if(toggle) {
//         std::cout << "Gamemode changed to Robot!" << std::endl;
//         mode = "Robot";
//     }
// }
// void PlayerObject_toggleSpiderMode(gd::PlayerObject* self, bool* toggle) {
//     matdash::orig<&PlayerObject_toggleSpiderMode, matdash::Thiscall>(self, toggle);
//     if(toggle) {
//         std::cout << "Gamemode changed to Spider!" << std::endl;
//         mode = "Spider";
//     }
// }

auto cocos(const char* symbol) {
    static auto mod = GetModuleHandleA("libcocos2d.dll");
    return GetProcAddress(mod, symbol);
}

void Hooks::init() {
    matdash::add_hook<&PlayerObject_toggleFlyMode, matdash::Thiscall>(gd::base + 0x1F5E40);
    // matdash::add_hook<&PlayerObject_toggleBirdMode, matdash::Thiscall>(gd::base + 0x1F6050);
    // matdash::add_hook<&PlayerObject_toggleRollMode, matdash::Thiscall>(gd::base + 0x1F68E0);
    // matdash::add_hook<&PlayerObject_toggleDartMode, matdash::Thiscall>(gd::base + 0x1F62C0);
    // matdash::add_hook<&PlayerObject_toggleRobotMode, matdash::Thiscall>(gd::base + 0x1F6A10);
    // matdash::add_hook<&PlayerObject_toggleSpiderMode, matdash::Thiscall>(gd::base + 0x1F94D1);
    matdash::add_hook<&PlayLayer_onQuit, matdash::Thiscall>(gd::base + 0x20D810);
    matdash::add_hook<&PlayLayer_init>(gd::base + 0x1FB780);

//   matdash::add_hook<&PlayLayer_update_, matdash::Thiscall>(gd::base + 0x2029c0);

}