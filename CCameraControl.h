#pragma once
#include "afxdialogex.h"

// CCameraControl 대화 상자

class CCameraControl : public CDialogEx
{
	DECLARE_DYNAMIC(CCameraControl)

public:
	CCameraControl(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCameraControl();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CAMERA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio2d();
	afx_msg void OnBnClickedRadio3d();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
};
