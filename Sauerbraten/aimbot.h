#pragma once

class Aimbot {
public:
	Aimbot(Entity* localPlayer);
	void doAimbot();
private:
	Entity* localPlayer;
	Entity* getTarget();
	float getDistance2D(Vector3 src, Vector3 dst);
	float getDistance3D(Vector3 src, Vector3 dst);
	Vector2 getAngle(Vector3 src, Vector3 dst);
	Vector3 subtractVector(Vector3 one, Vector3 two);
};