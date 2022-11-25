#pragma once
#include <math.h>

#define WIRE_FRAME			1
#define FLAT_SHADING		2
#define SMOOTH_SHADING		3
#define CLOCKWISE			4
#define COUNTER_CLOCKWISE	5

struct Vertex
{
	float x;
	float y;
	float z;
};

struct Index
{
	int Count;
	int List[30];
	float Red;
	float Green;
	float Blue;
};

struct Vector3
{
	float x;
	float y;
	float z;
};

class Unit
{
public:
	Vertex m_Vertex[6000];
	Index m_FaceIndex[5000];
	float m_fAmbientLight[4];
	float m_fDiffuseLight[4];
	float m_fSpecularLight[4];
	float m_fAmbientMat[4];
	float m_fDiffuseMat[4];
	float m_fSpecularMat[4];
	float m_fLightPos[4];
	float m_fFaceNormal[5000][3];
	float m_fVertexNormal[6000][3];
	int m_nCountVertex;
	int m_nCountFace;
	int m_nCountEdge;
	int m_nShine;
	int m_nWinding;
	int m_nDisplayMode;

public:
	int nHP;
	bool bDie;
	float fMoveSpeed;
	Vector3 vPosition;
	Vector3 vRotate;
	Vector3 vCollider;
	enum MOVEDIRECT dir;

public:
	virtual void CalcNormal(float vertex[][3], float normal[]) { }
	virtual void ReduceToUnit(float vector[]) { }
	virtual void CalcFaceNormal() { }
	virtual void CalcVertexNormal() { }
};