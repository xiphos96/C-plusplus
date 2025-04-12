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
	// �̹��� ����Ʈ�� ������ ���¶�� �Ҹ� ��Ų��
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

	// �⺻ ��� ��Ʈ�� ��� ��� ��� ��Ʈ���� ����Ʈ ��Ʈ�ѿ� �����Ѵ�
	m_wndHeaderCtrl.SubclassWindow(::GetDlgItem(m_hWnd, 0));

	// �� ��ü�� ���õǴ� �Ӽ��� �����Ѵ�
	SetExtendedStyle(LVS_EX_FULLROWSELECT);
}

void CFlatListCtrl::SetHeaderImage(UINT nBitmap, int cx, int nGrow)
{
	// ���� �̹��� ����Ʈ�� �����Ǿ� �ִٸ� �Ҹ� ��Ų��
	if(m_ImageList.m_hImageList)
		m_ImageList.DeleteImageList();

	// �̹��� ����Ʈ�� �����Ѵ�
	m_ImageList.Create(nBitmap, cx, nGrow, RGB(255, 255, 255));
	// ��� ��� ��Ʈ�ѿ� �̹��� ����Ʈ�� �����Ѵ�
	m_wndHeaderCtrl.SetImageList(&m_ImageList);

	// ��� ��Ʈ���� �׸�鿡 ���� �̹����� �����Ѵ�
	int nSize = m_wndHeaderCtrl.GetItemCount(), i;
	HDITEM Item;

	for(i = 0; i < nSize; i++)
	{
		// ����� �׸� ������ ��´�
		Item.mask = HDI_FORMAT | HDI_IMAGE;
		m_wndHeaderCtrl.GetItem(i, &Item);

		// �̹��� �Ӽ��� �����Ѵ�
		Item.fmt	|= HDF_IMAGE;
		Item.iImage = i;
		m_wndHeaderCtrl.SetItem(i, &Item);
	}
}
