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

// 프로퍼티 시트의 크기를 설정하는 함수
void CCustomPropertySheet::SetSheetSize(int cx, int cy)
{
	if(cx <= 0 || cy <= 0)		return;

	m_nCX = cx;
	m_nCY = cy;
}

// 프로퍼티 페이지의 폰트를 통일시킬 것인지 설정하는 함수
void CCustomPropertySheet::UseSystemFont(BOOL bSystemFont)
{
	m_bUseSystemFont = bSystemFont;
}

// 프로퍼티 시트의 크기를 조절할 수 있도록 설정하는 함수
void CCustomPropertySheet::SetResize(BOOL bResize, int nMinCX, int nMinCY, int nMaxCX, int nMaxCY)
{
	// 크기 조절 가능 여부
	m_bResize		= bResize;
	// 프로퍼티 시트의 최소 크기
	m_MinSize.cx	= nMinCX;
	m_MinSize.cy	= nMinCY;
	// 프로퍼티 시트의 최대 크기
	m_MaxSize.cx	= nMaxCX;
	m_MaxSize.cy	= nMaxCY;
}

// 프로퍼티 페이지들의 폰트 속성을 사용하기 위한 가상 함수
void CCustomPropertySheet::BuildPropPageArray()
{
	// 만약 시스템 폰트를 그대로 사용한다면
	// 기본 프로퍼티 시트의 BuildPropPageArray() 함수를 호출한다
	if(m_bUseSystemFont)
	{
		CPropertySheet::BuildPropPageArray();
		return;
	}

	// 현재 존재하는 프로퍼티 페이지 정보들을 제거한다
	delete[] (PROPSHEETPAGE*)m_psh.ppsp;
	m_psh.ppsp = NULL;

	// 새로 프로퍼티 페이지들을 생성한다
#if _MSC_VER <= 1200
	// VC++ 6.0에서의 코드
	AFX_OLDPROPSHEETPAGE* ppsp = new AFX_OLDPROPSHEETPAGE[m_pages.GetSize()];
#else
	// VC++ .Net에서의 코드
	PROPSHEETPAGE* ppsp = new PROPSHEETPAGE[m_pages.GetSize()];
#endif

	// 현재 프로퍼티 페이지의 정보들을 새 프로퍼티 페이지 정보에 복사한다
	CPropertyPage* pPage;
	for(int i = 0; i < m_pages.GetSize(); i++)
	{
		pPage = GetPage(i);
		::memcpy(ppsp + i, &pPage->m_psp, sizeof(pPage->m_psp));
	}

	// 프로퍼티 시트 정보에 설정한다
	m_psh.ppsp = (LPPROPSHEETPAGE)ppsp;
	m_psh.nPages = (int)m_pages.GetSize();
}

BOOL CCustomPropertySheet::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	// 현재 프로퍼티 시트의 크기를 얻는다
	GetWindowRect(&m_rcSheet);

	// 만약 새로운 폭이나 높이가 설정되었다면
	if(m_nCX > 0 || m_nCY > 0)
	{
		int nDiffX = 0;
		int nDiffY = 0;

		// 만약 새로운 폭이 설정되었다면
		if(m_nCX > 0)
		{
			// 현재 폭과의 차이 값을 계산한다
			nDiffX = (m_nCX - m_rcSheet.Width()) / 2;
			// 새로운 위치와 폭을 설정한다
			m_rcSheet.left		-= nDiffX;
			m_rcSheet.right		= m_rcSheet.left + m_nCX;
		}
		// 만약 새로운 높이가 설정되었다면
		if(m_nCY > 0)
		{
			// 현재 높이와의 차이 값을 계산한다
			nDiffY = (m_nCY - m_rcSheet.Height()) / 2;
			// 새로운 위치와 높이를 설정한다
			m_rcSheet.top		-= nDiffY;
			m_rcSheet.bottom	= m_rcSheet.top + m_nCY;
		}

		// 새로운 위치와 크기로 프로퍼티 시트를 이동한다
		MoveWindow(&m_rcSheet);

		nDiffX *= 2;
		nDiffY *= 2;

		int i;
		CPropertyPage *pPage;
		CRect rcOld, rcNew;

		// 프로퍼티 시트의 크기 변화에 따라
		// 탭의 크기도 동일하게 변경시킨다
		CWnd *pChild = GetDlgItem(AFX_IDC_TAB_CONTROL);
		if(pChild)
		{
			pChild->GetWindowRect(&rcOld);
			pChild->SetWindowPos(NULL, 0, 0, rcOld.Width() + nDiffX, rcOld.Height() + nDiffY,
				SWP_NOZORDER | SWP_NOMOVE);
		}

		// 프로퍼티 시트의 크기 변화에 따라
		// 프로퍼티 페이지들의 크기도 동일하게 변경시킨다
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

		// 프로퍼티 시트의 크기 변화에 따라
		// 버튼의 위치도 변경시킨다
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

	// OnInitDialog() 함수가 호출되었음을 저장한다
	m_bInit = TRUE;

	return bResult;
}

void CCustomPropertySheet::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// 만약 크기 조정이 가능하다면
	if(m_bResize)
	{
		// 최소 크기와 최대 크기를 설정한다
		lpMMI->ptMinTrackSize.x = m_MinSize.cx;
		lpMMI->ptMinTrackSize.y = m_MinSize.cy;
		lpMMI->ptMaxTrackSize.x = m_MaxSize.cx;
		lpMMI->ptMaxTrackSize.y = m_MaxSize.cy;
	}

	CPropertySheet::OnGetMinMaxInfo(lpMMI);
}

void CCustomPropertySheet::OnSize(UINT nType, int cx, int cy) 
{
	// 만약 크기 조정이 가능하다면 반드시 WS_THICKFRAME 속성을 설정한다
	if(m_bResize)	ModifyStyle(0, WS_THICKFRAME);

	CPropertySheet::OnSize(nType, cx, cy);

	// OnInitDialog() 함수가 호출된 이후라면
	if(m_bInit)
	{
		int nNewWidth = cx;
		int nNewHeight = cy;

		CRect rcOld, rcNew;
		GetWindowRect(&rcNew);

		// 새로운 크기와 이전 크기의 차이를 계산한다
		int nDiffX = rcNew.Width() - m_rcSheet.Width();
		int nDiffY = rcNew.Height() - m_rcSheet.Height();
		m_rcSheet = rcNew;

		int i;
		CPropertyPage *pPage;

		// 프로퍼티 시트의 크기 변화에 따라
		// 탭의 크기도 동일하게 변경시킨다
		CWnd *pChild = GetDlgItem(AFX_IDC_TAB_CONTROL);
		if(pChild)
		{
			pChild->GetWindowRect(&rcOld);
			pChild->SetWindowPos(NULL, 0, 0, rcOld.Width() + nDiffX, rcOld.Height() + nDiffY,
				SWP_NOZORDER | SWP_NOMOVE);
		}

		// 프로퍼티 시트의 크기 변화에 따라
		// 프로퍼티 페이지들의 크기도 동일하게 변경시킨다
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

		// 프로퍼티 시트의 크기 변화에 따라
		// 버튼의 위치도 변경시킨다
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
