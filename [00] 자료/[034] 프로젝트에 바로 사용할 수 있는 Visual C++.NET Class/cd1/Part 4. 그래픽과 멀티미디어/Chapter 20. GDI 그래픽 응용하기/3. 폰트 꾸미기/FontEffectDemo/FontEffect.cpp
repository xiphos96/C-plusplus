// FontEffect.cpp : implementation file
//

#include "stdafx.h"
#include "fonteffectdemo.h"
#include "FontEffect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontEffect

CFontEffect::CFontEffect()
{
	// 텍스트 출력용 폰트를 생성한다
	HDC hDC = ::GetDC(NULL);
	m_TextFont.CreateFont(-MulDiv(30, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_BOLD,
		0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("궁서체"));
	::ReleaseDC(NULL, hDC);

	// 멤버 변수들을 초기화한다
	m_bOutLine = FALSE;
	m_nPointSize = 0;
	m_pPointArray = NULL;
	m_pTypeArray = NULL;
	m_pProcessFunc = NULL;
}

CFontEffect::~CFontEffect()
{
	// 폰트를 제거한다
	m_TextFont.DeleteObject();
	// 메모리를 해제한다
	if(m_pPointArray)		delete[] m_pPointArray;
	if(m_pTypeArray)		delete[] m_pTypeArray;
}


BEGIN_MESSAGE_MAP(CFontEffect, CStatic)
	//{{AFX_MSG_MAP(CFontEffect)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontEffect message handlers

// 텍스트를 변경하는 함수
void CFontEffect::SetText(LPCTSTR pText, BOOL bRebuild)
{
	if(pText == NULL)		return;

	m_strText = pText;

	// 옵션에 따라 경로를 다시 구성한다
	if(bRebuild)	BuildEffect();
}

// 추가 효과 함수를 설정하는 함수
void CFontEffect::SetFunction(LPPROCESSFUNC pFunc, BOOL bRebuild)
{
	if(pFunc == NULL)		return;

	m_pProcessFunc = pFunc;

	// 옵션에 따라 경로를 다시 구성한다
	if(bRebuild)	BuildEffect();
}

// 외곽선 출력 여부를 설정하는 함수
void CFontEffect::SetOutLine(BOOL bOutLine)
{
	if(m_bOutLine != bOutLine)
	{
		m_bOutLine = bOutLine;
		Invalidate(FALSE);
	}
}

// 텍스트에 대한 경로를 계산하는 함수
void CFontEffect::BuildEffect()
{
	// 이전 경로 포인터들을 삭제한다
	if(m_pPointArray)		delete[] m_pPointArray;
	// 이전 경로 형식들을 삭제한다
	if(m_pTypeArray)		delete[] m_pTypeArray;
	m_pPointArray = NULL;
	m_pTypeArray = NULL;
	m_nPointSize = 0;

	// 경로를 생성하기 위해 메모리 DC를 생성한다
	CDC *pDC = GetDC(), MemDC;
	MemDC.CreateCompatibleDC(pDC);

	// 텍스트 출력용 폰트를 설정한다
	CFont *pOldFont = MemDC.SelectObject(&m_TextFont);
	// 폰트를 사용한 기본 텍스트 출력 크기를 구한다
	m_TextSize = MemDC.GetTextExtent(m_strText);

	// 만약 출력되는 크기가 0라면 리턴한다
	if(m_TextSize.cx == 0 || m_TextSize.cy == 0)
	{
		MemDC.SelectObject(pOldFont);
		MemDC.DeleteDC();
		ReleaseDC(pDC);
		return;
	}

	// 텍스트 출력을 위한 임시 비트맵을 생성한다
	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(pDC, m_TextSize.cx, m_TextSize.cy);
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// 텍스트 출력 배경을 투명으로 설정한다
	MemDC.SetBkMode(TRANSPARENT);

	// 경로를 생성하기 위해 Path 시작을 알린다
	MemDC.BeginPath();
	// 텍스트를 출력한다
	MemDC.TextOut(0, 0, m_strText);
	// 경로 생성을 종료한다
	MemDC.EndPath();

	// 텍스트 출력에 대한 경로를 구성하는데 필요한 포인트 갯수를 구한다
	m_nPointSize = MemDC.GetPath(NULL, NULL, 0);
	// 만약 포인트 갯수가 유효하지 않으면 리턴한다
	if(m_nPointSize == 0)
	{
		MemDC.SelectObject(pOldBmp);
		MemDC.SelectObject(pOldFont);
		MemDC.DeleteDC();
		MemBmp.DeleteObject();
		ReleaseDC(pDC);

		return;
	}

	// 경로를 구성하는데 필요한 포인트 배열을 생성한다
	m_pPointArray = new CPoint[m_nPointSize];
	// 경로를 구성하는데 필요한 형식 배열을 생성한다
	m_pTypeArray = new BYTE[m_nPointSize];

	// 텍스트 출력에 대한 경로를 얻는다
	MemDC.GetPath(m_pPointArray, m_pTypeArray, m_nPointSize);
	
	// 리소스를 반환한다
	MemDC.SelectObject(pOldBmp);
	MemDC.SelectObject(pOldFont);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
	ReleaseDC(pDC);

	// 만약 추가 효과 함수가 설정되어 있다면
	if(m_pProcessFunc)
	{
		// 추가 효과 함수를 호출한다
		m_pProcessFunc(m_nPointSize, m_pPointArray, m_TextSize);

		// 효과가 적용된 후의 출력 영역을 계산한다
		m_rcOutput.SetRect(m_pPointArray[0].x, m_pPointArray[0].y,
			m_pPointArray[0].x, m_pPointArray[0].y);

		for(int i = 0; i < m_nPointSize; i++)
		{
			if(m_pPointArray[i].x < m_rcOutput.left)
				m_rcOutput.left = m_pPointArray[i].x;
			if(m_pPointArray[i].x > m_rcOutput.right)
				m_rcOutput.right = m_pPointArray[i].x;

			if(m_pPointArray[i].y < m_rcOutput.top)
				m_rcOutput.top = m_pPointArray[i].y;
			if(m_pPointArray[i].y > m_rcOutput.bottom)
				m_rcOutput.bottom = m_pPointArray[i].y;
		}
	}
	else
		// 텍스트 크기를 출력 영역으로 사용한다
		m_rcOutput.SetRect(0, 0, m_TextSize.cx, m_TextSize.cy);

	Invalidate(FALSE);
}

void CFontEffect::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// 더블 버퍼링을 구현한다
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	CRect rcClient;
	GetClientRect(&rcClient);

	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);
	
	// 배경을 하얀색으로 칠한다
	MemDC.FillSolidRect(0, 0, rcClient.Width(), rcClient.Height(), RGB(255, 255, 255));

	// 텍스트 출력에 대한 경로를 출력한다
	DrawEffect(&MemDC, rcClient.Width(), rcClient.Height());

	// 화면에 출력한다
	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(),
		&MemDC, 0, 0, SRCCOPY);

	// 리소스를 반환한다
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

BOOL CFontEffect::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

// 경로를 출력하는 함수
void CFontEffect::DrawEffect(CDC *pDC, int cx, int cy)
{
	if(pDC == NULL || m_pPointArray == NULL || m_pTypeArray == NULL)		return;

	int i;
	// 경로 그래프가 화면의 중앙에 나타나도록 오프셋을 계산한다
	int nOffsetX = (cx - m_rcOutput.Width()) / 2 - m_rcOutput.left;
	int nOffsetY = (cy - m_rcOutput.Height()) / 2 - m_rcOutput.top;

	CPoint pTempPoint[3];

	// FillPath()를 사용하기 위해서 우선 경로를 생성한다
	pDC->BeginPath();

	// 효과가 적용된 경로 포인터들을 출력한다
	for(i = 0; i < m_nPointSize; i++)
	{
		// 각 출력 형식에 따라 포인터들을 사용하여 선 혹은 베지어 곡선을 그린다
		switch(m_pTypeArray[i])
		{
		case PT_MOVETO : 
			pDC->MoveTo(m_pPointArray[i].x + nOffsetX,
				m_pPointArray[i].y + nOffsetY);
			break;

		case PT_LINETO | PT_CLOSEFIGURE:
		case PT_LINETO :
			pDC->LineTo(m_pPointArray[i].x + nOffsetX,
				m_pPointArray[i].y + nOffsetY);
			break;

		case PT_BEZIERTO | PT_CLOSEFIGURE:
		case PT_BEZIERTO :
			pTempPoint[0] = m_pPointArray[i];
			pTempPoint[1] = m_pPointArray[i + 1];
			pTempPoint[2] = m_pPointArray[i + 2];

			pTempPoint[0].Offset(nOffsetX, nOffsetY);
			pTempPoint[1].Offset(nOffsetX, nOffsetY);
			pTempPoint[2].Offset(nOffsetX, nOffsetY);

			pDC->PolyBezierTo(pTempPoint, 3);

			i += 2;
			break;
		}
	}

	// 경로 중에서 폐도형이 아닌 도형을 폐도형으로 만든다
	pDC->CloseFigure();
	// 경로 생성을 종료한다
	pDC->EndPath();

	// 만약 외곽선 출력이라면 StrokePath() 함수로 경로를 그린다
	if(m_bOutLine)		pDC->StrokePath();
	else
	{
		// 만약 외곽선 출력이 아니라면 경로 내부를 칠할 브러쉬를 생성한다
		CBrush BlackBrush, *pOldBrush;
		BlackBrush.CreateSolidBrush(RGB(0, 0, 0));
		pOldBrush = pDC->SelectObject(&BlackBrush);

		// FillPath() 함수로 내부가 채워진 경로를 출력한다
		pDC->FillPath();

		// 리소스를 반환한다
		pDC->SelectObject(pOldBrush);
		BlackBrush.DeleteObject();
	}
}
