#pragma once

namespace neuron {
    enum GJGameMode {
        mCUBE,
        mSHIP,
        mBALL,
        mUFO,
        mWAVE,
        mROBOT,
        mSPIDER
    };

    enum GJPlayerSize {
        sNORMAL,
        sMINI
    };

    enum GJPlayerGravity {
        gNORMAL,
        gUPSIDE_DOWN
    };

    const char* GMToString(GJGameMode gamemode);
    const char* GVToString(GJPlayerGravity gv);
    const char* SZToString(GJPlayerSize sz);
}
