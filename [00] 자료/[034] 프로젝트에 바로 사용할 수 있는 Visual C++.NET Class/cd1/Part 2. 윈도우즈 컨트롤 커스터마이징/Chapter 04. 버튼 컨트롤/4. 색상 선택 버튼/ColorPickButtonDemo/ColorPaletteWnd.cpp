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

// ��� ����
#define CONST_COLORBOX_SIZE			18				// ���� �׸��� ũ��
#define CONST_TEXT_HEIGHT			20				// �⺻ ����� More Colors ��ư�� ����

// ���� ���� �ʱ�ȭ
COLOR_TABLE *CColorPaletteWnd::m_pColorTable = NULL;	// ���� ���̺��� �ʱ�ȭ
int CColorPaletteWnd::m_nCount		 = 0;	// ���� ���̺� ���� ������ �ʱ�ȭ


CColorPaletteWnd::CColorPaletteWnd()
{
	// ���� ���̺��� �ʱ�ȭ�Ѵ�
	InitColorTable();

	// ���� �������� �ʱ�ȭ �Ѵ�
	m_pParent		= NULL;
	m_clrColor		= RGB(0, 0, 0);
	m_clrBkgnd		= ::GetSysColor(COLOR_BTNFACE);
	m_nBorder		= ::GetSystemMetrics(SM_CXEDGE);

	m_bColorDialog	= FALSE;

	// ��Ʈ ����
	HDC hDC = ::GetDC(NULL);
	m_TextFont.CreateFont(-MulDiv(9, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, FW_NORMAL,
		0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, "����");
	::ReleaseDC(NULL, hDC);

	// �� �������� �ʱ�ȭ�Ѵ�
	m_rcDefault.SetRect(m_nBorder, m_nBorder,
		m_nBorder + 8 * CONST_COLORBOX_SIZE, m_nBorder + CONST_TEXT_HEIGHT);
	m_rcColorBox.SetRect(m_nBorder, m_rcDefault.bottom + m_nBorder,
		m_rcDefault.right, m_rcDefault.bottom + m_nBorder + 5 * CONST_COLORBOX_SIZE);
	m_rcMore.SetRect(m_nBorder, m_rcColorBox.bottom + m_nBorder,
		m_rcColorBox.right, m_rcColorBox.bottom + m_nBorder + CONST_TEXT_HEIGHT);
	m_rcWindow.SetRect(0, 0, m_rcMore.right + m_nBorder, m_rcMore.bottom + m_nBorder);
}

// ���� ���̺� ���� �ʱ�ȭ �Լ�
void CColorPaletteWnd::InitColorTable()
{
	// ī��Ʈ�� 1 ������Ų��
	m_nCount++;

	// �̹� ���� ���̺��� �ʱ�ȭ �Ǿ� �ִٸ� �׳� �����Ѵ�
	if(m_pColorTable != NULL)			return;

	// ���� ���̺��� ����� �� ������ �ʱ�ȭ�Ѵ�
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
	// �ؽ�Ʈ ��Ʈ�� �����Ѵ�
	m_TextFont.DeleteObject();

	// ī��Ʈ�� 1 ���� ��Ų��
	m_nCount--;

	// ���� ������ ���̻� ���� ���� ���̺��� �����Ѵٸ� �����Ѵ�
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

// �ʱ� ����� ��ġ�� �ȷ�Ʈ �����츦 �����ϴ� �Լ�
BOOL CColorPaletteWnd::Init(COLORREF clrColor, CWnd *pParent, int x, int y, UINT nID)
{
	// �ʱ� ����� �θ� �����쿡 ���� �ڵ��� �����Ѵ�
	m_clrColor	= clrColor;
	m_pParent	= pParent;

	// �ȷ�Ʈ �����찡 ��µ� �θ� �����쿡���� ��ǥ�� ��ü ȭ�鿡���� ��ǥ�� ��ȯ�Ѵ�
	CRect rcWnd = m_rcWindow;
	rcWnd.OffsetRect(x, y);
	m_pParent->ClientToScreen(&rcWnd);

	// �������� �۾� ������ ���Ѵ�
	CRect rcWorkArea;
	::SystemParametersInfo(SPI_GETWORKAREA, 0, &rcWorkArea, 0);

	// ���� �������� �۾� ������ ��� ���
	// �ȷ�Ʈ �������� ��� ��ġ�� �۾� ���� �������� �����Ѵ�
	int nOffsetX = 0;
	int nOffsetY = 0;

	if(rcWnd.left < 0)
		nOffsetX = rcWnd.left * -1;
	if(rcWnd.right > rcWorkArea.right)
		nOffsetX = rcWorkArea.right - rcWnd.right;
	if(rcWnd.bottom > rcWorkArea.bottom)
		nOffsetY = -1 * (y + rcWnd.Height());

	rcWnd.OffsetRect(nOffsetX, nOffsetY);

	// �˾� ������ν� �����ϱ� ���� ������ Ŭ������ ����Ѵ�
	UINT nStyle = CS_CLASSDC | CS_SAVEBITS | CS_HREDRAW | CS_VREDRAW;
	CString strClassName = AfxRegisterWndClass(nStyle, 0, 0, 0);

	// �˾� ������ν� �����Ѵ�
	if(!CreateEx(0, strClassName, "Palette", WS_VISIBLE | WS_POPUP, rcWnd, m_pParent, 0, NULL))
	{
		return FALSE;
	}

	// ȭ�鿡 �����Ѵ�
	ShowWindow(SW_SHOW);
	UpdateWindow();

	// ���� �����츦 �����ϰ�
	if(!m_wndToolTip.Create(this))		return FALSE;

	// �� ��ư�� ������ �����Ѵ�
	m_wndToolTip.AddTool(this, "�⺻ ����", m_rcDefault, 1);
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

	// �ʱ� ���� ���� ���� ���̺����� ��ȣ�� ã�´�
	m_nSelected = FindColor(m_clrColor);

	// ���콺 �̺�Ʈ�� ĸ���Ѵ�
	SetCapture();

	return TRUE;
}

// Ư�� ���� ���� ���� ���̺����� ��ȣ�� �����ϴ� �Լ�
int CColorPaletteWnd::FindColor(COLORREF clrColor)
{
	int i;

	// �⺻ �����̸� �⺻ ���� ��ư�� ��ȣ(-1)�� �����Ѵ�
	if(clrColor == CLR_DEFAULT)			return -1;

	// ���� ���̺� �����Ѵٸ� ���� ���̺����� ��ȣ�� �����Ѵ�
	for(i = 0; i < 40; i++)
	{
		if(m_pColorTable[i].clrColor == clrColor)
			return i;
	}

	// ���� ���̺� �������� �ʴ´ٸ�
	// More Colors ��ư�� ��ȣ(40)�� �����Ѵ�
	return 40;
}

// Ư�� ���� ���� ���� �̸��� �����ϴ� �Լ�
void CColorPaletteWnd::FindColorName(COLORREF clrColor, CString &strName)
{
	// �⺻ �����̸� "�⺻ ����"�� �����Ѵ�
	if(clrColor == CLR_DEFAULT)
	{
		strName = "�⺻ ����";
		return;
	}

	int i;

	// ���� ���̺��� �ʱ�ȭ�Ѵ�
	InitColorTable();

	// ���� ���̺� �����Ѵٸ� ���� ���̺��� ���� �̸��� �����Ѵ�
	for(i = 0; i < 40; i++)
	{
		if(m_pColorTable[i].clrColor == clrColor)
		{
			strName = m_pColorTable[i].strName;

			// ���� ���̺� ������ ���ҽ�Ű�� ���̻� ������ ���ٸ� �����Ѵ�
			m_nCount--;
			if(m_nCount == 0)
			{
				delete[] m_pColorTable;
				m_pColorTable = NULL;
			}
			return;
		}
	}

	// ���� ���̺� �������� �ʴ´ٸ�
	// "RGB(255, 255, 255)" ���·� �����Ѵ�
	strName.Format("RGB(%d, %d, %d)", GetRValue(m_pColorTable[i].clrColor),
		GetGValue(m_pColorTable[i].clrColor),
		GetBValue(m_pColorTable[i].clrColor));

	// ���� ���̺� ������ ���ҽ�Ű�� ���̻� ������ ���ٸ� �����Ѵ�
	m_nCount--;
	if(m_nCount == 0)
	{
		delete[] m_pColorTable;
		m_pColorTable = NULL;
	}
}

BOOL CColorPaletteWnd::PreTranslateMessage(MSG* pMsg) 
{
	// ���� ��Ʈ�ѿ��� ���콺 �̺�Ʈ�� �����Ѵ�
	m_wndToolTip.RelayEvent(pMsg);

	// ���� ���� ���콺 ĸ�縦 �ٸ� �����쿡�� �ϰ� �ִٸ�
	// �ȷ�Ʈ �����찡 ���콺 �̺�Ʈ�� ĸó�ϵ��� �Ѵ�
	if(GetCapture())
		if(GetCapture()->m_hWnd != m_hWnd)		SetCapture();

	return CWnd::PreTranslateMessage(pMsg);
}

void CColorPaletteWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// �ε巯�� ȭ�� ����� ���� ���� ���۸��� ����Ѵ�
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	CBitmap bmp, *pOldBmp;
	bmp.CreateCompatibleBitmap(&dc, m_rcWindow.right, m_rcWindow.bottom);
	pOldBmp = MemDC.SelectObject(&bmp);

	// ����� �⺻ ��� ������ ����Ѵ�
	MemDC.FillSolidRect(m_rcWindow, m_clrBkgnd);
	// �׵θ��� ����Ѵ�
	MemDC.DrawEdge(m_rcWindow, EDGE_RAISED, BF_RECT);

	// �⺻ ���� ��ư(-1)���� �� ���� �׸�, �׸��� More Colors ��ư(40)�� ȭ�鿡 ����Ѵ�
	int i;
	for(i = -1; i < 41; i++)
	{
		DrawColorCell(&MemDC, i);
	}

	// �޸𸮿� �׷��� �׸��� ȭ�鿡 ����Ѵ�
	dc.BitBlt(0, 0, m_rcWindow.right, m_rcWindow.bottom, &MemDC, 0, 0, SRCCOPY);

	// GDI ��ü���� �����Ѵ�
	MemDC.SelectObject(pOldBmp);

	bmp.DeleteObject();
	MemDC.DeleteDC();
}

// �ȷ�Ʈ �������� �� ������Ҹ� ȭ�鿡 ����ϴ� �Լ�
void CColorPaletteWnd::DrawColorCell(CDC *pDC, int nItem)
{
	CRect rcTemp;
	// ����Ϸ��� �׸��� ���� �׸����� üũ
	BOOL bSelected = (nItem == m_nSelected);

	// ���� �׸������� ���� �ؽ�Ʈ�� ������ �����Ѵ�
	COLORREF clrOldText = pDC->SetTextColor(bSelected ? RGB(255, 255, 255) : RGB(0, 0, 0));
	// �ؽ�Ʈ ��� ����� �������� �Ѵ�
	int nBkMode = pDC->SetBkMode(TRANSPARENT);
	// �ؽ�Ʈ ��� ��Ʈ�� �����Ѵ�
	CFont *pOldFont = pDC->SelectObject(&m_TextFont);

	// ����Ϸ��� �׸� ���� ȭ�鿡 ����Ѵ�
	switch(nItem)
	{
	case -1:
		// �⺻ ���� ��ư
		rcTemp = m_rcDefault;

		// �������� ����� �Ʒ��� �����ڸ� �׸���
		pDC->FillSolidRect(rcTemp, m_clrBkgnd);
		pDC->DrawEdge(rcTemp, EDGE_ETCHED, BF_BOTTOM);

		// ��ư�� ���� ũ�⸦ ���̰�
		rcTemp.bottom -= 3;

		// ���� ���� ���õ� ���¶�� ���� �������� ��ư�� �ٽ� �׸���
		if(bSelected)
			pDC->FillSolidRect(rcTemp, ::GetSysColor(COLOR_HIGHLIGHT));

		// �ؽ�Ʈ�� ����Ѵ�
		pDC->DrawText("�⺻ ����", 9, rcTemp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	case 40:
		// More Colors ��ư
		rcTemp = m_rcMore;

		// �������� ����� ���� �����ڸ� �׸���
		pDC->FillSolidRect(rcTemp, m_clrBkgnd);
		pDC->DrawEdge(rcTemp, EDGE_ETCHED, BF_TOP);

		// ��ư�� ���� ũ�⸦ ���̰�
		rcTemp.top += 2;

		// ���� ���� ���õ� ���¶�� ���� �������� ��ư�� �ٽ� �׸���
		if(bSelected)
			pDC->FillSolidRect(rcTemp, ::GetSysColor(COLOR_HIGHLIGHT));

		// �ؽ�Ʈ�� ����Ѵ�
		pDC->DrawText("More Colors...", 14, rcTemp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		break;
	default:
		// �׸� ��ȣ�� ���� �簢 ������ ���Ѵ�
		rcTemp.left		= m_rcColorBox.left + (nItem % 8) * CONST_COLORBOX_SIZE;
		rcTemp.top		= m_rcColorBox.top + (nItem / 8) * CONST_COLORBOX_SIZE;
		rcTemp.right	= rcTemp.left + CONST_COLORBOX_SIZE - 1;
		rcTemp.bottom	= rcTemp.top + CONST_COLORBOX_SIZE - 1;

		// �������� �����
		pDC->FillSolidRect(rcTemp, m_clrBkgnd);
		// ���� ���� ���õ� ���¶�� 
		if(bSelected)
		{
			// �׵θ��� �׸���
			pDC->FillSolidRect(rcTemp, ::GetSysColor(COLOR_HIGHLIGHT));
			rcTemp.DeflateRect(2, 2);
			pDC->FillSolidRect(rcTemp, RGB(200, 200, 200));
			rcTemp.DeflateRect(1, 1);
		}
		else
			rcTemp.DeflateRect(3, 3);

		// ������ ����Ѵ�
		pDC->FillSolidRect(&rcTemp, m_pColorTable[nItem].clrColor);
		break;
	}

	// GDI ��ü ȯ��
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
	// VC++ 6.0������ �ڵ�
void CColorPaletteWnd::OnActivateApp(BOOL bActive,  HTASK dwThreadID) 
{
	CWnd::OnActivateApp(bActive, dwThreadID);
#else
	// VC++.Net������ �ڵ�
void CColorPaletteWnd::OnActivateApp(BOOL bActive, DWORD dwThreadID) 
{
	CWnd::OnActivateApp(bActive, dwThreadID);
#endif

	// ���� �ٸ� ���α׷��� Ȱ��ȭ �Ǿ��ٸ�
	if(!bActive && !m_bColorDialog)
	{
		// ���� ������ ��� �ǵ��� �Ѵ�
		m_nSelected = -1;
		EndSelect(FALSE);
	}
}

void CColorPaletteWnd::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ������ ���� �׸��� �����Ѵ�
	int nOldSelect = m_nSelected;

	// ���� �⺻ ��ư�� ������ ���콺�� �ִٸ�
	if(m_rcDefault.PtInRect(point))
	{
		// �⺻ ��ư�� ��ȣ�� �����Ѵ�
		m_nSelected = -1;
	}
	else
	{
		// ���� More Colors ��ư�� ������ ���콺�� �ִٸ�
		if(m_rcMore.PtInRect(point))
		{
			// More Colors ��ư�� ��ȣ�� �����Ѵ�
			m_nSelected = 40;
		}
		else
		{
			// ���� ���� �׸���� ������ ���콺�� �ִٸ�
			if(m_rcColorBox.PtInRect(point))
			{
				// �ش� ���� �׸��� ��ȣ�� �����Ѵ�
				m_nSelected = ((point.y - m_rcColorBox.top) / CONST_COLORBOX_SIZE) * 8
					+ (point.x - m_rcColorBox.left) / CONST_COLORBOX_SIZE;
			}
		}
	}

	// ���� �ȷ�Ʈ �������� ���� ��ҿ� ���콺�� ��ġ�� �ִٸ�
	if(m_nSelected >= -1 && m_nSelected <= 40 && m_nSelected != nOldSelect)
	{
		// ������ ���� �׸��� �������� �ٽ� �׸���
		// ���� ���õ� �׸��� �������� �ٽ� �׸���
		CDC *pDC = GetDC();

		DrawColorCell(pDC, nOldSelect);
		DrawColorCell(pDC, m_nSelected);

		ReleaseDC(pDC);

		// ���� �θ� �����찡 �ִٸ� ���� �ٲ��� �˸���
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

	// ���콺�� �ȷ�Ʈ ������ �ۿ� ������ �����Ѵ�
	m_nSelected = -2;

	// ���� �⺻ ��ư�� ������ ���콺�� �ִٸ�
	if(m_rcDefault.PtInRect(point))
	{
		// �⺻ ��ư�� ��ȣ�� �����Ѵ�
		m_nSelected = -1;
	}
	else
	{
		// ���� More Colors ��ư�� ������ ���콺�� �ִٸ�
		if(m_rcMore.PtInRect(point))
		{
			// More Colors ��ư�� ��ȣ�� �����Ѵ�
			m_nSelected = 40;
		}
		else
		{
			// ���� ���� �׸���� ������ ���콺�� �ִٸ�
			if(m_rcColorBox.PtInRect(point))
			{
				// �ش� ���� �׸��� ��ȣ�� �����Ѵ�
				m_nSelected = ((point.y - m_rcColorBox.top) / CONST_COLORBOX_SIZE) * 8
					+ (point.x - m_rcColorBox.left) / CONST_COLORBOX_SIZE;
			}
		}
	}

	// �ȷ�Ʈ �������� ���� ��������� ���� ���� ������ ����ϰų� Ȯ���Ѵ�
	EndSelect(m_nSelected >= -1 && m_nSelected <= 40);
}

// Ű���忡 ���� ���� ���� �Լ�
void CColorPaletteWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// ������ ���� �׸��� �����Ѵ�
	int nOldSelect = m_nSelected;

	switch(nChar)
	{
	case VK_LEFT:
		// ���� ����Ű�� ��������
		// ���� �׸� ��ȣ�� 1 ���δ�
		m_nSelected -= 1;
		// ���� �⺻ ���� ��ư�� ��ȣ���� �۾����� More Colors ��ư ��ȣ�� �����Ѵ�
		if(m_nSelected < -1)		m_nSelected = 40;
		break;
	case VK_RIGHT:
		// ������ ����Ű�� ��������
		// ���� �׸� ��ȣ�� 1 ������Ų��
		m_nSelected += 1;
		// ���� More Colors ��ư�� ��ȣ���� Ŀ���� �⺻ ���� ��ư ��ȣ�� �����Ѵ�
		if(m_nSelected > 40)		m_nSelected = -1;
		break;
	case VK_UP:
		// ���� ����Ű�� ��������
		// ���� �׸� ��ȣ�� 8 ���δ�
		m_nSelected -= 8;
		// ���� �⺻ ���� ��ư���� �ٲ� ���̶�� More Colors ��ư ��ȣ�� �����Ѵ�
		if(m_nSelected < -8)		m_nSelected = 40;
		// ���� ���� �׸񿡼� �ٲ� ���̶�� �⺻ ���� ��ư ��ȣ�� �����Ѵ�
		if(m_nSelected < 0)			m_nSelected = -1;
		break;
	case VK_DOWN:
		// �Ʒ��� ����Ű�� ��������
		// ���� �׸� ��ȣ�� 8 ������Ų��
		m_nSelected += 8;
		// ���� More Colors ��ư���� �ٲ� ���̶�� �⺻ ���� ��ư ��ȣ�� �����Ѵ�
		if(m_nSelected > 47)		m_nSelected = -1;
		// ���� ���� �׸񿡼� �ٲ� ���̶�� More Colors ��ư ��ȣ�� �����Ѵ�
		if(m_nSelected > 39)		m_nSelected = 40;
		break;
	case VK_ESCAPE:
		// ESC Ű�� �������� ���� ������ ����Ѵ�
		EndSelect(FALSE);
		return;
	case VK_RETURN:
	case VK_SPACE:
		// ����Ű�� �����̽��ٰ� �������� ���� ���� ������ Ȯ���Ѵ�
		EndSelect(TRUE);
		return;
	}

	// ������ ���� �׸��� �������� �ٽ� �׸���
	// ���� ���õ� �׸��� �������� �ٽ� �׸���
	CDC *pDC = GetDC();

	DrawColorCell(pDC, nOldSelect);
	DrawColorCell(pDC, m_nSelected);

	ReleaseDC(pDC);

	// ���� �θ� �����찡 �ִٸ� ���� �ٲ��� �˸���
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

// ����ڰ� ������ �����ϰų� ����� ��� ó���ϴ� �Լ�
void CColorPaletteWnd::EndSelect(BOOL bSelOK)
{
	// ���࿡ ���� ���� ��Ҷ��
	if(!bSelOK)
	{
		// �ȷ�Ʈ �����츦 �Ҹ��Ű��
		DestroyWindow();
		// �θ� �����쿡�� �ȷ�Ʈ �����찡 �������� �˸���
		m_pParent->SendMessage(CLR_CLOSEUP, 0, m_clrColor);

		// �θ� �����쿡�� ���� ������ ��ҵǾ����� �˸���
		m_pParent->SendMessage(CLR_SELENDCANCEL, 0, m_clrColor);
		return;
	}

	// ���� More Colors ��ư�� �����ߴٸ�
	if(m_nSelected == 40)
	{
		// �÷� ���̾�αװ� ��������� �����Ѵ�
		m_bColorDialog = TRUE;

		// �ʱ� �������� �÷� ���̾�α׸� ����
		CColorDialog dlg(m_clrColor, CC_FULLOPEN | CC_ANYCOLOR, this);

		// ����� ���� ������ ������Ʈ������ �о� �÷� ���̾�α׿� �����Ѵ�
		COLORREF clrCustom[16];

		int i;
		CString strTemp;

		for(i = 0; i < 16; i++)
		{
			strTemp.Format("Color%d", i);
			clrCustom[i] = AfxGetApp()->GetProfileInt("Custom Color", strTemp, RGB(255, 255, 255));
		}

		dlg.m_cc.lpCustColors = clrCustom;

		// �÷� ���̾�α׸� ����
		BOOL bOK = (dlg.DoModal() == IDOK);

		// ����� ���� ������ ������Ʈ���� �����Ѵ�
		for(i = 0; i < 16; i++)
		{
			strTemp.Format("Color%d", i);
			AfxGetApp()->WriteProfileInt("Custom Color", strTemp, clrCustom[i]);
		}
		m_bColorDialog = FALSE;

		// ���� ������ �������� �ʾҴٸ�
		if(!bOK)
		{
			// �ٽ� ���콺 �̺�Ʈ�� ĸ���ϰ� ��Ŀ���� ���´�

			SetFocus();
			SetCapture();

			return;
		}

		// ���� ������ ������ �����Ѵ�
		m_clrColor = dlg.GetColor();
	}
	else
	{
		// ���� ������ ������ �����Ѵ�
		if(m_nSelected < 0)
		{
			m_clrColor = CLR_DEFAULT;
		}
		else
		{
			m_clrColor = m_pColorTable[m_nSelected].clrColor;
		}
	}

	// �ȷ�Ʈ �����츦 �Ҹ��Ű��
	DestroyWindow();
	// �θ� �����쿡�� �ȷ�Ʈ �����찡 �������� �˸���
	m_pParent->SendMessage(CLR_CLOSEUP, 0, m_clrColor);

	// �θ� �����쿡�� ���� ���� �Ϸ�Ǿ����� �˸���
	m_pParent->SendMessage(CLR_SELENDOK, 0, m_clrColor);
}
