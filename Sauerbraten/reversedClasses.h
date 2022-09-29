#pragma once

struct Vector3 {
	float x, y, z;
};

struct Vector2 {
	float x, y;
};

class Entity
{
public:
	Vector3 location; //0x0000
	char pad_000C[48]; //0x000C
	Vector2 viewAngle; //0x003C
	char pad_0044[228]; //0x0044
	int32_t alive; //0x0128
	char pad_012C[76]; //0x012C
	int32_t health; //0x0178
	char pad_017C[4]; //0x017C
	int32_t armor; //0x0180
	char pad_0184[500]; //0x0184
	char team[4]; //0x0378
	char pad_037C[192]; //0x037C
}; //Size: 0x043C

struct EntityList {
	Entity* entities[32];
};	