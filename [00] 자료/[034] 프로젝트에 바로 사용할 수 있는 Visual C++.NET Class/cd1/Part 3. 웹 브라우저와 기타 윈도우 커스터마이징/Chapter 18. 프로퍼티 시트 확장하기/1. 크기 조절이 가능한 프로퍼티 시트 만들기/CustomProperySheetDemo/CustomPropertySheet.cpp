// CustomPropertySheet.cpp : implementation file
//

#include "stdafx.h"
#include "CustomPropertySheet.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomPropertySheet

IMPLEMENT_DYNAMIC(CCustomPropertySheet, CPropertySheet)

CCustomPropertySheet::CCustomPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	m_nCX				= -1;
	m_nCY				= -1;
	m_bUseSystemFont	= TRUE;
	m_bResize			= FALSE;
	m_bInit				= FALSE;
}

CCustomPropertySheet::CCustomPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_nCX				= -1;
	m_nCY				= -1;
	m_bUseSystemFont	= TRUE;
	m_bResize			= FALSE;
	m_bInit				= FALSE;
}

CCustomPropertySheet::~CCustomPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CCustomPropertySheet, CPropertySheet)
	//{{AFX_MSG_MAP(CCustomPropertySheet)
	ON_WM_GETMINMAXINFO()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomPropertySheet message handlers

// ������Ƽ ��Ʈ�� ũ�⸦ �����ϴ� �Լ�
void CCustomPropertySheet::SetSheetSize(int cx, int cy)
{
	if(cx <= 0 || cy <= 0)		return;

	m_nCX = cx;
	m_nCY = cy;
}

// ������Ƽ �������� ��Ʈ�� ���Ͻ�ų ������ �����ϴ� �Լ�
void CCustomPropertySheet::UseSystemFont(BOOL bSystemFont)
{
	m_bUseSystemFont = bSystemFont;
}

// ������Ƽ ��Ʈ�� ũ�⸦ ������ �� �ֵ��� �����ϴ� �Լ�
void CCustomPropertySheet::SetResize(BOOL bResize, int nMinCX, int nMinCY, int nMaxCX, int nMaxCY)
{
	// ũ�� ���� ���� ����
	m_bResize		= bResize;
	// ������Ƽ ��Ʈ�� �ּ� ũ��
	m_MinSize.cx	= nMinCX;
	m_MinSize.cy	= nMinCY;
	// ������Ƽ ��Ʈ�� �ִ� ũ��
	m_MaxSize.cx	= nMaxCX;
	m_MaxSize.cy	= nMaxCY;
}

// ������Ƽ ���������� ��Ʈ �Ӽ��� ����ϱ� ���� ���� �Լ�
void CCustomPropertySheet::BuildPropPageArray()
{
	// ���� �ý��� ��Ʈ�� �״�� ����Ѵٸ�
	// �⺻ ������Ƽ ��Ʈ�� BuildPropPageArray() �Լ��� ȣ���Ѵ�
	if(m_bUseSystemFont)
	{
		CPropertySheet::BuildPropPageArray();
		return;
	}

	// ���� �����ϴ� ������Ƽ ������ �������� �����Ѵ�
	delete[] (PROPSHEETPAGE*)m_psh.ppsp;
	m_psh.ppsp = NULL;

	// ���� ������Ƽ ���������� �����Ѵ�
#if _MSC_VER <= 1200
	// VC++ 6.0������ �ڵ�
	AFX_OLDPROPSHEETPAGE* ppsp = new AFX_OLDPROPSHEETPAGE[m_pages.GetSize()];
#else
	// VC++ .Net������ �ڵ�
	PROPSHEETPAGE* ppsp = new PROPSHEETPAGE[m_pages.GetSize()];
#endif

	// ���� ������Ƽ �������� �������� �� ������Ƽ ������ ������ �����Ѵ�
	CPropertyPage* pPage;
	for(int i = 0; i < m_pages.GetSize(); i++)
	{
		pPage = GetPage(i);
		::memcpy(ppsp + i, &pPage->m_psp, sizeof(pPage->m_psp));
	}

	// ������Ƽ ��Ʈ ������ �����Ѵ�
	m_psh.ppsp = (LPPROPSHEETPAGE)ppsp;
	m_psh.nPages = (int)m_pages.GetSize();
}

BOOL CCustomPropertySheet::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	// ���� ������Ƽ ��Ʈ�� ũ�⸦ ��´�
	GetWindowRect(&m_rcSheet);

	// ���� ���ο� ���̳� ���̰� �����Ǿ��ٸ�
	if(m_nCX > 0 || m_nCY > 0)
	{
		int nDiffX = 0;
		int nDiffY = 0;

		// ���� ���ο� ���� �����Ǿ��ٸ�
		if(m_nCX > 0)
		{
			// ���� ������ ���� ���� ����Ѵ�
			nDiffX = (m_nCX - m_rcSheet.Width()) / 2;
			// ���ο� ��ġ�� ���� �����Ѵ�
			m_rcSheet.left		-= nDiffX;
			m_rcSheet.right		= m_rcSheet.left + m_nCX;
		}
		// ���� ���ο� ���̰� �����Ǿ��ٸ�
		if(m_nCY > 0)
		{
			// ���� ���̿��� ���� ���� ����Ѵ�
			nDiffY = (m_nCY - m_rcSheet.Height()) / 2;
			// ���ο� ��ġ�� ���̸� �����Ѵ�
			m_rcSheet.top		-= nDiffY;
			m_rcSheet.bottom	= m_rcSheet.top + m_nCY;
		}

		// ���ο� ��ġ�� ũ��� ������Ƽ ��Ʈ�� �̵��Ѵ�
		MoveWindow(&m_rcSheet);

		nDiffX *= 2;
		nDiffY *= 2;

		int i;
		CPropertyPage *pPage;
		CRect rcOld, rcNew;

		// ������Ƽ ��Ʈ�� ũ�� ��ȭ�� ����
		// ���� ũ�⵵ �����ϰ� �����Ų��
		CWnd *pChild = GetDlgItem(AFX_IDC_TAB_CONTROL);
		if(pChild)
		{
			pChild->GetWindowRect(&rcOld);
			pChild->SetWindowPos(NULL, 0, 0, rcOld.Width() + nDiffX, rcOld.Height() + nDiffY,
				SWP_NOZORDER | SWP_NOMOVE);
		}

		// ������Ƽ ��Ʈ�� ũ�� ��ȭ�� ����
		// ������Ƽ ���������� ũ�⵵ �����ϰ� �����Ų��
		for(i = 0; i < GetPageCount(); i++)
		{
			pPage = GetPage(i);

			if(::IsWindow(pPage->m_hWnd))
			{
				pPage->GetWindowRect(rcOld);
				pPage->SetWindowPos(NULL, 0, 0, rcOld.Width() + nDiffX, rcOld.Height() + nDiffY,
					SWP_NOZORDER | SWP_NOMOVE);
			}
		}

		// ������Ƽ ��Ʈ�� ũ�� ��ȭ�� ����
		// ��ư�� ��ġ�� �����Ų��
		UINT nButtons[] = { IDOK, IDCANCEL, ID_APPLY_NOW, IDHELP };
		for(i = 0; i < 4; i++)
		{
			pChild = GetDlgItem(nButtons[i]);
			if(pChild)
			{
				pChild->GetWindowRect(&rcOld);
				ScreenToClient(&rcOld);

				rcOld.OffsetRect(nDiffX, nDiffY);
				pChild->MoveWindow(rcOld);
			}
		}
	}

	// OnInitDialog() �Լ��� ȣ��Ǿ����� �����Ѵ�
	m_bInit = TRUE;

	return bResult;
}

void CCustomPropertySheet::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// ���� ũ�� ������ �����ϴٸ�
	if(m_bResize)
	{
		// �ּ� ũ��� �ִ� ũ�⸦ �����Ѵ�
		lpMMI->ptMinTrackSize.x = m_MinSize.cx;
		lpMMI->ptMinTrackSize.y = m_MinSize.cy;
		lpMMI->ptMaxTrackSize.x = m_MaxSize.cx;
		lpMMI->ptMaxTrackSize.y = m_MaxSize.cy;
	}

	CPropertySheet::OnGetMinMaxInfo(lpMMI);
}

void CCustomPropertySheet::OnSize(UINT nType, int cx, int cy) 
{
	// ���� ũ�� ������ �����ϴٸ� �ݵ�� WS_THICKFRAME �Ӽ��� �����Ѵ�
	if(m_bResize)	ModifyStyle(0, WS_THICKFRAME);

	CPropertySheet::OnSize(nType, cx, cy);

	// OnInitDialog() �Լ��� ȣ��� ���Ķ��
	if(m_bInit)
	{
		int nNewWidth = cx;
		int nNewHeight = cy;

		CRect rcOld, rcNew;
		GetWindowRect(&rcNew);

		// ���ο� ũ��� ���� ũ���� ���̸� ����Ѵ�
		int nDiffX = rcNew.Width() - m_rcSheet.Width();
		int nDiffY = rcNew.Height() - m_rcSheet.Height();
		m_rcSheet = rcNew;

		int i;
		CPropertyPage *pPage;

		// ������Ƽ ��Ʈ�� ũ�� ��ȭ�� ����
		// ���� ũ�⵵ �����ϰ� �����Ų��
		CWnd *pChild = GetDlgItem(AFX_IDC_TAB_CONTROL);
		if(pChild)
		{
			pChild->GetWindowRect(&rcOld);
			pChild->SetWindowPos(NULL, 0, 0, rcOld.Width() + nDiffX, rcOld.Height() + nDiffY,
				SWP_NOZORDER | SWP_NOMOVE);
		}

		// ������Ƽ ��Ʈ�� ũ�� ��ȭ�� ����
		// ������Ƽ ���������� ũ�⵵ �����ϰ� �����Ų��
		for(i = 0; i < GetPageCount(); i++)
		{
			pPage = GetPage(i);

			if(::IsWindow(pPage->m_hWnd))
			{
				pPage->GetWindowRect(rcOld);
				pPage->SetWindowPos(NULL, 0, 0, rcOld.Width() + nDiffX, rcOld.Height() + nDiffY,
					SWP_NOZORDER | SWP_NOMOVE);
			}
		}

		// ������Ƽ ��Ʈ�� ũ�� ��ȭ�� ����
		// ��ư�� ��ġ�� �����Ų��
		UINT nButtons[] = { IDOK, IDCANCEL, ID_APPLY_NOW, IDHELP };
		for(i = 0; i < 4; i++)
		{
			pChild = GetDlgItem(nButtons[i]);
			if(pChild)
			{
				pChild->GetWindowRect(&rcOld);
				ScreenToClient(&rcOld);

				rcOld.OffsetRect(nDiffX, nDiffY);
				pChild->MoveWindow(rcOld);
			}
		}
		Invalidate(FALSE);
	}
}
