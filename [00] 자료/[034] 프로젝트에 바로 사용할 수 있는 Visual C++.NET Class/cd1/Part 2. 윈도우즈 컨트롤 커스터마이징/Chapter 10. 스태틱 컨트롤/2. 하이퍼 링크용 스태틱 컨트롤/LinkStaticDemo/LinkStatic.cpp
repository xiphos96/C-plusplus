// LinkStatic.cpp : implementation file
//

#include "stdafx.h"
#include "linkstaticdemo.h"
#include "LinkStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkStatic

// �� ����� ���콺 Ŀ�� ID
#define IDC_HAND            MAKEINTRESOURCE(32649)
// ���ΰ� �ؽ�Ʈ ������ ����
#define CONST_ITEM_GAP		6


CLinkStatic::CLinkStatic()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_clrText		= RGB(0, 0, 238);
	m_clrHover		= ::GetSysColor(COLOR_HIGHLIGHTTEXT);
	m_clrBkgnd		= ::GetSysColor(COLOR_BTNFACE);

	m_bHover		= FALSE;
	m_bLeftImage	= TRUE;

	// �ո�� ���콺 Ŀ���� �ε��Ѵ�
	m_hCursor		= ::LoadCursor(NULL, MAKEINTRESOURCE(IDC_HAND));
}

CLinkStatic::~CLinkStatic()
{
	// ���� ���ҽ����� ��ȯ�Ѵ�
	if(m_hCursor)				::DeleteObject(m_hCursor);

	if(m_bmpImage.m_hObject)	m_bmpImage.DeleteObject();
	if(m_bmpMask.m_hObject)		m_bmpMask.DeleteObject();
	m_HoverFont.DeleteObject();
}


BEGIN_MESSAGE_MAP(CLinkStatic, CStatic)
	//{{AFX_MSG_MAP(CLinkStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_CONTROL_REFLECT(BN_CLICKED, OnClicked)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkStatic message handlers

void CLinkStatic::PreSubclassWindow() 
{
	// �׵θ� �Ӽ��� ���ְ� �˸� �޽��� �Ӽ��� �����Ѵ�
	ModifyStyle(WS_BORDER, SS_NOTIFY);
	ModifyStyleEx(WS_EX_CLIENTEDGE | WS_EX_STATICEDGE, 0);

	// Ŭ���̾�Ʈ ������ ���Ѵ�
	GetClientRect(&m_rcClient);
	// �ؽ�Ʈ�� ��� ������ Ŭ���̾�Ʈ �������� �����Ѵ�
	m_rcText = m_rcClient;

	// ����ƽ ��Ʈ���� ��Ʈ�� ��´�
	LOGFONT LogFont;
	CFont *pFont = GetFont();
	// ����ƽ ��Ʈ���� ��Ʈ���� �α� ��Ʈ�� ��´�
	pFont->GetLogFont(&LogFont);

	// ���� �Ӽ��� �����Ѵ�
	LogFont.lfUnderline = TRUE;

	// ���� �Ӽ��� ���� ��Ʈ�� �����Ѵ�
	m_HoverFont.CreateFontIndirect(&LogFont);

	// ���� ��Ʈ���� �����Ѵ�
	m_wndToolTip.Create(this, TTS_ALWAYSTIP);
	m_wndToolTip.Activate(FALSE);
	m_wndToolTip.AddTool(this, m_strToolTip, m_rcClient, 1);
	m_wndToolTip.Activate(TRUE);

	CStatic::PreSubclassWindow();
}

BOOL CLinkStatic::PreTranslateMessage(MSG* pMsg) 
{
	// ���� ��Ʈ�ѿ��� ���콺 �̺�Ʈ�� �����Ѵ�
	m_wndToolTip.RelayEvent(pMsg);
	
	return CStatic::PreTranslateMessage(pMsg);
}

void CLinkStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	// �ε巯�� ȭ�� ����� ���� ���� ���۸��� �Ѵ�
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);

	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// ����� �������� ĥ�Ѵ�
	MemDC.FillSolidRect(&m_rcClient, m_clrBkgnd);

	// ��Ʈ���� �����Ǿ��ٸ�
	if(m_bmpImage.m_hObject)
	{
		// ��Ʈ���� �̹��� ��� ������ ����Ѵ�
		CDC BmpDC;
		BmpDC.CreateCompatibleDC(NULL);

		CBitmap *pOldBmp = BmpDC.SelectObject(&m_bmpImage);

		// ���� ������� ����Ǿ� �ִٸ�
		if(m_bmpMask.m_hObject)
		{
			// ����ũ ��Ʈ���� ����ؼ� ���� ó���� �Ͽ� ��Ʈ���� ����Ѵ�
			CDC MaskDC;
			MaskDC.CreateCompatibleDC(NULL);
			CBitmap *pOldMask = MaskDC.SelectObject(&m_bmpMask);

			// ����ũ ��Ʈ���� ����̱� ������,
			// 1�� ������ �⺻ ������ �Ͼ������ �ٲ�� 0�� ���ڻ��� ���������� �ٲ��.
			// �׸��� ȭ���� ����� AND �Ǿ�,
			// ����ũ�� ���� ������ ����� �״�� �巯���� ����ũ�� �̹��� ������ ���������� ����� ��������.
			MemDC.BitBlt(m_ptImage.x, m_ptImage.y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight,
				&MaskDC, 0, 0, SRCAND);
			// ���� ��Ʈ���� ���� �κ��� �̹� ���������� ó���Ǿ��� ������
			// ���� �κ��� ���� OR �Ǿ� ����� �״�� �����ϰ�,
			// ���� ��Ʈ���� ������ �κ��� �״�� �����Ǿ� �����Ƿ�
			// ����� �������� OR �Ǿ� ���� �̹����� �״�� ����Ѵ�.
			MemDC.BitBlt(m_ptImage.x, m_ptImage.y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight,
				&BmpDC, 0, 0, SRCPAINT);

			MaskDC.SelectObject(pOldMask);
			MaskDC.DeleteDC();
		}
		else
		{
			// ������� ������� �ʾҴٸ� �̹����� �׳� ����Ѵ�
			MemDC.BitBlt(m_ptImage.x, m_ptImage.y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight,
				&BmpDC, 0, 0, SRCCOPY);
		}

		BmpDC.SelectObject(pOldBmp);
		BmpDC.DeleteDC();
	}

	// �⺻ ��Ʈ�� �����Ѵ�
	CFont *pOldFont = MemDC.SelectObject(GetFont());
	if(m_bHover)
	{
		// ���� ���콺�� ��ġ�� �ִٸ� ���� ��Ʈ�� �����Ѵ�
		MemDC.SelectObject(&m_HoverFont);
		MemDC.SetTextColor(m_clrHover);
	}
	else
	{
		MemDC.SetTextColor(m_clrText);
	}
	// �ؽ�Ʈ�� ����� �������� �����Ѵ�
	MemDC.SetBkMode(TRANSPARENT);

	// �̹����� ��ġ�� ���� �ؽ�Ʈ�� �����Ѵ�
	int nDrawMode = DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
	if(m_bLeftImage)	nDrawMode |= DT_LEFT;
	else				nDrawMode |= DT_RIGHT;

	// ����ƽ ��Ʈ���� �ؽ�Ʈ�� ��� ����Ѵ�
	CString strText;
	GetWindowText(strText);
	MemDC.DrawText(strText, &m_rcText, nDrawMode);

	// ���� ��Ʈ�� ��ȯ�Ѵ�
	MemDC.SelectObject(pOldFont);

	// �޸� DC�� �ִ� ������ ȭ������ ����Ѵ�
	dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(),
		&MemDC, 0, 0, SRCCOPY);

	// GDI ��ü���� ��ȯ�Ѵ�
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

// ����ƽ ��Ʈ�ѿ� ��Ʈ���� �����ϴ� �Լ�
void CLinkStatic::SetLinkBmp(UINT nBitmapID, BOOL bLeft)
{
	// ���� ��Ʈ�ʵ��� �����Ѵ�
	if(m_bmpImage.m_hObject)			m_bmpImage.DeleteObject();
	if(m_bmpMask.m_hObject)				m_bmpMask.DeleteObject();

	// �� ��Ʈ���� �ε��Ѵ�
	m_bmpImage.LoadBitmap(nBitmapID);
	m_bmpInfo.bmWidth = m_bmpInfo.bmHeight = 0;

	if(m_bmpImage.m_hObject)
	{
		// ��Ʈ���� ������ ���� �д´�
		m_bmpImage.GetBitmap(&m_bmpInfo);
	}

	// �̹��� ��� ��ġ�� �����Ѵ�
	m_bLeftImage = bLeft;
	// �⺻ �ؽ�Ʈ ��� ��ġ�� Ŭ���̾�Ʈ �������� �Ѵ�
	m_rcText = m_rcClient;

	// �̹��� ��� ��ġ�� ����Ѵ�
	m_ptImage.y = (m_rcClient.Height() - m_bmpInfo.bmHeight) / 2;
	if(m_bLeftImage)
	{
		m_ptImage.x = 0;
		// �ؽ�Ʈ ��� ��ġ�� �����Ѵ�
		m_rcText.left = m_bmpInfo.bmWidth + CONST_ITEM_GAP;
	}
	else
	{
		m_ptImage.x = m_rcClient.right - m_bmpInfo.bmWidth;
		// �ؽ�Ʈ ��� ��ġ�� �����Ѵ�
		m_rcText.right = m_rcClient.right - m_bmpInfo.bmWidth - CONST_ITEM_GAP;
	}
}

// ����ƽ ��Ʈ�ѿ� ��Ʈ���� �����ϰ� ������� �����ϴ� �Լ�
void CLinkStatic::SetLinkBmp(UINT nBitmapID, COLORREF clrTransparent, BOOL bLeft)
{
	// ���� ��Ʈ���� �����Ѵ�
	if(m_bmpImage.m_hObject)			m_bmpImage.DeleteObject();
	if(m_bmpMask.m_hObject)				m_bmpMask.DeleteObject();

	// �� ��Ʈ���� �ε��Ѵ�
	m_bmpImage.LoadBitmap(nBitmapID);
	m_bmpInfo.bmWidth = m_bmpInfo.bmHeight = 0;

	if(m_bmpImage.m_hObject)
	{
		// ��Ʈ���� ������ ���� �д´�
		m_bmpImage.GetBitmap(&m_bmpInfo);
	}

	// �̹��� ��� ��ġ�� �����Ѵ�
	m_bLeftImage = bLeft;
	// �⺻ �ؽ�Ʈ ��� ��ġ�� Ŭ���̾�Ʈ �������� �Ѵ�
	m_rcText = m_rcClient;

	// �̹��� ��� ��ġ�� ����Ѵ�
	m_ptImage.y = (m_rcClient.Height() - m_bmpInfo.bmHeight) / 2;
	if(m_bLeftImage)
	{
		m_ptImage.x = 0;
		// �ؽ�Ʈ ��� ��ġ�� �����Ѵ�
		m_rcText.left = m_bmpInfo.bmWidth + CONST_ITEM_GAP;
	}
	else
	{
		m_ptImage.x = m_rcClient.right - m_bmpInfo.bmWidth;
		// �ؽ�Ʈ ��� ��ġ�� �����Ѵ�
		m_rcText.right = m_rcClient.right - m_bmpInfo.bmWidth - CONST_ITEM_GAP;
	}

	COLORREF	clrBmpBk, clrBmpText;

	// ������� �����Ѵ�
	m_clrTransparent = clrTransparent;

	CDC BmpDC, MaskDC;
	
	BmpDC.CreateCompatibleDC(NULL);
	MaskDC.CreateCompatibleDC(NULL);

	// ����ũ ��Ʈ���� �����Ѵ� - ����ũ ��Ʈ���� ��� ��Ʈ���̴�
	m_bmpMask.CreateBitmap(m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, 1, 1, NULL);

	CBitmap *pOldBmp = BmpDC.SelectObject(&m_bmpImage);
	CBitmap *pOldMask = MaskDC.SelectObject(&m_bmpMask);

	// ���� ��Ʈ���� DC�� ������ ��������� �����ϰ� ����ũ ��Ʈ�ʿ� �����Ѵ�
	// �̶� ����ũ ��Ʈ���� ����̱� ������,
	// ���� ��Ʈ�� DC�� ������ ����� �κ��� ������� �����ǰ�
	// ������ �κе��� ���������� �����ȴ�
	clrBmpBk = BmpDC.SetBkColor(m_clrTransparent);
	MaskDC.BitBlt(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &BmpDC, 0, 0, SRCCOPY);

	// ���� ��Ʈ���� DC�� ���ڻ��� �Ͼ������ �ϰ�,
	// ���� ��Ʈ���� DC�� ������ ���������� �Ͽ� ����ũ ��Ʈ�ʰ� AND ������ �Ѵ�
	// �̶� ����ũ ��Ʈ���� ������ �κ��� ���ڻ��� �Ͼ���� �ǰ�
	// ����ũ ��Ʈ���� �Ͼ�� �κ��� ������ ���������� �ٲ�� �ȴ�.
	// �ٲ� ����ũ ��Ʈ�ʰ� ���� ��Ʈ���� AND ������ �ؼ�,
	// ����Ʈ ��Ʈ���� �Ͼ���� �ش��ϴ� ���� ��Ʈ�� �κ��� ���� �̹����� �����ǰ�,
	// ����ũ ��Ʈ���� �������� �ش��ϴ� ���� ��Ʈ�� �κ��� ���������� ĥ������
	clrBmpText = BmpDC.SetTextColor(RGB(255, 255, 255));
	BmpDC.SetBkColor(RGB(0, 0, 0));
	BmpDC.BitBlt(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &MaskDC, 0, 0, SRCAND);

	// ���� ������� �ǵ��� ���´�
	BmpDC.SetTextColor(clrBmpText);
	BmpDC.SetBkColor(clrBmpBk);

	// ���� ��Ʈ������ �ǵ��� ���´�
	BmpDC.SelectObject(pOldBmp);
	MaskDC.SelectObject(pOldMask);

	// DC���� �����Ѵ�
	BmpDC.DeleteDC();
	MaskDC.DeleteDC();
}

// ����ƽ ��Ʈ���� ������ �����ϴ� �Լ�
void CLinkStatic::SetToolTipText(LPCTSTR pTip)
{
	// ������ �����ϰ�
	m_strToolTip = pTip;

	// ���� ��Ʈ���� ��Ȱ��ȭ ��Ų ��
	m_wndToolTip.Activate(FALSE);
	// ������ �����ϰ�
	m_wndToolTip.UpdateTipText(m_strToolTip, this, 1);
	// ���� ��Ʈ���� �ٽ� Ȱ��ȭ ��Ų��
	m_wndToolTip.Activate(TRUE);
}

BOOL CLinkStatic::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

BOOL CLinkStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// ����ƽ ��Ʈ�ѿ����� ���콺 Ŀ���� �ٲ۴�
	::SetCursor(m_hCursor);

	return TRUE;
//	return CStatic::OnSetCursor(pWnd, nHitTest, message);
}

void CLinkStatic::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���콺�� ����ƽ ��Ʈ�� ������ �̵� ���̸�,
	// �ý��ۿ��� ���콺�� ����ƽ ��Ʈ�ѷκ����� Ż�⿡ ���� �޽����� ������ ���� ��û
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags		= TME_LEAVE;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);

	// ���콺�� ��ġ�� ������ �����Ѵ�
	m_bHover = TRUE;
	// ȭ���� �ٽ� �׸���
	Invalidate(FALSE);
	
	CStatic::OnMouseMove(nFlags, point);
}

LRESULT CLinkStatic::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// ���콺�� ����ƽ ��Ʈ�ѿ��� Ż�������Ƿ� ����ƽ ��Ʈ�� �ٽ� �׸�
	m_bHover = FALSE;
	Invalidate(FALSE);

	return 0;
}

void CLinkStatic::OnClicked() 
{
	// ����ƽ ��Ʈ���� �ؽ�Ʈ�� ��´�
	CString strText;
	GetWindowText(strText);

	// ���� ���������� �����Ǿ� ���� �ʴٸ�
	if(strText.Find(":") < 0)
	{
		// ���� ���� �ּҰ� �ƴ϶�� "http://"�� �տ� ���δ�
		if(strText.Find("@") < 0)		strText.Insert(0, "http://");
		// ���� ���� �ּҶ�� "mailto:"�� �տ� ���δ�
		else							strText.Insert(0, "mailto:");
	}

	// ��ũ�� �����Ѵ�
	::ShellExecute(NULL, "open", strText, NULL, NULL, SWP_SHOWWINDOW);
}
