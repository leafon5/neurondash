#include "playerproperties.hpp"

const char* GJGameModeStrings[] = {"mCUBE", "mSHIP", "mBALL", "mUFO", "mWAVE", "mROBOT", "mSPIDER"};
const char* GJPlayerGravityStrings[] = {"gNORMAL", "gUPSIDE_DOWN"};
const char* GJPlayerSizeStrings[] = {"sNORMAL", "sMINI"};

const char* neuron::GMToString(neuron::GJGameMode gamemode)  {
    if (gamemode < mCUBE || gamemode > mSPIDER) {
        return nullptr; // Invalid gamemode, return null
    }
    return GJGameModeStrings[gamemode];
}
const char* neuron::GVToString(neuron::GJPlayerGravity gv) {
    if (gv < gNORMAL || gv > gUPSIDE_DOWN) {
        return nullptr;
    }
    return GJPlayerGravityStrings[gv];
}
const char* neuron::SZToString(neuron::GJPlayerSize sz) {
    if (sz < sNORMAL || sz > sMINI) {
        return nullptr;
    }
    return GJPlayerSizeStrings[sz];
}
