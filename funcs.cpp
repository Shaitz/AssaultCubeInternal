#include "pch.h"

bool setRecoil()
{
	auto result = false;
	DWORD dwProtect;

	if (VirtualProtect(reinterpret_cast<LPVOID>(recoil), 3, PAGE_EXECUTE_READWRITE, &dwProtect))
	{
		memcpy(reinterpret_cast<BYTE*>(recoil), reinterpret_cast<BYTE*>(0x4622B4), 3); //0x4622B4 return address of recoil func (add it at the beginning to skip recoil)
		result = VirtualProtect(reinterpret_cast<LPVOID>(recoil), 3, dwProtect, &dwProtect);
	}
	return result;
}