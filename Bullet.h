#pragma once

#include "Unit.h"

class Bullet : public Unit
{
public:
	Bullet();
	bool isFire;
public:
	void CalcNormal(float vertex[][3], float normal[]);
	void ReduceToUnit(float vector[]);
	void CalcFaceNormal();
	void CalcVertexNormal();
};