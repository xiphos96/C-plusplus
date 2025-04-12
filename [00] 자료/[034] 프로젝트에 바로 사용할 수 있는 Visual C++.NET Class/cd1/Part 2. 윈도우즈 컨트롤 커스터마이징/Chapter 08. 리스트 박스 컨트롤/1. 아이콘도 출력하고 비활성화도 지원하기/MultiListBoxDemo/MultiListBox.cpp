// MultiListBox.cpp : implementation file
//

#include "stdafx.h"
#include "multilistboxdemo.h"
#include "MultiListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiListBox

// 항목간 간격, 이미지와 텍스트의 간격
#define CONST_ITEM_GAP		2

CMultiListBox::CMultiListBox()
{
	// 멤버 변수들을 초기화한다
	m_pImageList	= NULL;

	m_clrBkgnd		= ::GetSysColor(COLOR_WINDOW);
	m_clrSelected	= ::GetSysColor(COLOR_HIGHLIGHT);
	m_clrText		= ::GetSysColor(COLOR_WINDOWTEXT);
}

CMultiListBox::~CMultiListBox()
{
}


BEGIN_MESSAGE_MAP(CMultiListBox, CDragListBox)
	//{{AFX_MSG_MAP(CMultiListBox)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiListBox message handlers

void CMultiListBox::PreSubclassWindow() 
{
	// 사용자 정의 그리기로 속성들을 변경한다
	ModifyStyle(LBS_SORT, LBS_OWNERDRAWVARIABLE | LBS_HASSTRINGS | LBS_NOINTEGRALHEIGHT);
	
	CDragListBox::PreSubclassWindow();
}

// 이미지 리스트 설정 함수
void CMultiListBox::SetImageList(CImageList *pImageList)
{
	// 이미지 리스트를 설정한다
	m_pImageList = pImageList;

	if(m_pImageList)
	{
		// 새로 설정된 이미지 리스트의 이미지 크기를 얻는다
		IMAGEINFO info;
		m_pImageList->GetImageInfo(0, &info);

		m_szImage.cx = info.rcImage.right - info.rcImage.left;
		m_szImage.cy = info.rcImage.bottom - info.rcImage.top;
	}
	else
		// 이미지 크기를 초기화한다
		m_szImage.cx = m_szImage.cy = 0;

	// 만약 현재 윈도우로써 보이는 상태라면 다시 그리기
	if(IsWindowVisible())		Invalidate();
}

// 새로운 항목을 추가하는 함수
int CMultiListBox::AddString(LPCTSTR lpszItem, int nImage)
{
	// 새로운 항목 데이터를 생성한다
	LPLBDATA pData	= new LBDATA;
	// 데이터 속성을 설정한다
	pData->bEnable	= TRUE;
	pData->nImage	= nImage;

	// 새로운 항목을 추가한다
	int nIndex = CDragListBox::AddString(lpszItem);
	// 항목의 데이터를 설정한다
	SetItemData(nIndex, (DWORD_PTR)pData);

	// 새로운 항목의 번호를 리턴한다
	return nIndex;
}

// 새로운 항목을 특정 위치에 추가하는 함수
int CMultiListBox::InsertString(int nIndex, LPCTSTR lpszItem, int nImage)
{
	// 새로운 항목 데이터를 생성한다
	LPLBDATA pData	= new LBDATA;
	// 데이터 속성을 설정한다
	pData->bEnable	= TRUE;
	pData->nImage	= nImage;

	// 새로운 항목을 특정 위치에 추가한다
	nIndex = CDragListBox::InsertString(nIndex, lpszItem);
	// 항목의 데이터를 설정한다
	SetItemData(nIndex, (DWORD_PTR)pData);

	// 새로운 항목의 번호를 리턴한다
	return nIndex;
}

// 특정 항목을 삭제하는 함수
int CMultiListBox::DeleteString(int nIndex)
{
	// 항목의 데이터를 얻는다
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);
	// 항목의 데이터를 소멸시킨다
	if(pData)		delete pData;

	// 항목을 삭제한다
	return CDragListBox::DeleteString(nIndex);
}

// 모든 항목을 삭제하는 함수
void CMultiListBox::ResetContent()
{
	// 항목의 갯수를 얻는다
	int i, nSize = GetCount();
	LPLBDATA pData;

	// 모든 항목에 대해 반복한다
	for(i = 0; i < nSize; i++)
	{
		// 항목의 데이터를 얻는다
		pData = (LPLBDATA)GetItemData(i);
		// 항목의 데이터를 소멸시킨다
		delete pData;
	}

	// 모든 항목을 삭제한다
	CDragListBox::ResetContent();
}

// 특정 항목의 이미지 번호를 리턴하는 함수
int CMultiListBox::GetImage(int nIndex)
{
	// 항목 번호의 유효성을 확인한다
	if(nIndex < 0 || nIndex >= GetCount())		return -1;

	// 항목의 데이터를 얻는다
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);

	// 항목의 이미지 번호를 리턴한다
	return pData->nImage;
}

	// 특정 항목의 이미지 번호를 설정하는 함수
int CMultiListBox::SetImage(int nIndex, int nImage)
{
	// 항목 번호의 유효성을 확인한다
	if(nIndex < 0 || nIndex >= GetCount())		return -1;
	// 이미지 번호의 유효성을 확인한다
	if(m_pImageList->GetImageCount() <= nImage)	return -1;

	// 항목의 데이터를 얻는다
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);

	// 항목의 이미지 번호를 설정한다
	pData->nImage = nImage;

	// 만약 현재 리스트 박스가 보이는 윈도우라면
	if(IsWindowVisible())
	{
		CRect rcItem;

		// 수정된 항목의 영역을 구한다
		GetItemRect(nIndex, &rcItem);
		// 해당 영역을 다시 그린다
		InvalidateRect(rcItem);
	}
	// 항목의 번호를 리턴한다
	return pData->nImage;
}

// 특정 항목이 활성화 상태인지 리턴하는 함수
BOOL CMultiListBox::IsEnabled(int nIndex)
{
	// 항목 번호의 유효성을 확인한다
	if(nIndex < 0 || nIndex >= GetCount())		return FALSE;

	// 항목의 데이터를 얻는다
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);

	// 현재 활성화 상태를 리턴한다
	return pData->bEnable;
}

// 특정 항목을 활성화 시키거나 비활성화 시키는 함수
BOOL CMultiListBox::EnableString(int nIndex, BOOL bEnable)
{
	// 항목 번호의 유효성을 확인한다
	if(nIndex < 0 || nIndex >= GetCount())		return FALSE;

	// 항목의 데이터를 얻는다
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);

	// 만약 현재 상태와 같다면 리턴
	if(pData->bEnable == bEnable)	return bEnable;
	// 새로운 활성화 상태를 설정한다
	pData->bEnable = bEnable;

	// 만약 현재 리스트 박스가 보이는 윈도우라면
	if(IsWindowVisible())
	{
		CRect rcItem;

		// 수정된 항목의 영역을 구한다
		GetItemRect(nIndex, &rcItem);
		// 해당 영역을 다시 그린다
		InvalidateRect(rcItem);
	}

	// 항목의 활성화 상태를 리턴한다
	return pData->bEnable;
}

// 각 항목의 크기를 계산하는 함수
void CMultiListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	CString	strText;
	// 항목의 텍스트를 구한다
	GetText(lpMeasureItemStruct->itemID, strText);

	CRect	rcItem(0, 0, lpMeasureItemStruct->itemWidth, lpMeasureItemStruct->itemHeight);

	if(rcItem.right == 0)
	{
		CRect rcClient;
		GetClientRect(&rcClient);
		rcItem.right = rcClient.Width();
	}

	// 리스트 박스의 기본 폰트를 설정한다
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// 항목의 텍스트를 출력하는데 필요한 크기를 구한다
	pDC->DrawText(strText, rcItem, DT_WORDBREAK | DT_EXPANDTABS | DT_CALCRECT);

	// 항목의 텍스트 폭에 이미지 폭을 더하여 항목의 폭을 설정한다
	lpMeasureItemStruct->itemWidth = rcItem.Width() + m_szImage.cx + (m_szImage.cx > 0 ? CONST_ITEM_GAP : 0);
	// 항목의 텍스트 높이와 이미지 높이 중에 큰 값을 항목의 높이로 설정한다
	lpMeasureItemStruct->itemHeight = max(rcItem.Height(), m_szImage.cy);

	// 항목의 여백을 더한다
	lpMeasureItemStruct->itemWidth += CONST_ITEM_GAP * 2;
	lpMeasureItemStruct->itemHeight += CONST_ITEM_GAP * 2;

	// 폰트를 반환하고 DC를 반환한다
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);
}

// 각 항목을 출력하는 함수
void CMultiListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// 더블 버퍼링을 실행한다
	CDC dc, MemDC;
	dc.Attach(lpDrawItemStruct->hDC);
	MemDC.CreateCompatibleDC(&dc);

	// 항목의 사각 영역을 구한다
	CRect rcItem = lpDrawItemStruct->rcItem;
	rcItem.OffsetRect(-rcItem.left, -rcItem.top);

	// 메모리 DC의 비트맵을 생성하고 설정한다
	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, rcItem.Width(), rcItem.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// 항목의 데이터를 구한다
	LPLBDATA pData = (LPLBDATA)GetItemData(lpDrawItemStruct->itemID);

	// 항목의 현재 상태를 구한다
	BOOL bIsSelected	= (lpDrawItemStruct->itemState & ODS_SELECTED);
	BOOL bIsFocused		= (lpDrawItemStruct->itemState & ODS_FOCUS);
	BOOL bIsDisabled	= ((lpDrawItemStruct->itemState & ODS_DISABLED) || !pData->bEnable);

	COLORREF clrBkgnd;

	// 항목이 선택된 상태와 아닐 때의 배경색을 구한다
	if(bIsSelected && !bIsDisabled)		clrBkgnd = m_clrSelected;
	else								clrBkgnd = m_clrBkgnd;
	// 항목의 배경을 칠한다
	MemDC.FillSolidRect(&rcItem, clrBkgnd);

	// 텍스트 출력 위치를 구한다
	CRect rcText = rcItem;
	rcText.DeflateRect(CONST_ITEM_GAP, CONST_ITEM_GAP);

	// 만약 항목의 이미지가 설정되어 있다면
	if(m_pImageList && pData->nImage >= 0)
	{
		// 이미지 출력 위치를 계산한다
		CRect rcImage = rcText;
		rcImage.right = rcImage.left + m_szImage.cx;
		rcImage.bottom = rcImage.top + m_szImage.cy;

		// 항목 이미지에 대한 아이콘을 생성한다
		HICON hIcon = m_pImageList->ExtractIcon(pData->nImage);
		if(hIcon)
		{
			// 현재 활성화 상태에 따라 아이콘을 출력한다
			MemDC.DrawState(rcImage.TopLeft(), m_szImage, hIcon,
				bIsDisabled ? DSS_DISABLED : DSS_NORMAL, (CBrush*)NULL);

			// 아이콘을 소멸시킨다
			::DestroyIcon(hIcon);
		}

		// 텍스트 출력 위치를 보정한다
		rcText.left = rcImage.right + CONST_ITEM_GAP;
	}

	// 항목의 텍스트를 구한다
	CString strItem;
	GetText(lpDrawItemStruct->itemID, strItem);

	// 리스트 박스 컨트롤의 기본 폰트를 설정한다
	CFont *pOldFont = MemDC.SelectObject(GetFont());
	// 텍스트 출력 배경을 투명으로 설정한다
	MemDC.SetBkMode(TRANSPARENT);
	// 현재 활성화 상태에 따라 텍스트 출력 색상을 설정한다
	if(bIsDisabled)			MemDC.SetTextColor(::GetSysColor(COLOR_GRAYTEXT));
	else
	{
		// 만약 선택된 항목이라면 텍스트 색상을 반전 시킨다
		if(bIsSelected)		MemDC.SetTextColor(0x00ffffff & (~m_clrText));
		else				MemDC.SetTextColor(m_clrText);
	}

	// 항목의 텍스트를 출력한다
	MemDC.DrawText(strItem, rcText, DT_WORDBREAK | DT_EXPANDTABS);
	// 폰트를 반환한다
	MemDC.SelectObject(pOldFont);

	// 만약 현재 선택된 항목이라면 사각 테두리를 그린다
	if(bIsFocused && !bIsDisabled)		MemDC.DrawFocusRect(&rcItem);

	// 메모리 DC의 내용을 화면에 출력한다
	dc.BitBlt(lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.top,
		rcItem.Width(), rcItem.Height(), &MemDC, 0, 0, SRCCOPY);

	// 이전 비트맵을 설정한다
	MemDC.SelectObject(pOldBmp);
	// 메모리 DC를 제거한다
	MemDC.DeleteDC();
	// 메모리 비트맵을 제거한다
	MemBmp.DeleteObject();
	dc.Detach();
}

void CMultiListBox::OnDestroy() 
{
	CDragListBox::OnDestroy();

	// 리스트 박스가 소멸할 때 모든 항목의 데이터를 소멸 시킨다
	ResetContent();
}
