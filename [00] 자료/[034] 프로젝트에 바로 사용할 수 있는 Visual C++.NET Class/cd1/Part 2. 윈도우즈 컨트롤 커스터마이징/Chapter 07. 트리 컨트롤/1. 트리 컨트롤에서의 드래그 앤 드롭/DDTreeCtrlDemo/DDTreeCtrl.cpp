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

// 드롭시 대상 노드를 확장하는 타이머 ID
#define CONST_EXPAND_TIMER_ID			1

CDDTreeCtrl::CDDTreeCtrl()
{
	// 멤버 변수를 초기화한다
	m_bDragging		= FALSE;
	m_pDragImage	= NULL;
	m_pDropTree		= NULL;

	m_hDragCursor	= AfxGetApp()->LoadCursor(IDC_DRAG_CURSOR);
}

CDDTreeCtrl::~CDDTreeCtrl()
{
	// 만약 드래그 이미지가 존재하면 제거한다
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

// 이미지 영역까지 고려한 항목 사각 영역 획득 함수
void CDDTreeCtrl::GetItemRect(HTREEITEM hItem, LPRECT lpRect)
{
	// 텍스트 영역을 구한다
	CTreeCtrl::GetItemRect(hItem, lpRect, TRUE);

	// 이미지 리스트가 설정되어 있는지 확인한다
	CImageList *pImageList = GetImageList(TVSIL_NORMAL);
	if(pImageList == NULL)					return;
	if(pImageList->GetImageCount() <= 0)	return;

	// 이미지 리스트의 이미지 폭을 구한다
	IMAGEINFO info;
	pImageList->GetImageInfo(0, &info);

	// 이미지 폭을 항목 폭에 더한다
	lpRect->right += info.rcImage.right - info.rcImage.left;
}

// 드래그 이미지를 생성하는 함수
CImageList* CDDTreeCtrl::CreateDragImageEx(LPPOINT lpPoint)
{
	CRect rcClient, rcSelected, rcTemp;
	// 클라이언트 영역을 얻는다
	GetClientRect(&rcClient);

	// 드래그될 항목의 영역을 구한다
	CArray<HTREEITEM, HTREEITEM> ItemArray;
	HTREEITEM hSelected = m_hDragNode;
	GetItemRect(hSelected, &rcSelected);

	// 드래그 대상 배열에 추가한다
	ItemArray.Add(hSelected);

	// 드래그 항목이 하위 항목을 갖고 있고 확장 되어 있을 경우
	UINT nState = GetItemState(hSelected, TVIF_STATE);
	if(ItemHasChildren(hSelected) && (nState & TVIS_EXPANDED))
	{
		// 하위 항목의 영역도 구한다
		CreateDragImageLoop(hSelected, rcClient, rcSelected, ItemArray);
	}

	// 메모리 DC를 생성한다
	CDC *pDC = GetDC();
	CDC MemDC;

	MemDC.CreateCompatibleDC(pDC);

	// 전체 선택 항목 사각 영역만큼 비트맵을 생성한다
	CBitmap bmp, *pOldBmp;
	bmp.CreateCompatibleBitmap(pDC, rcSelected.Width(), rcSelected.Height());
	// 메모리 DC에 비트맵을 설정한다
	pOldBmp = MemDC.SelectObject(&bmp);

	// 메모리 DC의 배경을 투명색(흰색)으로 칠한다
	MemDC.FillSolidRect(0, 0, rcSelected.Width(), rcSelected.Height(), RGB(255, 255, 255));

	CPoint pt;
	CImageList *pItemImage;

	// 하위 항목의 갯수만큼 반복한다
	int i, nSize = (int)ItemArray.GetSize();
	for(i = 0; i < nSize; i++)
	{
		// 하위 항목의 핸들을 얻는다
		hSelected = ItemArray.GetAt(i);

		// 드래그될 항목에 대한 드래그 이미지를 생성한다
		pItemImage = CreateDragImage(hSelected);
		// 드래그 이미지가 정상적으로 생성되었다면
		if(pItemImage)
		{
			// 항목 사각 영역을 구한다
			GetItemRect(hSelected, &rcTemp);

			// 드래그 이미지 시작 위치를 전체 선택 항목 사각 영역의 시작점에서의 상대 좌표로 변경한다
			pt = rcTemp.TopLeft();
			pt.Offset(-rcSelected.left, -rcSelected.top);

			// 메모리 DC에 드래그 이미지를 출력한다
			pItemImage->Draw(&MemDC, 0, pt, ILD_NORMAL);

			// 드래그 이미지를 삭제한다
			pItemImage->DeleteImageList();
			delete pItemImage;
		}
	}

	// 메모리 DC의 비트맵을 반환한다
	MemDC.SelectObject(pOldBmp);
	// 메모리 DC를 제거한다
	MemDC.DeleteDC();
	ReleaseDC(pDC);

	// 이미지 리스트를 생성한다
	CImageList *pDragImage = new CImageList;
	// 전체 선택 항목 사각 영역 크기로 생성한다
	pDragImage->Create(rcSelected.Width(), rcSelected.Height(), ILC_COLOR | ILC_MASK, 0, 1);
	// 항목 이미지들을 그린 비트맵을 이미지 리스트에 설정하고, 투명색을 설정한다
	pDragImage->Add(&bmp, RGB(255, 255, 255));

	// 비트맵을 제거한다
	bmp.DeleteObject();

	// 인자로 좌표 포인터가 넘겨졌으면
	if(lpPoint)
	{
		// 드래그 항목 영역의 시작점을 설정한다
		*lpPoint = rcSelected.TopLeft();
	}

	// 이미지 리스트를 리턴한다
	return pDragImage;
}

// 드래그되는 하위 항목을 찾는 함수
void CDDTreeCtrl::CreateDragImageLoop(HTREEITEM hParent, CRect &rcClient, CRect &rcSelected,
	CArray<HTREEITEM, HTREEITEM> &ItemArray)
{
	// 하위 항목 핸들을 구한다
	HTREEITEM hChild = GetChildItem(hParent);
	CRect rcItem;
	UINT nState;

	// 모든 하위 항목에 대해 반복한다
	for(; hChild;)
	{
		// 하위 항목의 사각 영역을 구한다
		GetItemRect(hChild, &rcItem);
		// 현재 보이는 항목일 경우
		if(rcClient.left < rcItem.right && rcClient.right > rcItem.left
			&& rcClient.top < rcItem.bottom && rcClient.bottom > rcItem.top)
		{
			// 드래그 이미지 생성 대상으로 추가한다
			ItemArray.Add(hChild);
			// 항목 사각 영역을 전체 선택 사각 영역에 추가한다
			rcSelected.UnionRect(rcItem, rcSelected);

			// 만약 하위 항목을 갖고 있고 확장되어 있다면
			nState = GetItemState(hChild, TVIF_STATE);
			if(ItemHasChildren(hChild) && (nState & TVIS_EXPANDED))
			{
				// 하위 항목의 영역을 구한다
				CreateDragImageLoop(hChild, rcClient, rcSelected, ItemArray);
			}
		}

		// 다음 하위 항목을 찾는다
		hChild = GetNextItem(hChild, TVGN_NEXT);
	}
}

void CDDTreeCtrl::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	*pResult = 0;

	// 만약 선택된 항목이 없다면 리턴
	m_hDragNode = pNMTreeView->itemNew.hItem;
	if(m_hDragNode == NULL)			return;

	CPoint pt;
	// 드래그 이미지 리스트를 생성한다
	m_pDragImage	= CreateDragImageEx(&pt);
	// 변수들을 초기화한다
	m_bDragging		= TRUE;
	m_hDropNode		= NULL;
	m_pDropTree		= NULL;

	// 현재 좌표에서 이미지 리스트의 시작 위치를 제한다
	pt.x = pNMTreeView->ptDrag.x - pt.x;
	pt.y = pNMTreeView->ptDrag.y - pt.y;

	// 드래그 이미지를 마우스 커서와 함께 출력한다
	m_pDragImage->BeginDrag(0, pt);
	m_pDragImage->DragEnter(NULL, pt);

	// 마우스 이벤트를 캡춰한다
	SetCapture();
}

void CDDTreeCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 만약 드래그 중이면
	if(m_bDragging)
	{
		// 현재 좌표를 스크린 좌표로 바꾼다
		CPoint pt = point;
		ClientToScreen(&pt);
		// 드래그 이미지의 위치를 변경한다
		m_pDragImage->DragMove(pt);
		// 드래그 이미지를 감춘다
		m_pDragImage->DragShowNolock(FALSE);

		// 마우스 좌표의 윈도우 포인터를 얻는다
		CWnd* pDropWnd = WindowFromPoint(pt);

		// 만약 이전에 드래그 되었던 트리 컨트롤이 있다면
		if(m_pDropTree != NULL)
		{
			// 만약 드롭 하이라이트 되었던 항목이 있다면
			if(m_hDropNode != NULL)
			{
				// 드롭 하이라이트 속성을 제거하여 다시 출력한다
				m_pDropTree->SetItemState(m_hDropNode, 0, TVIS_DROPHILITED);
				m_pDropTree->UpdateWindow();
			}
			// 멤버 변수를 초기화한다
			m_hDropNode = NULL;
			m_pDropTree = NULL;
		}

		// 만약 마우스가 위치한 곳의 윈도우가 트리 컨트롤이면
		if(pDropWnd->IsKindOf(RUNTIME_CLASS(CTreeCtrl)))
		{
			// 마우스 커서를 드래그 커서로 설정한다
			SetCursor(m_hDragCursor);

			// 윈도우 포인터를 트리 컨트롤 포인터로 바꾸어 멤버 변수에 저장한다
			m_pDropTree = (CTreeCtrl*)pDropWnd;
			// 마우스 커서 좌표를 트리 컨트롤의 클라이언트 좌표로 변경한다
			m_pDropTree->ScreenToClient(&pt);

			// 마우스가 위치한 항목 핸들을 구한다
			m_hDropNode = m_pDropTree->HitTest(pt, NULL);

			// 만약 항목 핸들이 구해졌다면
			if(m_hDropNode != NULL)
			{
				// 항목에 드롭 하이라이트 속성을 설정하고 다시 출력한다
				m_pDropTree->SetItemState(m_hDropNode, TVIS_DROPHILITED, TVIS_DROPHILITED);
				m_pDropTree->UpdateWindow();

				// 드롭 항목 확장 타이머를 시작한다
				SetTimer(CONST_EXPAND_TIMER_ID, 1000, NULL);
			}
		}
		else
		{
			// 마우스 커서를 금지 표시로 바꾼다
			SetCursor(LoadCursor(NULL, IDC_NO));
		}

		// 드래그 이미지를 다시 출력한다
		m_pDragImage->DragShowNolock(TRUE);
	}
	
	CTreeCtrl::OnMouseMove(nFlags, point);
}

void CDDTreeCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// 만약 드래그 중이면
	if(m_bDragging)
	{
		// 드롭 항목 확장 타이머를 중지한다
		KillTimer(CONST_EXPAND_TIMER_ID);

		// 마우스 이벤트 캡춰를 중지한다
		ReleaseCapture();

		// 드래그 이미지 출력을 종료한다
		m_pDragImage->EndDrag();
		// 드래그 이미지 리스트를 제거한다
		m_pDragImage->DeleteImageList();
		delete m_pDragImage;
		m_pDragImage = NULL;

		// 현재 좌표를 스크린 좌표로 바꾼다
		CPoint pt = point;
		ClientToScreen(&pt);

		// 마우스 좌표의 윈도우 포인터를 얻는다
		CWnd* pDropWnd = WindowFromPoint(pt);

		// 만약 이전에 드래그 되었던 트리 컨트롤이 있다면
		if(m_pDropTree != NULL)
		{
			// 만약 드롭 하이라이트 되었던 항목이 있다면
			if(m_hDropNode != NULL)
			{
				// 드롭 하이라이트 속성을 제거하여 다시 출력한다
				m_pDropTree->SetItemState(m_hDropNode, 0, TVIS_DROPHILITED);
				m_pDropTree->UpdateWindow();
			}
		}

		// 만약 마우스가 위치한 곳의 윈도우가 트리 컨트롤이면
		if(pDropWnd->IsKindOf(RUNTIME_CLASS(CTreeCtrl)))
		{
			// 윈도우 포인터를 트리 컨트롤 포인터로 바꾸어 멤버 변수에 저장한다
			m_pDropTree = (CTreeCtrl*)pDropWnd;
			// 마우스 커서 좌표를 트리 컨트롤의 클라이언트 좌표로 변경한다
			m_pDropTree->ScreenToClient(&pt);

			// 마우스가 위치한 항목 핸들을 구한다
			m_hDropNode = m_pDropTree->HitTest(pt, NULL);

			// 선택된 항목을 드롭 트리 컨트롤로 옮긴다
			DropItems();
		}

		// 멤버 변수들을 초기화한다
		m_bDragging = FALSE;
		m_pDropTree = NULL;
		m_hDragNode = NULL;
		m_hDropNode = NULL;
	}
	
	CTreeCtrl::OnLButtonUp(nFlags, point);
}

// 선택된 항목을 드롭 대상 트리 컨트롤에 옮기는 함수
void CDDTreeCtrl::DropItems()
{
	// 컨트롤키가 눌려졌는지 여부
	BOOL bCopy = ::GetKeyState(VK_CONTROL) & 0x8000, bSabon = FALSE;

	// 만약 드래그한 트리 컨트롤과 드롭되는 트리 컨트롤이 동일하다면
	if(m_hWnd == m_pDropTree->m_hWnd)
	{
		// 만약 동일한 위치로 드롭된다면
		if(GetParentItem(m_hDragNode) == m_hDropNode)
		{
			// 만약 복사하는 것이 아니라면
			if(!bCopy)
			{
				// 동일한 위치이므로 리턴
				MessageBox("원본 항목과 대상 항목의 위치가 같아 드롭할 수 없습니다.");
				return;
			}
			// 복사하는 것이라면 사본으로 생성한다
			bSabon = TRUE;
		}

		// 드래그하는 항목 내부로 드롭되었는지 확인한다
		HTREEITEM hParent = m_hDropNode;

		for(; hParent != NULL;)
		{
			if(hParent == m_hDragNode)
			{
				MessageBox("드래그 항목에 포함된 노드에는 드롭할 수 없습니다.");
				return;
			}

			hParent = GetParentItem(hParent);
		}
	}

	SDropItemInfo DropItems;

	// 드래그하는 항목에 대한 정보를 얻는다
	DropItems.hItem		= m_hDragNode;
	DropItems.strItem	= GetItemText(m_hDragNode);

	::memset(&DropItems.tvItem, 0, sizeof(TVITEM));
	DropItems.tvItem.mask		= TVIF_HANDLE | TVIF_IMAGE | TVIF_PARAM | TVIF_SELECTEDIMAGE | TVIF_STATE;
	DropItems.tvItem.hItem		= m_hDragNode;
	DropItems.tvItem.stateMask	= TVIS_BOLD | TVIS_CUT | TVIS_EXPANDED;

	GetItem(&DropItems.tvItem);

	// 만약 하위 항목을 갖는다면 하위 항목들에 대한 정보를 구한다
	if(ItemHasChildren(m_hDragNode))
		FindDropTarget(&DropItems);

	// 만약 복사하는 것이 아니라면 드래그되는 항목을 삭제한다
	if(!bCopy)	DeleteItem(m_hDragNode);
	// 만약 사본을 생성해야 한다면 "사본 - "을 항목 이름에 덧붙인다
	if(bSabon)	DropItems.strItem.Insert(0, "사본 - ");

	// 드롭 트리 컨트롤에 항목들을 추가한다
	AddDropItem(m_hDropNode, &DropItems);

	// 드롭된 항목을 확장한다
	m_pDropTree->Expand(m_hDropNode, TVE_EXPAND);
	// 드롭된 항목을 선택한다
	m_pDropTree->SelectItem(DropItems.hItem);
}

// 드롭될 하위 항목들의 정보를 구하는 함수
void CDDTreeCtrl::FindDropTarget(SDropItemInfo *pParent)
{
	// 하위 항목들을 구한다
	HTREEITEM hChild = GetChildItem(pParent->hItem);
	SDropItemInfo *pChild;

	// 모든 하위 항목들에 대해 반복한다
	for(; hChild != NULL; hChild = GetNextItem(hChild, TVGN_NEXT))
	{
		// 하위 항목의 정보를 구한다
		pChild = new SDropItemInfo;
		pChild->hItem	= hChild;
		pChild->strItem	= GetItemText(hChild);

		::memset(&pChild->tvItem, 0, sizeof(TVITEM));
		pChild->tvItem.mask			= TVIF_HANDLE | TVIF_IMAGE | TVIF_PARAM | TVIF_SELECTEDIMAGE | TVIF_STATE;
		pChild->tvItem.hItem		= hChild;
		pChild->tvItem.stateMask	= TVIS_BOLD | TVIS_CUT | TVIS_EXPANDED;

		GetItem(&pChild->tvItem);

		// 하위 항목 배열에 추가한다
		pParent->Childs.Add(pChild);

		// 만약 하위 항모을 갖는다면 하위 항목들을 정보를 구한다
		if(ItemHasChildren(hChild))
			FindDropTarget(pChild);
	}
}

// 드롭 트리 컨트롤에 하위 항목들을 추가하는 함수
void CDDTreeCtrl::AddDropItem(HTREEITEM hParent, SDropItemInfo *pNew)
{
	// 만약 부모 노드가 없다면 루트 노드로 생성한다
	if(hParent == NULL)		hParent = TVI_ROOT;

	// 새로운 항목을 생성한다
	pNew->hItem = m_pDropTree->InsertItem(pNew->strItem, pNew->tvItem.iImage, pNew->tvItem.iSelectedImage, hParent);
	// 정보를 설정한다
	pNew->tvItem.mask = TVIF_HANDLE | TVIF_PARAM | TVIF_STATE;
	m_pDropTree->SetItem(&pNew->tvItem);

	// 하위 항목들이 있다면
	int i, nSize = (int)pNew->Childs.GetSize();
	for(i = 0; i < nSize; i++)
	{
		// 하위 항목들을 트리에 추가한다
		AddDropItem(pNew->hItem, pNew->Childs.GetAt(i));
	}
	// 만약 항목이 확장된 상태였다면
	if(pNew->tvItem.state & TVIS_EXPANDED)
		// 항목을 확장한다
		m_pDropTree->Expand(pNew->hItem, TVE_EXPAND);
}

void CDDTreeCtrl::OnTimer(UINT nIDEvent) 
{
	// 만약 현재 드래그 중이라면
	if(m_bDragging && m_pDropTree && m_hDropNode)
	{
		// 드롭 되는 항목의 속성을 구한다
		UINT nState = m_pDropTree->GetItemState(m_hDropNode, TVIF_STATE);

		// 만약 하위 항목을 갖고 있고 확장되지 않았다면
		if(!(nState & TVIS_EXPANDED) && m_pDropTree->ItemHasChildren(m_hDropNode))
			// 드롭 항목을 확장한다
			m_pDropTree->Expand(m_hDropNode, TVE_EXPAND);
	}

	// 드롭 항목 확장 타이머를 중지한다
	KillTimer(CONST_EXPAND_TIMER_ID);
	
	CTreeCtrl::OnTimer(nIDEvent);
}

// 만약 항목 이름이 편집되었다면
void CDDTreeCtrl::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;

	// 만약 항목 이름이 정상적으로 입력되었다면
	if(pTVDispInfo->item.pszText != NULL)
	{
		// 새로운 이름을 항목의 이름으로 설정한다
		pTVDispInfo->item.mask = TVIF_TEXT;
		SetItem(&pTVDispInfo->item);
	}

	*pResult = 0;
}
