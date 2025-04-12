// AutoTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "Autotabctrldemo.h"
#include "AutoTabCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControlContainer

// 생성자
CControlContainer::CControlContainer()
{
	// 멤버 변수들을 초기화한다
	m_bShow = FALSE;
}

// 소멸자
CControlContainer::~CControlContainer()
{
	// 컨트롤 배열을 초기화한다
	m_Controls.RemoveAll();
}

// 컨테이너에 컨트롤을 추가하는 함수
int CControlContainer::AddControl(CWnd *pCtrl)
{
	// 컨트롤 배열에 포인터를 추가한다
	return (int)m_Controls.Add(pCtrl);
}

// 컨테이너의 컨트롤들을 보이거나 감추는 함수
void CControlContainer::ShowControls(BOOL bShow)
{
	// 만약 현재 상태와 동일하다면 리턴
	if(m_bShow == bShow)		return;

	// 새로운 상태를 저장한다
	m_bShow = bShow;

	// 컨트롤 배열의 모든 컨트롤을 보이거나 감춘다
	int i, nSize = (int)m_Controls.GetSize();
	CWnd *pWnd;

	for(i = 0; i < nSize; i++)
	{
		pWnd = m_Controls.GetAt(i);
		pWnd->SetWindowPos(&CWnd::wndTop, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE |
			(bShow ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
	}
}


/////////////////////////////////////////////////////////////////////////////
// CAutoTabCtrl

CAutoTabCtrl::CAutoTabCtrl()
{
}

CAutoTabCtrl::~CAutoTabCtrl()
{
	// 컨테이너 배열의 내용을 제거한다
	int i, nSize = (int)m_Containers.GetSize();

	for(i = 0; i < nSize; i++)
	{
		delete m_Containers.GetAt(i);
	}
	m_Containers.RemoveAll();
}


BEGIN_MESSAGE_MAP(CAutoTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CAutoTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	ON_NOTIFY_REFLECT(TCN_SELCHANGING, OnSelchanging)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoTabCtrl message handlers

void CAutoTabCtrl::OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// 현재 탭 번호를 얻는다
	int nTab = GetCurSel();

	// 탭 번호가 정상이라면
	if(nTab >= 0 && nTab < m_Containers.GetSize())
	{
		// 탭에 해당하는 컨테이너 포인터를 얻는다
		CControlContainer *pContainer = m_Containers.GetAt(nTab);
		// 컨테이너의 컨트롤들을 감춘다
		pContainer->ShowControls(FALSE);
	}

	// 부모 다이얼로그에게 탭이 바뀌고 있음을 알린다
	GetParent()->SendMessage(WM_AT_SELCHANGING, GetDlgCtrlID(), nTab);

	*pResult = 0;
}

void CAutoTabCtrl::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// 현재 탭 번호를 얻는다
	int nTab = GetCurSel();

	// 탭 번호가 정상이라면
	if(nTab >= 0 && nTab < m_Containers.GetSize())
	{
		// 탭에 해당하는 컨테이너 포인터를 얻는다
		CControlContainer *pContainer = m_Containers.GetAt(nTab);
		// 컨테이너의 컨트롤들을 보이게 만든다
		pContainer->ShowControls(TRUE);
	}

	// 부모 다이얼로그에게 탭이 바뀌었음을 알린다
	GetParent()->SendMessage(WM_AT_SELCHANGE, GetDlgCtrlID(), nTab);

	*pResult = 0;
}

// 특정 탭을 선택하는 함수
int CAutoTabCtrl::SetCurSel(int nItem)
{
	// 현재 탭 번호를 얻는다
	int nCur = GetCurSel();
	CControlContainer *pContainer;

	// 만약 현재 탭 번호가 새로 설정하는 탭 번호와 다르다면
	if(nCur != nItem)
	{
		// 현재 탭 번호가 정상이라면
		if(nCur >= 0 && nCur < m_Containers.GetSize())
		{
			// 탭에 해당하는 컨테이너 포인터를 얻는다
			pContainer = m_Containers.GetAt(nCur);
			// 컨테이너의 컨트롤들을 감춘다
			pContainer->ShowControls(FALSE);
		}

		// 새로운 탭을 선택한다
		CTabCtrl::SetCurSel(nItem);
	}

	// 만약 새로운 탭 번호가 정상이라면
	if(nItem >= 0 && nItem < m_Containers.GetSize())
	{
		// 탭에 해당하는 컨테이너 포인터를 얻는다
		pContainer = m_Containers.GetAt(nItem);
		// 컨테이너의 컨트롤들을 보이게 만든다
		pContainer->ShowControls(TRUE);
	}

	// 이전 탭 번호를 리턴한다
	return nCur;
}

// 특정 탭에 컨트롤을 추가하는 함수
BOOL CAutoTabCtrl::AddControl(int nTab, CWnd *pWnd)
{
	// 만약 탭 번호가 정상이 아니라면 리턴한다
	if(nTab < 0 || nTab >= m_Containers.GetSize())		return FALSE;

	// 탭에 해당하는 컨테이너 포인터를 얻는다
	CControlContainer *pContainer = m_Containers.GetAt(nTab);
	// 컨테이너를 얻을 수 없다면 리턴한다
	if(pContainer == NULL)					return FALSE;

	// 추가하려는 컨트롤을 감춘다
	pWnd->ShowWindow(SW_HIDE);
	// 컨테이너에 추가한다
	pContainer->AddControl(pWnd);

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CAutoTabCtrl::InsertItem(int nItem, TCITEM* pTabCtrlItem)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nItem, pTabCtrlItem) < 0)	return FALSE;

	// 새로운 컨테이너를 생성한다
	CControlContainer *pItem = new CControlContainer;

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Containers.GetSize())
		// 해당 위치에 삽입한다
		m_Containers.InsertAt(nItem, pItem);
	else
		// 배열에 추가한다
		m_Containers.Add(pItem);

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CAutoTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nItem, lpszItem) < 0)	return FALSE;

	// 새로운 컨테이너를 생성한다
	CControlContainer *pItem = new CControlContainer;

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Containers.GetSize())
		// 해당 위치에 삽입한다
		m_Containers.InsertAt(nItem, pItem);
	else
		// 배열에 추가한다
		m_Containers.Add(pItem);

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CAutoTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem, int nImage)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nItem, lpszItem, nImage) < 0)	return FALSE;

	// 새로운 컨테이너를 생성한다
	CControlContainer *pItem = new CControlContainer;

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Containers.GetSize())
		// 해당 위치에 삽입한다
		m_Containers.InsertAt(nItem, pItem);
	else
		// 배열에 추가한다
		m_Containers.Add(pItem);

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CAutoTabCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nMask, nItem, lpszItem, nImage, lParam) < 0)	return FALSE;

	// 새로운 컨테이너를 생성한다
	CControlContainer *pItem = new CControlContainer;

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Containers.GetSize())
		// 해당 위치에 삽입한다
		m_Containers.InsertAt(nItem, pItem);
	else
		// 배열에 추가한다
		m_Containers.Add(pItem);

	return TRUE;
}

// 특정 탭을 삭제하는 함수
BOOL CAutoTabCtrl::DeleteItem(int nItem)
{
	// 탭을 삭제한다
	if(!CTabCtrl::DeleteItem(nItem))		return FALSE;

	// 탭 번호가 컨테이너 배열의 크기보다 작다면
	if(nItem >= 0 && nItem < m_Containers.GetSize())
	{
		// 해당 컨테이너를 삭제한다
		delete m_Containers.GetAt(nItem);
		// 배열에서 컨테이너를 제거한다
		m_Containers.RemoveAt(nItem);
	}

	return TRUE;
}

// 모든 탭을 삭제하는 함수
BOOL CAutoTabCtrl::DeleteAllItems()
{
	// 모든 탭을 삭제한다
	if(!CTabCtrl::DeleteAllItems())			return FALSE;

	// 컨테이너 배열의 크기를 구한다
	int i, nSize = (int)m_Containers.GetSize();
	for(i = 0; i < nSize; i++)
	{
		// 각 컨테이너를 삭제한다
		delete m_Containers.GetAt(i);
	}
	// 배열을 초기화한다
	m_Containers.RemoveAll();

	return TRUE;
}
