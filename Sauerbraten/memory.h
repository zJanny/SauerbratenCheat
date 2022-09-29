#pragma once

namespace memory {
	extern Entity* getLocalPlayer();
	extern int getPlayerCount();
	extern Entity* getEntityByID(int id);
	extern EntityList* getEntityList();
}