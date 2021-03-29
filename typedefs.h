#pragma once
#include "pch.h"

typedef std::int32_t(__stdcall* oWglSwapBuffers)(HDC);

inline oWglSwapBuffers FpWglSwapBuffers = nullptr;