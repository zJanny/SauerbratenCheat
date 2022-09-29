#include "includes.h"
#include "cheat.h"
#include "memory.h"
#include "reversedClasses.h"

namespace cheat {
	void mainLoop();
	void openConsole();
	void getInstances();

	Entity* localPlayer;

	void initCheat() {
		openConsole();
		getInstances();
		mainLoop();
	}

	void getInstances() {
		localPlayer = memory::getLocalPlayer();
	}

	void mainLoop() {
		while (true) {
			std::cout << "Player count: " << memory::getPlayerCount() << std::endl;
			EntityList* entityList = memory::getEntityList();
			for (int i = 0; i < memory::getPlayerCount(); i++) {
				std::cout << "Player: " << i << " Health: " << entityList->entities[i]->health << std::endl;
			}
			Sleep(500);
		}
	}

	void openConsole() {
		AllocConsole();
		FILE* f;
		freopen_s(&f, "CONOUT$", "w", stdout);
	}
}