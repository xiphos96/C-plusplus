// ColorPaletteWnd.cpp : implementation file
//

#include "stdafx.h"
#include "colorpickbuttondemo.h"
#include "ColorPaletteWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorPaletteWnd

// 상수 정의
#define CONST_COLORBOX_SIZE			18				// 색상 항목의 크기
#define CONST_TEXT_HEIGHT			20				// 기본 색상과 More Colors 버튼의 높이

// 정적 변수 초기화
COLOR_TABLE *CColorPaletteWnd::m_pColorTable = NULL;	// 색상 테이블의 초기화
int CColorPaletteWnd::m_nCount		 = 0;	// 색상 테이블 참조 갯수의 초기화


CColorPaletteWnd::CColorPaletteWnd()
{
	// 색상 테이블을 초기화한다
	InitColorTable();

	// 각종 변수들을 초기화 한다
	m_pParent		= NULL;
	m_clrColor		= RGB(0, 0, 0);
	m_clrBkgnd		= ::GetSysColor(COLOR_BTNFACE);
	m_nBorder		= ::GetSystemMetrics(SM_CXEDGE);

	m_bColorDialog	= FALSE;

	// 폰트 생성
	HDC hDC = ::GetDC(NULL);
	m_TextFont.CreateFont(-MulDiv(9, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "굴림");
	::ReleaseDC(NULL, hDC);

	// 각 영역들을 초기화한다
	m_rcDefault.SetRect(m_nBorder, m_nBorder,
		m_nBorder + 8 * CONST_COLORBOX_SIZE, m_nBorder + CONST_TEXT_HEIGHT);
	m_rcColorBox.SetRect(m_nBorder, m_rcDefault.bottom + m_nBorder,
		m_rcDefault.right, m_rcDefault.bottom + m_nBorder + 5 * CONST_COLORBOX_SIZE);
	m_rcMore.SetRect(m_nBorder, m_rcColorBox.bottom + m_nBorder,
		m_rcColorBox.right, m_rcColorBox.bottom + m_nBorder + CONST_TEXT_HEIGHT);
	m_rcWindow.SetRect(0, 0, m_rcMore.right + m_nBorder, m_rcMore.bottom + m_nBorder);
}

// 색상 테이블에 대한 초기화 함수
void CColorPaletteWnd::InitColorTable()
{
	// 카운트를 1 증가시킨다
	m_nCount++;

	// 이미 색상 테이블이 초기화 되어 있다면 그냥 리턴한다
	if(m_pColorTable != NULL)			return;

	// 색상 테이블을 만들고 그 값들을 초기화한다
	m_pColorTable	= new COLOR_TABLE[40];

	m_pColorTable[0].clrColor = RGB(0x00, 0x00, 0x00);
	m_pColorTable[0].strName = "Black";
	m_pColorTable[1].clrColor = RGB(0xA5, 0x2A, 0x00);
	m_pColorTable[1].strName = "Brown";
	m_pColorTable[2].clrColor = RGB(0x00, 0x40, 0x40);
	m_pColorTable[2].strName = "Dark Olive Green";
	m_pColorTable[3].clrColor = RGB(0x00, 0x55, 0x00);
	m_pColorTable[3].strName = "Dark Green";
	m_pColorTable[4].clrColor = RGB(0x00, 0x00, 0x5E);
	m_pColorTable[4].strName = "Dark Teal";
	m_pColorTable[5].clrColor = RGB(0x00, 0x00, 0x8B);
	m_pColorTable[5].strName = "Dark blue";
	m_pColorTable[6].clrColor = RGB(0x4B, 0x00, 0x82);
	m_pColorTable[6].strName = "Indigo";
	m_pColorTable[7].clrColor = RGB(0x28, 0x28, 0x28);
	m_pColorTable[7].strName = "Dark grey";

	m_pColorTable[8].clrColor = RGB(0x8B, 0x00, 0x00);
	m_pColorTable[8].strName = "Dark red";
	m_pColorTable[9].clrColor = RGB(0xFF, 0x68, 0x20);
	m_pColorTable[9].strName = "Orange";
	m_pColorTable[10].clrColor = RGB(0x8B, 0x8B, 0x00);
	m_pColorTable[10].strName = "Dark yellow";
	m_pColorTable[11].clrColor = RGB(0x00, 0x93, 0x00);
	m_pColorTable[11].strName = "Green";
	m_pColorTable[12].clrColor = RGB(0x38, 0x8E, 0x8E);
	m_pColorTable[12].strName = "Teal";
	m_pColorTable[13].clrColor = RGB(0x00, 0x00, 0xFF);
	m_pColorTable[13].strName = "Blue";
	m_pColorTable[14].clrColor = RGB(0x7B, 0x7B, 0xC0);
	m_pColorTable[14].strName = "Blue-grey";
	m_pColorTable[15].clrColor = RGB(0x66, 0x66, 0x66);
	m_pColorTable[15].strName = "Grey - 40";

	m_pColorTable[16].clrColor = RGB(0xFF, 0x00, 0x00);
	m_pColorTable[16].strName = "Red";
	m_pColorTable[17].clrColor = RGB(0xFF, 0xAD, 0x5B);
	m_pColorTable[17].strName = "Light orange";
	m_pColorTable[18].clrColor = RGB(0x32, 0xCD, 0x32);
	m_pColorTable[18].strName = "Lime";
	m_pColorTable[19].clrColor = RGB(0x3C, 0xB3, 0x71);
	m_pColorTable[19].strName = "Sea green";
	m_pColorTable[20].clrColor = RGB(0x7F, 0xFF, 0xD4);
	m_pColorTable[20].strName = "Aqua";
	m_pColorTable[21].clrColor = RGB(0x7D, 0x9E, 0xC0);
	m_pColorTable[21].strName = "Light blue";
	m_pColorTable[22].clrColor = RGB(0x80, 0x00, 0x80);
	m_pColorTable[22].strName = "Violet";
	m_pColorTable[23].clrColor = RGB(0x80, 0x80, 0x80);
	m_pColorTable[23].strName = "Grey - 50";

	m_pColorTable[24].clrColor = RGB(0xFF, 0xC0, 0xCB);
	m_pColorTable[24].strName = "Pink";
	m_pColorTable[25].clrColor = RGB(0xFF, 0xD7, 0x00);
	m_pColorTable[25].strName = "Gold";
	m_pColorTable[26].clrColor = RGB(0xFF, 0xFF, 0x00);
	m_pColorTable[26].strName = "Yellow";
	m_pColorTable[27].clrColor = RGB(0x00, 0xFF, 0x00);
	m_pColorTable[27].strName = "Bright green";
	m_pColorTable[28].clrColor = RGB(0x40, 0xE0, 0xD0);
	m_pColorTable[28].strName = "Turquoise";
	m_pColorTable[29].clrColor = RGB(0xC0, 0xFF, 0xFF);
	m_pColorTable[29].strName = "Skyblue";
	m_pColorTable[30].clrColor = RGB(0x48, 0x00, 0x48);
	m_pColorTable[30].strName = "Plum";
	m_pColorTable[31].clrColor = RGB(0xC0, 0xC0, 0xC0);
	m_pColorTable[31].strName = "Light grey";

	m_pColorTable[32].clrColor = RGB(0xFF, 0xE4, 0xE1);
	m_pColorTable[32].strName = "Rose";
	m_pColorTable[33].clrColor = RGB(0xD2, 0xB4, 0x8C);
	m_pColorTable[33].strName = "Tan";
	m_pColorTable[34].clrColor = RGB(0xFF, 0xFF, 0xE0);
	m_pColorTable[34].strName = "Light yellow";
	m_pColorTable[35].clrColor = RGB(0x98, 0xFB, 0x98);
	m_pColorTable[35].strName = "Pale green";
	m_pColorTable[36].clrColor = RGB(0xAF, 0xEE, 0xEE);
	m_pColorTable[36].strName = "Pale turquoise";
	m_pColorTable[37].clrColor = RGB(0x68, 0x83, 0x8B);
	m_pColorTable[37].strName = "Pale blue";
	m_pColorTable[38].clrColor = RGB(0xE6, 0xE6, 0xFA);
	m_pColorTable[38].strName = "Lavender";
	m_pColorTable[39].clrColor = RGB(0xFF, 0xFF, 0xFF);
	m_pColorTable[39].strName = "White";
}

CColorPaletteWnd::~CColorPaletteWnd()
{
	// 텍스트 폰트를 제거한다
	m_TextFont.DeleteObject();

	// 카운트를 1 감소 시킨다
	m_nCount--;

	// 만약 참조가 더이상 없고 색상 테이블이 존재한다면 제거한다
	if(m_nCount == 0 && m_pColorTable)
	{
		delete[] m_pColorTable;
		m_pColorTable = NULL;
	}
}


BEGIN_MESSAGE_MAP(CColorPaletteWnd, CWnd)
	//{{AFX_MSG_MAP(CColorPaletteWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_ACTIVATEAPP()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CColorPaletteWnd message handlers

// 초기 색상과 위치로 팔레트 윈도우를 생성하는 함수
BOOL CColorPaletteWnd::Init(COLORREF clrColor, CWnd *pParent, int x, int y, UINT nID)
{
	// 초기 색상과 부모 윈도우에 대한 핸들을 저장한다
	m_clrColor	= clrColor;
	m_pParent	= pParent;

	// 팔레트 윈도우가 출력될 부모 윈도우에서의 좌표를 전체 화면에서의 좌표로 변환한다
	CRect rcWnd = m_rcWindow;
	rcWnd.OffsetRect(x, y);
	m_pParent->ClientToScreen(&rcWnd);

	// 윈도우즈 작업 영역을 구한다
	CRect rcWorkArea;
	::SystemParametersInfo(SPI_GETWORKAREA, 0, &rcWorkArea, 0);

	// 만약 윈도우즈 작업 영역을 벗어날 경우
	// 팔레트 윈도우의 출력 위치를 작업 영역 안쪽으로 조정한다
	int nOffsetX = 0;
	int nOffsetY = 0;

	if(rcWnd.left < 0)
		nOffsetX = rcWnd.left * -1;
	if(rcWnd.right > rcWorkArea.right)
		nOffsetX = rcWorkArea.right - rcWnd.right;
	if(rcWnd.bottom > rcWorkArea.bottom)
		nOffsetY = -1 * (y + rcWnd.Height());

	rcWnd.OffsetRect(nOffsetX, nOffsetY);

	// 팝업 윈도우로써 생성하기 위해 윈도우 클래스를 등록한다
	UINT nStyle = CS_CLASSDC | CS_SAVEBITS | CS_HREDRAW | CS_VREDRAW;
	CString strClassName = AfxRegisterWndClass(nStyle, 0, 0, 0);

	// 팝업 윈도우로써 생성한다
	if(!CreateEx(0, strClassName, "Palette", WS_VISIBLE | WS_POPUP, rcWnd, m_pParent, 0, NULL))
	{
		return FALSE;
	}

	// 화면에 갱신한다
	ShowWindow(SW_SHOW);
	UpdateWindow();

	// 툴팁 윈도우를 생성하고
	if(!m_wndToolTip.Create(this))		return FALSE;

	// 각 버튼의 툴팁을 설정한다
	m_wndToolTip.AddTool(this, "기본 색상", m_rcDefault, 1);
	m_wndToolTip.AddTool(this, "More Colors...", m_rcMore, 2);

	CRect rcTemp;
	for(int i = 0; i < 40; i++)
	{
		rcTemp.left		= m_rcColorBox.left + (i % 8) * CONST_COLORBOX_SIZE;
		rcTemp.right	= rcTemp.left + CONST_COLORBOX_SIZE - 1;
		rcTemp.top		= m_rcColorBox.top + (i / 8) * CONST_COLORBOX_SIZE;
		rcTemp.bottom	= rcTemp.top + CONST_COLORBOX_SIZE - 1;

		m_wndToolTip.AddTool(this, m_pColorTable[i].strName, rcTemp, i + 3);
	}

	// 초기 색상에 대한 색상 테이블에서의 번호를 찾는다
	m_nSelected = FindColor(m_clrColor);

	// 마우스 이벤트를 캡춰한다
	SetCapture();

	return TRUE;
}

// 특정 색상에 대한 색상 테이블에서의 번호를 리턴하는 함수
int CColorPaletteWnd::FindColor(COLORREF clrColor)
{
	int i;

	// 기본 색상이면 기본 색상 버튼의 번호(-1)를 리턴한다
	if(clrColor == CLR_DEFAULT)			return -1;

	// 색상 테이블에 존재한다면 색상 테이블에서의 번호를 리턴한다
	for(i = 0; i < 40; i++)
	{
		if(m_pColorTable[i].clrColor == clrColor)
			return i;
	}

	// 색상 테이블에 존재하지 않는다면
	// More Colors 버튼의 번호(40)을 리턴한다
	return 40;
}

// 특정 색상에 대한 색상 이름을 리턴하는 함수
void CColorPaletteWnd::FindColorName(COLORREF clrColor, CString &strName)
{
	// 기본 색상이면 "기본 색상"을 설정한다
	if(clrColor == CLR_DEFAULT)
	{
		strName = "기본 색상";
		return;
	}

	int i;

	// 색상 테이블을 초기화한다
	InitColorTable();

	// 색상 테이블에 존재한다면 색상 테이블의 색상 이름을 설정한다
	for(i = 0; i < 40; i++)
	{
		if(m_pColorTable[i].clrColor == clrColor)
		{
			strName = m_pColorTable[i].strName;

			// 색상 테이블 참조를 감소시키고 더이상 참조가 없다면 제거한다
			m_nCount--;
			if(m_nCount == 0)
			{
				delete[] m_pColorTable;
				m_pColorTable = NULL;
			}
			return;
		}
	}

	// 색상 테이블에 존재하지 않는다면
	// "RGB(255, 255, 255)" 형태로 설정한다
	strName.Format("RGB(%d, %d, %d)", GetRValue(m_pColorTable[i].clrColor),
		GetGValue(m_pColorTable[i].clrColor),
		GetBValue(m_pColorTable[i].clrColor));

	// 색상 테이블 참조를 감소시키고 더이상 참조가 없다면 제거한다
	m_nCount--;
	if(m_nCount == 0)
	{
		delete[] m_pColorTable;
		m_pColorTable = NULL;
	}
}

BOOL CColorPaletteWnd::PreTranslateMessage(MSG* pMsg) 
{
	// 툴팁 컨트롤에게 마우스 이벤트를 전달한다
	m_wndToolTip.RelayEvent(pMsg);

	// 만약 현재 마우스 캡춰를 다른 윈도우에서 하고 있다면
	// 팔레트 윈도우가 마우스 이벤트를 캡처하도록 한다
	if(GetCapture())
		if(GetCapture()->m_hWnd != m_hWnd)		SetCapture();

	return CWnd::PreTranslateMessage(pMsg);
}

void CColorPaletteWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// 부드러운 화면 출력을 위해 더블 버퍼링을 사용한다
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	CBitmap bmp, *pOldBmp;
	bmp.CreateCompatibleBitmap(&dc, m_rcWindow.right, m_rcWindow.bottom);
	pOldBmp = MemDC.SelectObject(&bmp);

	// 배경을 기본 배경 색으로 출력한다
	MemDC.FillSolidRect(m_rcWindow, m_clrBkgnd);
	// 테두리를 출력한다
	MemDC.DrawEdge(m_rcWindow, EDGE_RAISED, BF_RECT);

	// 기본 색상 버튼(-1)부터 각 색상 항목, 그리고 More Colors 버튼(40)을 화면에 출력한다
	int i;
	for(i = -1; i < 41; i++)
	{
		DrawColorCell(&MemDC, i);
	}

	// 메모리에 그려진 그림을 화면에 출력한다
	dc.BitBlt(0, 0, m_rcWindow.right, m_rcWindow.bottom, &MemDC, 0, 0, SRCCOPY);

	// GDI 객체들을 제거한다
	MemDC.SelectObject(pOldBmp);

	bmp.DeleteObject();
	MemDC.DeleteDC();
}

// 팔레트 윈도우의 각 구성요소를 화면에 출력하는 함수
void CColorPaletteWnd::DrawColorCell(CDC *pDC, int nItem)
{
	CRect rcTemp;
	// 출력하려는 항목이 현재 항목인지 체크
	BOOL bSelected = (nItem == m_nSelected);

	// 현재 항목인지에 따라 텍스트의 색상을 변경한다
	COLORREF clrOldText = pDC->SetTextColor(bSelected ? RGB(255, 255, 255) : RGB(0, 0, 0));
	// 텍스트 출력 배경을 투명으로 한다
	int nBkMode = pDC->SetBkMode(TRANSPARENT);
	// 텍스트 출력 폰트를 설정한다
	CFont *pOldFont = pDC->SelectObject(&m_TextFont);

	// 출력하려는 항목에 따라 화면에 출력한다
	switch(nItem)
	{
	case -1:
		// 기본 색상 버튼
		rcTemp = m_rcDefault;

		// 배경색으로 지우고 아래쪽 구분자를 그린다
		pDC->FillSolidRect(rcTemp, m_clrBkgnd);
		pDC->DrawEdge(rcTemp, EDGE_ETCHED, BF_BOTTOM);

		// 버튼의 수직 크기를 줄이고
		rcTemp.bottom -= 3;

		// 만약 현재 선택된 상태라면 반전 색상으로 버튼을 다시 그린다
		if(bSelected)
			pDC->FillSolidRect(rcTemp, ::GetSysColor(COLOR_HIGHLIGHT));

		// 텍스트를 출력한다
		pDC->DrawText("기본 색상", 9, rcTemp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	case 40:
		// More Colors 버튼
		rcTemp = m_rcMore;

		// 배경색으로 지우고 위쪽 구분자를 그린다
		pDC->FillSolidRect(rcTemp, m_clrBkgnd);
		pDC->DrawEdge(rcTemp, EDGE_ETCHED, BF_TOP);

		// 버튼의 수직 크기를 줄이고
		rcTemp.top += 2;

		// 만약 현재 선택된 상태라면 반전 색상으로 버튼을 다시 그린다
		if(bSelected)
			pDC->FillSolidRect(rcTemp, ::GetSysColor(COLOR_HIGHLIGHT));

		// 텍스트를 출력한다
		pDC->DrawText("More Colors...", 14, rcTemp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		break;
	default:
		// 항목 번호에 따른 사각 영역을 구한다
		rcTemp.left		= m_rcColorBox.left + (nItem % 8) * CONST_COLORBOX_SIZE;
		rcTemp.top		= m_rcColorBox.top + (nItem / 8) * CONST_COLORBOX_SIZE;
		rcTemp.right	= rcTemp.left + CONST_COLORBOX_SIZE - 1;
		rcTemp.bottom	= rcTemp.top + CONST_COLORBOX_SIZE - 1;

		// 배경색으로 지운다
		pDC->FillSolidRect(rcTemp, m_clrBkgnd);
		// 만약 현재 선택된 상태라면 
		if(bSelected)
		{
			// 테두리를 그린다
			pDC->FillSolidRect(rcTemp, ::GetSysColor(COLOR_HIGHLIGHT));
			rcTemp.DeflateRect(2, 2);
			pDC->FillSolidRect(rcTemp, RGB(200, 200, 200));
			rcTemp.DeflateRect(1, 1);
		}
		else
			rcTemp.DeflateRect(3, 3);

		// 색상을 출력한다
		pDC->FillSolidRect(&rcTemp, m_pColorTable[nItem].clrColor);
		break;
	}

	// GDI 객체 환원
	pDC->SelectObject(pOldFont);
	pDC->SetTextColor(clrOldText);
	pDC->SetBkMode(nBkMode);
}

BOOL CColorPaletteWnd::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
//	return CWnd::OnEraseBkgnd(pDC);
}

#if _MSC_VER <= 1200
	// VC++ 6.0에서의 코드
void CColorPaletteWnd::OnActivateApp(BOOL bActive,  HTASK dwThreadID) 
{
	CWnd::OnActivateApp(bActive, dwThreadID);
#else
	// VC++.Net에서의 코드
void CColorPaletteWnd::OnActivateApp(BOOL bActive, DWORD dwThreadID) 
{
	CWnd::OnActivateApp(bActive, dwThreadID);
#endif

	// 만약 다른 프로그램이 활성화 되었다면
	if(!bActive && !m_bColorDialog)
	{
		// 색상 선택이 취소 되도록 한다
		m_nSelected = -1;
		EndSelect(FALSE);
	}
}

void CColorPaletteWnd::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 마지막 선택 항목을 저장한다
	int nOldSelect = m_nSelected;

	// 만약 기본 버튼의 영역에 마우스가 있다면
	if(m_rcDefault.PtInRect(point))
	{
		// 기본 버튼의 번호를 설정한다
		m_nSelected = -1;
	}
	else
	{
		// 만약 More Colors 버튼의 영역에 마우스가 있다면
		if(m_rcMore.PtInRect(point))
		{
			// More Colors 버튼의 번호를 설정한다
			m_nSelected = 40;
		}
		else
		{
			// 만약 색상 항목들의 영역에 마우스가 있다면
			if(m_rcColorBox.PtInRect(point))
			{
				// 해당 색상 항목의 번호를 설정한다
				m_nSelected = ((point.y - m_rcColorBox.top) / CONST_COLORBOX_SIZE) * 8
					+ (point.x - m_rcColorBox.left) / CONST_COLORBOX_SIZE;
			}
		}
	}

	// 만약 팔레트 윈도우의 구성 요소에 마우스가 위치해 있다면
	if(m_nSelected >= -1 && m_nSelected <= 40 && m_nSelected != nOldSelect)
	{
		// 마지막 선택 항목을 비선택으로 다시 그리고
		// 새로 선택된 항목을 선택으로 다시 그린다
		CDC *pDC = GetDC();

		DrawColorCell(pDC, nOldSelect);
		DrawColorCell(pDC, m_nSelected);

		ReleaseDC(pDC);

		// 만약 부모 윈도우가 있다면 색상 바뀜을 알린다
		if(m_pParent)
		{
			if(m_nSelected < 0)
				m_pParent->SendMessage(CLR_TRACKCOLOR, m_nSelected, CLR_DEFAULT);
			else
				if(m_nSelected < 40)
					m_pParent->SendMessage(CLR_TRACKCOLOR, m_nSelected, m_pColorTable[m_nSelected].clrColor);
		}
	}
	
	CWnd::OnMouseMove(nFlags, point);
}

void CColorPaletteWnd::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CWnd::OnLButtonUp(nFlags, point);

	// 마우스가 팔레트 윈도우 밖에 있음을 설정한다
	m_nSelected = -2;

	// 만약 기본 버튼의 영역에 마우스가 있다면
	if(m_rcDefault.PtInRect(point))
	{
		// 기본 버튼의 번호를 설정한다
		m_nSelected = -1;
	}
	else
	{
		// 만약 More Colors 버튼의 영역에 마우스가 있다면
		if(m_rcMore.PtInRect(point))
		{
			// More Colors 버튼의 번호를 설정한다
			m_nSelected = 40;
		}
		else
		{
			// 만약 색상 항목들의 영역에 마우스가 있다면
			if(m_rcColorBox.PtInRect(point))
			{
				// 해당 색상 항목의 번호를 설정한다
				m_nSelected = ((point.y - m_rcColorBox.top) / CONST_COLORBOX_SIZE) * 8
					+ (point.x - m_rcColorBox.left) / CONST_COLORBOX_SIZE;
			}
		}
	}

	// 팔레트 윈도우의 구성 요소인지에 따라 색상 선택을 취소하거나 확인한다
	EndSelect(m_nSelected >= -1 && m_nSelected <= 40);
}

// 키보드에 의한 색상 변경 함수
void CColorPaletteWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// 마지막 선택 항목을 저장한다
	int nOldSelect = m_nSelected;

	switch(nChar)
	{
	case VK_LEFT:
		// 왼쪽 방향키가 눌려지면
		// 선택 항목 번호를 1 줄인다
		m_nSelected -= 1;
		// 만약 기본 색상 버튼의 번호보다 작아지면 More Colors 버튼 번호를 설정한다
		if(m_nSelected < -1)		m_nSelected = 40;
		break;
	case VK_RIGHT:
		// 오른쪽 방향키가 눌려지면
		// 선택 항목 번호를 1 증가시킨다
		m_nSelected += 1;
		// 만약 More Colors 버튼의 번호보다 커지면 기본 색상 버튼 번호를 설정한다
		if(m_nSelected > 40)		m_nSelected = -1;
		break;
	case VK_UP:
		// 위쪽 방향키가 눌려지면
		// 선택 항목 번호를 8 줄인다
		m_nSelected -= 8;
		// 만약 기본 색상 버튼에서 바뀐 것이라면 More Colors 버튼 번호를 설정한다
		if(m_nSelected < -8)		m_nSelected = 40;
		// 만약 색상 항목에서 바뀐 것이라면 기본 색상 버튼 번호를 설정한다
		if(m_nSelected < 0)			m_nSelected = -1;
		break;
	case VK_DOWN:
		// 아래쪽 방향키가 눌려지면
		// 선택 항목 번호를 8 증가시킨다
		m_nSelected += 8;
		// 만약 More Colors 버튼에서 바뀐 것이라면 기본 색상 버튼 번호를 설정한다
		if(m_nSelected > 47)		m_nSelected = -1;
		// 만약 색상 항목에서 바뀐 것이라면 More Colors 버튼 번호를 설정한다
		if(m_nSelected > 39)		m_nSelected = 40;
		break;
	case VK_ESCAPE:
		// ESC 키가 눌려지면 색상 선택을 취소한다
		EndSelect(FALSE);
		return;
	case VK_RETURN:
	case VK_SPACE:
		// 엔터키나 스페이스바가 눌려지면 현재 선택 색상을 확인한다
		EndSelect(TRUE);
		return;
	}

	// 마지막 선택 항목을 비선택으로 다시 그리고
	// 새로 선택된 항목을 선택으로 다시 그린다
	CDC *pDC = GetDC();

	DrawColorCell(pDC, nOldSelect);
	DrawColorCell(pDC, m_nSelected);

	ReleaseDC(pDC);

	// 만약 부모 윈도우가 있다면 색상 바뀜을 알린다
	if(m_pParent)
	{
		if(m_nSelected < 0)
			m_pParent->SendMessage(CLR_TRACKCOLOR, m_nSelected, CLR_DEFAULT);
		else
			if(m_nSelected < 40)
				m_pParent->SendMessage(CLR_TRACKCOLOR, m_nSelected, m_pColorTable[m_nSelected].clrColor);
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

// 사용자가 색상을 선택하거나 취소한 경우 처리하는 함수
void CColorPaletteWnd::EndSelect(BOOL bSelOK)
{
	// 만약에 색상 선택 취소라면
	if(!bSelOK)
	{
		// 팔레트 윈도우를 소멸시키고
		DestroyWindow();
		// 부모 윈도우에게 팔레트 윈도우가 닫혔음을 알린다
		m_pParent->SendMessage(CLR_CLOSEUP, 0, m_clrColor);

		// 부모 윈도우에게 색상 선택이 취소되었음을 알린다
		m_pParent->SendMessage(CLR_SELENDCANCEL, 0, m_clrColor);
		return;
	}

	// 만약 More Colors 버튼을 선택했다면
	if(m_nSelected == 40)
	{
		// 컬러 다이얼로그가 띄워졌음을 설정한다
		m_bColorDialog = TRUE;

		// 초기 색상으로 컬러 다이얼로그를 띄운다
		CColorDialog dlg(m_clrColor, CC_FULLOPEN | CC_ANYCOLOR, this);

		// 사용자 정의 색상을 레지스트리에서 읽어 컬러 다이얼로그에 설정한다
		COLORREF clrCustom[16];

		int i;
		CString strTemp;

		for(i = 0; i < 16; i++)
		{
			strTemp.Format("Color%d", i);
			clrCustom[i] = AfxGetApp()->GetProfileInt("Custom Color", strTemp, RGB(255, 255, 255));
		}

		dlg.m_cc.lpCustColors = clrCustom;

		// 컬러 다이얼로그를 띄운다
		BOOL bOK = (dlg.DoModal() == IDOK);

		// 사용자 정의 색상을 레지스트리에 저장한다
		for(i = 0; i < 16; i++)
		{
			strTemp.Format("Color%d", i);
			AfxGetApp()->WriteProfileInt("Custom Color", strTemp, clrCustom[i]);
		}
		m_bColorDialog = FALSE;

		// 만약 색상을 선택하지 않았다면
		if(!bOK)
		{
			// 다시 마우스 이벤트를 캡춰하고 포커스를 갖는다

			SetFocus();
			SetCapture();

			return;
		}

		// 새로 설정된 색상을 저장한다
		m_clrColor = dlg.GetColor();
	}
	else
	{
		// 현재 선택한 색상을 저장한다
		if(m_nSelected < 0)
		{
			m_clrColor = CLR_DEFAULT;
		}
		else
		{
			m_clrColor = m_pColorTable[m_nSelected].clrColor;
		}
	}

	// 팔레트 윈도우를 소멸시키고
	DestroyWindow();
	// 부모 윈도우에게 팔레트 윈도우가 닫혔음을 알린다
	m_pParent->SendMessage(CLR_CLOSEUP, 0, m_clrColor);

	// 부모 윈도우에게 색상 선택 완료되었음을 알린다
	m_pParent->SendMessage(CLR_SELENDOK, 0, m_clrColor);
}
