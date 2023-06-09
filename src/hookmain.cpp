#include "hookmain.hpp"

#include <matdash/minhook.hpp>


neuron::Player* player_1 = nullptr;
neuron::Player* player_2 = nullptr; 
// neuron::GameLevel* nlevel = nullptr;


bool inGame = false;

bool PlayLayer_init(gd::PlayLayer* self, gd::GJGameLevel* level) {
    if (!matdash::orig<&PlayLayer_init>(self, level)) return false;
    inGame = true;
    std::cout << "PlayLayer " << (inGame ? "on" : "off") << std::endl;
    std::cout << "GD BASE: " << &gd::base << std::endl;
    std::cout << "playlayer addr:"<< &self << std::endl;
    // delete nlevel;
    // nlevel = nullptr;

    // std::cout << "new gamelevel" << std::endl;
    // nlevel = new neuron::GameLevel(level, true);

    return true;
}

// now the onquit doesnt want to hook????????
void PlayLayer_onQuit(gd::PlayLayer* self) {
    inGame = false;
    std::cout << "PlayLayer " << (inGame ? "on" : "off") << std::endl;
    
    delete player_1;
    delete player_2;
    // delete nlevel;

    player_1 = nullptr;
    player_2 = nullptr;
    // nlevel = nullptr;

    // if(nlevel) {
    //     std::cout << "GAMELEVEL NOT DELETED, MEMORY LEAK LOL" << std::endl;
    // }
    // else if(!nlevel) {
    //     std::cout << "deleted lol" << std::endl;
    // }
    matdash::orig<&PlayLayer_onQuit, matdash::Thiscall>(self);

    // std::cout << nlevel << std::endl;
}

void PlayLayer_resetLevel(gd::PlayLayer* self) {
    matdash::orig<&PlayLayer_resetLevel, matdash::Thiscall>(self);
    std::cout << "Level reset" << std::endl;

    delete player_1;
    delete player_2;

    player_1 = nullptr;
    player_2 = nullptr;

    player_1 = new neuron::Player();
    player_2 = new neuron::Player();

    player_1->init(self->m_player1, self, true);
    player_2->init(self->m_player2, self, false);
}
void PlayLayer_pushButton(gd::PlayLayer* self, int idk, bool button) {
    player_1->onClick();
    matdash::orig<&PlayLayer_pushButton>(self, idk, button);
}
void PlayLayer_releaseButton(gd::PlayLayer* self, int idk, bool button) {
    player_1->onRelease();
    matdash::orig<&PlayLayer_releaseButton>(self, idk, button);
}
matdash::cc::thiscall<void> PlayLayer_Update(gd::PlayLayer* self, float dt) {
    matdash::orig<&PlayLayer_Update>(self, dt);
    player_2->update();
    player_1->update();
    return {};
}
auto cocos(const char* symbol) {
    static auto mod = GetModuleHandleA("libcocos2d.dll");
    return GetProcAddress(mod, symbol);
}

void Hooks::init() {
    matdash::add_hook<&PlayLayer_onQuit, matdash::Thiscall>(gd::base + 0x20D810);
    matdash::add_hook<&PlayLayer_init>(gd::base + 0x1FB780);
    matdash::add_hook<&PlayLayer_resetLevel>(gd::base + 0x20BF00);
//   matdash::add_hook<&PlayLayer_update_, matdash::Thiscall>(gd::base + 0x2029c0);
    matdash::add_hook<&PlayLayer_Update>(gd::base + 0x2029C0);

    // perhaps?
    
    matdash::add_hook<&PlayLayer_pushButton>(gd::base + 0x111500);
    matdash::add_hook<&PlayLayer_releaseButton>(gd::base + 0x111660);

}