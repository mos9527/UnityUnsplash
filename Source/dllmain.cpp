#include "pch.h"
// Signatures
SIG_SCAN
(
    sigSetSplashScreenState,
    0x180000000,
    "\x40\x57\x48\x83\xEC\x20\x48\x8B\x05\x00\x00\x00\x00\x8B\xF9\x39\x48\x08\x0F\x84\x00\x00\x00\x00\x48\x89\x5C\x24\x00\x33\xDB\x89\x48\x08\x39\x1D\x00\x00\x00\x00\x48\x89\x6C\x24\x00\x48\x8D\x2D\x00\x00\x00\x00\x48\x89\x2D\x00\x00\x00\x00\x76\x57\x48\x89\x74\x24\x00\x48\x8D\x35\x00\x00\x00\x00\x0F\x1F\x80\x00\x00\x00\x00", 
    "xxxxxxxxx????xxxxxxx????xxxx?xxxxxxx????xxxx?xxx????xxx????xxxxxx?xxx????xxx????"
)
SIG_SCAN
(
    sigRenderOverlays,
    0x180000000,
    "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\xF9\xE8\x00\x00\x00\x00\x48\x8B\xC8\x48\x8B\xD8\x48\x8B\x10\xFF\x92\x00\x00\x00\x00\x4C\x8B\x03\x33\xD2\x48\x8B\xCB\x0F\xB6\xF0\x41\xFF\x90\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x74\x04\x8B\xCF\xFF\xD0\x85\xFF",
    "xxxx?xxxx?xxxxxxxx????xxxxxxxxxxx????xxxxxxxxxxxxxx????xxx????xxxxxxxxxxx"
)
HOOK(void, __fastcall, _SetSplashScreenState, sigSetSplashScreenState(), int state) {
    original_SetSplashScreenState(3); 
}
HOOK(__int64, __fastcall, _RenderOverlays, sigRenderOverlays(), int a1) {
    return original_RenderOverlays(1);
}
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
#ifdef _DEBUG
        AllocConsole();
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);        
#endif
        INSTALL_HOOK(_SetSplashScreenState);
        INSTALL_HOOK(_RenderOverlays);
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
