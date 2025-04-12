// DialogTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "dialogtabctrldemo.h"
#include "DialogTabCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogTabCtrl

// 탭의 테두리와 다이얼로그 사이의 여백
#define CONST_TAB_GAP		4


CDialogTabCtrl::CDialogTabCtrl()
{
}

CDialogTabCtrl::~CDialogTabCtrl()
{
}


BEGIN_MESSAGE_MAP(CDialogTabCtrl, CTabCtrl)
	//{{AFX_MSG_MAP(CDialogTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGING, OnSelchanging)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogTabCtrl message handlers

void CDialogTabCtrl::OnSelchanging(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// 현재 탭 번호를 얻는다
	int nTab = GetCurSel();

	// 탭 항목의 높이를 구하여 다이얼로그의 위치를 계산한다
	CRect rcItem;
	GetItemRect(0, &rcItem);
	int x = CONST_TAB_GAP;
	int y = rcItem.Height() * GetRowCount() + CONST_TAB_GAP;

	// 탭 번호가 정상이라면
	if(nTab >= 0 && nTab < m_Dialogs.GetSize())
	{
		// 탭을 구현하는 다이얼로그 포인터를 얻는다
		CDialog *pDialog = m_Dialogs.GetAt(nTab);
		// 다이얼로그를 감춘다
		pDialog->SetWindowPos(this, x, y, 0, 0,
			SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOZORDER | SWP_HIDEWINDOW);
	}
	
	// 부모 다이얼로그에게 탭이 바뀌고 있음을 알린다
	GetParent()->SendMessage(WM_AT_SELCHANGING, GetDlgCtrlID(), nTab);
	
	*pResult = 0;
}

void CDialogTabCtrl::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// 현재 탭 번호를 얻는다
	int nTab = GetCurSel();

	// 탭 항목의 높이를 구하여 다이얼로그의 위치를 계산한다
	CRect rcItem;
	GetItemRect(0, &rcItem);
	int x = CONST_TAB_GAP;
	int y = rcItem.Height() * GetRowCount() + CONST_TAB_GAP;

	// 탭 번호가 정상이라면
	if(nTab >= 0 && nTab < m_Dialogs.GetSize())
	{
		// 탭을 구현하는 다이얼로그 포인터를 얻는다
		CDialog *pDialog = m_Dialogs.GetAt(nTab);
		// 다이얼로그를 보이게 만든다
		pDialog->SetWindowPos(this, x, y, 0, 0,
			SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOZORDER | SWP_SHOWWINDOW);
	}

	// 부모 다이얼로그에게 탭이 바뀌었음을 알린다
	GetParent()->SendMessage(WM_AT_SELCHANGE, GetDlgCtrlID(), nTab);
	
	*pResult = 0;
}

// 특정 탭을 선택하는 함수
int CDialogTabCtrl::SetCurSel(int nItem)
{
	// 현재 탭 번호를 얻는다
	int nCur = GetCurSel();
	CDialog *pDialog;

	// 만약 현재 탭 번호가 새로 설정하는 탭 번호와 다르다면
	if(nCur != nItem)
	{
		// 현재 탭 번호가 정상이라면
		if(nCur >= 0 && nCur < m_Dialogs.GetSize())
		{
			// 탭을 구현하는 다이얼로그 포인터를 구한다
			pDialog = m_Dialogs.GetAt(nCur);
			// 다이얼로그를 감춘다
			pDialog->SetWindowPos(this, 0, 0, 0, 0,
				SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOZORDER | SWP_HIDEWINDOW);
		}

		// 새로운 탭을 선택한다
		CTabCtrl::SetCurSel(nItem);
	}

	CRect rcItem;
	GetItemRect(0, &rcItem);
	int x = CONST_TAB_GAP;
	int y = rcItem.Height() * GetRowCount() + CONST_TAB_GAP;

	// 만약 새로운 탭 번호가 정상이라면
	if(nItem >= 0 && nItem < m_Dialogs.GetSize())
	{
		// 탭을 구현하는 다이얼로그 포인터를 구한다
		pDialog = m_Dialogs.GetAt(nItem);
		// 다이얼로그를 보이게 만든다
		pDialog->SetWindowPos(this, x, y, 0, 0,
			SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOZORDER | SWP_SHOWWINDOW);
	}

	// 이전 탭 번호를 리턴한다
	return nCur;
}

// 현재 탭을 구현하는 다이얼로그를 리턴하는 함수
CDialog* CDialogTabCtrl::GetCurSelDlg()
{
	// 현재 선택된 탭 번호를 구한다
	int nItem = GetCurSel();

	// 만약 탭 번호가 정상이 아니라면 리턴한다
	if(nItem < 0 || nItem >= m_Dialogs.GetSize())		return NULL;

	// 다이얼로그 배열에서 현재 탭을 구현하는 다이얼로그 포인터를 리턴한다
	return m_Dialogs.GetAt(nItem);
}

// 특정 탭을 구현하는 다이얼로그를 리턴하는 함수
CDialog* CDialogTabCtrl::GetDialog(int nItem)
{
	// 만약 탭 번호가 정상이 아니라면 리턴한다
	if(nItem < 0 || nItem >= m_Dialogs.GetSize())		return NULL;

	// 다이얼로그 배열에서 해당 탭을 구현하는 다이얼로그 포인터를 리턴한다
	return m_Dialogs.GetAt(nItem);
}

// 새로운 탭을 생성하는 함수
BOOL CDialogTabCtrl::InsertItem(int nItem, TCITEM* pTabCtrlItem, CDialog *pDialog)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nItem, pTabCtrlItem) < 0)	return FALSE;

	// 다이얼로그를 감춘다
	pDialog->ShowWindow(SW_HIDE);

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Dialogs.GetSize())
		// 해당 위치에 삽입한다
		m_Dialogs.InsertAt(nItem, pDialog);
	else
		// 배열에 추가한다
		m_Dialogs.Add(pDialog);

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CDialogTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem, CDialog *pDialog)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nItem, lpszItem) < 0)	return FALSE;

	// 다이얼로그를 감춘다
	pDialog->ShowWindow(SW_HIDE);

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Dialogs.GetSize())
		// 해당 위치에 삽입한다
		m_Dialogs.InsertAt(nItem, pDialog);
	else
		// 배열에 추가한다
		m_Dialogs.Add(pDialog);

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CDialogTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem, int nImage, CDialog *pDialog)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nItem, lpszItem, nImage) < 0)	return FALSE;

	// 다이얼로그를 감춘다
	pDialog->ShowWindow(SW_HIDE);

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Dialogs.GetSize())
		// 해당 위치에 삽입한다
		m_Dialogs.InsertAt(nItem, pDialog);
	else
		// 배열에 추가한다
		m_Dialogs.Add(pDialog);

	return TRUE;
}

// 새로운 탭을 생성하는 함수
BOOL CDialogTabCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam, CDialog *pDialog)
{
	// 탭을 추가한다
	if(CTabCtrl::InsertItem(nMask, nItem, lpszItem, nImage, lParam) < 0)	return FALSE;

	// 다이얼로그를 감춘다
	pDialog->ShowWindow(SW_HIDE);

	// 만약 탭 중간에 삽입하는 것이라면
	if(nItem < m_Dialogs.GetSize())
		// 해당 위치에 삽입한다
		m_Dialogs.InsertAt(nItem, pDialog);
	else
		// 배열에 추가한다
		m_Dialogs.Add(pDialog);

	return TRUE;
}

// 특정 탭을 삭제하는 함수
BOOL CDialogTabCtrl::DeleteItem(int nItem)
{
	// 탭을 삭제한다
	if(!CTabCtrl::DeleteItem(nItem))		return FALSE;

	// 탭 번호가 정상이라면
	if(nItem >= 0 && nItem < m_Dialogs.GetSize())
	{
		// 배열에서 해당 다이얼로그 포인터를 제거한다
		m_Dialogs.RemoveAt(nItem);
	}

	return TRUE;
}

// 모든 탭을 삭제하는 함수
BOOL CDialogTabCtrl::DeleteAllItems()
{
	// 모든 탭을 삭제한다
	if(!CTabCtrl::DeleteAllItems())			return FALSE;

	// 배열을 초기화한다
	m_Dialogs.RemoveAll();

	return TRUE;
}
