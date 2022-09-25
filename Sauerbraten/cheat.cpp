#include "includes.h"
#include "cheat.h"
#include "memory.h"

namespace cheat {
	void mainLoop();
	void openConsole();
	void getInstances();

	LocalPlayer* localPlayer;

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

		}
	}

	void openConsole() {
		AllocConsole();
		FILE* f;
		freopen_s(&f, "CONOUT$", "w", stdout);
	}
}