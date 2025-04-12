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

// �׸� ����, �̹����� �ؽ�Ʈ�� ����
#define CONST_ITEM_GAP		2

CMultiListBox::CMultiListBox()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
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
	// ����� ���� �׸���� �Ӽ����� �����Ѵ�
	ModifyStyle(LBS_SORT, LBS_OWNERDRAWVARIABLE | LBS_HASSTRINGS | LBS_NOINTEGRALHEIGHT);
	
	CDragListBox::PreSubclassWindow();
}

// �̹��� ����Ʈ ���� �Լ�
void CMultiListBox::SetImageList(CImageList *pImageList)
{
	// �̹��� ����Ʈ�� �����Ѵ�
	m_pImageList = pImageList;

	if(m_pImageList)
	{
		// ���� ������ �̹��� ����Ʈ�� �̹��� ũ�⸦ ��´�
		IMAGEINFO info;
		m_pImageList->GetImageInfo(0, &info);

		m_szImage.cx = info.rcImage.right - info.rcImage.left;
		m_szImage.cy = info.rcImage.bottom - info.rcImage.top;
	}
	else
		// �̹��� ũ�⸦ �ʱ�ȭ�Ѵ�
		m_szImage.cx = m_szImage.cy = 0;

	// ���� ���� ������ν� ���̴� ���¶�� �ٽ� �׸���
	if(IsWindowVisible())		Invalidate();
}

// ���ο� �׸��� �߰��ϴ� �Լ�
int CMultiListBox::AddString(LPCTSTR lpszItem, int nImage)
{
	// ���ο� �׸� �����͸� �����Ѵ�
	LPLBDATA pData	= new LBDATA;
	// ������ �Ӽ��� �����Ѵ�
	pData->bEnable	= TRUE;
	pData->nImage	= nImage;

	// ���ο� �׸��� �߰��Ѵ�
	int nIndex = CDragListBox::AddString(lpszItem);
	// �׸��� �����͸� �����Ѵ�
	SetItemData(nIndex, (DWORD_PTR)pData);

	// ���ο� �׸��� ��ȣ�� �����Ѵ�
	return nIndex;
}

// ���ο� �׸��� Ư�� ��ġ�� �߰��ϴ� �Լ�
int CMultiListBox::InsertString(int nIndex, LPCTSTR lpszItem, int nImage)
{
	// ���ο� �׸� �����͸� �����Ѵ�
	LPLBDATA pData	= new LBDATA;
	// ������ �Ӽ��� �����Ѵ�
	pData->bEnable	= TRUE;
	pData->nImage	= nImage;

	// ���ο� �׸��� Ư�� ��ġ�� �߰��Ѵ�
	nIndex = CDragListBox::InsertString(nIndex, lpszItem);
	// �׸��� �����͸� �����Ѵ�
	SetItemData(nIndex, (DWORD_PTR)pData);

	// ���ο� �׸��� ��ȣ�� �����Ѵ�
	return nIndex;
}

// Ư�� �׸��� �����ϴ� �Լ�
int CMultiListBox::DeleteString(int nIndex)
{
	// �׸��� �����͸� ��´�
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);
	// �׸��� �����͸� �Ҹ��Ų��
	if(pData)		delete pData;

	// �׸��� �����Ѵ�
	return CDragListBox::DeleteString(nIndex);
}

// ��� �׸��� �����ϴ� �Լ�
void CMultiListBox::ResetContent()
{
	// �׸��� ������ ��´�
	int i, nSize = GetCount();
	LPLBDATA pData;

	// ��� �׸� ���� �ݺ��Ѵ�
	for(i = 0; i < nSize; i++)
	{
		// �׸��� �����͸� ��´�
		pData = (LPLBDATA)GetItemData(i);
		// �׸��� �����͸� �Ҹ��Ų��
		delete pData;
	}

	// ��� �׸��� �����Ѵ�
	CDragListBox::ResetContent();
}

// Ư�� �׸��� �̹��� ��ȣ�� �����ϴ� �Լ�
int CMultiListBox::GetImage(int nIndex)
{
	// �׸� ��ȣ�� ��ȿ���� Ȯ���Ѵ�
	if(nIndex < 0 || nIndex >= GetCount())		return -1;

	// �׸��� �����͸� ��´�
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);

	// �׸��� �̹��� ��ȣ�� �����Ѵ�
	return pData->nImage;
}

	// Ư�� �׸��� �̹��� ��ȣ�� �����ϴ� �Լ�
int CMultiListBox::SetImage(int nIndex, int nImage)
{
	// �׸� ��ȣ�� ��ȿ���� Ȯ���Ѵ�
	if(nIndex < 0 || nIndex >= GetCount())		return -1;
	// �̹��� ��ȣ�� ��ȿ���� Ȯ���Ѵ�
	if(m_pImageList->GetImageCount() <= nImage)	return -1;

	// �׸��� �����͸� ��´�
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);

	// �׸��� �̹��� ��ȣ�� �����Ѵ�
	pData->nImage = nImage;

	// ���� ���� ����Ʈ �ڽ��� ���̴� ��������
	if(IsWindowVisible())
	{
		CRect rcItem;

		// ������ �׸��� ������ ���Ѵ�
		GetItemRect(nIndex, &rcItem);
		// �ش� ������ �ٽ� �׸���
		InvalidateRect(rcItem);
	}
	// �׸��� ��ȣ�� �����Ѵ�
	return pData->nImage;
}

// Ư�� �׸��� Ȱ��ȭ �������� �����ϴ� �Լ�
BOOL CMultiListBox::IsEnabled(int nIndex)
{
	// �׸� ��ȣ�� ��ȿ���� Ȯ���Ѵ�
	if(nIndex < 0 || nIndex >= GetCount())		return FALSE;

	// �׸��� �����͸� ��´�
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);

	// ���� Ȱ��ȭ ���¸� �����Ѵ�
	return pData->bEnable;
}

// Ư�� �׸��� Ȱ��ȭ ��Ű�ų� ��Ȱ��ȭ ��Ű�� �Լ�
BOOL CMultiListBox::EnableString(int nIndex, BOOL bEnable)
{
	// �׸� ��ȣ�� ��ȿ���� Ȯ���Ѵ�
	if(nIndex < 0 || nIndex >= GetCount())		return FALSE;

	// �׸��� �����͸� ��´�
	LPLBDATA pData = (LPLBDATA)GetItemData(nIndex);

	// ���� ���� ���¿� ���ٸ� ����
	if(pData->bEnable == bEnable)	return bEnable;
	// ���ο� Ȱ��ȭ ���¸� �����Ѵ�
	pData->bEnable = bEnable;

	// ���� ���� ����Ʈ �ڽ��� ���̴� ��������
	if(IsWindowVisible())
	{
		CRect rcItem;

		// ������ �׸��� ������ ���Ѵ�
		GetItemRect(nIndex, &rcItem);
		// �ش� ������ �ٽ� �׸���
		InvalidateRect(rcItem);
	}

	// �׸��� Ȱ��ȭ ���¸� �����Ѵ�
	return pData->bEnable;
}

// �� �׸��� ũ�⸦ ����ϴ� �Լ�
void CMultiListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	CString	strText;
	// �׸��� �ؽ�Ʈ�� ���Ѵ�
	GetText(lpMeasureItemStruct->itemID, strText);

	CRect	rcItem(0, 0, lpMeasureItemStruct->itemWidth, lpMeasureItemStruct->itemHeight);

	if(rcItem.right == 0)
	{
		CRect rcClient;
		GetClientRect(&rcClient);
		rcItem.right = rcClient.Width();
	}

	// ����Ʈ �ڽ��� �⺻ ��Ʈ�� �����Ѵ�
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// �׸��� �ؽ�Ʈ�� ����ϴµ� �ʿ��� ũ�⸦ ���Ѵ�
	pDC->DrawText(strText, rcItem, DT_WORDBREAK | DT_EXPANDTABS | DT_CALCRECT);

	// �׸��� �ؽ�Ʈ ���� �̹��� ���� ���Ͽ� �׸��� ���� �����Ѵ�
	lpMeasureItemStruct->itemWidth = rcItem.Width() + m_szImage.cx + (m_szImage.cx > 0 ? CONST_ITEM_GAP : 0);
	// �׸��� �ؽ�Ʈ ���̿� �̹��� ���� �߿� ū ���� �׸��� ���̷� �����Ѵ�
	lpMeasureItemStruct->itemHeight = max(rcItem.Height(), m_szImage.cy);

	// �׸��� ������ ���Ѵ�
	lpMeasureItemStruct->itemWidth += CONST_ITEM_GAP * 2;
	lpMeasureItemStruct->itemHeight += CONST_ITEM_GAP * 2;

	// ��Ʈ�� ��ȯ�ϰ� DC�� ��ȯ�Ѵ�
	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);
}

// �� �׸��� ����ϴ� �Լ�
void CMultiListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// ���� ���۸��� �����Ѵ�
	CDC dc, MemDC;
	dc.Attach(lpDrawItemStruct->hDC);
	MemDC.CreateCompatibleDC(&dc);

	// �׸��� �簢 ������ ���Ѵ�
	CRect rcItem = lpDrawItemStruct->rcItem;
	rcItem.OffsetRect(-rcItem.left, -rcItem.top);

	// �޸� DC�� ��Ʈ���� �����ϰ� �����Ѵ�
	CBitmap MemBmp, *pOldBmp;
	MemBmp.CreateCompatibleBitmap(&dc, rcItem.Width(), rcItem.Height());
	pOldBmp = MemDC.SelectObject(&MemBmp);

	// �׸��� �����͸� ���Ѵ�
	LPLBDATA pData = (LPLBDATA)GetItemData(lpDrawItemStruct->itemID);

	// �׸��� ���� ���¸� ���Ѵ�
	BOOL bIsSelected	= (lpDrawItemStruct->itemState & ODS_SELECTED);
	BOOL bIsFocused		= (lpDrawItemStruct->itemState & ODS_FOCUS);
	BOOL bIsDisabled	= ((lpDrawItemStruct->itemState & ODS_DISABLED) || !pData->bEnable);

	COLORREF clrBkgnd;

	// �׸��� ���õ� ���¿� �ƴ� ���� ������ ���Ѵ�
	if(bIsSelected && !bIsDisabled)		clrBkgnd = m_clrSelected;
	else								clrBkgnd = m_clrBkgnd;
	// �׸��� ����� ĥ�Ѵ�
	MemDC.FillSolidRect(&rcItem, clrBkgnd);

	// �ؽ�Ʈ ��� ��ġ�� ���Ѵ�
	CRect rcText = rcItem;
	rcText.DeflateRect(CONST_ITEM_GAP, CONST_ITEM_GAP);

	// ���� �׸��� �̹����� �����Ǿ� �ִٸ�
	if(m_pImageList && pData->nImage >= 0)
	{
		// �̹��� ��� ��ġ�� ����Ѵ�
		CRect rcImage = rcText;
		rcImage.right = rcImage.left + m_szImage.cx;
		rcImage.bottom = rcImage.top + m_szImage.cy;

		// �׸� �̹����� ���� �������� �����Ѵ�
		HICON hIcon = m_pImageList->ExtractIcon(pData->nImage);
		if(hIcon)
		{
			// ���� Ȱ��ȭ ���¿� ���� �������� ����Ѵ�
			MemDC.DrawState(rcImage.TopLeft(), m_szImage, hIcon,
				bIsDisabled ? DSS_DISABLED : DSS_NORMAL, (CBrush*)NULL);

			// �������� �Ҹ��Ų��
			::DestroyIcon(hIcon);
		}

		// �ؽ�Ʈ ��� ��ġ�� �����Ѵ�
		rcText.left = rcImage.right + CONST_ITEM_GAP;
	}

	// �׸��� �ؽ�Ʈ�� ���Ѵ�
	CString strItem;
	GetText(lpDrawItemStruct->itemID, strItem);

	// ����Ʈ �ڽ� ��Ʈ���� �⺻ ��Ʈ�� �����Ѵ�
	CFont *pOldFont = MemDC.SelectObject(GetFont());
	// �ؽ�Ʈ ��� ����� �������� �����Ѵ�
	MemDC.SetBkMode(TRANSPARENT);
	// ���� Ȱ��ȭ ���¿� ���� �ؽ�Ʈ ��� ������ �����Ѵ�
	if(bIsDisabled)			MemDC.SetTextColor(::GetSysColor(COLOR_GRAYTEXT));
	else
	{
		// ���� ���õ� �׸��̶�� �ؽ�Ʈ ������ ���� ��Ų��
		if(bIsSelected)		MemDC.SetTextColor(0x00ffffff & (~m_clrText));
		else				MemDC.SetTextColor(m_clrText);
	}

	// �׸��� �ؽ�Ʈ�� ����Ѵ�
	MemDC.DrawText(strItem, rcText, DT_WORDBREAK | DT_EXPANDTABS);
	// ��Ʈ�� ��ȯ�Ѵ�
	MemDC.SelectObject(pOldFont);

	// ���� ���� ���õ� �׸��̶�� �簢 �׵θ��� �׸���
	if(bIsFocused && !bIsDisabled)		MemDC.DrawFocusRect(&rcItem);

	// �޸� DC�� ������ ȭ�鿡 ����Ѵ�
	dc.BitBlt(lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.top,
		rcItem.Width(), rcItem.Height(), &MemDC, 0, 0, SRCCOPY);

	// ���� ��Ʈ���� �����Ѵ�
	MemDC.SelectObject(pOldBmp);
	// �޸� DC�� �����Ѵ�
	MemDC.DeleteDC();
	// �޸� ��Ʈ���� �����Ѵ�
	MemBmp.DeleteObject();
	dc.Detach();
}

void CMultiListBox::OnDestroy() 
{
	CDragListBox::OnDestroy();

	// ����Ʈ �ڽ��� �Ҹ��� �� ��� �׸��� �����͸� �Ҹ� ��Ų��
	ResetContent();
}
