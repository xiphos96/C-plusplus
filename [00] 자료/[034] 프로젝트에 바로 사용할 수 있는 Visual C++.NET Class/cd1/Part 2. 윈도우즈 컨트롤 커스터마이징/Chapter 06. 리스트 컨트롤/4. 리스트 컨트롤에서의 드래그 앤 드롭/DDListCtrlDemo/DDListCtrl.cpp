// DDListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ddlistctrldemo.h"
#include "DDListCtrl.h"

// CArray를 사용하기 위한 헤더 파일
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
	// 멤버 변수를 초기화한다
	m_bDragging		= FALSE;
	m_pDragImage	= NULL;
	m_pDropList		= NULL;
}

CDDListCtrl::~CDDListCtrl()
{
	// 만약 드래그 이미지가 존재하면 제거한다
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
	// 행 전체를 선택하는 확장 속성을 설정한다
	SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	CListCtrl::PreSubclassWindow();
}

// 드래그 이미지를 생성하는 함수
CImageList* CDDListCtrl::CreateDragImageEx(LPPOINT lpPoint)
{
	CRect rcTemp, rcSelected;
	// 클라이언트 영역을 얻는다
	GetClientRect(&rcTemp);

	// 클라이언트 영역의 폭을 저장한다
	int nWidth  = rcTemp.Width(), nItem;

	// 화면에 보이는 첫번째 행을 찾는다
	int nStart = GetTopIndex() - 1;
	// 시작 행 번호를 보정한다
	if(nStart < 0)					nStart = 0;

	// 화면에 보이는 마지막 행을 계산한다
	int nEnd = nStart + GetCountPerPage() + 1;
	// 마지막 행 번호를 보정한다
	if(nEnd >= GetItemCount())		nEnd = GetItemCount() - 1;

	// 선택된 전체 항목의 사각 영역을 초기화한다
	rcSelected.SetRectEmpty();
	// 선택된 항목을 찾는다
	POSITION pos = GetFirstSelectedItemPosition();
	for(; pos;)
	{
		// 선택된 항목 번호를 얻는다
		nItem = GetNextSelectedItem(pos);
		// 만약 화면에 보이지 않는 항목이면 건너뛴다
		if(nItem < nStart || nItem > nEnd)		continue;

		// 항목의 사각 영역을 얻는다
		GetItemRect(nItem, &rcTemp, LVIR_BOUNDS);

		// 항목의 폭을 클라이언트 영역 폭에 맞게 조정한다
		if(rcTemp.left < 0)				rcTemp.left = 0;
		if(rcTemp.Width() > nWidth)		rcTemp.right = rcTemp.left + nWidth;

		// 전체 선택 항목 사각 영역에 항목의 사각 영역을 추가한다
		rcSelected.UnionRect(rcSelected, rcTemp);
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

	// 선택된 항목을 찾는다
	pos = GetFirstSelectedItemPosition();
	for(; pos;)
	{
		// 선택된 항목 번호를 얻는다
		nItem = GetNextSelectedItem(pos);
		// 만약 화면에 보이지 않는 항목이면 건너뛴다
		if(nItem < nStart || nItem > nEnd)		continue;

		// 선택된 항목에 대한 드래그 이미지를 생성한다
		pItemImage = CreateDragImage(nItem, &pt);
		// 드래그 이미지가 정상적으로 생성되었다면
		if(pItemImage)
		{
			// 항목 사각 영역을 구한다
			GetItemRect(nItem, &rcTemp, LVIR_BOUNDS);

			// 드래그 이미지 시작 위치를 전체 선택 항목 사각 영역의 시작점에서의 상대 좌표로 변경한다
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
		// 전체 선택 항목 사각 영역의 시작점을 설정한다
		*lpPoint = rcSelected.TopLeft();
	}

	// 이미지 리스트를 리턴한다
	return pDragImage;
}

// 항목 드래그 시작 함수
void CDDListCtrl::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	*pResult = 0;

	// 만약 선택된 항목이 없다면 리턴
	if(GetSelectedCount() <= 0)			return;

	CPoint pt;
	// 드래그 이미지 리스트를 생성한다
	m_pDragImage	= CreateDragImageEx(&pt);
	// 변수들을 초기화한다
	m_bDragging		= TRUE;
	m_nDropIndex	= -1;
	m_pDropList		= NULL;

	// 현재 좌표에서 이미지 리스트의 시작 위치를 제한다
	pt.x = pNMListView->ptAction.x - pt.x;
	pt.y = pNMListView->ptAction.y - pt.y;

	// 드래그 이미지를 마우스 커서와 함께 출력한다
	m_pDragImage->BeginDrag(0, pt);
	m_pDragImage->DragEnter(NULL, pt);

	// 마우스 이벤트를 캡춰한다
	SetCapture ();
}

void CDDListCtrl::OnMouseMove(UINT nFlags, CPoint point) 
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

		// 만약 이전에 드래그 되었던 리스트 컨트롤이 있다면
		if(m_pDropList != NULL)
		{
			// 만약 드롭 하이라이트 되었던 항목이 있다면
			if(m_nDropIndex >= 0)
			{
				// 드롭 하이라이트 속성을 제거하여 다시 출력한다
				m_pDropList->SetItemState(m_nDropIndex, 0, LVIS_DROPHILITED);
				m_pDropList->RedrawItems(m_nDropIndex, m_nDropIndex);
				m_pDropList->UpdateWindow();
			}
			// 멤버 변수를 초기화한다
			m_nDropIndex = -1;
			m_pDropList = NULL;
		}

		// 만약 마우스가 위치한 곳의 윈도우가 리스트 컨트롤이면
		if(pDropWnd->IsKindOf(RUNTIME_CLASS(CListCtrl)))
		{
			// 마우스 커서를 화살표로 설정한다
			SetCursor(LoadCursor(NULL, IDC_ARROW));

			// 윈도우 포인터를 리스트 컨트롤 포인터로 바꾸어 멤버 변수에 저장한다
			m_pDropList = (CListCtrl*)pDropWnd;
			// 마우스 커서 좌표를 리스트 컨트롤의 클라이언트 좌표로 변경한다
			m_pDropList->ScreenToClient(&pt);

			// 마우스가 위치한 항목 번호를 얻는다
			m_nDropIndex = m_pDropList->HitTest(pt, NULL);

			// 만약 항목 번호가 얻어졌다면
			if(m_nDropIndex >= 0)
			{
				// 항목에 드롭 하이라이트 속성을 설정하고 다시 출력한다
				m_pDropList->SetItemState(m_nDropIndex, LVIS_DROPHILITED, LVIS_DROPHILITED);
				m_pDropList->RedrawItems(m_nDropIndex, m_nDropIndex);
				m_pDropList->UpdateWindow();
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
	
	CListCtrl::OnMouseMove(nFlags, point);
}

void CDDListCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// 만약 드래그 중이면
	if(m_bDragging)
	{
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

		// 만약 이전에 드래그 되었던 리스트 컨트롤이 있다면
		if(m_pDropList != NULL)
		{
			// 만약 드롭 하이라이트 되었던 항목이 있다면
			if(m_nDropIndex >= 0)
			{
				// 드롭 하이라이트 속성을 제거하여 다시 출력한다
				m_pDropList->SetItemState(m_nDropIndex, 0, LVIS_DROPHILITED);
				m_pDropList->RedrawItems(m_nDropIndex, m_nDropIndex);
				m_pDropList->UpdateWindow();
			}
		}

		// 만약 마우스가 위치한 곳의 윈도우가 리스트 컨트롤이면
		if(pDropWnd->IsKindOf(RUNTIME_CLASS(CListCtrl)))
		{
			// 윈도우 포인터를 리스트 컨트롤 포인터로 바꾸어 멤버 변수에 저장한다
			m_pDropList = (CListCtrl*)pDropWnd;

			// 마우스 커서 좌표를 리스트 컨트롤의 클라이언트 좌표로 변경한다
			m_pDropList->ScreenToClient(&pt);

			// 마우스가 위치한 항목 번호를 얻는다
			m_nDropIndex = m_pDropList->HitTest(pt, NULL);

			// 선택된 항목을 드롭 리스트 컨트롤로 옮긴다
			DropItems();
		}

		// 멤버 변수들을 초기화한다
		m_bDragging = FALSE;
		m_pDropList = NULL;
		m_nDropIndex = -1;
	}
	
	CListCtrl::OnLButtonUp(nFlags, point);
}

// 선택된 항목을 드롭 대상 리스트 컨트롤에 옮기는 함수
void CDDListCtrl::DropItems()
{
	// Ctrl키가 눌려진 상태인지 여부
	BOOL bCopy = ::GetKeyState(VK_CONTROL) & 0x8000;
	// 사본을 생성해야 하는지 여부
	BOOL bSabon = (bCopy && (m_hWnd == m_pDropList->m_hWnd));

	CArray<SDropItemInfo*, SDropItemInfo*> DropItems;
	SDropItemInfo *pItem;

	// 선택된 항목을 찾는다
	POSITION pos = GetFirstSelectedItemPosition();
	for(; pos;)
	{
		// 선택된 항목 구조체 객체를 생성한다
		pItem = new SDropItemInfo;

		// 선택된 항목 번호를 저장한다
		pItem->nItem = GetNextSelectedItem(pos);
		// 선택된 항목 텍스트를 저장한다
		pItem->strItem = GetItemText(pItem->nItem, 0);

		// 선택된 항목의 속성들을 저장한다
		::memset(&pItem->lvItem, 0, sizeof(LVITEM));
		pItem->lvItem.mask		= LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
		pItem->lvItem.iItem		= pItem->nItem;
		pItem->lvItem.iSubItem	= 0;
		pItem->lvItem.stateMask = LVIS_CUT | LVIS_DROPHILITED | LVIS_FOCUSED | LVIS_SELECTED | LVIS_OVERLAYMASK | LVIS_STATEIMAGEMASK;
		GetItem(&pItem->lvItem);

		// 드롭 항목 배열에 추가한다
		DropItems.Add(pItem);
	}

	int nItem;
	// 만약 복사하기가 아니면 선택된 항목을 찾는다
	pos = GetFirstSelectedItemPosition();
	for(; pos && !bCopy; )
	{
		// 선택된 항목 번호를 얻는다
		nItem = GetNextSelectedItem(pos);

		// 만약 현재 리스트 컨트롤에서 드래그하고 드롭했다면
		if(this->m_hWnd == m_pDropList->m_hWnd)
			// 만약 드롭된 위치가 드래그한 위치보다 뒤에 있다면 위치를 보정한다
			if(nItem < m_nDropIndex)		m_nDropIndex--;

		// 드래그된 항목을 삭제한다
		DeleteItem(nItem);

		// 또다른 선택된 항목을 찾는다
		pos = GetFirstSelectedItemPosition();
	}

	// 드롭 리스트 컨트롤에서 선택된 항목을 찾는다
	pos = m_pDropList->GetFirstSelectedItemPosition();
	for(; pos; )
	{
		// 항목의 번호를 얻는다
		nItem = m_pDropList->GetNextSelectedItem(pos);

		// 선택된 상태를 해제한다
		m_pDropList->SetItemState(nItem, 0, LVIS_SELECTED);

		// 또 다른 선택된 항목을 찾는다
		pos = m_pDropList->GetFirstSelectedItemPosition();
	}

	// 드롭 항목 배열의 크기를 얻는다
	int nSize = (int)DropItems.GetSize(), nPos;
	for(nItem = nSize - 1; nItem >= 0; nItem--)
	{
		// 드롭 항목을 얻는다
		pItem = DropItems.GetAt(nItem);
		// 만약 드롭 위치가 없다면
		if(m_nDropIndex < 0)
			// 리스트 컨트롤의 제일 뒤 위치를 설정한다
			nPos = m_pDropList->GetItemCount();
		else
			// 드롭 위치를 설정한다
			nPos = m_nDropIndex;

		// 만약 사본을 생성하는 것이면
		if(bSabon)		pItem->strItem.Insert(0, "사본 - ");

		// 드롭 위치에 항목을 추가한다
		nPos = m_pDropList->InsertItem(nPos, pItem->strItem);
		// 추가된 항목의 속성을 설정한다
		pItem->lvItem.iItem = nPos;
		m_pDropList->SetItem(&pItem->lvItem);
		// 추가된 항목을 선택 상태로 만든다
		m_pDropList->SetItemState(nPos, LVIS_SELECTED, LVIS_SELECTED);

		// 항목을 제거한다
		delete pItem;
	}

	// 배열을 초기화한다
	DropItems.RemoveAll();
}
