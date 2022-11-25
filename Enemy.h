#pragma once

#include "Unit.h"
class Enemy : public Unit
{
public:
	Enemy();
public:
	void CalcNormal(float vertex[][3], float normal[]);
	void ReduceToUnit(float vector[]);
	void CalcFaceNormal();
	void CalcVertexNormal();
};