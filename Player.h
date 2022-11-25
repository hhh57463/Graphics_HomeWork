#pragma once

#include "Unit.h"
#include "Bullet.h"

class Player : public Unit
{
public:
	Player();
public:
	Bullet bullet[BULLET_COUNT];
	int bulletIdx;
public:
	void CalcNormal(float vertex[][3], float normal[]);
	void ReduceToUnit(float vector[]);
	void CalcFaceNormal();
	void CalcVertexNormal();
};