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
	// 정렬 관련 변수 초기화
	m_nSortColumn		= -1;
	m_bSortAscending	= FALSE;
}

CFlatListCtrl::~CFlatListCtrl()
{
	// 이미지 리스트가 생성된 상태라면 소멸 시킨다
	if(m_ImageList.m_hImageList)
		m_ImageList.DeleteImageList();
}


BEGIN_MESSAGE_MAP(CFlatListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CFlatListCtrl)
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	//}}AFX_MSG_MAP
	// 반드시 아래와 같이 타입에 따른 핸들러를 지정해야 한다
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnNeedText)
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnNeedText)
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

	// 윈도우가 갖고 있는 툴팁 기능을 활성화 한다
	EnableToolTips();
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

BOOL CFlatListCtrl::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	LPNMHEADER pNMHD = (LPNMHEADER)lParam;

	switch(pNMHD->hdr.code)
	{
	case HDN_ITEMCHANGEDA:
	case HDN_ITEMCHANGEDW:
		// 만약 항목에 변화가 생기면 헤더 컨트롤의 툴팁 영역을 다시 계산한다
		m_wndHeaderCtrl.RecalcToolRect();
		break;
	}
	
	return CListCtrl::OnNotify(wParam, lParam, pResult);
}

// 컬럼 추가 처리 함수
int CFlatListCtrl::InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat, int nWidth, int nSubItem)
{
	// 리스트 컨트롤의 기본 컬럼 추가 루틴을 실행한다
	int nIndex = CListCtrl::InsertColumn(nCol, lpszColumnHeading, nFormat, nWidth, nSubItem);

	// 만약 리포트 형식이고 컬럼이 정상적으로 추가되었다면
	if(nIndex >= 0 && (GetStyle() & LVS_TYPEMASK) == LVS_REPORT)
	{
		// 헤더 컨트롤의 해당 컬럼에 툴팁을 추가한다
		if(!m_wndHeaderCtrl.AddTool(nIndex, lpszColumnHeading))	return -1;
	}

	return nIndex;
}

// 항목 추가 처리 함수
int CFlatListCtrl::InsertItem(const LVITEM* pItem)
{
	// 새로운 항목을 추가한다
	int nNewItem = CListCtrl::InsertItem(pItem);

	// 만약 정렬 컬럼이 지정되어 있다면 정렬한다
	// 새로 추가된 항목의 번호가 변경될 경우 그 값을 받는다
	if(m_nSortColumn >= 0)		Sort(&nNewItem);

	// 추가된 항목의 번호를 리턴한다
	return nNewItem;
}

// 항목 추가 처리 함수
int CFlatListCtrl::InsertItem(int nItem, LPCTSTR lpszItem)
{
	// 새로운 항목을 추가한다
	int nNewItem = CListCtrl::InsertItem(nItem, lpszItem);

	// 만약 정렬 컬럼이 지정되어 있다면 정렬한다
	// 새로 추가된 항목의 번호가 변경될 경우 그 값을 받는다
	if(m_nSortColumn >= 0)		Sort(&nNewItem);

	// 추가된 항목의 번호를 리턴한다
	return nNewItem;
}

// 항목 추가 처리 함수
int CFlatListCtrl::InsertItem(int nItem, LPCTSTR lpszItem, int nImage)
{
	// 새로운 항목을 추가한다
	int nNewItem = CListCtrl::InsertItem(nItem, lpszItem, nImage);

	// 만약 정렬 컬럼이 지정되어 있다면 정렬한다
	// 새로 추가된 항목의 번호가 변경될 경우 그 값을 받는다
	if(m_nSortColumn >= 0)		Sort(&nNewItem);

	// 추가된 항목의 번호를 리턴한다
	return nNewItem;
}

// 항목 추가 처리 함수
int CFlatListCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, UINT nState, UINT nStateMask, int nImage, LPARAM lParam)
{
	// 새로운 항목을 추가한다
	int nNewItem = CListCtrl::InsertItem(nMask, nItem, lpszItem, nState, nStateMask, nImage, lParam);

	// 만약 정렬 컬럼이 지정되어 있다면 정렬한다
	// 새로 추가된 항목의 번호가 변경될 경우 그 값을 받는다
	if(m_nSortColumn >= 0)		Sort(&nNewItem);

	// 추가된 항목의 번호를 리턴한다
	return nNewItem;
}

// EnableToolTips()에 의한 툴팁 출력 여부 요청 함수
int CFlatListCtrl::OnToolHitTest(CPoint point, TOOLINFO * pTI) const
{
	// 클라이언트 영역을 구한다
	CRect rcTemp;
	GetClientRect(&rcTemp);

	// 만약 클라이언트 영역 안에 있지 않다면 리턴
	if(!rcTemp.PtInRect(point))			return -1;
	// 만약 항목이 없다면 리턴
	if(GetItemCount() == 0)				return -1;

	// 첫번째 보이는 항목의 번호를 얻는다
	int nTop	= GetTopIndex();
	// 한 페이지에 보이는 항목의 갯수를 얻어 마지막 항목의 번호를 계산한다
	int nBottom = nTop + GetCountPerPage(), i;

	// 마지막 항목의 번호가 항목 범위를 초과한다면 조정한다
	if(nBottom >= GetItemCount())	nBottom = GetItemCount() - 1;

	// 화면에 보이는 항목들에 대해 툴팁 여부를 조사한다
	for(i = nTop; i <= nBottom; i++)
	{
		// 항목의 영역을 구한다
		GetItemRect(i, rcTemp, LVIR_BOUNDS);

		// 항목의 영역에 속한다면
		if(rcTemp.PtInRect(point))
		{
			// 툴팁 출력을 위한 속성을 설정한다
			pTI->hwnd		= m_hWnd;
			pTI->uId		= (UINT)(i + 1);
			// TTN_NEEDTEXT 알림 메시지를 받도록 LPSTR_TEXTCALLBACK을 설정한다
			pTI->lpszText	= LPSTR_TEXTCALLBACK;
			pTI->rect		= rcTemp;

			// 툴팁 ID를 리턴한다
			return pTI->uId;
		}
	}

	return -1;
}

// 툴팁 텍스트를 얻기 위해 호출되는 함수
BOOL CFlatListCtrl::OnNeedText(UINT id, NMHDR* pNMHDR, LRESULT* pResult)
{
	// ASCII 코드와 UNICODE에 대해 모두 처리한다
	TOOLTIPTEXTA* pTipAscii = (TOOLTIPTEXTA*)pNMHDR;
	TOOLTIPTEXTW* pTipUnicode = (TOOLTIPTEXTW*)pNMHDR;

	// 툴팁 ID를 얻는다
	UINT nID = pNMHDR->idFrom;

	// 만약 ID가 없다면 리턴
	if(nID == 0)		return FALSE;

	// 툴팁 ID에서 항목 번호를 얻는다
	int nItem = nID - 1;

	// 해당 항목에 대한 툴팁 텍스트를 구성한다
	CString strTipText;
	strTipText.Format("[%s] - [%s] : [%s]",
		GetItemText(nItem, 0),
		GetItemText(nItem, 1),
		GetItemText(nItem, 2));

	// 만약 아스키 코드라면
	if(pNMHDR->code == TTN_NEEDTEXTA)
	{
		// 툴팁 텍스트를 아스키코드 툴팁 구조체에 설정한다
		pTipAscii->lpszText = LPSTR(LPCTSTR(strTipText));
	}
	else
	{
		// 툴팁 텍스트를 유니코드 툴팁 구조체에 설정한다
		pTipUnicode->lpszText = (WCHAR*)strTipText.AllocSysString();
	}

	*pResult = 0;

	return TRUE;
}

// 헤더 컨트롤의 컬럼에 대한 클릭 이벤트 핸들러
void CFlatListCtrl::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	// 클릭된 컬럼의 번호를 얻는다
	int nID = pNMListView->iSubItem;

	// 만약 현재 지정된 정렬 컬럼이라면
	if(pNMListView->iSubItem == m_nSortColumn)
		// 정렬 방향을 반대로 바꿔서 정렬한다
		Sort(pNMListView->iSubItem, !m_bSortAscending);
	else
		// 새로운 컬럼을 기준으로 오름차순 정렬한다
		Sort(pNMListView->iSubItem, TRUE);

	*pResult = 0;
}

// 정렬 함수
void CFlatListCtrl::Sort(int *pNew)
{
	// 현재 설정된 조건으로 정렬한다
	Sort(m_nSortColumn, m_bSortAscending, pNew);
}

// 정렬 함수
void CFlatListCtrl::Sort(int nCol, BOOL bAscending, int *pNew)
{
	// 새로운 컬럼과 방향을 저장한다
	m_nSortColumn		= nCol;
	m_bSortAscending	= bAscending;

	// 헤더 컨트롤을 다시 그린다
	m_wndHeaderCtrl.SetSortColumn(nCol, bAscending);

	// 퀵 정렬을 실행한다
	QuickSort(0, GetItemCount() - 1, pNew);
}

// 퀵정렬 함수
void CFlatListCtrl::QuickSort(int nStart, int nEnd, int *pNew)
{
	// 만약 시작 번호가 끝 번호보다 작지 않다면 리턴
	if(nStart >= nEnd)		return;

	// 첫 항목을 기준으로 큰 값과 작은 값을 구별하여 두 부분으로 나눈다
	int nHalf = Partition(nStart, nEnd, pNew);

	// 기준에 대한 앞쪽 부분에 대해 다시 퀵 정렬을 실행한다
	QuickSort(nStart, nHalf - 1, pNew);
	// 기준에 대한 뒤쪽 부분에 대해 다시 퀵 정렬을 실행한다
	QuickSort(nHalf + 1, nEnd, pNew);
}

// 기준 값을 중심으로 큰 값과 작은 값으로 나누는 함수
int CFlatListCtrl::Partition(int nStart, int nEnd, int *pNew)
{
	BOOL bContinue;
	CString strItem;
	// 첫 항목을 기준으로 삼아, 텍스트와 항목 번호를 저장한다
	CString strBase = GetItemText(nStart, m_nSortColumn);
	int nBase = nStart;
	int nMax = ++nEnd;

	// 시작 번호가 끝 번호보다 작은 동안 실행한다
	for(; nStart < nEnd;)
	{
		// 기준 바로 뒤부터
		// 오름차순정렬시 기준 값보다 큰 항목을 찾는다
		// 내림차순정렬시 기준 값보다 작은 항목을 찾는다
		for(bContinue = TRUE; bContinue && nStart < nMax - 1;)
		{
			nStart++;
			strItem = GetItemText(nStart, m_nSortColumn);

			if(m_bSortAscending)
				bContinue = strBase.CompareNoCase(strItem) > 0;
			else
				bContinue = strBase.CompareNoCase(strItem) < 0;
		}
		// 끝 번호부터
		// 오름차순정렬시 기준 값보다 작은 항목을 찾는다
		// 내림차순정렬시 기준 값보다 큰 항목을 찾는다
		for(bContinue = TRUE; bContinue;)
		{
			nEnd--;
			strItem = GetItemText(nEnd, m_nSortColumn);

			if(m_bSortAscending)
				bContinue = strBase.CompareNoCase(strItem) < 0;
			else
				bContinue = strBase.CompareNoCase(strItem) > 0;
		}

		// 큰 항목과 작은 항목을 찾았고 시작 번호가 끝 번호보다 작으면
		if(nStart < nEnd)
		{
			// 큰 항목과 작은 항목의 위치를 바꾼다
			Swap(nStart, nEnd);
			// 바뀐 항목 중 새로 추가된 항목이 있다면 새로운 번호를 저장한다
			if(pNew)
			{
				if(*pNew == nStart)		*pNew = nEnd;
				else
					if(*pNew == nEnd)	*pNew = nStart;
			}
		}
		else
		{
			// 기준 값과 끝에서 앞으로 이동하던 항목의 위치를 바꾼다
			Swap(nBase, nEnd);
			// 바뀐 항목 중 새로 추가된 항목이 있다면 새로운 번호를 저장한다
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

// 두 항목을 맞 바꾸는 함수
void CFlatListCtrl::Swap(int nItem1, int nItem2)
{
	// 바꿀 두 항목의 번호가 같다면 리턴
	if(nItem1 == nItem2)			return;

	// 컬럼 갯수를 얻는다
	int nColSize = m_wndHeaderCtrl.GetItemCount(), i;

	LVITEM Item1, Item2;
	CString strItem1, strItem2;

	// 모든 컬럼에 대해 수행한다
	for(i = 0; i < nColSize; i++)
	{
		// 두 항목의 텍스트를 읽는다
		strItem1 = GetItemText(nItem1, i);
		strItem2 = GetItemText(nItem2, i);

		// 두 항목의 속성을 읽는다
		Item1.mask	= LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
		Item1.iItem = nItem1;
		Item1.iSubItem = i;
		Item1.stateMask = LVIS_CUT | LVIS_DROPHILITED |	LVIS_FOCUSED | LVIS_SELECTED | LVIS_OVERLAYMASK | LVIS_STATEIMAGEMASK;
		
		Item2 = Item1;
		Item2.iItem = nItem2;

		GetItem(&Item1);
		GetItem(&Item2);

		// 두 항목의 텍스트를 바꾼다
		SetItemText(nItem1, i, strItem2);
		SetItemText(nItem2, i, strItem1);

		// 두 항목의 속성을 바꾼다
		Item1.iItem = nItem2;
		Item2.iItem = nItem1;

		SetItem(&Item1);
		SetItem(&Item2);
	}
}
