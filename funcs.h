#pragma once
#include "pch.h"

inline std::list<std::shared_ptr<ByteBuffer>> ByteBuffers;

extern bool setRecoil(std::uintptr_t* recoilBuf, std::uint8_t isEnabled);
extern bool isHackEnabled(std::uint8_t type1, std::uint8_t type2);
extern bool toggleHack(std::uint8_t* type1, std::uint8_t type2);