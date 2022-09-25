#pragma once

struct Vector3 {
	float x, y, z;
};

class LocalPlayer
{
public:
	Vector3 location; //0x0000
	char pad_000C[352]; //0x000C
	int32_t health; //0x016C
	char pad_0170[711]; //0x0170
}; //Size: 0x0437