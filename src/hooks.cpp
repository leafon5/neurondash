#include "hooks.hpp"

bool (__thiscall* PlayLayer_init)(gd::PlayLayer* self, gd::GJGameLevel* level);
bool __fastcall PlayLayer_init_H(gd::PlayLayer* self, void*, gd::GJGameLevel* level) {
    if (!PlayLayer_init(self, level)) return false;

    auto sprite = CCSprite::create("dialogIcon_017.png");

    self->addChild(sprite);
    // ...
    std::cout << "LETS FUCKIN GOOOOO";

    return true;
} 

void Hooks::init() {
    
    MH_Initialize();

   
    MH_CreateHook(
        reinterpret_cast<void*>(gd::base + 0x1FB780),
        reinterpret_cast<void*>(&PlayLayer_init_H),
        reinterpret_cast<void**>(&PlayLayer_init) 
    );

    MH_EnableHook(MH_ALL_HOOKS);

}