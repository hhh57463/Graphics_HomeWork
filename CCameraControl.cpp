// CCameraControl.cpp: 구현 파일
//

#include "pch.h"
#include "20181375P4.h"
#include "afxdialogex.h"
#include "CCameraControl.h"
#include "MainFrm.h"
#include "20181375P4Doc.h"
#include "20181375P4View.h"


// CCameraControl 대화 상자

IMPLEMENT_DYNAMIC(CCameraControl, CDialogEx)

CCameraControl::CCameraControl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CAMERA, pParent)
{

}

CCameraControl::~CCameraControl()
{
}

void CCameraControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCameraControl, CDialogEx)

	ON_BN_CLICKED(IDC_RADIO_2D, &CCameraControl::OnBnClickedRadio2d)
	ON_BN_CLICKED(IDC_RADIO_3D, &CCameraControl::OnBnClickedRadio3d)
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


// CCameraControl 메시지 처리기


BOOL CCameraControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	((CButton*)GetDlgItem(IDC_RADIO_2D))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO_3D))->SetCheck(FALSE);
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CCameraControl::OnBnClickedRadio2d()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20181375P4View* pView = (CMy20181375P4View*)(pFrame->GetActiveView());
	pView->mode_2D = TRUE;
	pView->mode_3D = FALSE;
	pView->ChangeMode = TRUE;
	pView->SetTimer(1, 100, NULL);
}


void CCameraControl::OnBnClickedRadio3d()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20181375P4View* pView = (CMy20181375P4View*)(pFrame->GetActiveView());
	pView->mode_2D = FALSE;
	pView->mode_3D = TRUE;
	pView->ChangeMode = TRUE;
	pView->SetTimer(1, 100, NULL);
}

void CCameraControl::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nID == SC_CLOSE)
	{
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CMy20181375P4View* pView = (CMy20181375P4View*)(pFrame->GetActiveView());
		
		pView->ChangeMode = FALSE;
		pView->SetTimer(0, 100, NULL);
	}
	CDialogEx::OnSysCommand(nID, lParam);
}
