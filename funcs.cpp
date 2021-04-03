#include "pch.h"

bool setRecoil(uintptr_t* recoilBuf, uint8_t isEnabled)
{
	auto result = false;
	DWORD dwProtect;

	if (VirtualProtect(reinterpret_cast<LPVOID>(recoil), 3, PAGE_EXECUTE_READWRITE, &dwProtect))
	{
		if (!hasHack(isEnabled, HackType::RECOIL))
		{
			auto recoilData = std::make_shared<ByteBuffer>();
			for (auto i = 0; i < 3; ++i)
				recoilData->data[i] = *reinterpret_cast<BYTE*>(recoil + i);
			*recoilBuf = reinterpret_cast<uintptr_t>(recoilData->data);
			memcpy(reinterpret_cast<BYTE*>(recoil), reinterpret_cast<BYTE*>(0x4622B4), 3); //0x4622B4 return address of recoil func (add it at the beginning to skip recoil)
		}
		else
		{
			for (auto i = 0; i < 3; ++i)
				*reinterpret_cast<BYTE*>(recoil + i) = *reinterpret_cast<BYTE*>(recoilBuf + i);
		}

		result = VirtualProtect(reinterpret_cast<LPVOID>(recoil), 3, dwProtect, &dwProtect);
	}
	return result;
}

bool hasHack(uint8_t type1, uint8_t type2)
{
	return (type1 & type2) == type2;
}