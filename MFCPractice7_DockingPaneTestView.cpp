
// MFCPractice7_DockingPaneTestView.cpp: CMFCPractice7DockingPaneTestView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCPractice7_DockingPaneTest.h"
#endif

#include "MFCPractice7_DockingPaneTestDoc.h"
#include "MFCPractice7_DockingPaneTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCPractice7DockingPaneTestView

IMPLEMENT_DYNCREATE(CMFCPractice7DockingPaneTestView, CView)

BEGIN_MESSAGE_MAP(CMFCPractice7DockingPaneTestView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCPractice7DockingPaneTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCPractice7DockingPaneTestView 생성/소멸

CMFCPractice7DockingPaneTestView::CMFCPractice7DockingPaneTestView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCPractice7DockingPaneTestView::~CMFCPractice7DockingPaneTestView()
{
}

BOOL CMFCPractice7DockingPaneTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCPractice7DockingPaneTestView 그리기

void CMFCPractice7DockingPaneTestView::OnDraw(CDC* pDC)
{
	CMFCPractice7DockingPaneTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CFont *oldFont, *currentFont, newFont;
	if (m_bFont == TRUE)
	{
		newFont.CreatePointFontIndirect(&m_logFont);
		oldFont = pDC->SelectObject(&newFont);
	}
	else
	{
		currentFont = pDC->GetCurrentFont();
		oldFont = pDC->SelectObject(currentFont);
	}

	pDC->SetTextColor(m_colorText);

	pDC->TextOut(m_ptPosition.x, m_ptPosition.y, m_strOutput);

	CSize sizeText;
	sizeText = pDC->GetTextExtent(m_strOutput);
	m_nTextWidth = sizeText.cx;
	m_nTextHeight = sizeText.cy;

	pDC->SelectObject(oldFont);
}


// CMFCPractice7DockingPaneTestView 인쇄


void CMFCPractice7DockingPaneTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCPractice7DockingPaneTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCPractice7DockingPaneTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCPractice7DockingPaneTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFCPractice7DockingPaneTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCPractice7DockingPaneTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCPractice7DockingPaneTestView 진단

#ifdef _DEBUG
void CMFCPractice7DockingPaneTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPractice7DockingPaneTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPractice7DockingPaneTestDoc* CMFCPractice7DockingPaneTestView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPractice7DockingPaneTestDoc)));
	return (CMFCPractice7DockingPaneTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCPractice7DockingPaneTestView 메시지 처리기
