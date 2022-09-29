#include "includes.h"
#include "memory.h"

namespace offsets {
	uintptr_t localPlayer = 0x2A3528;
}

namespace memory {
	uintptr_t getBaseAddress() {
		return (uintptr_t)GetModuleHandle(NULL);
	}

	uintptr_t getPointerAddr(uintptr_t ptr, std::vector<unsigned int> offsets) {
		uintptr_t addr = ptr;

		for (unsigned int i = 0; i < offsets.size(); ++i) {
			addr = *(uintptr_t*)addr;
			addr += offsets[i];
		}

		return addr;
	}

	LocalPlayer* getLocalPlayer() {
		return *(LocalPlayer**)(getBaseAddress() + offsets::localPlayer);
	}
	
}