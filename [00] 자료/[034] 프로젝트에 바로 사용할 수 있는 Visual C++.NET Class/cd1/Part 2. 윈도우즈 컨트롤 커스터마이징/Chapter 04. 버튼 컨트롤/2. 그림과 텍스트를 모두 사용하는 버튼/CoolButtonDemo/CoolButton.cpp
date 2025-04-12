// CoolButton.cpp : implementation file
//

#include "stdafx.h"
#include "CoolButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoolButton

// �� ����� ���콺 Ŀ�� ID
#define IDC_HAND            MAKEINTRESOURCE(32649)

// ��ư�� �ܰ����� �̹����� �ؽ�Ʈ������ ����(�ȼ�)
#define CONST_GAP			4

CCoolButton::CCoolButton()
{
	// �ո�� ���콺 Ŀ���� �ε��Ѵ�
	m_hCursor		= ::LoadCursor(NULL, MAKEINTRESOURCE(IDC_HAND));

	// ���� �������� �ʱ�ȭ�Ѵ�
	m_hIcon			= NULL;

	m_nImageType	= IMG_BMP;
	m_bFlat			= TRUE;
	m_bHover		= FALSE;

	m_clrColors[COLOR_TEXT]		= ::GetSysColor(COLOR_BTNTEXT);
	m_clrColors[COLOR_BKGND]	= ::GetSysColor(COLOR_BTNFACE);
	m_clrColors[COLOR_TEXT_IN]	= ::GetSysColor(COLOR_BTNTEXT);
	m_clrColors[COLOR_BKGND_IN] = ::GetSysColor(COLOR_BTNFACE);

	m_nTextAlign	= ALIGN_RIGHT;
}

CCoolButton::~CCoolButton()
{
	// ���� ���ҽ����� ��ȯ�Ѵ�
	if(m_hCursor)				::DeleteObject(m_hCursor);
	if(m_hIcon)					::DeleteObject(m_hIcon);

	if(m_bmpImage.m_hObject)	m_bmpImage.DeleteObject();
	if(m_bmpMask.m_hObject)		m_bmpMask.DeleteObject();
}


BEGIN_MESSAGE_MAP(CCoolButton, CButton)
	//{{AFX_MSG_MAP(CCoolButton)
	ON_WM_SETCURSOR()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoolButton message handlers

void CCoolButton::PreSubclassWindow() 
{
	// ���� ��ư�� ũ�⸦ �����Ѵ�
	GetClientRect(&m_rcClient);
	// �⺻ �ؽ�Ʈ ��ġ�� ��ư�� �߾����� �����Ѵ�
	m_rcText = m_rcClient;
	
	// BS_OWNERDRAW �Ӽ��� �����Ѵ�
	ModifyStyle(0, BS_OWNERDRAW);

	// �⺻ �ؽ�Ʈ�� ��ư�� ĸ������ �����Ѵ�
	GetWindowText(m_strToolTip);

	// ���� ��Ʈ���� �����Ѵ�
	m_wndToolTip.Create(this, TTS_ALWAYSTIP);
	m_wndToolTip.Activate(FALSE);
	m_wndToolTip.AddTool(this, m_strToolTip, m_rcClient, 1);
	m_wndToolTip.Activate(TRUE);

	CButton::PreSubclassWindow();
}

BOOL CCoolButton::PreTranslateMessage(MSG* pMsg) 
{
	// ���� ��Ʈ�ѿ��� ���콺 �̺�Ʈ�� �����Ѵ�
	m_wndToolTip.RelayEvent(pMsg);
	
	return CButton::PreTranslateMessage(pMsg);
}

// ��ư ����� ���� �׸��� �Լ�
void CCoolButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// ������ DC �ڵ�� CDC ��ü�� �����Ѵ�
	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	// �ε巯�� ȭ�� ����� ���� �޸� DC�� �����ϰ� ���� ���۸��� �����Ѵ�
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	CBitmap MemBmp, *pOldBmp;

	MemBmp.CreateCompatibleBitmap(pDC, m_rcClient.Width(), m_rcClient.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// ��ư�� �Ʒ��� ����� ����Ѵ�.
	MemDC.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), pDC, 0, 0, SRCCOPY);

	// ����� �׸���
	DrawBkgnd(&MemDC, lpDrawItemStruct->itemState & ODS_SELECTED, 
		!(lpDrawItemStruct->itemState & ODS_DISABLED));

	// �̹����� �׸���
	DrawImage(&MemDC, lpDrawItemStruct->itemState & ODS_SELECTED);

	// �ؽ�Ʈ�� �׸���
	DrawText(&MemDC, lpDrawItemStruct->itemState & ODS_SELECTED,
		!(lpDrawItemStruct->itemState & ODS_DISABLED));

	// �׵θ��� �׸���
	DrawBorder(&MemDC, lpDrawItemStruct->itemState & ODS_SELECTED,
		lpDrawItemStruct->itemState & ODS_FOCUS);

	// �޸� DC�� ��µ� ��� ������ ȭ�鿡 ����Ѵ�
	pDC->BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), &MemDC, 0, 0, SRCCOPY);

	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	MemBmp.DeleteObject();
}

// ����� �׸��� �Լ�
void CCoolButton::DrawBkgnd(CDC *pDC, BOOL bPressed, BOOL bEnable)
{
	// ��Ȱ��ȭ �������� ��� ��ư���� ��ü ��ư������ ���� ������ ĥ�Ѵ�
	if(m_bHover && bEnable)
	{
		pDC->FillSolidRect(&m_rcClient, m_clrColors[COLOR_BKGND_IN]);
	}
	else
	{
		if(m_bFlat)	pDC->FillSolidRect(&m_rcClient,
					::GetSysColor(COLOR_BTNFACE));
		else		pDC->FillSolidRect(&m_rcClient,
					m_clrColors[COLOR_BKGND]);
	}
}

// �׵θ��� �׸��� �Լ�
void CCoolButton::DrawBorder(CDC *pDC, BOOL bPressed, BOOL bFocus)
{
	// ���� ���콺�� ������ �ְų� ��� ��ư�� �ƴ϶��
	if(m_bHover || !m_bFlat)
	{
		// ���� ������ ���¶�� 
		if(bPressed)
			// ������ ����� 3���� �׵θ��� �׸���
			pDC->Draw3dRect(m_rcClient, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DHILIGHT));
		else
			// Ƣ��� ����� 3���� �׵θ��� �׸���
			pDC->Draw3dRect(m_rcClient, ::GetSysColor(COLOR_3DHILIGHT), ::GetSysColor(COLOR_3DSHADOW));
	}

	// ���� ���� ��ư�� ��Ŀ���� ���� �ִٸ�
	if(bFocus)
	{
		// ��ư�� �������� ���� 3�ȼ��� �̵��Ͽ� ��Ŀ�� �簢���� �׸���
		CRect rcTemp = m_rcClient;
		rcTemp.DeflateRect(3, 3);
		pDC->DrawFocusRect(&rcTemp);
	}
}

// �̹����� �׸��� �Լ�
void CCoolButton::DrawImage(CDC *pDC, BOOL bPressed)
{
	// �̹��� ��ġ�� �ӽ� �����Ѵ�
	CPoint ptImage = m_ptImage;

	// ���� ���� ��ư�� ������ ���¶��
	// �̹����� �밢�� �Ʒ��� 1�ȼ��� �̵���Ų��
	if(bPressed)
	{
		ptImage.x += 1;
		ptImage.y += 1;
	}

	// ���� ��ư�� �̹��� Ÿ�Կ� ���� ȭ�鿡 �̹����� ����Ѵ�
	switch(m_nImageType)
	{
	case IMG_BMP:
		// ��Ʈ���� �����Ǿ��ٸ�
		if(m_bmpImage.m_hObject)
		{
			// ��Ʈ���� ��ư�� �̹��� ��� ������ ����Ѵ�
			CDC BmpDC;
			BmpDC.CreateCompatibleDC(NULL);

			CBitmap *pOldBmp = BmpDC.SelectObject(&m_bmpImage);

			// ���� ������� ����Ǿ� �ִٸ�
			if(m_bmpMask.m_hObject)
			{
				// ����ũ ��Ʈ���� ����ؼ� ���� ó���� �Ͽ�
				// ��Ʈ���� ����Ѵ�
				CDC MaskDC;
				MaskDC.CreateCompatibleDC(NULL);
				CBitmap *pOldMask = MaskDC.SelectObject(&m_bmpMask);

				// ����ũ ��Ʈ���� ����̱� ������,
				// 1�� ������ �⺻ ������ �Ͼ������ �ٲ�� 0�� ���ڻ��� ���������� �ٲ��.
				// �׸��� ȭ���� ����� AND �Ǿ�,
				// ����ũ�� ���� ������ ����� �״�� �巯���� ����ũ�� �̹��� ������ ���������� ����� ��������.
				pDC->BitBlt(ptImage.x, ptImage.y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &MaskDC, 0, 0, SRCAND);
				// ���� ��Ʈ���� ���� �κ��� �̹� ���������� ó���Ǿ��� ������
				// ���� �κ��� ���� OR �Ǿ� ����� �״�� �����ϰ�,
				// ���� ��Ʈ���� ������ �κ��� �״�� �����Ǿ� �����Ƿ�
				// ����� �������� OR �Ǿ� ���� �̹����� �״�� ����Ѵ�.
				pDC->BitBlt(ptImage.x, ptImage.y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &BmpDC, 0, 0, SRCPAINT);

				MaskDC.SelectObject(pOldMask);
				MaskDC.DeleteDC();
			}
			else
			{
				// ������� ������� �ʾҴٸ� �̹����� �׳� ����Ѵ�
				pDC->BitBlt(ptImage.x, ptImage.y, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &BmpDC, 0, 0, SRCCOPY);
			}

			BmpDC.SelectObject(pOldBmp);
			BmpDC.DeleteDC();
		}
		break;
	case IMG_ICON:
		// ���࿡ �������� �����Ǿ��ٸ�
		if(m_hIcon)
		{
			// �������� �̹��� ������ ����Ѵ�
			pDC->DrawIcon(ptImage, m_hIcon);
		}
		break;
	}
}

// �ؽ�Ʈ�� �׸��� �Լ�
void CCoolButton::DrawText(CDC *pDC, BOOL bPressed, BOOL bEnable)
{
	// ��ư�� �ؽ�Ʈ�� �д´�
	GetWindowText(m_strText);

	// �ؽ�Ʈ ��ġ�� �ӽ� �����Ѵ�
	CRect rcTemp = m_rcText;

	// ���� ���� ��ư�� ������ ���¶��
	// �ؽ�Ʈ�� �밢�� �Ʒ��� 1�ȼ��� �̵���Ų��
	if(bPressed)
	{
		rcTemp.OffsetRect(1, 1);
	}

	// �ؽ�Ʈ�� ����� �����ϰ� �����Ѵ�
	int nBkMode = pDC->SetBkMode(TRANSPARENT);
	COLORREF clrText;

	// ���� ��ư�� ��Ȱ��ȭ�� ���¶�� ȸ������ �ؽ�Ʈ ������ �����Ѵ�
	if(!bEnable)
	{
		clrText = pDC->SetTextColor(RGB(200, 200, 200));
	}
	else
	{
		// ���콺�� ��ư�� ������ �ִ��Ŀ� ���� �ؽ�Ʈ ������ �����Ѵ�
		if(m_bHover)
			clrText = pDC->SetTextColor(m_clrColors[COLOR_TEXT_IN]);
		else
			clrText = pDC->SetTextColor(m_clrColors[COLOR_TEXT]);
	}

	// �θ� ���̾�α��� ��Ʈ�� ��ų� �ý����� ��Ʈ�� ����ؼ� �ؽ�Ʈ�� ����Ѵ�
	CFont *pFont = GetParent()->GetFont(), *pOldFont;
	if(pFont == NULL)
		pFont = CFont::FromHandle((HFONT)GetStockObject( DEFAULT_GUI_FONT));
	pOldFont = pDC->SelectObject(pFont);

	pDC->DrawText(m_strText, &rcTemp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	pDC->SelectObject(pOldFont);
	pDC->SetBkMode(nBkMode);
	pDC->SetTextColor(clrText);
}

BOOL CCoolButton::OnEraseBkgnd(CDC* pDC) 
{
	// �������� ���ֱ� ���� ����� ĥ���� �ʴ´�
	return TRUE;	
//	return CButton::OnEraseBkgnd(pDC);
}

BOOL CCoolButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// ��ư������ ���콺 Ŀ���� �ٲ۴�
	::SetCursor(m_hCursor);

	return TRUE;
//	return CButton::OnSetCursor(pWnd, nHitTest, message);
}

void CCoolButton::OnSetFocus(CWnd* pOldWnd) 
{
	CButton::OnSetFocus(pOldWnd);
	
	// ��Ŀ���� ��ư�� ���� �Ǹ� ȭ���� �ٽ� �׸���
	Invalidate(FALSE);
}

void CCoolButton::OnKillFocus(CWnd* pNewWnd) 
{
	CButton::OnKillFocus(pNewWnd);
	
	// ��Ŀ���� �Ұ� �Ǹ� ȭ���� �ٽ� �׸���
	Invalidate(FALSE);
}

void CCoolButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���콺�� ��ư ������ �̵� ���̸�,
	// �ý��ۿ��� ���콺�� ��ư ���԰� Ż�⿡ ���� �޽����� ������ ���� ��û
	TRACKMOUSEEVENT MouseEvent;
	MouseEvent.cbSize		= sizeof(TRACKMOUSEEVENT);
	MouseEvent.dwFlags	= TME_LEAVE | TME_HOVER;
	MouseEvent.hwndTrack	= m_hWnd;
	MouseEvent.dwHoverTime	= 1;

	::TrackMouseEvent(&MouseEvent);
	
	CButton::OnMouseMove(nFlags, point);
}

LRESULT CCoolButton::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	// ���콺�� ��ư�� ���������Ƿ� ��ư �ٽ� �׸�
	m_bHover = TRUE;
	Invalidate(FALSE);

	return 0;
}

LRESULT CCoolButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	// ���콺�� ��ư���� Ż�������Ƿ� ��ư �ٽ� �׸�
	m_bHover = FALSE;
	Invalidate(FALSE);

	return 0;
}

void CCoolButton::OnSize(UINT nType, int cx, int cy) 
{
	CButton::OnSize(nType, cx, cy);
	
	// ��ư�� ũ�Ⱑ ����Ǿ����Ƿ� �� ũ�⸦ ���� �� ��ư �ٽ� �׸�
	GetClientRect(&m_rcClient);

	RepositionAll();
}

void CCoolButton::RepositionAll()
{
	// �⺻ �ؽ�Ʈ ��ġ�� ��ư ��ü�� �߾�
	m_rcText = m_rcClient;

	switch(m_nTextAlign)
	{
	case ALIGN_LEFT:
		// �ؽ�Ʈ�� ���ʿ� ��ġ
		m_ptImage.x = m_rcClient.right - m_bmpInfo.bmWidth - CONST_GAP;
		m_ptImage.y = (m_rcClient.Height() - m_bmpInfo.bmHeight) / 2;
		m_rcText.right = m_ptImage.x;
		break;
	case ALIGN_RIGHT:
		// �ؽ�Ʈ�� �����ʿ� ��ġ
		m_ptImage.x = CONST_GAP;
		m_ptImage.y = (m_rcClient.Height() - m_bmpInfo.bmHeight) / 2;
		m_rcText.left = m_ptImage.x + m_bmpInfo.bmWidth;
		break;
	case ALIGN_TOP:
		// �ؽ�Ʈ�� ���ʿ� ��ġ
		m_ptImage.x = (m_rcClient.Width() - m_bmpInfo.bmWidth) / 2;
		m_ptImage.y = m_rcClient.bottom - m_bmpInfo.bmHeight - CONST_GAP;
		m_rcText.bottom = m_ptImage.y;
		break;
	case ALIGN_BOTTOM:
		// �ؽ�Ʈ�� �Ʒ��ʿ� ��ġ
		m_ptImage.x = (m_rcClient.Width() - m_bmpInfo.bmWidth) / 2;
		m_ptImage.y = CONST_GAP;
		m_rcText.top = m_ptImage.y + m_bmpInfo.bmHeight;
		break;
	case ALIGN_OVER:
		// �ؽ�Ʈ�� �̹����� ��ư�� �߾ӿ� ��ġ
		m_ptImage.x = (m_rcClient.Width() - m_bmpInfo.bmWidth) / 2;
		m_ptImage.y = (m_rcClient.Height() - m_bmpInfo.bmHeight) / 2;
		break;
	}

	// ���� ���� ��ư�� �������� ���� �׸�
	if(::IsWindow(m_hWnd))		Invalidate(FALSE);
}

// ��ư�� ��Ʈ���� �����ϴ� �Լ�
void CCoolButton::SetButtonBmp(UINT nBitmapID)
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

	// �̹��� Ÿ���� ��Ʈ������ �����Ѵ�
	m_nImageType = IMG_BMP;

	// �ؽ�Ʈ�� �̹����� ���ġ�Ѵ�
	RepositionAll();
}

// ��ư�� ��Ʈ���� �����ϰ� ������� �����ϴ� �Լ�
void CCoolButton::SetButtonBmp(UINT nBitmapID, COLORREF clrTransparent)
{
	// ���� ��Ʈ���� �����Ѵ�
	if(m_bmpImage.m_hObject)		m_bmpImage.DeleteObject();
	if(m_bmpMask.m_hObject)			m_bmpMask.DeleteObject();

	// �� ��Ʈ���� �ε��Ѵ�
	m_bmpImage.LoadBitmap(nBitmapID);
	m_bmpInfo.bmWidth = m_bmpInfo.bmHeight = 0;

	if(m_bmpImage.m_hObject)
	{
		// ��Ʈ���� ������ ���� �д´�
		m_bmpImage.GetBitmap(&m_bmpInfo);
	}

	// �̹��� Ÿ���� ��Ʈ������ �����Ѵ�
	m_nImageType = IMG_BMP;

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
	// ���� ��Ʈ�� DC�� ������ ����� �κ��� 1�� �����ǰ� ������ �κе��� 0���� �����ȴ�
	clrBmpBk = BmpDC.SetBkColor(m_clrTransparent);
	MaskDC.BitBlt(0, 0, m_bmpInfo.bmWidth, m_bmpInfo.bmHeight, &BmpDC, 0, 0, SRCCOPY);

	// ���� ��Ʈ���� DC�� ���ڻ��� �Ͼ������ �ϰ�,
	// ���� ��Ʈ���� DC�� ������ ���������� �Ͽ� ����ũ ��Ʈ�ʰ� AND ������ �Ѵ�
	// ����ũ ��Ʈ���� ����̱� ������,
	// 1�� ������ ���������� �ٲ�� 0�� ���ڻ��� �Ͼ������ �ٲ��.
	// ��������� ���� ��Ʈ���� ����� �κа� �������� AND�ǰ� �Ǿ� �������� �ǰ�
	// ���� ��Ʈ���� ��Ÿ �κа� �Ͼ���� AND�ǰ� �Ǿ� ���� ��Ʈ���� �״�� �����ϰ� �ȴ�.
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

	// �ؽ�Ʈ�� �̹����� ���ġ�Ѵ�
	RepositionAll();
}

// ��ư�� �������� �����ϴ� �Լ�
void CCoolButton::SetButtonIcon(UINT nIconID)
{
	// ���� �������� �����Ѵ�
	if(m_hIcon)						::DeleteObject(m_hIcon);

	// �� �������� �ε��Ѵ�
	m_hIcon = ::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(nIconID));
	m_bmpInfo.bmWidth = m_bmpInfo.bmHeight = 0;

	if(m_hIcon)
	{
		// �������� ũ�⸦ ���´�
		ICONINFO IconInfo;

		if(::GetIconInfo(m_hIcon, &IconInfo))
		{
			::GetObject(IconInfo.hbmColor, sizeof(BITMAP), &m_bmpInfo);
		}
	}

	// �̹��� Ÿ���� ���������� �����Ѵ�
	m_nImageType = IMG_ICON;

	// �ؽ�Ʈ�� �̹����� ���ġ�Ѵ�
	RepositionAll();
}

// ��� ��ư���� �����ϴ� �Լ�
void CCoolButton::SetFlat(BOOL bFlat)
{
	if(m_bFlat == bFlat)		return;

	m_bFlat = bFlat;

	// ���� ���� ��ư�� �������� ���� �׸�
	if(::IsWindow(m_hWnd))		Invalidate(FALSE);
}

// ��ư�� �ؽ�Ʈ�� �����ϴ� �Լ�
void CCoolButton::SetButtonText(LPCTSTR pText)
{
	// ��ư�� �ؽ�Ʈ ����
	m_strText = pText;

	// �ؽ�Ʈ�� �̹����� ���ġ�Ѵ�
	RepositionAll();
}

// ��ư�� ������ �����ϴ� �Լ�
COLORREF CCoolButton::GetButtonColor(ENUM_COLOR_TYPE nColor)
{
	if(nColor < 0 || nColor > COLOR_MAX)		return -1;

	return m_clrColors[nColor];
}

// ��ư�� ������ �����ϴ� �Լ�
void CCoolButton::SetButtonColor(ENUM_COLOR_TYPE nColor, COLORREF clrColor)
{
	if(nColor < 0 || nColor > COLOR_MAX)		return;

	m_clrColors[nColor] = clrColor;

	// ���� ���� ��ư�� �������� ���� �׸�
	if(::IsWindow(m_hWnd))		Invalidate(FALSE);
}

// ��ư���� �ؽ�Ʈ ��ġ�� �����ϴ� �Լ�
void CCoolButton::SetTextAlign(ENUM_TEXT_ALIGN nAlign)
{
	m_nTextAlign = nAlign;

	// �ؽ�Ʈ�� �̹����� ���ġ�Ѵ�
	RepositionAll();
}

// ��ư�� ������ �����ϴ� �Լ�
void CCoolButton::SetToolTipText(LPCTSTR pTip)
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

void CCoolButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ��ư�� �������� ���� ���·� ����
	SendMessage(BM_SETSTATE, FALSE, 0);

	CWnd* pParent = GetParent();
	if( NULL != pParent )
	{
		// �������� Ŭ�� �̺�Ʈ �߻�
		::SendMessage(pParent->m_hWnd, WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(), BN_CLICKED), (LPARAM)m_hWnd);
	}
	
	CButton::OnLButtonUp(nFlags, point);
}

void CCoolButton::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// ��ư�� ������ ���·� ����
	SendMessage(BM_SETSTATE, TRUE, 0);
	
	CButton::OnLButtonDblClk(nFlags, point);
}
