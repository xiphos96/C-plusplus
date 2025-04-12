// FlatListCtrl.cpp : implementation file
//

#include "stdafx.h"
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
	// �ݵ�� �Ʒ��� ���� Ÿ�Կ� ���� �ڵ鷯�� �����ؾ� �Ѵ�
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnNeedText)
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnNeedText)
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

	// �����찡 ���� �ִ� ���� ����� Ȱ��ȭ �Ѵ�
	EnableToolTips();
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

BOOL CFlatListCtrl::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	LPNMHEADER pNMHD = (LPNMHEADER)lParam;

	switch(pNMHD->hdr.code)
	{
	case HDN_ITEMCHANGEDA:
	case HDN_ITEMCHANGEDW:
		// ���� �׸� ��ȭ�� ����� ��� ��Ʈ���� ���� ������ �ٽ� ����Ѵ�
		m_wndHeaderCtrl.RecalcToolRect();
		break;
	}
	
	return CListCtrl::OnNotify(wParam, lParam, pResult);
}

// �÷� �߰� ó�� �Լ�
int CFlatListCtrl::InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat, int nWidth, int nSubItem)
{
	// ����Ʈ ��Ʈ���� �⺻ �÷� �߰� ��ƾ�� �����Ѵ�
	int nIndex = CListCtrl::InsertColumn(nCol, lpszColumnHeading, nFormat, nWidth, nSubItem);

	// ���� ����Ʈ �����̰� �÷��� ���������� �߰��Ǿ��ٸ�
	if(nIndex >= 0 && (GetStyle() & LVS_TYPEMASK) == LVS_REPORT)
	{
		// ��� ��Ʈ���� �ش� �÷��� ������ �߰��Ѵ�
		if(!m_wndHeaderCtrl.AddTool(nIndex, lpszColumnHeading))	return -1;
	}

	return nIndex;
}

// EnableToolTips()�� ���� ���� ��� ���� ��û �Լ�
int CFlatListCtrl::OnToolHitTest(CPoint point, TOOLINFO * pTI) const
{
	// Ŭ���̾�Ʈ ������ ���Ѵ�
	CRect rcTemp;
	GetClientRect(&rcTemp);

	// ���� Ŭ���̾�Ʈ ���� �ȿ� ���� �ʴٸ� ����
	if(!rcTemp.PtInRect(point))			return -1;
	// ���� �׸��� ���ٸ� ����
	if(GetItemCount() == 0)				return -1;

	// ù��° ���̴� �׸��� ��ȣ�� ��´�
	int nTop	= GetTopIndex();
	// �� �������� ���̴� �׸��� ������ ��� ������ �׸��� ��ȣ�� ����Ѵ�
	int nBottom = nTop + GetCountPerPage(), i;

	// ������ �׸��� ��ȣ�� �׸� ������ �ʰ��Ѵٸ� �����Ѵ�
	if(nBottom >= GetItemCount())	nBottom = GetItemCount() - 1;

	// ȭ�鿡 ���̴� �׸�鿡 ���� ���� ���θ� �����Ѵ�
	for(i = nTop; i <= nBottom; i++)
	{
		// �׸��� ������ ���Ѵ�
		GetItemRect(i, rcTemp, LVIR_BOUNDS);

		// �׸��� ������ ���Ѵٸ�
		if(rcTemp.PtInRect(point))
		{
			// ���� ����� ���� �Ӽ��� �����Ѵ�
			pTI->hwnd		= m_hWnd;
			pTI->uId		= (UINT)(i + 1);
			// TTN_NEEDTEXT �˸� �޽����� �޵��� LPSTR_TEXTCALLBACK�� �����Ѵ�
			pTI->lpszText	= LPSTR_TEXTCALLBACK;
			pTI->rect		= rcTemp;

			// ���� ID�� �����Ѵ�
			return pTI->uId;
		}
	}

	return -1;
}

// ���� �ؽ�Ʈ�� ��� ���� ȣ��Ǵ� �Լ�
BOOL CFlatListCtrl::OnNeedText(UINT id, NMHDR* pNMHDR, LRESULT* pResult)
{
	// ASCII �ڵ�� UNICODE�� ���� ��� ó���Ѵ�
	TOOLTIPTEXTA* pTipAscii = (TOOLTIPTEXTA*)pNMHDR;
	TOOLTIPTEXTW* pTipUnicode = (TOOLTIPTEXTW*)pNMHDR;

	// ���� ID�� ��´�
	UINT nID = pNMHDR->idFrom;

	// ���� ID�� ���ٸ� ����
	if(nID == 0)		return FALSE;

	// ���� ID���� �׸� ��ȣ�� ��´�
	int nItem = nID - 1;

	// �ش� �׸� ���� ���� �ؽ�Ʈ�� �����Ѵ�
	CString strTipText;
	strTipText.Format("[%s] - [%s] : [%s]",
		GetItemText(nItem, 0),
		GetItemText(nItem, 1),
		GetItemText(nItem, 2));

	// ���� �ƽ�Ű �ڵ���
	if(pNMHDR->code == TTN_NEEDTEXTA)
	{
		// ���� �ؽ�Ʈ�� �ƽ�Ű�ڵ� ���� ����ü�� �����Ѵ�
		pTipAscii->lpszText = LPSTR(LPCTSTR(strTipText));
	}
	else
	{
		// ���� �ؽ�Ʈ�� �����ڵ� ���� ����ü�� �����Ѵ�
		pTipUnicode->lpszText = (WCHAR*)strTipText.AllocSysString();
	}

	*pResult = 0;

	return TRUE;
}
