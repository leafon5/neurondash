#include "hookmain.hpp"

#include <matdash/minhook.hpp>


gd::GJGameLevel* gjlevel = nullptr;
gd::PlayLayer* playlayer = nullptr;
neuron::Player* player_1 = nullptr;
neuron::Player* player_2 = nullptr; 




bool inGame = false;

bool PlayLayer_init(gd::PlayLayer* self, gd::GJGameLevel* level) {
    if (!matdash::orig<&PlayLayer_init>(self, level)) return false;
    inGame = true;
    std::cout << "PlayLayer " << (inGame ? "on" : "off") << std::endl;
    gjlevel = level;
    playlayer = self;
    return true;
}

void PlayLayer_onQuit(gd::PlayLayer* self) {
    matdash::orig<&PlayLayer_onQuit, matdash::Thiscall>(self);
    inGame = false;
    std::cout << "PlayLayer " << (inGame ? "on" : "off") << std::endl;
    gjlevel = nullptr;
    playlayer = nullptr;
    
    delete player_1;
    delete player_2;

    player_1 = nullptr;
    player_2 = nullptr;
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

    player_1->init(self->m_player1, true);
    player_2->init(self->m_player2, false);
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


}