#pragma once

#include <Windows.h>
#include <psapi.h>

#define CUBE_EXE_NAME "cubeworld.exe"

class MemoryHelper
{
public:
	static MODULEINFO GetModuleInfo(HMODULE module_handle)
	{
		MODULEINFO module_info;
		GetModuleInformation(GetCurrentProcess(), module_handle, &module_info, sizeof(MODULEINFO));
		return module_info;
	}

	static MODULEINFO GetModuleInfo(const char* module)
	{
		return GetModuleInfo(GetModuleHandle(module));
	}

	static uint64_t GetCubeBase()
	{
		static auto cube_info = GetModuleInfo(CUBE_EXE_NAME);
		return (uint64_t)cube_info.lpBaseOfDll;
	}

	static void PatchMemory(void* dst, void* src, uint64_t size)
	{
		DWORD OldProtection;
		if (VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &OldProtection))
		{
			memcpy(dst, src, size);
			VirtualProtect(dst, size, OldProtection, &OldProtection);
		}
	}

	template<class T>
	static void PatchMemory(void* dst, T src)
	{
		if (!dst) return;
		DWORD OldProtection;
		auto size = sizeof(T);
		if (VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &OldProtection))
		{
			memcpy(dst, &src, size);
			VirtualProtect(dst, size, OldProtection, &OldProtection);
		}
	}
};
