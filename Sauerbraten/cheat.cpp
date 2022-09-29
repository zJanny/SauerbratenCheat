#include "includes.h"
#include "cheat.h"
#include "memory.h"
#include "aimbot.h"

namespace cheat {
	void mainLoop();
	void openConsole();
	void getInstances();

	Entity* localPlayer;
	Aimbot* aimbot;

	void initCheat() {
		openConsole();
		getInstances();
		mainLoop();
	}

	void getInstances() {
		localPlayer = memory::getLocalPlayer();
		aimbot = new Aimbot(localPlayer);
	}

	void mainLoop() {
		while (true) {
			if (GetAsyncKeyState(VK_RBUTTON)) {
				aimbot->doAimbot();
			}
		}
	}

	void openConsole() {
		AllocConsole();
		FILE* f;
		freopen_s(&f, "CONOUT$", "w", stdout);
	}
}