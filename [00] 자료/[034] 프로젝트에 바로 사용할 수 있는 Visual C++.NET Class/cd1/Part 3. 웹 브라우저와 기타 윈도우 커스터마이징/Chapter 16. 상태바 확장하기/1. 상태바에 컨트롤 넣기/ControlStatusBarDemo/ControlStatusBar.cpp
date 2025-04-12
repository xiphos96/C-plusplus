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
	// 컨트롤 페인 구조체 배열을 초기화한다
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

// 새로운 페인에 컨트롤을 추가하는 함수
int CControlStatusBar::InsertControlPane(LPCTSTR pText, CONTROL_TYPE nType, UINT nID, int nPane, int nWidth)
{
	CWnd *pWnd;

	// 추가할 컨트롤의 타입에 따라
	switch(nType)
	{
	case CONTROL_STATIC:
		// 스태틱 객체를 생성한다
		pWnd = new CStatic;
		// 윈도우로써 생성한다
		((CStatic*)pWnd)->Create(pText, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, nID);
		break;
	case CONTROL_EDIT:
		// 에디트 박스 객체를 생성한다
		pWnd = new CEdit;
		// 윈도우로써 생성한다
		((CEdit*)pWnd)->Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, nID);
		break;
	case CONTROL_BUTTON:
		// 버튼 객체를 생성한다
		pWnd = new CButton;
		// 윈도우로써 생성한다
		((CButton*)pWnd)->Create(pText, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON , CRect(0, 0, 0, 0), this, nID);
		break;
	case CONTROL_CHECK:
		// 체크 박스 객체를 생성한다
		pWnd = new CButton;
		// 윈도우로써 생성한다
		((CButton*)pWnd)->Create(pText, WS_CHILD | WS_VISIBLE | BS_CHECKBOX, CRect(0, 0, 0, 0), this, nID);
		break;
	case CONTROL_PROGRESS:
		// 프로그래스바 객체를 생성한다
		pWnd = new CProgressCtrl;
		// 윈도우로써 생성한다
		((CProgressCtrl*)pWnd)->Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, nID);
		break;
	default:
		// 정의되지 않은 컨트롤은 실패로 리턴한다
		return 0;
	}

	// 컨트롤에 상태바의 폰트를 설정한다
	pWnd->SetFont(GetFont());

	// 페인을 생성하고 컨트롤을 설정한다
	int nPanes = InsertControlPane(pWnd, nID, nPane, nWidth);

	// 만약 컨트롤 페인 생성에 실패하면
	if(nPanes == 0)
	{
		// 생성하였던 컨트롤을 제거한다
		pWnd->DestroyWindow();
		delete pWnd;
	}

	// 현재 페인 갯수를 리턴한다
	return nPanes;
}

// 새로운 페인에 컨트롤을 추가하는 함수
int CControlStatusBar::InsertControlPane(CWnd *pWnd, UINT nID, int nPane, int nWidth)
{
	// 현재 페인 갯수를 얻는다
	int nPanes = GetStatusBarCtrl().GetParts(0, NULL);
	// 만약 페인 인덱스가 유효하지 않다면 리턴
	if(nPanes < nPane)					return 0;

	// 모든 컨트롤 페인 배열에 대해
	SControlPane *pPane;
	int i, nSize = m_ControlArray.GetSize();

	for(i = 0; i < nSize; i++)
	{
		pPane = m_ControlArray.GetAt(i);

		// 동일한 ID의 페인이 존재한다면
		if(pPane->nID == nID)
		{
			// 이전에 인덱스 번호를 조정했던 페인의 인덱스를 되돌린다
			for(i -= 1; i >= 0; i--)
			{
				pPane = m_ControlArray.GetAt(i);
				if(pPane->nPane > nPane)	pPane->nPane -= 1;
			}

			// 실패로 리턴한다
			return 0;
		}
		// 만약 페인 인덱스가 추가할 위치 이후라면 인덱스를 1 증가시킨다
		if(pPane->nPane >= nPane)		pPane->nPane += 1;
	}

	// 컨트롤 페인 구조체를 생성하고 값을 설정한다
	pPane					= new SControlPane;
	pPane->pWnd				= pWnd;
	pPane->nID				= nID;
	pPane->nPane			= nPane;
	pPane->strText			= "";

	// 컨트롤 페인 배열에 추가한다
	m_ControlArray.Add(pPane);

	UINT *pIDs		= new UINT[nPanes + 1];
	UINT *pStyles	= new UINT[nPanes + 1];
	int *pWidth		= new int[nPanes + 1];
	CString *pTexts = new CString[nPanes + 1];

	// 현재 상태바의 각 페인 정보를 얻는다
	for(i = 0; i < nPanes + 1; i++)
	{
		// 추가될 위치 앞의 값은 그대로 저장한다
		if(i < nPane)
		{
			GetPaneInfo(i, pIDs[i], pStyles[i], pWidth[i]);
			pTexts[i] = GetPaneText(i);
		}
		else
		{
			// 추가될 위치에는 새로 생성된 페인 정보로 설정한다
			if(i == nPane)
			{
				pIDs[i]		= nID;
				pStyles[i]	= SBPS_NORMAL;
				pWidth[i]	= nWidth;
				pTexts[i]	= "";
			}
			else
			{
				// 추가될 위치 이후의 페인들은 새로 생성된 페인 정보 뒤에 추가한다
				GetPaneInfo(i - 1, pIDs[i], pStyles[i], pWidth[i]);
				pTexts[i] = GetPaneText(i - 1);
			}
		}
	}

	// 상태바의 페인을 다시 생성한다
	SetIndicators(pIDs, nPanes + 1);

	// 새로 생성된 페인들의 속성을 이전 속성과 동일하게 설정한다
	for(i = 0; i < nPanes + 1; i++)
	{
		SetPaneInfo(i, pIDs[i], pStyles[i], pWidth[i]);
		SetPaneText(i, pTexts[i]);
	}

	// 메모리를 제거한다
	delete[] pIDs;
	delete[] pStyles;
	delete[] pWidth;
	delete[] pTexts;

	// 총 페인 갯수를 리턴한다
	return nPanes + 1;
}

// 컨트롤 페인을 삭제하는 함수
int CControlStatusBar::RemoveControlPane(int nPane)
{
	// 현재 페인 갯수를 얻는다
	int nPanes = GetStatusBarCtrl().GetParts(0, NULL);

	// 만약 페인 인덱스가 유효하지 않다면 리턴
	if(nPanes <= nPane)		return 0;

	// 모든 컨트롤 페인 배열에 대해 검색
	SControlPane *pPane;
	int i, nSize = m_ControlArray.GetSize();

	for(i = 0; i < nSize; i++)
	{
		pPane = m_ControlArray.GetAt(i);

		// 해당 페인 인덱스의 컨트롤 페인에 대해
		if(pPane->nPane == nPane)
		{
			// 만약 삭제될 페인의 컨트롤이 생성되어 있다면 소멸시킨다
			if(pPane->pWnd->m_hWnd)		pPane->pWnd->DestroyWindow();
			// 컨트롤 페인 구조체를 삭제한다
			delete pPane;

			// 삭제 페인의 구조체를 배열에서 삭제한다
			m_ControlArray.RemoveAt(i--);
			nSize--;
		}
		else
			if(pPane->nPane > nPane)
			{
				// 삭제될 페인의 뒤에 있는 페인은 페인 번호를 감소 시킨다
				pPane->nPane--;
			}
	}

	UINT *pIDs		= new UINT[nPanes - 1];
	UINT *pStyles	= new UINT[nPanes - 1];
	int *pWidth		= new int[nPanes - 1];
	CString *pTexts = new CString[nPanes - 1];

	// 현재 상태바의 각 페인 정보를 얻는다
	for(i = 0; i < nPanes; i++)
	{
		// 추가될 위치 앞의 값은 그대로 저장한다
		if(i < nPane)
		{
			GetPaneInfo(i, pIDs[i], pStyles[i], pWidth[i]);
			pTexts[i] = GetPaneText(i);
		}
		else
		{
			// 추가될 위치 이후의 페인들을 삭제 페인 위치로 이동한다
			if(i > nPane)
			{
				GetPaneInfo(i, pIDs[i - 1], pStyles[i - 1], pWidth[i - 1]);
				pTexts[i - 1] = GetPaneText(i);
			}
		}
	}

	// 상태바의 페인을 다시 생성한다
	SetIndicators(pIDs, nPanes - 1);

	// 새로 생성된 페인들의 속성을 이전 속성과 동일하게 설정한다
	for(i = 0; i < nPanes - 1; i++)
	{
		SetPaneInfo(i, pIDs[i], pStyles[i], pWidth[i]);
		SetPaneText(i, pTexts[i]);
	}

	// 메모리를 제거한다
	delete[] pIDs;
	delete[] pStyles;
	delete[] pWidth;
	delete[] pTexts;

	// 총 페인 갯수를 리턴한다
	return nPanes - 1;
}

// 상태바의 컨트롤들의 위치를 재조정하는 함수
void CControlStatusBar::RepositionAll()
{
	int nHorz, nVert, nSpace, i, nSize = m_ControlArray.GetSize();
	UINT nStyle;
	CRect rcPane;
	SControlPane *pPane;

	// 현재 상태바의 테두리 속성을 얻는다
	GetStatusBarCtrl().GetBorders(nHorz, nVert, nSpace);

	// 모든 컨트롤 페인들에 대해
	for(i = 0; i < nSize; i++)
	{
		// 컨트롤 페인 구조체 정보를 얻는다
		pPane = m_ControlArray.GetAt(i);

		// 해당 페인의 사각 영역을 얻는다
		GetItemRect(pPane->nPane, rcPane);
		// 해당 페인의 스타일을 얻는다
		nStyle = GetPaneStyle(pPane->nPane);

		// 만약 테두리를 사용한다면
		if(!(nStyle & SBPS_NOBORDERS))
			// 테두리만큼 사각 영역을 조정한다
			rcPane.DeflateRect(nHorz + nSpace, nVert);

		// 페인 위치로 컨트롤을 옮긴다
		pPane->pWnd->MoveWindow(rcPane);
	}
}

// 특정 페인의 폭을 설정하는 함수
int CControlStatusBar::SetPaneWidth(int nPane, int nWidth)
{
	// 현재 페인 갯수를 얻는다
	int nPanes = GetStatusBarCtrl().GetParts(0, NULL);
	// 만약 페인 인덱스가 유효하지 않다면 리턴
	if(nPane >= nPanes)			return 0;

	UINT nID, nStyle;
	int nOldWidth;

	// 페인의 정보를 얻는다
	GetPaneInfo(nPane, nID, nStyle, nOldWidth);
	// 페인의 정보에서 폭 속성만을 새 속성으로 바꾸어 설정한다
	SetPaneInfo(nPane, nID, nStyle, nWidth);

	// 이전 폭을 리턴한다
	return nOldWidth;
}

// 특정 인덱스의 컨트롤 페인 구조체를 리턴하는 함수
SControlPane* CControlStatusBar::GetControlPane(int nPane)
{
	int i, nSize = m_ControlArray.GetSize();
	SControlPane *pPane;

	// 모든 컨트롤 페인 배열에 대해 검색한다
	for(i = 0; i < nSize; i++)
	{
		// 컨트롤 페인 구조체를 얻는다
		pPane = m_ControlArray.GetAt(i);
		// 만약 페인의 인덱스가 동일하다면 해당 구조체 포인터를 리턴한다
		if(pPane->nPane == nPane)		return pPane;
	}	

	// 찾지 못하였을 경우 NULL을 리턴한다
	return NULL;
}

// 특정 ID의 컨트롤 페인 구조체를 리턴하는 함수
SControlPane* CControlStatusBar::GetControlPane(UINT nID)
{
	int i, nSize = m_ControlArray.GetSize();
	SControlPane *pPane;

	// 모든 컨트롤 페인 배열에 대해 검색한다
	for(i = 0; i < nSize; i++)
	{
		// 컨트롤 페인 구조체를 얻는다
		pPane = m_ControlArray.GetAt(i);
		// 만약 페인의 ID가 동일하다면 해당 구조체 포인터를 리턴한다
		if(pPane->nID == nID)		return pPane;
	}

	// 찾지 못하였을 경우 NULL을 리턴한다
	return NULL;
}

void CControlStatusBar::OnSize(UINT nType, int cx, int cy) 
{
	CStatusBar::OnSize(nType, cx, cy);

	// 상태바의 크기가 변경되었을 경우 컨트롤들을 재배치한다
	RepositionAll();
}

void CControlStatusBar::OnDestroy() 
{
	CStatusBar::OnDestroy();

	// 상태바가 윈도우로써 소멸될 때
	// 모든 컨트롤 배열에 대해
	int i, nSize = m_ControlArray.GetSize();
	SControlPane *pPane;

	for(i = 0; i < nSize; i++)
	{
		// 컨트롤 페인 구조체를 얻는다
		pPane = m_ControlArray.GetAt(i);

		// 만약 컨트롤이 윈도우로써 생성되어 있다면
		if(pPane->pWnd->m_hWnd)
			// 컨트롤을 윈도우로써 소멸시킨다
			pPane->pWnd->DestroyWindow();
	}
}
