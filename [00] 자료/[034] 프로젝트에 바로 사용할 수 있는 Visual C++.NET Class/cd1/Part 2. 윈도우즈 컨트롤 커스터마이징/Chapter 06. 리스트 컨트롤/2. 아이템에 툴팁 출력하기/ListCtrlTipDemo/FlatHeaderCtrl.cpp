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

// 항목의 테두리 혹은 항목의 텍스트/이미지/비트맵 사이의 간격
#define CONST_TERM			6

CFlatHeaderCtrl::CFlatHeaderCtrl()
{
	// 멤버 변수들을 초기화한다
	m_clrFace		= ::GetSysColor(COLOR_3DFACE);
	m_clrHighLight	= ::GetSysColor(COLOR_3DHIGHLIGHT);
	m_clrShadow		= ::GetSysColor(COLOR_3DSHADOW);
	m_clrText		= ::GetSysColor(COLOR_BTNTEXT);

	m_HighLightPen.CreatePen(PS_SOLID, 1, m_clrHighLight);
	m_ShadowPen.CreatePen(PS_SOLID, 1, m_clrShadow);
}

CFlatHeaderCtrl::~CFlatHeaderCtrl()
{
	// 생성된 GDI 객체들을 소멸시킨다
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
	// 클라이언트 영역 크기를 얻는다
	GetClientRect(&m_rcClient);

	// 툴팁을 생성한다
	m_wndToolTip.Create(this);
	m_wndToolTip.Activate(TRUE);

	CHeaderCtrl::PreSubclassWindow();
}

void CFlatHeaderCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// 출력 대상 영역을 얻는다
	CRect rcClip;
	if(dc.GetClipBox(&rcClip) == ERROR)	return;

	// 출력 대상 영역을 기본 색상으로 칠한다
	dc.FillSolidRect(rcClip, m_clrFace);

	int i, nWidth;
	CRect rcItem;
	char szText[100];
	HDITEM Item;
	CBitmap *pBitmap;

	// 헤더의 항목 갯수를 얻는다
	int nSize = GetItemCount();
	// 헤더 컨트롤의 출력 폭을 0으로 조정한다
	m_rcClient.right = m_rcClient.left;

	CPen *pOldPen;
	// 헤더 컨트롤의 헤더 
	CFont *pOldFont = dc.SelectObject(GetFont());

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(m_clrText);

	// 이미지 리스트를 얻는다
	CImageList *pImageList = GetImageList();
	CSize szImage;

	// 이미지의 사이즈를 얻는다
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

	// 헤더 컨트롤의 항목 갯수만큼 반복
	for(i = 0; i < nSize; i++)
	{
		// 항목 이름 버퍼를 초기화
		::memset(szText, 0, sizeof(szText));

		// 항목 정보를 얻기 위해 구조체를 초기화한다
		Item.mask		= HDI_WIDTH | HDI_FORMAT | HDI_TEXT | HDI_IMAGE | HDI_BITMAP;
		Item.pszText	= szText;
		Item.cchTextMax = sizeof(szText);

		// 항목 정보를 얻는다
		GetItem(i, &Item);
		// 항목 영역을 얻는다
		GetItemRect(i, &rcItem);

		// 만약 항목이 출력 대상 영역에 속한다면
		if(rcItem.right >= rcClip.left && rcItem.left <= rcClip.right)
		{
			// 만약 비트맵이 설정되어 있다면 비트맵 객체를 생성한다.
			pBitmap = NULL;
			if(Item.fmt & HDF_BITMAP && Item.mask & HDI_BITMAP && Item.hbm)
			{
				pBitmap = CBitmap::FromHandle(Item.hbm);
			}

			// 좌우 여백을 둔다
			rcItem.left += CONST_TERM;
			rcItem.right -= CONST_TERM;

			// 항목의 텍스트 출력 방향에 따라 다르게 출력한다
			switch(Item.fmt & HDF_JUSTIFYMASK)
			{
			case HDF_LEFT:
				// 이미지를 항목의 좌측에 먼저 그린다
				nWidth = DrawImage(&dc, &rcItem, &Item, pImageList, &szImage);
				// 이미지 영역을 제한다
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// 이미지의 좌측에 텍스트를 출력한다
				nWidth = DrawText(&dc, &rcItem, &Item);
				// 텍스트 영역을 제한다
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// 텍스트의 좌측에 비트맵을 출력한다
				DrawBitmap(&dc, &rcItem, &Item, pBitmap);
				break;
			case HDF_CENTER:
				// 이미지를 항목의 좌측에 먼저 그린다
				nWidth = DrawImage(&dc, &rcItem, &Item, pImageList, &szImage);
				// 이미지 영역을 제한다
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// 비트맵을 항목의 우측에 출력한다
				nWidth = DrawBitmap(&dc, &rcItem, &Item, pBitmap);
				// 비트맵 영역을 제한다
				rcItem.right -= (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// 텍스트를 나머지 영역의 중앙에 출력한다
				DrawText(&dc, &rcItem, &Item);
				break;
			case HDF_RIGHT:
				// 이미지를 항목의 좌측에 먼저 그린다
				nWidth = DrawImage(&dc, &rcItem, &Item, pImageList, &szImage);
				// 이미지 영역을 제한다
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// 비트맵을 좌측에 출력한다
				nWidth = DrawBitmap(&dc, &rcItem, &Item, pBitmap);
				// 비트맵 영역을 제한다
				rcItem.left += (nWidth > 0) ? nWidth + CONST_TERM : 0;
				// 텍스트를 우측에 출력한다
				DrawText(&dc, &rcItem, &Item);
				break;
			}

			// 항목의 영역을 다시 구한다
			GetItemRect(i, &rcItem);

			// 만약 마지막 항목이 아니라면
			if(i < nSize - 1)
			{
				// 다음 항목과의 구별을 위해 구분자를 출력한다
				pOldPen = dc.SelectObject(&m_ShadowPen);
				dc.MoveTo(rcItem.right - 1, rcItem.top + 2);
				dc.LineTo(rcItem.right - 1, rcItem.bottom - 2);

				dc.SelectObject(&m_HighLightPen);
				dc.MoveTo(rcItem.right, rcItem.top + 2);
				dc.LineTo(rcItem.right, rcItem.bottom - 2);

				dc.SelectObject(pOldPen);
			}
		}

		// 헤더 컨트롤의 폭에 항목의 폭을 더한다
		m_rcClient.right += Item.cxy;
	}

	// 헤더 컨트롤에 대해 출력하였다면 
	if(m_rcClient.Width() > 0)
	{
		// 출력된 영역 외곽에 3차원 테두리를 출력한다
		dc.Draw3dRect(m_rcClient, m_clrHighLight, m_clrShadow);
	}

	dc.SelectObject(pOldFont);
}

// 항목의 이미지를 출력하는 함수
int CFlatHeaderCtrl::DrawImage(CDC *pDC, CRect *pRect, LPHDITEM pItem, CImageList *pImageList, CSize *pSize)
{
	// 이미지의 크기가 0이라면 리턴
	if(pSize->cx == 0 || pSize->cy == 0)									return 0;
	// 만약 항목 정보에 이미지 정보가 없다면 리턴
	if(!(pItem->mask & HDI_IMAGE))											return 0;
	// 만약 항목에 이미지가 없다면 리턴
	if(!(pItem->fmt & HDF_IMAGE))											return 0;
	// 만약 이미지 번호가 잘못 지정되었다면 리턴
	if(pItem->iImage < 0 || pItem->iImage >= pImageList->GetImageCount())	return 0;
	// 만약 출력할 영역이 없다면 리턴
	if(pRect->Width() <= 0)													return 0;

	// 이미지의 출력 위치를 계산한다
	CPoint ptImage;
	ptImage.x = pRect->left;
	ptImage.y = (pRect->top + pRect->bottom - pSize->cy) / 2;

	// 이미지의 출력 크기를 계산한다
	CSize szImage;
	szImage.cx = (pRect->Width() < pSize->cx) ? pRect->Width() : pSize->cx;
	szImage.cy = pSize->cy;

	// 이미지 리스트에서 항목의 이미지를 출력한다
	pImageList->DrawIndirect(pDC, pItem->iImage, ptImage, szImage, CPoint(0, 0));

	// 출력된 이미지 폭을 리턴한다
	return pSize->cx;
}

// 항목의 텍스트를 출력하는 함수
int CFlatHeaderCtrl::DrawText(CDC* pDC, CRect *pRect, LPHDITEM pItem)
{
	// 만약 출력할 영역이 없거나 텍스트 정보가 없거나 텍스트가 없다면 리턴
	if(pRect->Width() <= 0 || !(pItem->mask & HDI_TEXT) || !(pItem->fmt & HDF_STRING))	return 0;

	// 텍스트 출력을 위해 필요한 영역을 구한다
	CSize szText = pDC->GetTextExtent(pItem->pszText);

	// 텍스트 출력 방향에 따라 텍스트 출력 옵션을 설정한다
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
	// 출력 옵션에 따라 텍스트를 출력한다
	pDC->DrawText(pItem->pszText, -1, pRect, nFormat);

	// 출력된 폭을 계산하고 리턴한다
	szText.cx = pRect->Width() < szText.cx ? pRect->Width() : szText.cx;
	if(szText.cx < 0)	szText.cx = 0;

	return szText.cx;
}

// 항목의 비트맵을 출력하는 함수
int CFlatHeaderCtrl::DrawBitmap(CDC* pDC, CRect *pRect, LPHDITEM pItem, CBitmap* pBitmap)
{
	// 비트맵이 없다면 리턴
	if(pBitmap == NULL)		return 0;

	// 비트맵 정보를 얻는다
	BITMAP BmpInfo;
	pBitmap->GetObject(sizeof(BITMAP), &BmpInfo);

	// 만약 출력 폭 보다 비트맵 폭이 넓거나 출력 폭이 없다면 리턴
	if(BmpInfo.bmWidth > pRect->Width() || pRect->Width() <= 0)		return 0;

	// 만약 텍스트 출력 방향이 중앙이면 비트맵 출력 위치를 오른쪽으로 설정
	CPoint ptPoint;
	if(pItem->fmt & HDF_JUSTIFYMASK == HDF_CENTER)
		ptPoint.x = pRect->right - BmpInfo.bmHeight;
	else
		// 비트맵 출력 위치를 왼쪽으로 설정
		ptPoint.x = pRect->left;
	ptPoint.y = (pRect->top + pRect->bottom - BmpInfo.bmHeight) / 2;

	// DC를 생성하여 비트맵을 설정한다
	CDC BmpDC;
	BmpDC.CreateCompatibleDC(pDC);
	CBitmap *pOldBmp = BmpDC.SelectObject(pBitmap);

	// 비트맵을 화면에 출력한다
	pDC->BitBlt(ptPoint.x, ptPoint.y, BmpInfo.bmWidth, BmpInfo.bmHeight,
		&BmpDC, 0, 0, SRCCOPY);

	BmpDC.SelectObject(pOldBmp);
	BmpDC.DeleteDC();

	// 비트맵 출력 폭을 리턴한다
	return BmpInfo.bmWidth;
}

BOOL CFlatHeaderCtrl::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
//	return CHeaderCtrl::OnEraseBkgnd(pDC);
}

BOOL CFlatHeaderCtrl::PreTranslateMessage(MSG* pMsg) 
{
	// 툴팁 컨트롤에게 메시지를 전달
	m_wndToolTip.RelayEvent(pMsg);
	
	return CHeaderCtrl::PreTranslateMessage(pMsg);
}

// 특정 컬럼에 대해 툴팁을 설정하는 함수
BOOL CFlatHeaderCtrl::AddTool(int nCol, LPCTSTR pTipText)
{
	// 툴팁 출력 대상 컬럼의 번호 확인
	if(nCol < 0 || nCol >= GetItemCount())		return FALSE;

	// 컬럼의 사각 영역을 얻는다
	CRect rcCol;
	GetItemRect(nCol, &rcCol);

	// 툴팁 컨트롤에 해당 영역을 추가한다
	return m_wndToolTip.AddTool(this, pTipText, &rcCol, nCol + 1);
}

// 각 컬럼 항목의 위치에 따라 툴팁 출력 영역을 다시 계산하는 함수
void CFlatHeaderCtrl::RecalcToolRect()
{
	// 툴팁 컨트롤이 생성되지 않은 상태에서는 리턴
	if(!::IsWindow(m_wndToolTip.m_hWnd))	return;

	char strTip[100];
	int i, nSize, nWidth;
	HDITEM Item;
	CRect rcItem;
	CSize szText;
	CBitmap *pBitmap;
	BITMAP BmpInfo;

	// 항목 갯수를 얻는다
	nSize = GetItemCount();

	// 이미지 리스트를 얻는다
	CImageList *pImageList = GetImageList();
	CSize szImage;

	// 이미지의 사이즈를 얻는다
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

	// 현재 헤더컨트롤의 DC를 얻고 폰트를 설정한다
	CDC *pDC = GetDC();
	CFont *pOldFont = (CFont*)pDC->SelectObject(GetFont());

	// 헤더 컨트롤의 항목 갯수만큼 반복
	for(i = 0; i < nSize; i++)
	{
		// 항목 이름 버퍼를 초기화
		::memset(strTip, 0, sizeof(strTip));

		// 항목 정보를 얻기 위해 구조체를 초기화한다
		Item.mask		= HDI_WIDTH | HDI_FORMAT | HDI_TEXT | HDI_IMAGE | HDI_BITMAP;
		Item.pszText	= strTip;
		Item.cchTextMax = sizeof(strTip); 

		// 항목 정보를 얻는다
		GetItem(i, &Item);
		// 항목 영역을 얻는다
		GetItemRect(i, &rcItem);

		// 항목에 필요한 최소 폭 구하기
		// 여백을 더한다
		nWidth = CONST_TERM * 2;
		// 만약 비트맵이 설정되어 있고 존재한다면
		if(Item.fmt & HDF_BITMAP && Item.mask & HDI_BITMAP && Item.hbm)
		{
			// 비트맵 객체의 포인터를 생성한다
			pBitmap = CBitmap::FromHandle(Item.hbm);
			// 비트맵 정보를 얻는다
			pBitmap->GetBitmap(&BmpInfo);

			// 비트맵의 폭이 존재한다면
			if(BmpInfo.bmWidth > 0)
			{
				// 비트맵의 폭을 더한다
				nWidth += BmpInfo.bmWidth;
				// 여백을 더한다
				nWidth += CONST_TERM;
			}
		}

		// 만약 이미지가 설정되어 있고 존재한다면
		if((Item.mask & HDI_IMAGE) && (Item.fmt & HDF_IMAGE)
			&& (Item.iImage >= 0 && Item.iImage < pImageList->GetImageCount()))
		{
			// 이미지의 폭이 존재한다면
			if(szImage.cx > 0)
			{
				// 이미지의 폭을 더한다
				nWidth += szImage.cx;
				// 여백을 더한다
				nWidth += CONST_TERM;
			}
		}

		// 텍스트 출력에 필요한 크기을 구한다
		szText = pDC->GetTextExtent(Item.pszText, ::strlen(Item.pszText));
		// 텍스트 폭을 더한다
		nWidth += szText.cx;

		// 만약 현재 항목의 폭이 항목을 출력하는데 필요한 영역보다 크다면
		// 툴팁을 출력하지 않기 위해서 사각 영역을 초기화한다
		if(nWidth < rcItem.Width())			rcItem.SetRectEmpty();

		// 해당 항목의 툴팁을 변경한다
		m_wndToolTip.SetToolRect(this, i + 1, &rcItem);
	}

	// DC를 반환하고 폰트를 되돌린다
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);
}
