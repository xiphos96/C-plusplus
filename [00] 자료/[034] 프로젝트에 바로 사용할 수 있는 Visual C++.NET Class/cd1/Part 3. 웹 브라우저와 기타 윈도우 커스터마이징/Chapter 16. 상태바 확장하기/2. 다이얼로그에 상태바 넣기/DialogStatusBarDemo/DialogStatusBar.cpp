// DialogStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "dialogstatusbardemo.h"
#include "DialogStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogStatusBar

// ���¹��� ���̸� �����ϴ� ���
#define	CONST_STATUSBAR_HEIGHT		24


CDialogStatusBar::CDialogStatusBar()
{
}

CDialogStatusBar::~CDialogStatusBar()
{
}


BEGIN_MESSAGE_MAP(CDialogStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CDialogStatusBar)
	ON_WM_MENUSELECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogStatusBar message handlers

// ���¹� ���� �Լ�
BOOL CDialogStatusBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
{
	// �⺻ ���¹� ���� �Լ��� �����Ѵ�
	if(!CStatusBar::Create(pParentWnd, dwStyle, nID))	return FALSE;

	// �θ� �������� Ŭ���̾�Ʈ ������ ��´�
	CRect rcStatus;
	pParentWnd->GetClientRect(&rcStatus);

	// ���¹��� ������ Ŭ���̾�Ʈ �Ʒ������� �����Ѵ�
	rcStatus.top = rcStatus.bottom - CONST_STATUSBAR_HEIGHT;

	// ���¹��� ��ġ�� �ű��
	MoveWindow(rcStatus);

	return TRUE;
}

// ���� ���� �Լ�
BOOL CDialogStatusBar::SetIndicators(const UINT* lpIDArray, int nIDCount)
{
	// �⺻ ���¹� ���� ���� �Լ��� �����Ѵ�
	if(!CStatusBar::SetIndicators(lpIDArray, nIDCount))	return FALSE;

	// ���� �߿��� ID_SEPARATOR�� ID�� ���� ������ ã�´�
	int i;
	for(i = 0; i < nIDCount; i++)
	{
		// ���� ID�� ID_SEPARATOR��� �⺻ �޴� ���¸� �ؽ�Ʈ�� ����Ѵ�
		if(lpIDArray[i] == ID_SEPARATOR)	SetPaneText(i, "�غ�");
	}

	return TRUE;
}

// �θ� �������� ũ�� ��ȭ�� ���� ���¹� ��ġ/ũ�� ��ȭ �Լ�
void CDialogStatusBar::OnResize(int cx, int cy)
{
	// ���� ���¹ٰ� ������ ���¶��
	if(m_hWnd)
	{
		CRect rcStatus;

		// ���ο� �θ� �������� �Ʒ������� ���¹ٸ� �ű��
		rcStatus.SetRect(0, cy - CONST_STATUSBAR_HEIGHT, cx, cy);
		MoveWindow(&rcStatus);
	}
}

// �θ� �������� �޴� ���ý� �޴� �ؽ�Ʈ ��� �Լ�
void CDialogStatusBar::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu) 
{
	CString strText;

	// �ش� �޴��� �ؽ�Ʈ�� ��´�
	if(nItemID > 0)			strText.LoadString(nItemID);
	// ���� �ؽ�Ʈ�� ���ٸ� �⺻ �޴� ���� �ؽ�Ʈ�� �����Ѵ�
	if(strText.IsEmpty())	strText = "�غ�";

	// ��� ���ο� ���ؼ� ID�� ID_SEPARATOR�� ������ ã�´�
	int nPanes = GetStatusBarCtrl().GetParts(0, NULL), i;
	for(i = 0; i < nPanes; i++)
	{
		if(GetItemID(i) == ID_SEPARATOR)
		{
			// ID�� ID_SEPARATOR�� ������ �ؽ�Ʈ�� �޴� �ؽ�Ʈ�� �����Ѵ�
			SetPaneText(i, strText);
		}
	}
}
