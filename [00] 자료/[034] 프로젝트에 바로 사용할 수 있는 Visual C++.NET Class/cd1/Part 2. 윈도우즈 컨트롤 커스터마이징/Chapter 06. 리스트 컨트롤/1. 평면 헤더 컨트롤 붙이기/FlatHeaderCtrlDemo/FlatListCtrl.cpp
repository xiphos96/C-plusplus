// FlatListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "flatheaderctrldemo.h"
#include "FlatListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlatListCtrl

CFlatListCtrl::CFlatListCtrl()
{
}

CFlatListCtrl::~CFlatListCtrl()
{
	// 이미지 리스트가 생성된 상태라면 소멸 시킨다
	if(m_ImageList.m_hImageList)
		m_ImageList.DeleteImageList();
}


BEGIN_MESSAGE_MAP(CFlatListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CFlatListCtrl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlatListCtrl message handlers

void CFlatListCtrl::PreSubclassWindow() 
{
	CListCtrl::PreSubclassWindow();

	// 기본 헤더 컨트롤 대신 평면 헤더 컨트롤을 리스트 컨트롤에 설정한다
	m_wndHeaderCtrl.SubclassWindow(::GetDlgItem(m_hWnd, 0));

	// 행 전체가 선택되는 속성을 설정한다
	SetExtendedStyle(LVS_EX_FULLROWSELECT);
}

void CFlatListCtrl::SetHeaderImage(UINT nBitmap, int cx, int nGrow)
{
	// 만약 이미지 리스트가 생성되어 있다면 소멸 시킨다
	if(m_ImageList.m_hImageList)
		m_ImageList.DeleteImageList();

	// 이미지 리스트를 생성한다
	m_ImageList.Create(nBitmap, cx, nGrow, RGB(255, 255, 255));
	// 평면 헤더 컨트롤에 이미지 리스트를 설정한다
	m_wndHeaderCtrl.SetImageList(&m_ImageList);

	// 헤더 컨트롤의 항목들에 대해 이미지를 설정한다
	int nSize = m_wndHeaderCtrl.GetItemCount(), i;
	HDITEM Item;

	for(i = 0; i < nSize; i++)
	{
		// 헤더의 항목 정보를 얻는다
		Item.mask = HDI_FORMAT | HDI_IMAGE;
		m_wndHeaderCtrl.GetItem(i, &Item);

		// 이미지 속성을 설정한다
		Item.fmt	|= HDF_IMAGE;
		Item.iImage = i;
		m_wndHeaderCtrl.SetItem(i, &Item);
	}
}
