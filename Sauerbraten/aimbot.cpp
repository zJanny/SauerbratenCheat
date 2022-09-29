#include "includes.h"
#include "memory.h"
#include "aimbot.h"

#define PI 3.14159265358979323846

Aimbot::Aimbot(Entity* localPlayer) {
	this->localPlayer = localPlayer;
}

float Aimbot::getDistance2D(Vector3 src, Vector3 dst) {
	return sqrtf(powf(dst.x - src.x, 2.0f) + powf(dst.y - src.y, 2.0f));
}

float Aimbot::getDistance3D(Vector3 src, Vector3 dst) {
	return sqrtf(powf(dst.x - src.x, 2.0f) + powf(dst.y - src.y, 2.0f) + powf(dst.z - src.z, 2.0f));
}

Vector2 Aimbot::getAngle(Vector3 src, Vector3 dst) {
	Vector2 angle;
	angle.x = -atan2f(dst.x - src.x, dst.y - src.y) / PI * 180.0f;
	angle.y = asinf((dst.z - src.z) / getDistance2D(src, dst)) * 180.0f / PI;
	return angle;
}

Entity* Aimbot::getTarget() {
	Entity* target = nullptr;
	float lastDistance = 9999999999999999999999.0f;

	for (int i = 1; i < memory::getPlayerCount(); i++) {
		Entity* ent = memory::getEntityByID(i);

		if (localPlayer->team == ent->team || !ent->alive) {
			continue;
		}
		float dist = getDistance3D(localPlayer->location, ent->location);
		if (dist < lastDistance) {
			lastDistance = dist;
			target = ent;
		}

	}
	return target;
}

void Aimbot::doAimbot() {
	Entity* target = getTarget();
	localPlayer->viewAngle = getAngle(localPlayer->location, target->location);

}