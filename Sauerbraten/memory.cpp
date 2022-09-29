#include "includes.h"
#include "memory.h"

namespace offsets {
	uintptr_t localPlayer = 0x2A3528;
	uintptr_t entityList = 0x346C90;
	uintptr_t playerCount = 0xC;
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

	Entity* getLocalPlayer() {
		return *(Entity**)(getBaseAddress() + offsets::localPlayer);
	}

	Entity* getEntityByID(int id) {
		EntityList* list = *(EntityList**)(getPointerAddr(getBaseAddress() + offsets::entityList, {}));

		return list->entities[id];
	}

	EntityList* getEntityList() {
		return *(EntityList**)(getPointerAddr(getBaseAddress() + offsets::entityList, {}));
	}

	int getPlayerCount() {
		return *(int*)(getBaseAddress() + offsets::entityList + offsets::playerCount);
	}
	
}