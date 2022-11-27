
// 20181375P4View.h: CMy20181375P4View 클래스의 인터페이스
//

#pragma once
#include "CCameraControl.h"
#include "CDisplayControl.h"
#include "Player.h"
#include "Enemy.h"

enum MOVEDIRECT
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

class CMy20181375P4View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20181375P4View() noexcept;
	DECLARE_DYNCREATE(CMy20181375P4View)

// 특성입니다.
public:
	CMy20181375P4Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMy20181375P4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

public:
	HGLRC m_hRC;
	CDC* m_pDC;
	bool InitializeOpenGL();
	bool SetupPixelFormat();
	void RenderScene(Unit& unit);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	GLdouble m_dAspectRatio;
	GLfloat m_From[3];
	GLfloat m_At[3];
	GLfloat m_UP[3];
	GLfloat m_Angle;
	bool m_bFileOpen;
	CString m_strFileType;
	CString m_strFileWinding;
	CCameraControl m_dlgCameraControl;
	afx_msg void OnCameraControl();
	bool m_bDisplayCameraConrol;
	CDisplayControl m_dlgDisplayControl;
	afx_msg void OnDisplayControl();
	bool m_bDisplayDisplayControl;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

public:
	Player player;
	Enemy enemy[ENEMY_COUNT];
	GLint enemySpawnCount;
	void PlaneSetting(Unit& unit, CString path);
	TCHAR path[256];
	CString playerPath;
	CString enemyPath;
	CString bulletPath;
	bool ChangeMode;
	bool mode_2D;
	bool mode_3D;
	GLint FrameCount;
	GLint killCount;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 20181375P4View.cpp의 디버그 버전
inline CMy20181375P4Doc* CMy20181375P4View::GetDocument() const
   { return reinterpret_cast<CMy20181375P4Doc*>(m_pDocument); }
#endif

