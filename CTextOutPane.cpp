// CTextOutPane.cpp: 구현 파일
//

#include "pch.h"
#include "MFCPractice7_DockingPaneTest.h"
#include "CTextOutPane.h"


// CTextOutPane

IMPLEMENT_DYNAMIC(CTextOutPane, CDockablePane)

CTextOutPane::CTextOutPane()
{

}

CTextOutPane::~CTextOutPane()
{
}


BEGIN_MESSAGE_MAP(CTextOutPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CTextOutPane 메시지 처리기




int CTextOutPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (!m_ctrlTextOut.Create(IDD_DIALOG_TEXTOUT, this))
	{
		MessageBox(_T("도킹팬 윈도우 생성 실패"));
		return -1;
	}

	m_ctrlTextOut.ShowWindow(SW_SHOW);

	return 0;
}


void CTextOutPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_ctrlTextOut.GetSafeHwnd())
	{
		m_ctrlTextOut.MoveWindow(0, 0, cx, cy);
		m_ctrlTextOut.SetFocus();
	}
}
