#pragma once

#include "Unit.h"
#include "Bullet.h"

class Player : public Unit
{
public:
	Player();
public:
	Bullet bullet[30];
	int bulletIdx;
public:
	void CalcNormal(float vertex[][3], float normal[]);
	void ReduceToUnit(float vector[]);
	void CalcFaceNormal();
	void CalcVertexNormal();
};