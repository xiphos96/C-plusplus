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

// ������
CControlContainer::CControlContainer()
{
	// ��� �������� �ʱ�ȭ�Ѵ�
	m_bShow = FALSE;
}

// �Ҹ���
CControlContainer::~CControlContainer()
{
	// ��Ʈ�� �迭�� �ʱ�ȭ�Ѵ�
	m_Controls.RemoveAll();
}

// �����̳ʿ� ��Ʈ���� �߰��ϴ� �Լ�
int CControlContainer::AddControl(CWnd *pCtrl)
{
	// ��Ʈ�� �迭�� �����͸� �߰��Ѵ�
	return (int)m_Controls.Add(pCtrl);
}

// �����̳��� ��Ʈ�ѵ��� ���̰ų� ���ߴ� �Լ�
void CControlContainer::ShowControls(BOOL bShow)
{
	// ���� ���� ���¿� �����ϴٸ� ����
	if(m_bShow == bShow)		return;

	// ���ο� ���¸� �����Ѵ�
	m_bShow = bShow;

	// ��Ʈ�� �迭�� ��� ��Ʈ���� ���̰ų� �����
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
	// �����̳� �迭�� ������ �����Ѵ�
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
	// ���� �� ��ȣ�� ��´�
	int nTab = GetCurSel();

	// �� ��ȣ�� �����̶��
	if(nTab >= 0 && nTab < m_Containers.GetSize())
	{
		// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
		CControlContainer *pContainer = m_Containers.GetAt(nTab);
		// �����̳��� ��Ʈ�ѵ��� �����
		pContainer->ShowControls(FALSE);
	}

	// �θ� ���̾�α׿��� ���� �ٲ�� ������ �˸���
	GetParent()->SendMessage(WM_AT_SELCHANGING, GetDlgCtrlID(), nTab);

	*pResult = 0;
}

void CAutoTabCtrl::OnSelchange(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// ���� �� ��ȣ�� ��´�
	int nTab = GetCurSel();

	// �� ��ȣ�� �����̶��
	if(nTab >= 0 && nTab < m_Containers.GetSize())
	{
		// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
		CControlContainer *pContainer = m_Containers.GetAt(nTab);
		// �����̳��� ��Ʈ�ѵ��� ���̰� �����
		pContainer->ShowControls(TRUE);
	}

	// �θ� ���̾�α׿��� ���� �ٲ������ �˸���
	GetParent()->SendMessage(WM_AT_SELCHANGE, GetDlgCtrlID(), nTab);

	*pResult = 0;
}

// Ư�� ���� �����ϴ� �Լ�
int CAutoTabCtrl::SetCurSel(int nItem)
{
	// ���� �� ��ȣ�� ��´�
	int nCur = GetCurSel();
	CControlContainer *pContainer;

	// ���� ���� �� ��ȣ�� ���� �����ϴ� �� ��ȣ�� �ٸ��ٸ�
	if(nCur != nItem)
	{
		// ���� �� ��ȣ�� �����̶��
		if(nCur >= 0 && nCur < m_Containers.GetSize())
		{
			// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
			pContainer = m_Containers.GetAt(nCur);
			// �����̳��� ��Ʈ�ѵ��� �����
			pContainer->ShowControls(FALSE);
		}

		// ���ο� ���� �����Ѵ�
		CTabCtrl::SetCurSel(nItem);
	}

	// ���� ���ο� �� ��ȣ�� �����̶��
	if(nItem >= 0 && nItem < m_Containers.GetSize())
	{
		// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
		pContainer = m_Containers.GetAt(nItem);
		// �����̳��� ��Ʈ�ѵ��� ���̰� �����
		pContainer->ShowControls(TRUE);
	}

	// ���� �� ��ȣ�� �����Ѵ�
	return nCur;
}

// Ư�� �ǿ� ��Ʈ���� �߰��ϴ� �Լ�
BOOL CAutoTabCtrl::AddControl(int nTab, CWnd *pWnd)
{
	// ���� �� ��ȣ�� ������ �ƴ϶�� �����Ѵ�
	if(nTab < 0 || nTab >= m_Containers.GetSize())		return FALSE;

	// �ǿ� �ش��ϴ� �����̳� �����͸� ��´�
	CControlContainer *pContainer = m_Containers.GetAt(nTab);
	// �����̳ʸ� ���� �� ���ٸ� �����Ѵ�
	if(pContainer == NULL)					return FALSE;

	// �߰��Ϸ��� ��Ʈ���� �����
	pWnd->ShowWindow(SW_HIDE);
	// �����̳ʿ� �߰��Ѵ�
	pContainer->AddControl(pWnd);

	return TRUE;
}

// ���ο� ���� �����ϴ� �Լ�
BOOL CAutoTabCtrl::InsertItem(int nItem, TCITEM* pTabCtrlItem)
{
	// ���� �߰��Ѵ�
	if(CTabCtrl::InsertItem(nItem, pTabCtrlItem) < 0)	return FALSE;

	// ���ο� �����̳ʸ� �����Ѵ�
	CControlContainer *pItem = new CControlContainer;

	// ���� �� �߰��� �����ϴ� ���̶��
	if(nItem < m_Containers.GetSize())
		// �ش� ��ġ�� �����Ѵ�
		m_Containers.InsertAt(nItem, pItem);
	else
		// �迭�� �߰��Ѵ�
		m_Containers.Add(pItem);

	return TRUE;
}

// ���ο� ���� �����ϴ� �Լ�
BOOL CAutoTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem)
{
	// ���� �߰��Ѵ�
	if(CTabCtrl::InsertItem(nItem, lpszItem) < 0)	return FALSE;

	// ���ο� �����̳ʸ� �����Ѵ�
	CControlContainer *pItem = new CControlContainer;

	// ���� �� �߰��� �����ϴ� ���̶��
	if(nItem < m_Containers.GetSize())
		// �ش� ��ġ�� �����Ѵ�
		m_Containers.InsertAt(nItem, pItem);
	else
		// �迭�� �߰��Ѵ�
		m_Containers.Add(pItem);

	return TRUE;
}

// ���ο� ���� �����ϴ� �Լ�
BOOL CAutoTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem, int nImage)
{
	// ���� �߰��Ѵ�
	if(CTabCtrl::InsertItem(nItem, lpszItem, nImage) < 0)	return FALSE;

	// ���ο� �����̳ʸ� �����Ѵ�
	CControlContainer *pItem = new CControlContainer;

	// ���� �� �߰��� �����ϴ� ���̶��
	if(nItem < m_Containers.GetSize())
		// �ش� ��ġ�� �����Ѵ�
		m_Containers.InsertAt(nItem, pItem);
	else
		// �迭�� �߰��Ѵ�
		m_Containers.Add(pItem);

	return TRUE;
}

// ���ο� ���� �����ϴ� �Լ�
BOOL CAutoTabCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam)
{
	// ���� �߰��Ѵ�
	if(CTabCtrl::InsertItem(nMask, nItem, lpszItem, nImage, lParam) < 0)	return FALSE;

	// ���ο� �����̳ʸ� �����Ѵ�
	CControlContainer *pItem = new CControlContainer;

	// ���� �� �߰��� �����ϴ� ���̶��
	if(nItem < m_Containers.GetSize())
		// �ش� ��ġ�� �����Ѵ�
		m_Containers.InsertAt(nItem, pItem);
	else
		// �迭�� �߰��Ѵ�
		m_Containers.Add(pItem);

	return TRUE;
}

// Ư�� ���� �����ϴ� �Լ�
BOOL CAutoTabCtrl::DeleteItem(int nItem)
{
	// ���� �����Ѵ�
	if(!CTabCtrl::DeleteItem(nItem))		return FALSE;

	// �� ��ȣ�� �����̳� �迭�� ũ�⺸�� �۴ٸ�
	if(nItem >= 0 && nItem < m_Containers.GetSize())
	{
		// �ش� �����̳ʸ� �����Ѵ�
		delete m_Containers.GetAt(nItem);
		// �迭���� �����̳ʸ� �����Ѵ�
		m_Containers.RemoveAt(nItem);
	}

	return TRUE;
}

// ��� ���� �����ϴ� �Լ�
BOOL CAutoTabCtrl::DeleteAllItems()
{
	// ��� ���� �����Ѵ�
	if(!CTabCtrl::DeleteAllItems())			return FALSE;

	// �����̳� �迭�� ũ�⸦ ���Ѵ�
	int i, nSize = (int)m_Containers.GetSize();
	for(i = 0; i < nSize; i++)
	{
		// �� �����̳ʸ� �����Ѵ�
		delete m_Containers.GetAt(i);
	}
	// �迭�� �ʱ�ȭ�Ѵ�
	m_Containers.RemoveAll();

	return TRUE;
}
