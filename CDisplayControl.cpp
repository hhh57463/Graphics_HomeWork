// CDisplayControl.cpp: 구현 파일
//

#include "pch.h"
#include "20181375P4.h"
#include "afxdialogex.h"
#include "CDisplayControl.h"
#include "MainFrm.h"
#include "20181375P4Doc.h"
#include "20181375P4View.h"

// CDisplayControl 대화 상자

IMPLEMENT_DYNAMIC(CDisplayControl, CDialogEx)

CDisplayControl::CDisplayControl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DISPLAY, pParent)
{

}

CDisplayControl::~CDisplayControl()
{
}

void CDisplayControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDisplayControl, CDialogEx)
	ON_COMMAND(IDC_RADIO_WIRE, &CDisplayControl::OnRadioWire)
	ON_COMMAND(IDC_RADIO_Flat, &CDisplayControl::OnRadioFlat)
	ON_COMMAND(IDC_RADIO_SMOOTH, &CDisplayControl::OnRadioSmooth)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CDisplayControl::OnClickedButtonReset)
END_MESSAGE_MAP()


// CDisplayControl 메시지 처리기


BOOL CDisplayControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20181375P4View* pView = (CMy20181375P4View*)(pFrame->GetActiveView());
	CButton* m_Button;

	switch (pView->player.m_nDisplayMode)
	{
		case WIRE_FRAME:
			m_Button = (CButton*)GetDlgItem(IDC_RADIO_WIRE);
			m_Button->SetCheck(TRUE);
			break;
		case FLAT_SHADING:
			m_Button = (CButton*)GetDlgItem(IDC_RADIO_Flat);
			m_Button->SetCheck(TRUE);
			break;
		case SMOOTH_SHADING:
			m_Button = (CButton*)GetDlgItem(IDC_RADIO_SMOOTH);
			m_Button->SetCheck(TRUE);
			break;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDisplayControl::OnRadioWire()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20181375P4View* pView = (CMy20181375P4View*)(pFrame->GetActiveView());
	pView->player.m_nDisplayMode = WIRE_FRAME;
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		pView->enemy[i].m_nDisplayMode = WIRE_FRAME;
	}
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		pView->player.bullet[i].m_nDisplayMode = WIRE_FRAME;
	}
	pView->RedrawWindow();
}


void CDisplayControl::OnRadioFlat()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20181375P4View* pView = (CMy20181375P4View*)(pFrame->GetActiveView());
	pView->player.m_nDisplayMode = FLAT_SHADING;
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		pView->enemy[i].m_nDisplayMode = FLAT_SHADING;
	}
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		pView->player.bullet[i].m_nDisplayMode = FLAT_SHADING;
	}
	pView->RedrawWindow();
}


void CDisplayControl::OnRadioSmooth()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20181375P4View* pView = (CMy20181375P4View*)(pFrame->GetActiveView());
	pView->player.m_nDisplayMode = SMOOTH_SHADING;
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		pView->enemy[i].m_nDisplayMode = SMOOTH_SHADING;
	}
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		pView->player.bullet[i].m_nDisplayMode = SMOOTH_SHADING;
	}
	pView->RedrawWindow();
}

void CDisplayControl::OnClickedButtonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20181375P4View* pView = (CMy20181375P4View*)(pFrame->GetActiveView());
	CButton* m_Button;

	m_Button = (CButton*)GetDlgItem(IDC_RADIO_WIRE);
	m_Button->SetCheck(TRUE);

	m_Button = (CButton*)GetDlgItem(IDC_RADIO_Flat);
	m_Button->SetCheck(FALSE);

	m_Button = (CButton*)GetDlgItem(IDC_RADIO_SMOOTH);
	m_Button->SetCheck(FALSE);

	pView->player.m_nDisplayMode = WIRE_FRAME;
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		pView->enemy[i].m_nDisplayMode = WIRE_FRAME;
	}
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		pView->player.bullet[i].m_nDisplayMode = WIRE_FRAME;
	}
	pView->RedrawWindow();
}
