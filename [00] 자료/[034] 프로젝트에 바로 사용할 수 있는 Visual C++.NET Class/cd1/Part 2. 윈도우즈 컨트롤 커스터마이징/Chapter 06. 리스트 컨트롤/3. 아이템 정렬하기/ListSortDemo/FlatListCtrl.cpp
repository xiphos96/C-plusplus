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
	// ���� ���� ���� �ʱ�ȭ
	m_nSortColumn		= -1;
	m_bSortAscending	= FALSE;
}

CFlatListCtrl::~CFlatListCtrl()
{
	// �̹��� ����Ʈ�� ������ ���¶�� �Ҹ� ��Ų��
	if(m_ImageList.m_hImageList)
		m_ImageList.DeleteImageList();
}


BEGIN_MESSAGE_MAP(CFlatListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CFlatListCtrl)
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
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

// �׸� �߰� ó�� �Լ�
int CFlatListCtrl::InsertItem(const LVITEM* pItem)
{
	// ���ο� �׸��� �߰��Ѵ�
	int nNewItem = CListCtrl::InsertItem(pItem);

	// ���� ���� �÷��� �����Ǿ� �ִٸ� �����Ѵ�
	// ���� �߰��� �׸��� ��ȣ�� ����� ��� �� ���� �޴´�
	if(m_nSortColumn >= 0)		Sort(&nNewItem);

	// �߰��� �׸��� ��ȣ�� �����Ѵ�
	return nNewItem;
}

// �׸� �߰� ó�� �Լ�
int CFlatListCtrl::InsertItem(int nItem, LPCTSTR lpszItem)
{
	// ���ο� �׸��� �߰��Ѵ�
	int nNewItem = CListCtrl::InsertItem(nItem, lpszItem);

	// ���� ���� �÷��� �����Ǿ� �ִٸ� �����Ѵ�
	// ���� �߰��� �׸��� ��ȣ�� ����� ��� �� ���� �޴´�
	if(m_nSortColumn >= 0)		Sort(&nNewItem);

	// �߰��� �׸��� ��ȣ�� �����Ѵ�
	return nNewItem;
}

// �׸� �߰� ó�� �Լ�
int CFlatListCtrl::InsertItem(int nItem, LPCTSTR lpszItem, int nImage)
{
	// ���ο� �׸��� �߰��Ѵ�
	int nNewItem = CListCtrl::InsertItem(nItem, lpszItem, nImage);

	// ���� ���� �÷��� �����Ǿ� �ִٸ� �����Ѵ�
	// ���� �߰��� �׸��� ��ȣ�� ����� ��� �� ���� �޴´�
	if(m_nSortColumn >= 0)		Sort(&nNewItem);

	// �߰��� �׸��� ��ȣ�� �����Ѵ�
	return nNewItem;
}

// �׸� �߰� ó�� �Լ�
int CFlatListCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, UINT nState, UINT nStateMask, int nImage, LPARAM lParam)
{
	// ���ο� �׸��� �߰��Ѵ�
	int nNewItem = CListCtrl::InsertItem(nMask, nItem, lpszItem, nState, nStateMask, nImage, lParam);

	// ���� ���� �÷��� �����Ǿ� �ִٸ� �����Ѵ�
	// ���� �߰��� �׸��� ��ȣ�� ����� ��� �� ���� �޴´�
	if(m_nSortColumn >= 0)		Sort(&nNewItem);

	// �߰��� �׸��� ��ȣ�� �����Ѵ�
	return nNewItem;
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

// ��� ��Ʈ���� �÷��� ���� Ŭ�� �̺�Ʈ �ڵ鷯
void CFlatListCtrl::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	// Ŭ���� �÷��� ��ȣ�� ��´�
	int nID = pNMListView->iSubItem;

	// ���� ���� ������ ���� �÷��̶��
	if(pNMListView->iSubItem == m_nSortColumn)
		// ���� ������ �ݴ�� �ٲ㼭 �����Ѵ�
		Sort(pNMListView->iSubItem, !m_bSortAscending);
	else
		// ���ο� �÷��� �������� �������� �����Ѵ�
		Sort(pNMListView->iSubItem, TRUE);

	*pResult = 0;
}

// ���� �Լ�
void CFlatListCtrl::Sort(int *pNew)
{
	// ���� ������ �������� �����Ѵ�
	Sort(m_nSortColumn, m_bSortAscending, pNew);
}

// ���� �Լ�
void CFlatListCtrl::Sort(int nCol, BOOL bAscending, int *pNew)
{
	// ���ο� �÷��� ������ �����Ѵ�
	m_nSortColumn		= nCol;
	m_bSortAscending	= bAscending;

	// ��� ��Ʈ���� �ٽ� �׸���
	m_wndHeaderCtrl.SetSortColumn(nCol, bAscending);

	// �� ������ �����Ѵ�
	QuickSort(0, GetItemCount() - 1, pNew);
}

// ������ �Լ�
void CFlatListCtrl::QuickSort(int nStart, int nEnd, int *pNew)
{
	// ���� ���� ��ȣ�� �� ��ȣ���� ���� �ʴٸ� ����
	if(nStart >= nEnd)		return;

	// ù �׸��� �������� ū ���� ���� ���� �����Ͽ� �� �κ����� ������
	int nHalf = Partition(nStart, nEnd, pNew);

	// ���ؿ� ���� ���� �κп� ���� �ٽ� �� ������ �����Ѵ�
	QuickSort(nStart, nHalf - 1, pNew);
	// ���ؿ� ���� ���� �κп� ���� �ٽ� �� ������ �����Ѵ�
	QuickSort(nHalf + 1, nEnd, pNew);
}

// ���� ���� �߽����� ū ���� ���� ������ ������ �Լ�
int CFlatListCtrl::Partition(int nStart, int nEnd, int *pNew)
{
	BOOL bContinue;
	CString strItem;
	// ù �׸��� �������� ���, �ؽ�Ʈ�� �׸� ��ȣ�� �����Ѵ�
	CString strBase = GetItemText(nStart, m_nSortColumn);
	int nBase = nStart;
	int nMax = ++nEnd;

	// ���� ��ȣ�� �� ��ȣ���� ���� ���� �����Ѵ�
	for(; nStart < nEnd;)
	{
		// ���� �ٷ� �ں���
		// �����������Ľ� ���� ������ ū �׸��� ã�´�
		// �����������Ľ� ���� ������ ���� �׸��� ã�´�
		for(bContinue = TRUE; bContinue && nStart < nMax - 1;)
		{
			nStart++;
			strItem = GetItemText(nStart, m_nSortColumn);

			if(m_bSortAscending)
				bContinue = strBase.CompareNoCase(strItem) > 0;
			else
				bContinue = strBase.CompareNoCase(strItem) < 0;
		}
		// �� ��ȣ����
		// �����������Ľ� ���� ������ ���� �׸��� ã�´�
		// �����������Ľ� ���� ������ ū �׸��� ã�´�
		for(bContinue = TRUE; bContinue;)
		{
			nEnd--;
			strItem = GetItemText(nEnd, m_nSortColumn);

			if(m_bSortAscending)
				bContinue = strBase.CompareNoCase(strItem) < 0;
			else
				bContinue = strBase.CompareNoCase(strItem) > 0;
		}

		// ū �׸�� ���� �׸��� ã�Ұ� ���� ��ȣ�� �� ��ȣ���� ������
		if(nStart < nEnd)
		{
			// ū �׸�� ���� �׸��� ��ġ�� �ٲ۴�
			Swap(nStart, nEnd);
			// �ٲ� �׸� �� ���� �߰��� �׸��� �ִٸ� ���ο� ��ȣ�� �����Ѵ�
			if(pNew)
			{
				if(*pNew == nStart)		*pNew = nEnd;
				else
					if(*pNew == nEnd)	*pNew = nStart;
			}
		}
		else
		{
			// ���� ���� ������ ������ �̵��ϴ� �׸��� ��ġ�� �ٲ۴�
			Swap(nBase, nEnd);
			// �ٲ� �׸� �� ���� �߰��� �׸��� �ִٸ� ���ο� ��ȣ�� �����Ѵ�
			if(pNew)
			{
				if(*pNew == nBase)		*pNew = nEnd;
				else
					if(*pNew == nEnd)	*pNew = nBase;
			}
		}
	}

	return nEnd;
}

// �� �׸��� �� �ٲٴ� �Լ�
void CFlatListCtrl::Swap(int nItem1, int nItem2)
{
	// �ٲ� �� �׸��� ��ȣ�� ���ٸ� ����
	if(nItem1 == nItem2)			return;

	// �÷� ������ ��´�
	int nColSize = m_wndHeaderCtrl.GetItemCount(), i;

	LVITEM Item1, Item2;
	CString strItem1, strItem2;

	// ��� �÷��� ���� �����Ѵ�
	for(i = 0; i < nColSize; i++)
	{
		// �� �׸��� �ؽ�Ʈ�� �д´�
		strItem1 = GetItemText(nItem1, i);
		strItem2 = GetItemText(nItem2, i);

		// �� �׸��� �Ӽ��� �д´�
		Item1.mask	= LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
		Item1.iItem = nItem1;
		Item1.iSubItem = i;
		Item1.stateMask = LVIS_CUT | LVIS_DROPHILITED |	LVIS_FOCUSED | LVIS_SELECTED | LVIS_OVERLAYMASK | LVIS_STATEIMAGEMASK;
		
		Item2 = Item1;
		Item2.iItem = nItem2;

		GetItem(&Item1);
		GetItem(&Item2);

		// �� �׸��� �ؽ�Ʈ�� �ٲ۴�
		SetItemText(nItem1, i, strItem2);
		SetItemText(nItem2, i, strItem1);

		// �� �׸��� �Ӽ��� �ٲ۴�
		Item1.iItem = nItem2;
		Item2.iItem = nItem1;

		SetItem(&Item1);
		SetItem(&Item2);
	}
}
