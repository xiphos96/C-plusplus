// DDListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ddlistctrldemo.h"
#include "DDListCtrl.h"

// CArray�� ����ϱ� ���� ��� ����
#include <afxtempl.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDDListCtrl

CDDListCtrl::CDDListCtrl()
{
	// ��� ������ �ʱ�ȭ�Ѵ�
	m_bDragging		= FALSE;
	m_pDragImage	= NULL;
	m_pDropList		= NULL;
}

CDDListCtrl::~CDDListCtrl()
{
	// ���� �巡�� �̹����� �����ϸ� �����Ѵ�
	if(m_pDragImage)	delete m_pDragImage;
}


BEGIN_MESSAGE_MAP(CDDListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CDDListCtrl)
	ON_NOTIFY_REFLECT(LVN_BEGINDRAG, OnBegindrag)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDListCtrl message handlers

void CDDListCtrl::PreSubclassWindow() 
{
	// �� ��ü�� �����ϴ� Ȯ�� �Ӽ��� �����Ѵ�
	SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	CListCtrl::PreSubclassWindow();
}

// �巡�� �̹����� �����ϴ� �Լ�
CImageList* CDDListCtrl::CreateDragImageEx(LPPOINT lpPoint)
{
	CRect rcTemp, rcSelected;
	// Ŭ���̾�Ʈ ������ ��´�
	GetClientRect(&rcTemp);

	// Ŭ���̾�Ʈ ������ ���� �����Ѵ�
	int nWidth  = rcTemp.Width(), nItem;

	// ȭ�鿡 ���̴� ù��° ���� ã�´�
	int nStart = GetTopIndex() - 1;
	// ���� �� ��ȣ�� �����Ѵ�
	if(nStart < 0)					nStart = 0;

	// ȭ�鿡 ���̴� ������ ���� ����Ѵ�
	int nEnd = nStart + GetCountPerPage() + 1;
	// ������ �� ��ȣ�� �����Ѵ�
	if(nEnd >= GetItemCount())		nEnd = GetItemCount() - 1;

	// ���õ� ��ü �׸��� �簢 ������ �ʱ�ȭ�Ѵ�
	rcSelected.SetRectEmpty();
	// ���õ� �׸��� ã�´�
	POSITION pos = GetFirstSelectedItemPosition();
	for(; pos;)
	{
		// ���õ� �׸� ��ȣ�� ��´�
		nItem = GetNextSelectedItem(pos);
		// ���� ȭ�鿡 ������ �ʴ� �׸��̸� �ǳʶڴ�
		if(nItem < nStart || nItem > nEnd)		continue;

		// �׸��� �簢 ������ ��´�
		GetItemRect(nItem, &rcTemp, LVIR_BOUNDS);

		// �׸��� ���� Ŭ���̾�Ʈ ���� ���� �°� �����Ѵ�
		if(rcTemp.left < 0)				rcTemp.left = 0;
		if(rcTemp.Width() > nWidth)		rcTemp.right = rcTemp.left + nWidth;

		// ��ü ���� �׸� �簢 ������ �׸��� �簢 ������ �߰��Ѵ�
		rcSelected.UnionRect(rcSelected, rcTemp);
	}

	// �޸� DC�� �����Ѵ�
	CDC *pDC = GetDC();
	CDC MemDC;

	MemDC.CreateCompatibleDC(pDC);

	// ��ü ���� �׸� �簢 ������ŭ ��Ʈ���� �����Ѵ�
	CBitmap bmp, *pOldBmp;
	bmp.CreateCompatibleBitmap(pDC, rcSelected.Width(), rcSelected.Height());
	// �޸� DC�� ��Ʈ���� �����Ѵ�
	pOldBmp = MemDC.SelectObject(&bmp);

	// �޸� DC�� ����� �����(���)���� ĥ�Ѵ�
	MemDC.FillSolidRect(0, 0, rcSelected.Width(), rcSelected.Height(), RGB(255, 255, 255));

	CPoint pt;
	CImageList *pItemImage;

	// ���õ� �׸��� ã�´�
	pos = GetFirstSelectedItemPosition();
	for(; pos;)
	{
		// ���õ� �׸� ��ȣ�� ��´�
		nItem = GetNextSelectedItem(pos);
		// ���� ȭ�鿡 ������ �ʴ� �׸��̸� �ǳʶڴ�
		if(nItem < nStart || nItem > nEnd)		continue;

		// ���õ� �׸� ���� �巡�� �̹����� �����Ѵ�
		pItemImage = CreateDragImage(nItem, &pt);
		// �巡�� �̹����� ���������� �����Ǿ��ٸ�
		if(pItemImage)
		{
			// �׸� �簢 ������ ���Ѵ�
			GetItemRect(nItem, &rcTemp, LVIR_BOUNDS);

			// �巡�� �̹��� ���� ��ġ�� ��ü ���� �׸� �簢 ������ ������������ ��� ��ǥ�� �����Ѵ�
			pt.Offset(-rcSelected.left, -rcSelected.top);
			// �޸� DC�� �巡�� �̹����� ����Ѵ�
			pItemImage->Draw(&MemDC, 0, pt, ILD_NORMAL);
			// �巡�� �̹����� �����Ѵ�
			pItemImage->DeleteImageList();
			delete pItemImage;
		}
	}

	// �޸� DC�� ��Ʈ���� ��ȯ�Ѵ�
	MemDC.SelectObject(pOldBmp);
	// �޸� DC�� �����Ѵ�
	MemDC.DeleteDC();
	ReleaseDC(pDC);

	// �̹��� ����Ʈ�� �����Ѵ�
	CImageList *pDragImage = new CImageList;
	// ��ü ���� �׸� �簢 ���� ũ��� �����Ѵ�
	pDragImage->Create(rcSelected.Width(), rcSelected.Height(), ILC_COLOR | ILC_MASK, 0, 1);
	// �׸� �̹������� �׸� ��Ʈ���� �̹��� ����Ʈ�� �����ϰ�, ������� �����Ѵ�
	pDragImage->Add(&bmp, RGB(255, 255, 255));

	// ��Ʈ���� �����Ѵ�
	bmp.DeleteObject();

	// ���ڷ� ��ǥ �����Ͱ� �Ѱ�������
	if(lpPoint)
	{
		// ��ü ���� �׸� �簢 ������ �������� �����Ѵ�
		*lpPoint = rcSelected.TopLeft();
	}

	// �̹��� ����Ʈ�� �����Ѵ�
	return pDragImage;
}

// �׸� �巡�� ���� �Լ�
void CDDListCtrl::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	*pResult = 0;

	// ���� ���õ� �׸��� ���ٸ� ����
	if(GetSelectedCount() <= 0)			return;

	CPoint pt;
	// �巡�� �̹��� ����Ʈ�� �����Ѵ�
	m_pDragImage	= CreateDragImageEx(&pt);
	// �������� �ʱ�ȭ�Ѵ�
	m_bDragging		= TRUE;
	m_nDropIndex	= -1;
	m_pDropList		= NULL;

	// ���� ��ǥ���� �̹��� ����Ʈ�� ���� ��ġ�� ���Ѵ�
	pt.x = pNMListView->ptAction.x - pt.x;
	pt.y = pNMListView->ptAction.y - pt.y;

	// �巡�� �̹����� ���콺 Ŀ���� �Բ� ����Ѵ�
	m_pDragImage->BeginDrag(0, pt);
	m_pDragImage->DragEnter(NULL, pt);

	// ���콺 �̺�Ʈ�� ĸ���Ѵ�
	SetCapture ();
}

void CDDListCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���� �巡�� ���̸�
	if(m_bDragging)
	{
		// ���� ��ǥ�� ��ũ�� ��ǥ�� �ٲ۴�
		CPoint pt = point;
		ClientToScreen(&pt);
		// �巡�� �̹����� ��ġ�� �����Ѵ�
		m_pDragImage->DragMove(pt);
		// �巡�� �̹����� �����
		m_pDragImage->DragShowNolock(FALSE);

		// ���콺 ��ǥ�� ������ �����͸� ��´�
		CWnd* pDropWnd = WindowFromPoint(pt);

		// ���� ������ �巡�� �Ǿ��� ����Ʈ ��Ʈ���� �ִٸ�
		if(m_pDropList != NULL)
		{
			// ���� ��� ���̶���Ʈ �Ǿ��� �׸��� �ִٸ�
			if(m_nDropIndex >= 0)
			{
				// ��� ���̶���Ʈ �Ӽ��� �����Ͽ� �ٽ� ����Ѵ�
				m_pDropList->SetItemState(m_nDropIndex, 0, LVIS_DROPHILITED);
				m_pDropList->RedrawItems(m_nDropIndex, m_nDropIndex);
				m_pDropList->UpdateWindow();
			}
			// ��� ������ �ʱ�ȭ�Ѵ�
			m_nDropIndex = -1;
			m_pDropList = NULL;
		}

		// ���� ���콺�� ��ġ�� ���� �����찡 ����Ʈ ��Ʈ���̸�
		if(pDropWnd->IsKindOf(RUNTIME_CLASS(CListCtrl)))
		{
			// ���콺 Ŀ���� ȭ��ǥ�� �����Ѵ�
			SetCursor(LoadCursor(NULL, IDC_ARROW));

			// ������ �����͸� ����Ʈ ��Ʈ�� �����ͷ� �ٲپ� ��� ������ �����Ѵ�
			m_pDropList = (CListCtrl*)pDropWnd;
			// ���콺 Ŀ�� ��ǥ�� ����Ʈ ��Ʈ���� Ŭ���̾�Ʈ ��ǥ�� �����Ѵ�
			m_pDropList->ScreenToClient(&pt);

			// ���콺�� ��ġ�� �׸� ��ȣ�� ��´�
			m_nDropIndex = m_pDropList->HitTest(pt, NULL);

			// ���� �׸� ��ȣ�� ������ٸ�
			if(m_nDropIndex >= 0)
			{
				// �׸� ��� ���̶���Ʈ �Ӽ��� �����ϰ� �ٽ� ����Ѵ�
				m_pDropList->SetItemState(m_nDropIndex, LVIS_DROPHILITED, LVIS_DROPHILITED);
				m_pDropList->RedrawItems(m_nDropIndex, m_nDropIndex);
				m_pDropList->UpdateWindow();
			}
		}
		else
		{
			// ���콺 Ŀ���� ���� ǥ�÷� �ٲ۴�
			SetCursor(LoadCursor(NULL, IDC_NO));
		}

		// �巡�� �̹����� �ٽ� ����Ѵ�
		m_pDragImage->DragShowNolock(TRUE);
	}
	
	CListCtrl::OnMouseMove(nFlags, point);
}

void CDDListCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ���� �巡�� ���̸�
	if(m_bDragging)
	{
		// ���콺 �̺�Ʈ ĸ�縦 �����Ѵ�
		ReleaseCapture();

		// �巡�� �̹��� ����� �����Ѵ�
		m_pDragImage->EndDrag();
		// �巡�� �̹��� ����Ʈ�� �����Ѵ�
		m_pDragImage->DeleteImageList();
		delete m_pDragImage;
		m_pDragImage = NULL;

		// ���� ��ǥ�� ��ũ�� ��ǥ�� �ٲ۴�
		CPoint pt = point;
		ClientToScreen(&pt);

		// ���콺 ��ǥ�� ������ �����͸� ��´�
		CWnd* pDropWnd = WindowFromPoint(pt);

		// ���� ������ �巡�� �Ǿ��� ����Ʈ ��Ʈ���� �ִٸ�
		if(m_pDropList != NULL)
		{
			// ���� ��� ���̶���Ʈ �Ǿ��� �׸��� �ִٸ�
			if(m_nDropIndex >= 0)
			{
				// ��� ���̶���Ʈ �Ӽ��� �����Ͽ� �ٽ� ����Ѵ�
				m_pDropList->SetItemState(m_nDropIndex, 0, LVIS_DROPHILITED);
				m_pDropList->RedrawItems(m_nDropIndex, m_nDropIndex);
				m_pDropList->UpdateWindow();
			}
		}

		// ���� ���콺�� ��ġ�� ���� �����찡 ����Ʈ ��Ʈ���̸�
		if(pDropWnd->IsKindOf(RUNTIME_CLASS(CListCtrl)))
		{
			// ������ �����͸� ����Ʈ ��Ʈ�� �����ͷ� �ٲپ� ��� ������ �����Ѵ�
			m_pDropList = (CListCtrl*)pDropWnd;

			// ���콺 Ŀ�� ��ǥ�� ����Ʈ ��Ʈ���� Ŭ���̾�Ʈ ��ǥ�� �����Ѵ�
			m_pDropList->ScreenToClient(&pt);

			// ���콺�� ��ġ�� �׸� ��ȣ�� ��´�
			m_nDropIndex = m_pDropList->HitTest(pt, NULL);

			// ���õ� �׸��� ��� ����Ʈ ��Ʈ�ѷ� �ű��
			DropItems();
		}

		// ��� �������� �ʱ�ȭ�Ѵ�
		m_bDragging = FALSE;
		m_pDropList = NULL;
		m_nDropIndex = -1;
	}
	
	CListCtrl::OnLButtonUp(nFlags, point);
}

// ���õ� �׸��� ��� ��� ����Ʈ ��Ʈ�ѿ� �ű�� �Լ�
void CDDListCtrl::DropItems()
{
	// CtrlŰ�� ������ �������� ����
	BOOL bCopy = ::GetKeyState(VK_CONTROL) & 0x8000;
	// �纻�� �����ؾ� �ϴ��� ����
	BOOL bSabon = (bCopy && (m_hWnd == m_pDropList->m_hWnd));

	CArray<SDropItemInfo*, SDropItemInfo*> DropItems;
	SDropItemInfo *pItem;

	// ���õ� �׸��� ã�´�
	POSITION pos = GetFirstSelectedItemPosition();
	for(; pos;)
	{
		// ���õ� �׸� ����ü ��ü�� �����Ѵ�
		pItem = new SDropItemInfo;

		// ���õ� �׸� ��ȣ�� �����Ѵ�
		pItem->nItem = GetNextSelectedItem(pos);
		// ���õ� �׸� �ؽ�Ʈ�� �����Ѵ�
		pItem->strItem = GetItemText(pItem->nItem, 0);

		// ���õ� �׸��� �Ӽ����� �����Ѵ�
		::memset(&pItem->lvItem, 0, sizeof(LVITEM));
		pItem->lvItem.mask		= LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
		pItem->lvItem.iItem		= pItem->nItem;
		pItem->lvItem.iSubItem	= 0;
		pItem->lvItem.stateMask = LVIS_CUT | LVIS_DROPHILITED | LVIS_FOCUSED | LVIS_SELECTED | LVIS_OVERLAYMASK | LVIS_STATEIMAGEMASK;
		GetItem(&pItem->lvItem);

		// ��� �׸� �迭�� �߰��Ѵ�
		DropItems.Add(pItem);
	}

	int nItem;
	// ���� �����ϱⰡ �ƴϸ� ���õ� �׸��� ã�´�
	pos = GetFirstSelectedItemPosition();
	for(; pos && !bCopy; )
	{
		// ���õ� �׸� ��ȣ�� ��´�
		nItem = GetNextSelectedItem(pos);

		// ���� ���� ����Ʈ ��Ʈ�ѿ��� �巡���ϰ� ����ߴٸ�
		if(this->m_hWnd == m_pDropList->m_hWnd)
			// ���� ��ӵ� ��ġ�� �巡���� ��ġ���� �ڿ� �ִٸ� ��ġ�� �����Ѵ�
			if(nItem < m_nDropIndex)		m_nDropIndex--;

		// �巡�׵� �׸��� �����Ѵ�
		DeleteItem(nItem);

		// �Ǵٸ� ���õ� �׸��� ã�´�
		pos = GetFirstSelectedItemPosition();
	}

	// ��� ����Ʈ ��Ʈ�ѿ��� ���õ� �׸��� ã�´�
	pos = m_pDropList->GetFirstSelectedItemPosition();
	for(; pos; )
	{
		// �׸��� ��ȣ�� ��´�
		nItem = m_pDropList->GetNextSelectedItem(pos);

		// ���õ� ���¸� �����Ѵ�
		m_pDropList->SetItemState(nItem, 0, LVIS_SELECTED);

		// �� �ٸ� ���õ� �׸��� ã�´�
		pos = m_pDropList->GetFirstSelectedItemPosition();
	}

	// ��� �׸� �迭�� ũ�⸦ ��´�
	int nSize = (int)DropItems.GetSize(), nPos;
	for(nItem = nSize - 1; nItem >= 0; nItem--)
	{
		// ��� �׸��� ��´�
		pItem = DropItems.GetAt(nItem);
		// ���� ��� ��ġ�� ���ٸ�
		if(m_nDropIndex < 0)
			// ����Ʈ ��Ʈ���� ���� �� ��ġ�� �����Ѵ�
			nPos = m_pDropList->GetItemCount();
		else
			// ��� ��ġ�� �����Ѵ�
			nPos = m_nDropIndex;

		// ���� �纻�� �����ϴ� ���̸�
		if(bSabon)		pItem->strItem.Insert(0, "�纻 - ");

		// ��� ��ġ�� �׸��� �߰��Ѵ�
		nPos = m_pDropList->InsertItem(nPos, pItem->strItem);
		// �߰��� �׸��� �Ӽ��� �����Ѵ�
		pItem->lvItem.iItem = nPos;
		m_pDropList->SetItem(&pItem->lvItem);
		// �߰��� �׸��� ���� ���·� �����
		m_pDropList->SetItemState(nPos, LVIS_SELECTED, LVIS_SELECTED);

		// �׸��� �����Ѵ�
		delete pItem;
	}

	// �迭�� �ʱ�ȭ�Ѵ�
	DropItems.RemoveAll();
}
