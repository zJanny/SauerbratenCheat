#pragma once

struct Vector3 {
	float x, y, z;
};

struct Vector2 {
	float x, y;
};

class LocalPlayer
{
public:
	Vector3 location; //0x0000
	char pad_000C[48]; //0x000C
	Vector2 viewAngle; //0x003C
	char pad_0044[316]; //0x0044
	int32_t health; //0x0180
	char pad_0184[44]; //0x0184
	int32_t pistolAmmo; //0x01B0
	char pad_01B4[660]; //0x01B4
}; //Size: 0x0448