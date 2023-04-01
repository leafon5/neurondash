#include "hooks.hpp"

#include <matdash/minhook.hpp>

gd::GJGameLevel* thelevel;

std::string mode;

void PlayLayer_init(gd::PlayLayer* self, gd::GJGameLevel* level) {
    matdash::orig<&PlayLayer_init, matdash::Thiscall>(self, level);
    thelevel = level;
}
//void PlayLayer_update_(gd::PlayLayer* self, float dt) {
    // another way of specifying the calling convention
//    matdash::orig<&PlayLayer_update_, matdash::Thiscall>(self, dt);
    // std::cout << "i pooped" << std::endl;
//}

void PlayerObject_toggleFlyMode(gd::PlayerObject* self, bool* toggle) {
    matdash::orig<&PlayerObject_toggleFlyMode, matdash::Thiscall>(self, toggle);
    if(toggle) {
        std::cout << "Gamemode changed to ship!" << std::endl;
        mode = "Ship";
    }
}
void PlayerObject_toggleBirdMode(gd::PlayerObject* self, bool* toggle) {
    matdash::orig<&PlayerObject_toggleBirdMode, matdash::Thiscall>(self, toggle);
    if(toggle) {
        std::cout << "Gamemode changed to UFO!" << std::endl;
        mode = "UFO";
    }
}

void PlayerObject_toggleRollMode(gd::PlayerObject* self, bool* toggle) {
    matdash::orig<&PlayerObject_toggleRollMode, matdash::Thiscall>(self, toggle);
    if(toggle) {
        std::cout << "Gamemode changed to Ball!" << std::endl;
        mode = "Ball";
    }
}
void PlayerObject_toggleDartMode(gd::PlayerObject* self, bool* toggle) {
    matdash::orig<&PlayerObject_toggleDartMode, matdash::Thiscall>(self, toggle);
    if(toggle) {
        std::cout << "Gamemode changed to Wave!" << std::endl;
        mode = "Wave";
    }
}
void PlayerObject_toggleRobotMode(gd::PlayerObject* self, bool* toggle) {
    matdash::orig<&PlayerObject_toggleRobotMode, matdash::Thiscall>(self, toggle);
    if(toggle) {
        std::cout << "Gamemode changed to Robot!" << std::endl;
        mode = "Robot";
    }
}
void PlayerObject_toggleSpiderMode(gd::PlayerObject* self, bool* toggle) {
    matdash::orig<&PlayerObject_toggleSpiderMode, matdash::Thiscall>(self, toggle);
    if(toggle) {
        std::cout << "Gamemode changed to Spider!" << std::endl;
        mode = "Spider";
    }
}



void Hooks::init() {
    matdash::add_hook<&PlayerObject_toggleFlyMode, matdash::Thiscall>(gd::base + 0x1F5E40);
    matdash::add_hook<&PlayerObject_toggleBirdMode, matdash::Thiscall>(gd::base + 0x1F6050);
    matdash::add_hook<&PlayerObject_toggleRollMode, matdash::Thiscall>(gd::base + 0x1F68E0);
    matdash::add_hook<&PlayerObject_toggleDartMode, matdash::Thiscall>(gd::base + 0x1F62C0);
    matdash::add_hook<&PlayerObject_toggleRobotMode, matdash::Thiscall>(gd::base + 0x1F6A10);
    matdash::add_hook<&PlayerObject_toggleSpiderMode, matdash::Thiscall>(gd::base + 0x1F94D1);
    matdash::add_hook<&PlayLayer_init, matdash::Thiscall>(gd::base + 0x1FB780);
//   matdash::add_hook<&PlayLayer_update_, matdash::Thiscall>(gd::base + 0x2029c0);

}