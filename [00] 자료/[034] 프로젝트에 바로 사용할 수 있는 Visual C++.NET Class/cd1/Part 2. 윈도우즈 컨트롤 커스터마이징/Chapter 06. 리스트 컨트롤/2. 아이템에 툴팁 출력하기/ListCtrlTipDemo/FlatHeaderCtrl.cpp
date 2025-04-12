// FlatHeaderCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "FlatHeaderCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlatHeaderCtrl

// �׸��� �׵θ� Ȥ�� �׸��� �ؽ�Ʈ/�̹���/��Ʈ�� ������ ����
#define CONST_TERM			6

CFlatHeaderCtrl::CFlatHeaderCtrl()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_clrFace		= ::GetSysColor(COLOR_3DFACE);
	m_clrHighLight	= ::GetSysColor(COLOR_3DHIGHLIGHT);
	m_clrShadow		= ::GetSysColor(COLOR_3DSHADOW);
	m_clrText		= ::GetSysColor(COLOR_BTNTEXT);

	m_HighLightPen.CreatePen(PS_SOLID, 1, m_clrHighLight);
	m_ShadowPen.CreatePen(PS_SOLID, 1, m_clrShadow);
}

CFlatHeaderCtrl::~CFlatHeaderCtrl()
{
	// ������ GDI ��ü���� �Ҹ��Ų��
	m_HighLightPen.DeleteObject();
	m_ShadowPen.DeleteObject();
}


BEGIN_MESSAGE_MAP(CFlatHeaderCtrl, CHeaderCtrl)
	//{{AFX_MSG_MAP(CFlatHeaderCtrl)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlatHeaderCtrl message handlers

void CFlatHeaderCtrl::PreSubclassWindow() 
{
	// Ŭ���̾�Ʈ ���� ũ�⸦ ��´�
	GetClientRect(&m_rcClient);

	// ������ �����Ѵ�
	m_wndToolTip.Create(this);
	m_wndToolTip.Activate(TRUE);

	CHeaderCtrl::PreSubclassWindow();
}

void CFlatHeaderCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// ��� ��� ������ ��´�
	CRect rcClip;
	if(dc.GetClipBox(&rcClip) == ERROR)	return;

	// ��� ��� ������ �⺻ �������� ĥ�Ѵ�
	dc.FillSolidRect(rcClip, m_clrFace);

	int i, nWidth;
	CRect rcItem;
	char szText[100];
	HDITEM Item;
	CBitmap *pBitmap;

	// ����� �׸� ������ ��´�
	int nSize = GetItemCount();
	// ��� ��Ʈ���� ��� ���� 0���� �����Ѵ�
	m_rcClient.right = m_rcClient.left;

	CPen *pOldPen;
	// ��� ��Ʈ���� ��� 
	CFont *pOldFont = dc.SelectObject(GetFont());

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(m_clrText);

	// �̹��� ����Ʈ�� ��´�
	CImageList *pImageList = GetImageList();
	CSize szImage;

	// �̹����� ����� ��´�
	szImage.cx = szImage.cy = 0;
	if(pImageList)
	{
		if(pImageList->GetImageCount() > 0)
		{
			IMAGEINFO ImageInfo;
			pImageList->GetImageInfo(0, &ImageInfo);
			szImage.cx = ImageInfo.rcImage.right - ImageInfo.rcImage.left;
			szImage.cy = ImageInfo.rcImage.bottom - ImageInfo.rcImage.top;
		}
	}

	// ��� ��Ʈ���� �׸� ������ŭ �ݺ�
	for(i = 0; i < nSize; i++)
	{
		// �׸� �̸� ���۸� �ʱ�ȭ
		::memset(szText, 0, sizeof(szText));

		// �׸� ������ ��� ���� ����ü�� �ʱ�ȭ�Ѵ�
		Item.mask		= HDI_WIDTH | HDI_FORMAT | HDI_TEXT | HDI_IMAGE | HDI_BITMAP;
		Item.pszText	= szText;
		Item.cchTextMax = sizeof(szText);

		// �׸� ������ ��´�
		GetItem(i, &Item);
		// �׸� ������ ��´�
		GetItemRect(i, &rcItem);

		// ���� �׸��� ��� ��� ������ ���Ѵٸ�
		if(rcItem.right >= rcClip.left && rcItem.left <= rcClip.right)
		{
			// ���� ��Ʈ���� �����Ǿ� �ִٸ� ��Ʈ�� ��ü�� �����Ѵ�.
			pBitmap = NULL;
			if(Item.fmt & HDF_BITMAP && Item.mask & HDI_BITMAP && Item.hbm)
			{
				pBitmap = CBitmap::FromHandle(Item.hbm);
			}

			// �¿� ������ �д�
			rcItem.left += CONST_TERM;
			rcItem.right -= CONST_TERM;

			// �׸��� �ؽ�Ʈ ��� ���⿡ ���� �ٸ��� ����Ѵ�
			switch(Item.fmt & HDF_JUSTIFYMASK)
			{
			case HDF_LEFT:
				// �̹����� �׸��� ������ ���� �׸���
				nWidth = DrawImage(&dc, &rcItem, &Item, pImageList, &szImage);
				// �̹��� ������ ���Ѵ�
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// �̹����� ������ �ؽ�Ʈ�� ����Ѵ�
				nWidth = DrawText(&dc, &rcItem, &Item);
				// �ؽ�Ʈ ������ ���Ѵ�
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// �ؽ�Ʈ�� ������ ��Ʈ���� ����Ѵ�
				DrawBitmap(&dc, &rcItem, &Item, pBitmap);
				break;
			case HDF_CENTER:
				// �̹����� �׸��� ������ ���� �׸���
				nWidth = DrawImage(&dc, &rcItem, &Item, pImageList, &szImage);
				// �̹��� ������ ���Ѵ�
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// ��Ʈ���� �׸��� ������ ����Ѵ�
				nWidth = DrawBitmap(&dc, &rcItem, &Item, pBitmap);
				// ��Ʈ�� ������ ���Ѵ�
				rcItem.right -= (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// �ؽ�Ʈ�� ������ ������ �߾ӿ� ����Ѵ�
				DrawText(&dc, &rcItem, &Item);
				break;
			case HDF_RIGHT:
				// �̹����� �׸��� ������ ���� �׸���
				nWidth = DrawImage(&dc, &rcItem, &Item, pImageList, &szImage);
				// �̹��� ������ ���Ѵ�
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// ��Ʈ���� ������ ����Ѵ�
				nWidth = DrawBitmap(&dc, &rcItem, &Item, pBitmap);
				// ��Ʈ�� ������ ���Ѵ�
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// �ؽ�Ʈ�� ������ ����Ѵ�
				DrawText(&dc, &rcItem, &Item);
				break;
			}

			// �׸��� ������ �ٽ� ���Ѵ�
			GetItemRect(i, &rcItem);

			// ���� ������ �׸��� �ƴ϶��
			if(i < nSize - 1)
			{
				// ���� �׸���� ������ ���� �����ڸ� ����Ѵ�
				pOldPen = dc.SelectObject(&m_ShadowPen);
				dc.MoveTo(rcItem.right - 1, rcItem.top + 2);
				dc.LineTo(rcItem.right - 1, rcItem.bottom - 2);

				dc.SelectObject(&m_HighLightPen);
				dc.MoveTo(rcItem.right, rcItem.top + 2);
				dc.LineTo(rcItem.right, rcItem.bottom - 2);

				dc.SelectObject(pOldPen);
			}
		}

		// ��� ��Ʈ���� ���� �׸��� ���� ���Ѵ�
		m_rcClient.right += Item.cxy;
	}

	// ��� ��Ʈ�ѿ� ���� ����Ͽ��ٸ� 
	if(m_rcClient.Width() > 0)
	{
		// ��µ� ���� �ܰ��� 3���� �׵θ��� ����Ѵ�
		dc.Draw3dRect(m_rcClient, m_clrHighLight, m_clrShadow);
	}

	dc.SelectObject(pOldFont);
}

// �׸��� �̹����� ����ϴ� �Լ�
int CFlatHeaderCtrl::DrawImage(CDC *pDC, CRect *pRect, LPHDITEM pItem, CImageList *pImageList, CSize *pSize)
{
	// �̹����� ũ�Ⱑ 0�̶�� ����
	if(pSize->cx == 0 || pSize->cy == 0)									return 0;
	// ���� �׸� ������ �̹��� ������ ���ٸ� ����
	if(!(pItem->mask & HDI_IMAGE))											return 0;
	// ���� �׸� �̹����� ���ٸ� ����
	if(!(pItem->fmt & HDF_IMAGE))											return 0;
	// ���� �̹��� ��ȣ�� �߸� �����Ǿ��ٸ� ����
	if(pItem->iImage < 0 || pItem->iImage >= pImageList->GetImageCount())	return 0;
	// ���� ����� ������ ���ٸ� ����
	if(pRect->Width() <= 0)													return 0;

	// �̹����� ��� ��ġ�� ����Ѵ�
	CPoint ptImage;
	ptImage.x = pRect->left;
	ptImage.y = (pRect->top + pRect->bottom - pSize->cy) / 2;

	// �̹����� ��� ũ�⸦ ����Ѵ�
	CSize szImage;
	szImage.cx = (pRect->Width() < pSize->cx) ? pRect->Width() : pSize->cx;
	szImage.cy = pSize->cy;

	// �̹��� ����Ʈ���� �׸��� �̹����� ����Ѵ�
	pImageList->DrawIndirect(pDC, pItem->iImage, ptImage, szImage, CPoint(0, 0));

	// ��µ� �̹��� ���� �����Ѵ�
	return pSize->cx;
}

// �׸��� �ؽ�Ʈ�� ����ϴ� �Լ�
int CFlatHeaderCtrl::DrawText(CDC* pDC, CRect *pRect, LPHDITEM pItem)
{
	// ���� ����� ������ ���ų� �ؽ�Ʈ ������ ���ų� �ؽ�Ʈ�� ���ٸ� ����
	if(pRect->Width() <= 0 || !(pItem->mask & HDI_TEXT) || !(pItem->fmt & HDF_STRING))	return 0;

	// �ؽ�Ʈ ����� ���� �ʿ��� ������ ���Ѵ�
	CSize szText = pDC->GetTextExtent(pItem->pszText);

	// �ؽ�Ʈ ��� ���⿡ ���� �ؽ�Ʈ ��� �ɼ��� �����Ѵ�
	UINT nFormat = DT_END_ELLIPSIS | DT_SINGLELINE | DT_VCENTER;
	switch(pItem->fmt & HDF_JUSTIFYMASK)
	{
	case HDF_LEFT:
		nFormat |= DT_LEFT;
		break;
	case HDF_CENTER:
		nFormat |= DT_CENTER;
		break;
	case HDF_RIGHT:
		nFormat |= DT_RIGHT;
		break;
	}
	// ��� �ɼǿ� ���� �ؽ�Ʈ�� ����Ѵ�
	pDC->DrawText(pItem->pszText, -1, pRect, nFormat);

	// ��µ� ���� ����ϰ� �����Ѵ�
	szText.cx = pRect->Width() < szText.cx ? pRect->Width() : szText.cx;
	if(szText.cx < 0)	szText.cx = 0;

	return szText.cx;
}

// �׸��� ��Ʈ���� ����ϴ� �Լ�
int CFlatHeaderCtrl::DrawBitmap(CDC* pDC, CRect *pRect, LPHDITEM pItem, CBitmap* pBitmap)
{
	// ��Ʈ���� ���ٸ� ����
	if(pBitmap == NULL)		return 0;

	// ��Ʈ�� ������ ��´�
	BITMAP BmpInfo;
	pBitmap->GetObject(sizeof(BITMAP), &BmpInfo);

	// ���� ��� �� ���� ��Ʈ�� ���� �аų� ��� ���� ���ٸ� ����
	if(BmpInfo.bmWidth > pRect->Width() || pRect->Width() <= 0)		return 0;

	// ���� �ؽ�Ʈ ��� ������ �߾��̸� ��Ʈ�� ��� ��ġ�� ���������� ����
	CPoint ptPoint;
	if(pItem->fmt & HDF_JUSTIFYMASK == HDF_CENTER)
		ptPoint.x = pRect->right - BmpInfo.bmHeight;
	else
		// ��Ʈ�� ��� ��ġ�� �������� ����
		ptPoint.x = pRect->left;
	ptPoint.y = (pRect->top + pRect->bottom - BmpInfo.bmHeight) / 2;

	// DC�� �����Ͽ� ��Ʈ���� �����Ѵ�
	CDC BmpDC;
	BmpDC.CreateCompatibleDC(pDC);
	CBitmap *pOldBmp = BmpDC.SelectObject(pBitmap);

	// ��Ʈ���� ȭ�鿡 ����Ѵ�
	pDC->BitBlt(ptPoint.x, ptPoint.y, BmpInfo.bmWidth, BmpInfo.bmHeight,
		&BmpDC, 0, 0, SRCCOPY);

	BmpDC.SelectObject(pOldBmp);
	BmpDC.DeleteDC();

	// ��Ʈ�� ��� ���� �����Ѵ�
	return BmpInfo.bmWidth;
}

BOOL CFlatHeaderCtrl::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
//	return CHeaderCtrl::OnEraseBkgnd(pDC);
}

BOOL CFlatHeaderCtrl::PreTranslateMessage(MSG* pMsg) 
{
	// ���� ��Ʈ�ѿ��� �޽����� ����
	m_wndToolTip.RelayEvent(pMsg);
	
	return CHeaderCtrl::PreTranslateMessage(pMsg);
}

// Ư�� �÷��� ���� ������ �����ϴ� �Լ�
BOOL CFlatHeaderCtrl::AddTool(int nCol, LPCTSTR pTipText)
{
	// ���� ��� ��� �÷��� ��ȣ Ȯ��
	if(nCol < 0 || nCol >= GetItemCount())		return FALSE;

	// �÷��� �簢 ������ ��´�
	CRect rcCol;
	GetItemRect(nCol, &rcCol);

	// ���� ��Ʈ�ѿ� �ش� ������ �߰��Ѵ�
	return m_wndToolTip.AddTool(this, pTipText, &rcCol, nCol + 1);
}

// �� �÷� �׸��� ��ġ�� ���� ���� ��� ������ �ٽ� ����ϴ� �Լ�
void CFlatHeaderCtrl::RecalcToolRect()
{
	// ���� ��Ʈ���� �������� ���� ���¿����� ����
	if(!::IsWindow(m_wndToolTip.m_hWnd))	return;

	char strTip[100];
	int i, nSize, nWidth;
	HDITEM Item;
	CRect rcItem;
	CSize szText;
	CBitmap *pBitmap;
	BITMAP BmpInfo;

	// �׸� ������ ��´�
	nSize = GetItemCount();

	// �̹��� ����Ʈ�� ��´�
	CImageList *pImageList = GetImageList();
	CSize szImage;

	// �̹����� ����� ��´�
	szImage.cx = szImage.cy = 0;
	if(pImageList)
	{
		if(pImageList->GetImageCount() > 0)
		{
			IMAGEINFO ImageInfo;
			pImageList->GetImageInfo(0, &ImageInfo);
			szImage.cx = ImageInfo.rcImage.right - ImageInfo.rcImage.left;
			szImage.cy = ImageInfo.rcImage.bottom - ImageInfo.rcImage.top;
		}
	}

	// ���� �����Ʈ���� DC�� ��� ��Ʈ�� �����Ѵ�
	CDC *pDC = GetDC();
	CFont *pOldFont = (CFont*)pDC->SelectObject(GetFont());

	// ��� ��Ʈ���� �׸� ������ŭ �ݺ�
	for(i = 0; i < nSize; i++)
	{
		// �׸� �̸� ���۸� �ʱ�ȭ
		::memset(strTip, 0, sizeof(strTip));

		// �׸� ������ ��� ���� ����ü�� �ʱ�ȭ�Ѵ�
		Item.mask		= HDI_WIDTH | HDI_FORMAT | HDI_TEXT | HDI_IMAGE | HDI_BITMAP;
		Item.pszText	= strTip;
		Item.cchTextMax = sizeof(strTip); 

		// �׸� ������ ��´�
		GetItem(i, &Item);
		// �׸� ������ ��´�
		GetItemRect(i, &rcItem);

		// �׸� �ʿ��� �ּ� �� ���ϱ�
		// ������ ���Ѵ�
		nWidth = CONST_TERM * 2;
		// ���� ��Ʈ���� �����Ǿ� �ְ� �����Ѵٸ�
		if(Item.fmt & HDF_BITMAP && Item.mask & HDI_BITMAP && Item.hbm)
		{
			// ��Ʈ�� ��ü�� �����͸� �����Ѵ�
			pBitmap = CBitmap::FromHandle(Item.hbm);
			// ��Ʈ�� ������ ��´�
			pBitmap->GetBitmap(&BmpInfo);

			// ��Ʈ���� ���� �����Ѵٸ�
			if(BmpInfo.bmWidth > 0)
			{
				// ��Ʈ���� ���� ���Ѵ�
				nWidth += BmpInfo.bmWidth;
				// ������ ���Ѵ�
				nWidth += CONST_TERM;
			}
		}

		// ���� �̹����� �����Ǿ� �ְ� �����Ѵٸ�
		if((Item.mask & HDI_IMAGE) && (Item.fmt & HDF_IMAGE)
			&& (Item.iImage >= 0 && Item.iImage < pImageList->GetImageCount()))
		{
			// �̹����� ���� �����Ѵٸ�
			if(szImage.cx > 0)
			{
				// �̹����� ���� ���Ѵ�
				nWidth += szImage.cx;
				// ������ ���Ѵ�
				nWidth += CONST_TERM;
			}
		}

		// �ؽ�Ʈ ��¿� �ʿ��� ũ���� ���Ѵ�
		szText = pDC->GetTextExtent(Item.pszText, ::strlen(Item.pszText));
		// �ؽ�Ʈ ���� ���Ѵ�
		nWidth += szText.cx;

		// ���� ���� �׸��� ���� �׸��� ����ϴµ� �ʿ��� �������� ũ�ٸ�
		// ������ ������� �ʱ� ���ؼ� �簢 ������ �ʱ�ȭ�Ѵ�
		if(nWidth < rcItem.Width())			rcItem.SetRectEmpty();

		// �ش� �׸��� ������ �����Ѵ�
		m_wndToolTip.SetToolRect(this, i + 1, &rcItem);
	}

	// DC�� ��ȯ�ϰ� ��Ʈ�� �ǵ�����
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);
}
