#pragma once

#include "Unit.h"
class Enemy : public Unit
{
public:
	Enemy();
	bool isSpawn;
	int hp;
public:
	void CalcNormal(float vertex[][3], float normal[]);
	void ReduceToUnit(float vector[]);
	void CalcFaceNormal();
	void CalcVertexNormal();
};