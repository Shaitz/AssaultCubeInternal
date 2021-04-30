#pragma once
#include "vector.h"

inline std::uintptr_t FnWglSwapBuffers = reinterpret_cast<std::uintptr_t>(GetProcAddress(GetModuleHandle("opengl32.dll"), "wglSwapBuffers"));
inline std::uintptr_t moduleBase = reinterpret_cast<std::uintptr_t>(GetModuleHandle("ac_client.exe"));
inline std::uintptr_t recoil = 0x462020;
inline DWORD traceLine = 0x048a310;

enum HackType : uint8_t
{
	NO_HACK			= 0x00,
	RECOIL			= 0x01,
	FLY			= 0x02,
	NO_CLIP			= 0x04,
	INVINCIBLE		= 0x08,
	INFINITE_AMMO		= 0x10
};

struct ByteBuffer final
{
	BYTE data[32];
};

class player
{
public:
	char pad_0000[4]; //0x0000
	Vector3 headPos; //0x0004
	char pad_0010[36]; //0x0010
	Vector3 pos; //0x0034
	Vector2 angles; //0x0040
	char pad_0048[58]; //0x0048
	int8_t noclip; //0x0082
	int8_t inv; //0x0083
	char pad_0084[8]; //0x0084
	int8_t movingLeft; //0x008C
	int8_t movingRight; //0x008D
	int8_t movingForward; //0x008E
	int8_t movingBackwards; //0x008F
	char pad_0090[104]; //0x0090
	int32_t health; //0x00F8
	char pad_00FC[84]; //0x00FC
	int32_t arAmmo; //0x0150
	char pad_0154[484]; //0x0154
	int8_t spectate; //0x0338
	char pad_0339[59]; //0x0339
	class playerInventory* playerInventoryPtr; //0x0374
	char pad_0378[52]; //0x0378
}; //Size: 0x03AC

class guns
{
public:
	char pad_0000[12]; //0x0000
	class ar* ar; //0x000C
	char pad_0010[4]; //0x0010
	class curweap* currweap; //0x0014
	char pad_0018[32]; //0x0018
}; //Size: 0x0038

class curweap
{
public:
	int32_t curammo; //0x0000
	char pad_0004[32]; //0x0004
}; //Size: 0x0024

class ar
{
public:
	char pad_0000[280]; //0x0000
	int32_t maxARammo; //0x0118
	char pad_011C[24]; //0x011C
}; //Size: 0x0134

class playerInventory
{
public:
	char pad_0000[8]; //0x0000
	class player* weapOwnerPtr; //0x0008
	char pad_000C[8]; //0x000C
	class curWeapon* curWeaponPtr; //0x0014
	char pad_0018[36]; //0x0018
}; //Size: 0x003C

class curWeapon
{
public:
	int32_t curAmmo; //0x0000
	char pad_0004[80]; //0x0004
}; //Size: 0x0054

class ent // ac_client.exe + 10f4f8 (first 4 bytes 0 array starts at 4)
{
public:
	std::vector<player*> entityList;
};