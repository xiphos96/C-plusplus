// RulerView.cpp : implementation file
//

#include "stdafx.h"
#include "rulersplitterwnddemo.h"
#include "RulerView.h"

#include "RulerSplitterWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRulerView

// 수평/수직자의 눈금 크기
#define CONST_SCALE_5		3			// 5픽셀 단위의 눈금 크기
#define CONST_SCALE_10		6			// 10픽셀 단위의 눈금 크기

IMPLEMENT_DYNCREATE(CRulerView, CView)

CRulerView::CRulerView()
{
	// 멤버 변수들을 초기화한다
	m_bHorz			= TRUE;
	m_pScrollHint	= NULL;

	HDC hDC = ::GetDC(NULL);
	// 수평자용 폰트를 생성한다
	m_HorzFont.CreateFont(-MulDiv(7, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0,
		FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "굴림");
	// 수직자용 폰트를 생성한다
	m_VertFont.CreateFont(-MulDiv(7, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 900, 0,
		FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "굴림");
	::ReleaseDC(NULL, hDC);
}

CRulerView::~CRulerView()
{
	// 폰트 객체들을 소멸시킨다
	m_HorzFont.DeleteObject();
	m_VertFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CRulerView, CView)
	//{{AFX_MSG_MAP(CRulerView)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRulerView drawing

void CRulerView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();

	// 뷰의 클라이언트 영역을 구한다
	CRect rcClient;
	GetClientRect(&rcClient);

	CDC MemDC;
	CBitmap MemBmp, *pOldBmp;
	CFont *pOldFont;

	// 메모리 DC를 생성한다
	MemDC.CreateCompatibleDC(pDC);
	// 비트맵을 생성한다
	MemBmp.CreateCompatibleBitmap(pDC, rcClient.Width(), rcClient.Height());
	// 메모리 DC에 비트맵을 설정한다
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// 배경을 흰색으로 칠한다
	MemDC.FillSolidRect(&rcClient, RGB(255, 255, 255));
	// 만약 스크롤 정보가 존재한다면
	if(m_pScrollHint)
	{
		int i, nScale;
		CString strScale;

		// 수평자일 경우
		if(m_bHorz)
		{
			// 수평자용 폰트를 설정한다
			pOldFont = MemDC.SelectObject(&m_HorzFont);

			// 초기 5단위 눈금의 시작 위치를 계산한다
			i = 5 - m_pScrollHint->m_nScrollX % 5;
			if(i == 5)		i = 0;
			// 5단위로 눈금을 출력한다
			for(; i < rcClient.right; i += 5)
			{
				// 눈금의 실제 좌표값을 계산한다
				nScale = i + m_pScrollHint->m_nScrollX;
				// 만약 100 단위라면 수평자의 높이와 같은 크기로 눈금을 출력한다
				if(nScale % 100 == 0)
				{
					MemDC.MoveTo(i, rcClient.top);
					// 눈금의 좌표값을 출력한다
					strScale.Format("%d", nScale);
					MemDC.TextOut(i + 1, rcClient.top, strScale);
				}
				else
				{
					// 만약 10 단위라면
					if(nScale % 10 == 0)
						// 10단위 두께만큼 눈금을 출력한다
						MemDC.MoveTo(i, rcClient.bottom - CONST_SCALE_10);
					else
						// 5단위 두께만큼 눈금을 출력한다
						MemDC.MoveTo(i, rcClient.bottom - CONST_SCALE_5);
				}
				MemDC.LineTo(i, rcClient.bottom);
			}
		}
		else
		{
			// 수직자의 경우
			CSize szText;
			// 수직자용 폰트를 설정한다
			pOldFont = MemDC.SelectObject(&m_VertFont);

			// 초기 5단위 눈금의 시작 위치를 계산한다
			i = 5 - m_pScrollHint->m_nScrollY % 5;
			if(i == 5)		i = 0;
			// 5단위로 눈금을 출력한다
			for(; i < rcClient.bottom; i += 5)
			{
				// 눈금의 실제 좌표값을 계산한다
				nScale = i + m_pScrollHint->m_nScrollY;
				// 만약 100 단위라면 수직자의 폭과 같은 크기로 눈금을 출력한다
				if(nScale % 100 == 0)
				{
					MemDC.MoveTo(rcClient.left, i);
					strScale.Format("%d", nScale);
					// 눈금의 좌표값 출력에 필요한 영역을 구한다
					szText = MemDC.GetTextExtent(strScale);
					// 눈금의 좌표값을 출력한다
					MemDC.TextOut(rcClient.left, i + szText.cx + 2, strScale);
				}
				else
				{
					// 만약 10 단위라면
					if(nScale % 10 == 0)
						// 10단위 두께만큼 눈금을 출력한다
						MemDC.MoveTo(rcClient.right - CONST_SCALE_10, i);
					else
						// 5단위 두께만큼 눈금을 출력한다
						MemDC.MoveTo(rcClient.right - CONST_SCALE_5, i);
				}
				MemDC.LineTo(rcClient.right, i);
			}
		}

		// 메모리 DC에게 이전 폰트를 설정한다
		MemDC.SelectObject(pOldFont);

		// 커서 위치 표시줄을 출력한다
		DrawCursorLine(&MemDC, (m_bHorz ? m_pScrollHint->m_nCursorX : m_pScrollHint->m_nCursorY));
	}

	// 메모리 DC의 내용을 화면에 출력한다
	pDC->BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &MemDC, 0, 0, SRCCOPY);

	// 메모리 DC의 이전 비트맵을 설정한다
	MemDC.SelectObject(pOldBmp);
	// 메모리 DC를 소멸시킨다
	MemDC.DeleteDC();
	// 비트맵을 소멸시킨다
	MemBmp.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CRulerView diagnostics

#ifdef _DEBUG
void CRulerView::AssertValid() const
{
	CView::AssertValid();
}

void CRulerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRulerView message handlers

void CRulerView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();

	// 초기 커서 위치를 -1로 설정한다
	m_nLastCursor = -1;
}

BOOL CRulerView::OnEraseBkgnd(CDC* pDC) 
{
	// 배경을 지우지 않는다
	return TRUE;
}

// 현재 커서 위치를 표시하는 함수
void CRulerView::DrawCursorLine(CDC *pDC, int nCursor)
{
	// 래스터 오퍼레이션을 NOTXORPEN으로 설정한다
	int nROP = pDC->SetROP2(R2_NOTXORPEN), i;

	// 클라이언트 영역을 얻는다
	CRect rcClient;
	GetClientRect(&rcClient);

	// 만약 수평자라면
	if(m_bHorz)
	{
		// 마우스의 수평 위치에 수직 점선을 출력한다
		for(i = rcClient.top; i < rcClient.bottom; i += 2)
			pDC->SetPixel(nCursor, i, RGB(0, 0, 0));
	}
	else
	{
		// 만약 수직자라면 마우스의 수직 위치에 수평 점선을 출력한다
		for(i = rcClient.left; i < rcClient.right; i += 2)
			pDC->SetPixel(i, nCursor, RGB(0, 0, 0));
	}

	// 래스터 오퍼레이션 속성을 되돌린다
	pDC->SetROP2(nROP);
}

// 뷰의 업데이트가 필요할 경우 호출되는 함수
void CRulerView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// 업데이트 정보를 얻는다
	m_pScrollHint = (CScrollHint*)pHint;
	switch(lHint)
	{
	case UPDATE_HSCROLL:
		// 만약 수평으로 스크롤되었다면
		// 만약 현재 뷰가 수평자 뷰라면 뷰를 다시 그린다
		if(m_bHorz)			InvalidateRect(FALSE);
		break;
	case UPDATE_VSCROLL:
		// 만약 수직으로 스크롤되었다면
		// 만약 현재 뷰가 수직자 뷰라면 뷰를 다시 그린다
		if(!m_bHorz)		InvalidateRect(FALSE);
		break;
	case UPDATA_CURSOR:
		// 만약 커서 위치가 이동되었다면
		{
			CDC *pDC = GetDC();

			// 마지막 커서 위치의 라인을 지운다
			if(m_nLastCursor >= 0)		DrawCursorLine(pDC, m_nLastCursor);
			// 만약 수평자 뷰라면 커서의 X 좌표를 저장한다
			if(m_bHorz)		m_nLastCursor = m_pScrollHint->m_nCursorX;
			// 만약 수직자 뷰라면 커서의 Y 좌표를 저장한다
			else			m_nLastCursor = m_pScrollHint->m_nCursorY;
			// 커서의 위치에 라인을 다시 그린다
			DrawCursorLine(pDC, m_nLastCursor);

			ReleaseDC(pDC);
		}
		break;
	}
}
