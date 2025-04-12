// DDTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ddtreectrldemo.h"
#include "DDTreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDDTreeCtrl

// ��ӽ� ��� ��带 Ȯ���ϴ� Ÿ�̸� ID
#define CONST_EXPAND_TIMER_ID			1

CDDTreeCtrl::CDDTreeCtrl()
{
	// ��� ������ �ʱ�ȭ�Ѵ�
	m_bDragging		= FALSE;
	m_pDragImage	= NULL;
	m_pDropTree		= NULL;

	m_hDragCursor	= AfxGetApp()->LoadCursor(IDC_DRAG_CURSOR);
}

CDDTreeCtrl::~CDDTreeCtrl()
{
	// ���� �巡�� �̹����� �����ϸ� �����Ѵ�
	if(m_pDragImage)	delete m_pDragImage;
	::DeleteObject(m_hDragCursor);
}


BEGIN_MESSAGE_MAP(CDDTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CDDTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBegindrag)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndlabeledit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDTreeCtrl message handlers

// �̹��� �������� ����� �׸� �簢 ���� ȹ�� �Լ�
void CDDTreeCtrl::GetItemRect(HTREEITEM hItem, LPRECT lpRect)
{
	// �ؽ�Ʈ ������ ���Ѵ�
	CTreeCtrl::GetItemRect(hItem, lpRect, TRUE);

	// �̹��� ����Ʈ�� �����Ǿ� �ִ��� Ȯ���Ѵ�
	CImageList *pImageList = GetImageList(TVSIL_NORMAL);
	if(pImageList == NULL)					return;
	if(pImageList->GetImageCount() <= 0)	return;

	// �̹��� ����Ʈ�� �̹��� ���� ���Ѵ�
	IMAGEINFO info;
	pImageList->GetImageInfo(0, &info);

	// �̹��� ���� �׸� ���� ���Ѵ�
	lpRect->right += info.rcImage.right - info.rcImage.left;
}

// �巡�� �̹����� �����ϴ� �Լ�
CImageList* CDDTreeCtrl::CreateDragImageEx(LPPOINT lpPoint)
{
	CRect rcClient, rcSelected, rcTemp;
	// Ŭ���̾�Ʈ ������ ��´�
	GetClientRect(&rcClient);

	// �巡�׵� �׸��� ������ ���Ѵ�
	CArray<HTREEITEM, HTREEITEM> ItemArray;
	HTREEITEM hSelected = m_hDragNode;
	GetItemRect(hSelected, &rcSelected);

	// �巡�� ��� �迭�� �߰��Ѵ�
	ItemArray.Add(hSelected);

	// �巡�� �׸��� ���� �׸��� ���� �ְ� Ȯ�� �Ǿ� ���� ���
	UINT nState = GetItemState(hSelected, TVIF_STATE);
	if(ItemHasChildren(hSelected) && (nState & TVIS_EXPANDED))
	{
		// ���� �׸��� ������ ���Ѵ�
		CreateDragImageLoop(hSelected, rcClient, rcSelected, ItemArray);
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

	// ���� �׸��� ������ŭ �ݺ��Ѵ�
	int i, nSize = (int)ItemArray.GetSize();
	for(i = 0; i < nSize; i++)
	{
		// ���� �׸��� �ڵ��� ��´�
		hSelected = ItemArray.GetAt(i);

		// �巡�׵� �׸� ���� �巡�� �̹����� �����Ѵ�
		pItemImage = CreateDragImage(hSelected);
		// �巡�� �̹����� ���������� �����Ǿ��ٸ�
		if(pItemImage)
		{
			// �׸� �簢 ������ ���Ѵ�
			GetItemRect(hSelected, &rcTemp);

			// �巡�� �̹��� ���� ��ġ�� ��ü ���� �׸� �簢 ������ ������������ ��� ��ǥ�� �����Ѵ�
			pt = rcTemp.TopLeft();
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
		// �巡�� �׸� ������ �������� �����Ѵ�
		*lpPoint = rcSelected.TopLeft();
	}

	// �̹��� ����Ʈ�� �����Ѵ�
	return pDragImage;
}

// �巡�׵Ǵ� ���� �׸��� ã�� �Լ�
void CDDTreeCtrl::CreateDragImageLoop(HTREEITEM hParent, CRect &rcClient, CRect &rcSelected,
	CArray<HTREEITEM, HTREEITEM> &ItemArray)
{
	// ���� �׸� �ڵ��� ���Ѵ�
	HTREEITEM hChild = GetChildItem(hParent);
	CRect rcItem;
	UINT nState;

	// ��� ���� �׸� ���� �ݺ��Ѵ�
	for(; hChild;)
	{
		// ���� �׸��� �簢 ������ ���Ѵ�
		GetItemRect(hChild, &rcItem);
		// ���� ���̴� �׸��� ���
		if(rcClient.left < rcItem.right && rcClient.right > rcItem.left
			&& rcClient.top < rcItem.bottom && rcClient.bottom > rcItem.top)
		{
			// �巡�� �̹��� ���� ������� �߰��Ѵ�
			ItemArray.Add(hChild);
			// �׸� �簢 ������ ��ü ���� �簢 ������ �߰��Ѵ�
			rcSelected.UnionRect(rcItem, rcSelected);

			// ���� ���� �׸��� ���� �ְ� Ȯ��Ǿ� �ִٸ�
			nState = GetItemState(hChild, TVIF_STATE);
			if(ItemHasChildren(hChild) && (nState & TVIS_EXPANDED))
			{
				// ���� �׸��� ������ ���Ѵ�
				CreateDragImageLoop(hChild, rcClient, rcSelected, ItemArray);
			}
		}

		// ���� ���� �׸��� ã�´�
		hChild = GetNextItem(hChild, TVGN_NEXT);
	}
}

void CDDTreeCtrl::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	*pResult = 0;

	// ���� ���õ� �׸��� ���ٸ� ����
	m_hDragNode = pNMTreeView->itemNew.hItem;
	if(m_hDragNode == NULL)			return;

	CPoint pt;
	// �巡�� �̹��� ����Ʈ�� �����Ѵ�
	m_pDragImage	= CreateDragImageEx(&pt);
	// �������� �ʱ�ȭ�Ѵ�
	m_bDragging		= TRUE;
	m_hDropNode		= NULL;
	m_pDropTree		= NULL;

	// ���� ��ǥ���� �̹��� ����Ʈ�� ���� ��ġ�� ���Ѵ�
	pt.x = pNMTreeView->ptDrag.x - pt.x;
	pt.y = pNMTreeView->ptDrag.y - pt.y;

	// �巡�� �̹����� ���콺 Ŀ���� �Բ� ����Ѵ�
	m_pDragImage->BeginDrag(0, pt);
	m_pDragImage->DragEnter(NULL, pt);

	// ���콺 �̺�Ʈ�� ĸ���Ѵ�
	SetCapture();
}

void CDDTreeCtrl::OnMouseMove(UINT nFlags, CPoint point) 
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

		// ���� ������ �巡�� �Ǿ��� Ʈ�� ��Ʈ���� �ִٸ�
		if(m_pDropTree != NULL)
		{
			// ���� ��� ���̶���Ʈ �Ǿ��� �׸��� �ִٸ�
			if(m_hDropNode != NULL)
			{
				// ��� ���̶���Ʈ �Ӽ��� �����Ͽ� �ٽ� ����Ѵ�
				m_pDropTree->SetItemState(m_hDropNode, 0, TVIS_DROPHILITED);
				m_pDropTree->UpdateWindow();
			}
			// ��� ������ �ʱ�ȭ�Ѵ�
			m_hDropNode = NULL;
			m_pDropTree = NULL;
		}

		// ���� ���콺�� ��ġ�� ���� �����찡 Ʈ�� ��Ʈ���̸�
		if(pDropWnd->IsKindOf(RUNTIME_CLASS(CTreeCtrl)))
		{
			// ���콺 Ŀ���� �巡�� Ŀ���� �����Ѵ�
			SetCursor(m_hDragCursor);

			// ������ �����͸� Ʈ�� ��Ʈ�� �����ͷ� �ٲپ� ��� ������ �����Ѵ�
			m_pDropTree = (CTreeCtrl*)pDropWnd;
			// ���콺 Ŀ�� ��ǥ�� Ʈ�� ��Ʈ���� Ŭ���̾�Ʈ ��ǥ�� �����Ѵ�
			m_pDropTree->ScreenToClient(&pt);

			// ���콺�� ��ġ�� �׸� �ڵ��� ���Ѵ�
			m_hDropNode = m_pDropTree->HitTest(pt, NULL);

			// ���� �׸� �ڵ��� �������ٸ�
			if(m_hDropNode != NULL)
			{
				// �׸� ��� ���̶���Ʈ �Ӽ��� �����ϰ� �ٽ� ����Ѵ�
				m_pDropTree->SetItemState(m_hDropNode, TVIS_DROPHILITED, TVIS_DROPHILITED);
				m_pDropTree->UpdateWindow();

				// ��� �׸� Ȯ�� Ÿ�̸Ӹ� �����Ѵ�
				SetTimer(CONST_EXPAND_TIMER_ID, 1000, NULL);
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
	
	CTreeCtrl::OnMouseMove(nFlags, point);
}

void CDDTreeCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ���� �巡�� ���̸�
	if(m_bDragging)
	{
		// ��� �׸� Ȯ�� Ÿ�̸Ӹ� �����Ѵ�
		KillTimer(CONST_EXPAND_TIMER_ID);

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

		// ���� ������ �巡�� �Ǿ��� Ʈ�� ��Ʈ���� �ִٸ�
		if(m_pDropTree != NULL)
		{
			// ���� ��� ���̶���Ʈ �Ǿ��� �׸��� �ִٸ�
			if(m_hDropNode != NULL)
			{
				// ��� ���̶���Ʈ �Ӽ��� �����Ͽ� �ٽ� ����Ѵ�
				m_pDropTree->SetItemState(m_hDropNode, 0, TVIS_DROPHILITED);
				m_pDropTree->UpdateWindow();
			}
		}

		// ���� ���콺�� ��ġ�� ���� �����찡 Ʈ�� ��Ʈ���̸�
		if(pDropWnd->IsKindOf(RUNTIME_CLASS(CTreeCtrl)))
		{
			// ������ �����͸� Ʈ�� ��Ʈ�� �����ͷ� �ٲپ� ��� ������ �����Ѵ�
			m_pDropTree = (CTreeCtrl*)pDropWnd;
			// ���콺 Ŀ�� ��ǥ�� Ʈ�� ��Ʈ���� Ŭ���̾�Ʈ ��ǥ�� �����Ѵ�
			m_pDropTree->ScreenToClient(&pt);

			// ���콺�� ��ġ�� �׸� �ڵ��� ���Ѵ�
			m_hDropNode = m_pDropTree->HitTest(pt, NULL);

			// ���õ� �׸��� ��� Ʈ�� ��Ʈ�ѷ� �ű��
			DropItems();
		}

		// ��� �������� �ʱ�ȭ�Ѵ�
		m_bDragging = FALSE;
		m_pDropTree = NULL;
		m_hDragNode = NULL;
		m_hDropNode = NULL;
	}
	
	CTreeCtrl::OnLButtonUp(nFlags, point);
}

// ���õ� �׸��� ��� ��� Ʈ�� ��Ʈ�ѿ� �ű�� �Լ�
void CDDTreeCtrl::DropItems()
{
	// ��Ʈ��Ű�� ���������� ����
	BOOL bCopy = ::GetKeyState(VK_CONTROL) & 0x8000, bSabon = FALSE;

	// ���� �巡���� Ʈ�� ��Ʈ�Ѱ� ��ӵǴ� Ʈ�� ��Ʈ���� �����ϴٸ�
	if(m_hWnd == m_pDropTree->m_hWnd)
	{
		// ���� ������ ��ġ�� ��ӵȴٸ�
		if(GetParentItem(m_hDragNode) == m_hDropNode)
		{
			// ���� �����ϴ� ���� �ƴ϶��
			if(!bCopy)
			{
				// ������ ��ġ�̹Ƿ� ����
				MessageBox("���� �׸�� ��� �׸��� ��ġ�� ���� ����� �� �����ϴ�.");
				return;
			}
			// �����ϴ� ���̶�� �纻���� �����Ѵ�
			bSabon = TRUE;
		}

		// �巡���ϴ� �׸� ���η� ��ӵǾ����� Ȯ���Ѵ�
		HTREEITEM hParent = m_hDropNode;

		for(; hParent != NULL;)
		{
			if(hParent == m_hDragNode)
			{
				MessageBox("�巡�� �׸� ���Ե� ��忡�� ����� �� �����ϴ�.");
				return;
			}

			hParent = GetParentItem(hParent);
		}
	}

	SDropItemInfo DropItems;

	// �巡���ϴ� �׸� ���� ������ ��´�
	DropItems.hItem		= m_hDragNode;
	DropItems.strItem	= GetItemText(m_hDragNode);

	::memset(&DropItems.tvItem, 0, sizeof(TVITEM));
	DropItems.tvItem.mask		= TVIF_HANDLE | TVIF_IMAGE | TVIF_PARAM | TVIF_SELECTEDIMAGE | TVIF_STATE;
	DropItems.tvItem.hItem		= m_hDragNode;
	DropItems.tvItem.stateMask	= TVIS_BOLD | TVIS_CUT | TVIS_EXPANDED;

	GetItem(&DropItems.tvItem);

	// ���� ���� �׸��� ���´ٸ� ���� �׸�鿡 ���� ������ ���Ѵ�
	if(ItemHasChildren(m_hDragNode))
		FindDropTarget(&DropItems);

	// ���� �����ϴ� ���� �ƴ϶�� �巡�׵Ǵ� �׸��� �����Ѵ�
	if(!bCopy)	DeleteItem(m_hDragNode);
	// ���� �纻�� �����ؾ� �Ѵٸ� "�纻 - "�� �׸� �̸��� �����δ�
	if(bSabon)	DropItems.strItem.Insert(0, "�纻 - ");

	// ��� Ʈ�� ��Ʈ�ѿ� �׸���� �߰��Ѵ�
	AddDropItem(m_hDropNode, &DropItems);

	// ��ӵ� �׸��� Ȯ���Ѵ�
	m_pDropTree->Expand(m_hDropNode, TVE_EXPAND);
	// ��ӵ� �׸��� �����Ѵ�
	m_pDropTree->SelectItem(DropItems.hItem);
}

// ��ӵ� ���� �׸���� ������ ���ϴ� �Լ�
void CDDTreeCtrl::FindDropTarget(SDropItemInfo *pParent)
{
	// ���� �׸���� ���Ѵ�
	HTREEITEM hChild = GetChildItem(pParent->hItem);
	SDropItemInfo *pChild;

	// ��� ���� �׸�鿡 ���� �ݺ��Ѵ�
	for(; hChild != NULL; hChild = GetNextItem(hChild, TVGN_NEXT))
	{
		// ���� �׸��� ������ ���Ѵ�
		pChild = new SDropItemInfo;
		pChild->hItem	= hChild;
		pChild->strItem	= GetItemText(hChild);

		::memset(&pChild->tvItem, 0, sizeof(TVITEM));
		pChild->tvItem.mask			= TVIF_HANDLE | TVIF_IMAGE | TVIF_PARAM | TVIF_SELECTEDIMAGE | TVIF_STATE;
		pChild->tvItem.hItem		= hChild;
		pChild->tvItem.stateMask	= TVIS_BOLD | TVIS_CUT | TVIS_EXPANDED;

		GetItem(&pChild->tvItem);

		// ���� �׸� �迭�� �߰��Ѵ�
		pParent->Childs.Add(pChild);

		// ���� ���� �׸��� ���´ٸ� ���� �׸���� ������ ���Ѵ�
		if(ItemHasChildren(hChild))
			FindDropTarget(pChild);
	}
}

// ��� Ʈ�� ��Ʈ�ѿ� ���� �׸���� �߰��ϴ� �Լ�
void CDDTreeCtrl::AddDropItem(HTREEITEM hParent, SDropItemInfo *pNew)
{
	// ���� �θ� ��尡 ���ٸ� ��Ʈ ���� �����Ѵ�
	if(hParent == NULL)		hParent = TVI_ROOT;

	// ���ο� �׸��� �����Ѵ�
	pNew->hItem = m_pDropTree->InsertItem(pNew->strItem, pNew->tvItem.iImage, pNew->tvItem.iSelectedImage, hParent);
	// ������ �����Ѵ�
	pNew->tvItem.mask = TVIF_HANDLE | TVIF_PARAM | TVIF_STATE;
	m_pDropTree->SetItem(&pNew->tvItem);

	// ���� �׸���� �ִٸ�
	int i, nSize = (int)pNew->Childs.GetSize();
	for(i = 0; i < nSize; i++)
	{
		// ���� �׸���� Ʈ���� �߰��Ѵ�
		AddDropItem(pNew->hItem, pNew->Childs.GetAt(i));
	}
	// ���� �׸��� Ȯ��� ���¿��ٸ�
	if(pNew->tvItem.state & TVIS_EXPANDED)
		// �׸��� Ȯ���Ѵ�
		m_pDropTree->Expand(pNew->hItem, TVE_EXPAND);
}

void CDDTreeCtrl::OnTimer(UINT nIDEvent) 
{
	// ���� ���� �巡�� ���̶��
	if(m_bDragging && m_pDropTree && m_hDropNode)
	{
		// ��� �Ǵ� �׸��� �Ӽ��� ���Ѵ�
		UINT nState = m_pDropTree->GetItemState(m_hDropNode, TVIF_STATE);

		// ���� ���� �׸��� ���� �ְ� Ȯ����� �ʾҴٸ�
		if(!(nState & TVIS_EXPANDED) && m_pDropTree->ItemHasChildren(m_hDropNode))
			// ��� �׸��� Ȯ���Ѵ�
			m_pDropTree->Expand(m_hDropNode, TVE_EXPAND);
	}

	// ��� �׸� Ȯ�� Ÿ�̸Ӹ� �����Ѵ�
	KillTimer(CONST_EXPAND_TIMER_ID);
	
	CTreeCtrl::OnTimer(nIDEvent);
}

// ���� �׸� �̸��� �����Ǿ��ٸ�
void CDDTreeCtrl::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;

	// ���� �׸� �̸��� ���������� �ԷµǾ��ٸ�
	if(pTVDispInfo->item.pszText != NULL)
	{
		// ���ο� �̸��� �׸��� �̸����� �����Ѵ�
		pTVDispInfo->item.mask = TVIF_TEXT;
		SetItem(&pTVDispInfo->item);
	}

	*pResult = 0;
}
