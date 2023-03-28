#include "includes.h"
#include "hooks.hpp"

DWORD WINAPI thread_func(void* hModule) {

    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    freopen("CONIN$", "r", stdin);
    
    Hooks::init();
    
    std::string line;
    std::getline(std::cin, line);


    FreeConsole();
    FreeLibraryAndExitThread(static_cast<HMODULE>(hModule), 0);

    return 0;
}

BOOL APIENTRY DLLMain(HMODULE module, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        auto h = CreateThread(0, 0, thread_func, module, 0, 0);
        if (h)
            CloseHandle(h);
        else
            return FALSE;
    }
    return TRUE;
}