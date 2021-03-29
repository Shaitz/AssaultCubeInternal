#include "pch.h"

std::int32_t __stdcall enableCheats(HDC hDc)
{
    const auto localPlayer = *reinterpret_cast<player**>(moduleBase + 0x10f4f4);

    if (localPlayer)
    {
        localPlayer->health = 2000;
        localPlayer->playerInventoryPtr->curWeaponPtr->curAmmo = 2000;
    }
    return FpWglSwapBuffers(hDc);
}

DWORD WINAPI hackThread(LPVOID param)
{
    AllocConsole();
    SetConsoleTitle("AC hack");
    FILE* stream;
    freopen_s(&stream, "CONOUT$", "w", stdout);

    if (MH_Initialize() == MH_OK)
    {
        if (MH_CreateHook(reinterpret_cast<LPVOID>(FnWglSwapBuffers), &enableCheats, reinterpret_cast<LPVOID*>(&FpWglSwapBuffers)) == MH_OK)
            MH_EnableHook(reinterpret_cast<LPVOID>(FnWglSwapBuffers));
        else
            return -1;
    }
    while (1 & !GetAsyncKeyState(VK_NUMPAD0))
        Sleep(1);

#if _DEBUG
    const auto conHandle = GetConsoleWindow();
    FreeConsole();
    PostMessage(conHandle, WM_CLOSE, 0, 0);
#endif
    MH_DisableHook(reinterpret_cast<LPVOID> (FnWglSwapBuffers));
    MH_Uninitialize();
    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(param), NULL);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    DisableThreadLibraryCalls(hModule);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(hackThread), hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

