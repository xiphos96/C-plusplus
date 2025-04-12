// ControlStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "controlstatusbardemo.h"
#include "ControlStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControlStatusBar

CControlStatusBar::CControlStatusBar()
{
}

CControlStatusBar::~CControlStatusBar()
{
	// ��Ʈ�� ���� ����ü �迭�� �ʱ�ȭ�Ѵ�
	int i, nSize = m_ControlArray.GetSize();
	SControlPane *pPane;

	for(i = 0; i < nSize; i++)
	{
		pPane = m_ControlArray.GetAt(i);
		if(pPane->pWnd)		delete pPane->pWnd;
		delete pPane;
	}

	m_ControlArray.RemoveAll();
}


BEGIN_MESSAGE_MAP(CControlStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CControlStatusBar)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControlStatusBar message handlers

// ���ο� ���ο� ��Ʈ���� �߰��ϴ� �Լ�
int CControlStatusBar::InsertControlPane(LPCTSTR pText, CONTROL_TYPE nType, UINT nID, int nPane, int nWidth)
{
	CWnd *pWnd;

	// �߰��� ��Ʈ���� Ÿ�Կ� ����
	switch(nType)
	{
	case CONTROL_STATIC:
		// ����ƽ ��ü�� �����Ѵ�
		pWnd = new CStatic;
		// ������ν� �����Ѵ�
		((CStatic*)pWnd)->Create(pText, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, nID);
		break;
	case CONTROL_EDIT:
		// ����Ʈ �ڽ� ��ü�� �����Ѵ�
		pWnd = new CEdit;
		// ������ν� �����Ѵ�
		((CEdit*)pWnd)->Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, nID);
		break;
	case CONTROL_BUTTON:
		// ��ư ��ü�� �����Ѵ�
		pWnd = new CButton;
		// ������ν� �����Ѵ�
		((CButton*)pWnd)->Create(pText, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , CRect(0, 0, 0, 0), this, nID);
		break;
	case CONTROL_CHECK:
		// üũ �ڽ� ��ü�� �����Ѵ�
		pWnd = new CButton;
		// ������ν� �����Ѵ�
		((CButton*)pWnd)->Create(pText, WS_CHILD | WS_VISIBLE | BS_CHECKBOX, CRect(0, 0, 0, 0), this, nID);
		break;
	case CONTROL_PROGRESS:
		// ���α׷����� ��ü�� �����Ѵ�
		pWnd = new CProgressCtrl;
		// ������ν� �����Ѵ�
		((CProgressCtrl*)pWnd)->Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, nID);
		break;
	default:
		// ���ǵ��� ���� ��Ʈ���� ���з� �����Ѵ�
		return 0;
	}

	// ��Ʈ�ѿ� ���¹��� ��Ʈ�� �����Ѵ�
	pWnd->SetFont(GetFont());

	// ������ �����ϰ� ��Ʈ���� �����Ѵ�
	int nPanes = InsertControlPane(pWnd, nID, nPane, nWidth);

	// ���� ��Ʈ�� ���� ������ �����ϸ�
	if(nPanes == 0)
	{
		// �����Ͽ��� ��Ʈ���� �����Ѵ�
		pWnd->DestroyWindow();
		delete pWnd;
	}

	// ���� ���� ������ �����Ѵ�
	return nPanes;
}

// ���ο� ���ο� ��Ʈ���� �߰��ϴ� �Լ�
int CControlStatusBar::InsertControlPane(CWnd *pWnd, UINT nID, int nPane, int nWidth)
{
	// ���� ���� ������ ��´�
	int nPanes = GetStatusBarCtrl().GetParts(0, NULL);
	// ���� ���� �ε����� ��ȿ���� �ʴٸ� ����
	if(nPanes < nPane)					return 0;

	// ��� ��Ʈ�� ���� �迭�� ����
	SControlPane *pPane;
	int i, nSize = m_ControlArray.GetSize();

	for(i = 0; i < nSize; i++)
	{
		pPane = m_ControlArray.GetAt(i);

		// ������ ID�� ������ �����Ѵٸ�
		if(pPane->nID == nID)
		{
			// ������ �ε��� ��ȣ�� �����ߴ� ������ �ε����� �ǵ�����
			for(i -= 1; i >= 0; i--)
			{
				pPane = m_ControlArray.GetAt(i);
				if(pPane->nPane > nPane)	pPane->nPane -= 1;
			}

			// ���з� �����Ѵ�
			return 0;
		}
		// ���� ���� �ε����� �߰��� ��ġ ���Ķ�� �ε����� 1 ������Ų��
		if(pPane->nPane >= nPane)		pPane->nPane += 1;
	}

	// ��Ʈ�� ���� ����ü�� �����ϰ� ���� �����Ѵ�
	pPane					= new SControlPane;
	pPane->pWnd				= pWnd;
	pPane->nID				= nID;
	pPane->nPane			= nPane;
	pPane->strText			= "";

	// ��Ʈ�� ���� �迭�� �߰��Ѵ�
	m_ControlArray.Add(pPane);

	UINT *pIDs		= new UINT[nPanes + 1];
	UINT *pStyles	= new UINT[nPanes + 1];
	int *pWidth		= new int[nPanes + 1];
	CString *pTexts = new CString[nPanes + 1];

	// ���� ���¹��� �� ���� ������ ��´�
	for(i = 0; i < nPanes + 1; i++)
	{
		// �߰��� ��ġ ���� ���� �״�� �����Ѵ�
		if(i < nPane)
		{
			GetPaneInfo(i, pIDs[i], pStyles[i], pWidth[i]);
			pTexts[i] = GetPaneText(i);
		}
		else
		{
			// �߰��� ��ġ���� ���� ������ ���� ������ �����Ѵ�
			if(i == nPane)
			{
				pIDs[i]		= nID;
				pStyles[i]	= SBPS_NORMAL;
				pWidth[i]	= nWidth;
				pTexts[i]	= "";
			}
			else
			{
				// �߰��� ��ġ ������ ���ε��� ���� ������ ���� ���� �ڿ� �߰��Ѵ�
				GetPaneInfo(i - 1, pIDs[i], pStyles[i], pWidth[i]);
				pTexts[i] = GetPaneText(i - 1);
			}
		}
	}

	// ���¹��� ������ �ٽ� �����Ѵ�
	SetIndicators(pIDs, nPanes + 1);

	// ���� ������ ���ε��� �Ӽ��� ���� �Ӽ��� �����ϰ� �����Ѵ�
	for(i = 0; i < nPanes + 1; i++)
	{
		SetPaneInfo(i, pIDs[i], pStyles[i], pWidth[i]);
		SetPaneText(i, pTexts[i]);
	}

	// �޸𸮸� �����Ѵ�
	delete[] pIDs;
	delete[] pStyles;
	delete[] pWidth;
	delete[] pTexts;

	// �� ���� ������ �����Ѵ�
	return nPanes + 1;
}

// ��Ʈ�� ������ �����ϴ� �Լ�
int CControlStatusBar::RemoveControlPane(int nPane)
{
	// ���� ���� ������ ��´�
	int nPanes = GetStatusBarCtrl().GetParts(0, NULL);

	// ���� ���� �ε����� ��ȿ���� �ʴٸ� ����
	if(nPanes <= nPane)		return 0;

	// ��� ��Ʈ�� ���� �迭�� ���� �˻�
	SControlPane *pPane;
	int i, nSize = m_ControlArray.GetSize();

	for(i = 0; i < nSize; i++)
	{
		pPane = m_ControlArray.GetAt(i);

		// �ش� ���� �ε����� ��Ʈ�� ���ο� ����
		if(pPane->nPane == nPane)
		{
			// ���� ������ ������ ��Ʈ���� �����Ǿ� �ִٸ� �Ҹ��Ų��
			if(pPane->pWnd->m_hWnd)		pPane->pWnd->DestroyWindow();
			// ��Ʈ�� ���� ����ü�� �����Ѵ�
			delete pPane;

			// ���� ������ ����ü�� �迭���� �����Ѵ�
			m_ControlArray.RemoveAt(i--);
			nSize--;
		}
		else
			if(pPane->nPane > nPane)
			{
				// ������ ������ �ڿ� �ִ� ������ ���� ��ȣ�� ���� ��Ų��
				pPane->nPane--;
			}
	}

	UINT *pIDs		= new UINT[nPanes - 1];
	UINT *pStyles	= new UINT[nPanes - 1];
	int *pWidth		= new int[nPanes - 1];
	CString *pTexts = new CString[nPanes - 1];

	// ���� ���¹��� �� ���� ������ ��´�
	for(i = 0; i < nPanes; i++)
	{
		// �߰��� ��ġ ���� ���� �״�� �����Ѵ�
		if(i < nPane)
		{
			GetPaneInfo(i, pIDs[i], pStyles[i], pWidth[i]);
			pTexts[i] = GetPaneText(i);
		}
		else
		{
			// �߰��� ��ġ ������ ���ε��� ���� ���� ��ġ�� �̵��Ѵ�
			if(i > nPane)
			{
				GetPaneInfo(i, pIDs[i - 1], pStyles[i - 1], pWidth[i - 1]);
				pTexts[i - 1] = GetPaneText(i);
			}
		}
	}

	// ���¹��� ������ �ٽ� �����Ѵ�
	SetIndicators(pIDs, nPanes - 1);

	// ���� ������ ���ε��� �Ӽ��� ���� �Ӽ��� �����ϰ� �����Ѵ�
	for(i = 0; i < nPanes - 1; i++)
	{
		SetPaneInfo(i, pIDs[i], pStyles[i], pWidth[i]);
		SetPaneText(i, pTexts[i]);
	}

	// �޸𸮸� �����Ѵ�
	delete[] pIDs;
	delete[] pStyles;
	delete[] pWidth;
	delete[] pTexts;

	// �� ���� ������ �����Ѵ�
	return nPanes - 1;
}

// ���¹��� ��Ʈ�ѵ��� ��ġ�� �������ϴ� �Լ�
void CControlStatusBar::RepositionAll()
{
	int nHorz, nVert, nSpace, i, nSize = m_ControlArray.GetSize();
	UINT nStyle;
	CRect rcPane;
	SControlPane *pPane;

	// ���� ���¹��� �׵θ� �Ӽ��� ��´�
	GetStatusBarCtrl().GetBorders(nHorz, nVert, nSpace);

	// ��� ��Ʈ�� ���ε鿡 ����
	for(i = 0; i < nSize; i++)
	{
		// ��Ʈ�� ���� ����ü ������ ��´�
		pPane = m_ControlArray.GetAt(i);

		// �ش� ������ �簢 ������ ��´�
		GetItemRect(pPane->nPane, rcPane);
		// �ش� ������ ��Ÿ���� ��´�
		nStyle = GetPaneStyle(pPane->nPane);

		// ���� �׵θ��� ����Ѵٸ�
		if(!(nStyle & SBPS_NOBORDERS))
			// �׵θ���ŭ �簢 ������ �����Ѵ�
			rcPane.DeflateRect(nHorz + nSpace, nVert);

		// ���� ��ġ�� ��Ʈ���� �ű��
		pPane->pWnd->MoveWindow(rcPane);
	}
}

// Ư�� ������ ���� �����ϴ� �Լ�
int CControlStatusBar::SetPaneWidth(int nPane, int nWidth)
{
	// ���� ���� ������ ��´�
	int nPanes = GetStatusBarCtrl().GetParts(0, NULL);
	// ���� ���� �ε����� ��ȿ���� �ʴٸ� ����
	if(nPane >= nPanes)			return 0;

	UINT nID, nStyle;
	int nOldWidth;

	// ������ ������ ��´�
	GetPaneInfo(nPane, nID, nStyle, nOldWidth);
	// ������ �������� �� �Ӽ����� �� �Ӽ����� �ٲپ� �����Ѵ�
	SetPaneInfo(nPane, nID, nStyle, nWidth);

	// ���� ���� �����Ѵ�
	return nOldWidth;
}

// Ư�� �ε����� ��Ʈ�� ���� ����ü�� �����ϴ� �Լ�
SControlPane* CControlStatusBar::GetControlPane(int nPane)
{
	int i, nSize = m_ControlArray.GetSize();
	SControlPane *pPane;

	// ��� ��Ʈ�� ���� �迭�� ���� �˻��Ѵ�
	for(i = 0; i < nSize; i++)
	{
		// ��Ʈ�� ���� ����ü�� ��´�
		pPane = m_ControlArray.GetAt(i);
		// ���� ������ �ε����� �����ϴٸ� �ش� ����ü �����͸� �����Ѵ�
		if(pPane->nPane == nPane)		return pPane;
	}	

	// ã�� ���Ͽ��� ��� NULL�� �����Ѵ�
	return NULL;
}

// Ư�� ID�� ��Ʈ�� ���� ����ü�� �����ϴ� �Լ�
SControlPane* CControlStatusBar::GetControlPane(UINT nID)
{
	int i, nSize = m_ControlArray.GetSize();
	SControlPane *pPane;

	// ��� ��Ʈ�� ���� �迭�� ���� �˻��Ѵ�
	for(i = 0; i < nSize; i++)
	{
		// ��Ʈ�� ���� ����ü�� ��´�
		pPane = m_ControlArray.GetAt(i);
		// ���� ������ ID�� �����ϴٸ� �ش� ����ü �����͸� �����Ѵ�
		if(pPane->nID == nID)		return pPane;
	}

	// ã�� ���Ͽ��� ��� NULL�� �����Ѵ�
	return NULL;
}

void CControlStatusBar::OnSize(UINT nType, int cx, int cy) 
{
	CStatusBar::OnSize(nType, cx, cy);

	// ���¹��� ũ�Ⱑ ����Ǿ��� ��� ��Ʈ�ѵ��� ���ġ�Ѵ�
	RepositionAll();
}

void CControlStatusBar::OnDestroy() 
{
	CStatusBar::OnDestroy();

	// ���¹ٰ� ������ν� �Ҹ�� ��
	// ��� ��Ʈ�� �迭�� ����
	int i, nSize = m_ControlArray.GetSize();
	SControlPane *pPane;

	for(i = 0; i < nSize; i++)
	{
		// ��Ʈ�� ���� ����ü�� ��´�
		pPane = m_ControlArray.GetAt(i);

		// ���� ��Ʈ���� ������ν� �����Ǿ� �ִٸ�
		if(pPane->pWnd->m_hWnd)
			// ��Ʈ���� ������ν� �Ҹ��Ų��
			pPane->pWnd->DestroyWindow();
	}
}
