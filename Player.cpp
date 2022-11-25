#include "pch.h"
#include "Player.h"

Player::Player()
{
	m_nDisplayMode = SMOOTH_SHADING;
	m_nWinding = COUNTER_CLOCKWISE;
	m_fAmbientLight[0] = 0.1f;
	m_fAmbientLight[1] = 0.1f;
	m_fAmbientLight[2] = 0.1f;
	m_fAmbientLight[3] = 1.0f;

	m_fDiffuseLight[0] = 1.0f;
	m_fDiffuseLight[1] = 1.0f;
	m_fDiffuseLight[2] = 1.0f;
	m_fDiffuseLight[3] = 1.0f;

	m_fSpecularLight[0] = 1.0f;
	m_fSpecularLight[1] = 1.0f;
	m_fSpecularLight[2] = 1.0f;
	m_fSpecularLight[3] = 1.0f;

	m_fAmbientMat[0] = 0.1f;
	m_fAmbientMat[1] = 0.1f;
	m_fAmbientMat[2] = 0.1f;
	m_fAmbientMat[3] = 0.1f;

	m_fSpecularMat[0] = 0.5f;
	m_fSpecularMat[1] = 0.5f;
	m_fSpecularMat[2] = 0.5f;
	m_fSpecularMat[3] = 1.0f;

	m_fDiffuseMat[0] = 1.0f;
	m_fDiffuseMat[1] = 1.0f;
	m_fDiffuseMat[2] = 1.0f;
	m_fDiffuseMat[3] = 1.0f;

	m_fLightPos[0] = -50;
	m_fLightPos[1] = 50;
	m_fLightPos[2] = 100;
	m_fLightPos[3] = 1;

	m_nShine = 64;

	vPosition.x = 0.0f;
	vPosition.y = -100.0f;
	vPosition.z = 0.0f;

	vRotate.x = 90.0f;
	vRotate.y = 0.0f;
	vRotate.z = 0.0f;

	vCollider.x = 5;
	vCollider.y = 5;
	vCollider.z = 5;

	bulletIdx = 0;

	fMoveSpeed = 5.0f;

	bDie = FALSE;
}

void Player::CalcNormal(float vertex[][3], float normal[])
{
	float vertex1[3], vertex2[3];

	vertex1[0] = vertex[0][0] - vertex[1][0];
	vertex1[1] = vertex[0][1] - vertex[1][1];
	vertex1[2] = vertex[0][2] - vertex[1][2];

	vertex2[0] = vertex[1][0] - vertex[2][0];
	vertex2[1] = vertex[1][1] - vertex[2][1];
	vertex2[2] = vertex[1][2] - vertex[2][2];

	normal[0] = vertex1[1] * vertex2[2] - vertex1[2] * vertex2[1];
	normal[1] = vertex1[2] * vertex2[0] - vertex1[0] * vertex2[2];
	normal[2] = vertex1[0] * vertex2[1] - vertex1[1] * vertex2[0];

	ReduceToUnit(normal);
}

void Player::ReduceToUnit(float vector[])
{
	float length;

	length = (float)sqrt((vector[0] * vector[0]) + (vector[1] * vector[1]) + (vector[2] * vector[2]));

	if (length == 0.0f)
		length = 1.0f;

	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}

void Player::CalcFaceNormal()
{
	int i, j;
	float normal[3], vertices[3][3];

	for (i = 0; i < 5000; i++)
		for (j = 0; j < 3; j++)
			m_fFaceNormal[i][j] = 0.0f;

	for (i = 0; i < m_nCountFace; i++)
	{
		for (j = 0; j < 3; j++)
		{
			vertices[j][0] = m_Vertex[m_FaceIndex[i].List[j]].x;
			vertices[j][1] = m_Vertex[m_FaceIndex[i].List[j]].y;
			vertices[j][2] = m_Vertex[m_FaceIndex[i].List[j]].z;
		}

		CalcNormal(vertices, normal);
		if (m_nWinding == CLOCKWISE)
		{
			m_fFaceNormal[i][0] = -normal[0];
			m_fFaceNormal[i][1] = -normal[1];
			m_fFaceNormal[i][2] = -normal[2];
		}

		if (m_nWinding == COUNTER_CLOCKWISE)
		{
			m_fFaceNormal[i][0] = normal[0];
			m_fFaceNormal[i][1] = normal[1];
			m_fFaceNormal[i][2] = normal[2];
		}
	}
}

void Player::CalcVertexNormal()
{
	int i, j;

	for (i = 0; i < 6000; i++)
		for (j = 0; j < 3; j++)
			m_fVertexNormal[i][j] = 0.0f;

	for (i = 0; i < m_nCountFace; i++)
	{
		for (j = 0; j < m_FaceIndex[i].Count; j++)
		{
			m_fVertexNormal[m_FaceIndex[i].List[j]][0] += m_fFaceNormal[i][0];
			m_fVertexNormal[m_FaceIndex[i].List[j]][1] += m_fFaceNormal[i][1];
			m_fVertexNormal[m_FaceIndex[i].List[j]][2] += m_fFaceNormal[i][2];
		}
	}
	for (i = 0; i < m_nCountVertex; i++)
	{
		ReduceToUnit(m_fVertexNormal[i]);
	}
}