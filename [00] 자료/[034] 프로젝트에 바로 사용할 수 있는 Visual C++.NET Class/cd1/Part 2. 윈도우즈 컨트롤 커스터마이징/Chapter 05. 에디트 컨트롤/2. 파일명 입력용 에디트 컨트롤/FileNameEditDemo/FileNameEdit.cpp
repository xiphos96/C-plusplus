// FileNameEdit.cpp : implementation file
//

#include "stdafx.h"
#include "filenameeditdemo.h"
#include "FileNameEdit.h"

#include "Shlwapi.h"
#include ".\filenameedit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileNameEdit

// 파일/폴더 선택 버튼의 리소스 ID
#define ID_FILENAMEEDIT_BROWSE_BTN		100

CFileNameEdit::CFileNameEdit()
{
	// 초기에는 파일 선택, 읽기전용이 아닌 상태로 초기화
	m_bIsFileMode = TRUE;
	m_bIsReadOnly = FALSE;
}

CFileNameEdit::~CFileNameEdit()
{
}


BEGIN_MESSAGE_MAP(CFileNameEdit, CEdit)
	//{{AFX_MSG_MAP(CFileNameEdit)
	ON_WM_SIZE()
	ON_WM_ENABLE()
	ON_WM_DESTROY()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileNameEdit message handlers

void CFileNameEdit::PreSubclassWindow() 
{
	// SetRect()를 사용하기 위해서는 반드시 Multiline 속성이 설정되어야 한다
	// 코드로는 사실상 설정되지 않는다
	// 리소스 에디터에서 설정해야 한다
	ModifyStyle(0, ES_MULTILINE);

	// 현재 읽기 전용 모드인지 확인한다
	m_bIsReadOnly = GetStyle() & ES_READONLY;

	// 에디트 컨트롤의 클라이언트 크기를 얻는다
	GetClientRect(&m_rcEntireArea);

	// 버튼의 위치와, 버튼이 존재할 때의 편집 영역을 계산한다
	m_rcButton = m_rcClipArea = m_rcEntireArea;
	m_rcClipArea.right -= CONST_BROWSE_BTN_WIDTH + 1;
	m_rcButton.left = m_rcClipArea.right + 1;

	// 버튼을 생성한다
	m_btnBrowse.Create("", WS_CHILD | BS_OWNERDRAW,
		m_rcButton, this, ID_FILENAMEEDIT_BROWSE_BTN);

	CEdit::PreSubclassWindow();
}

void CFileNameEdit::OnSize(UINT nType, int cx, int cy) 
{
	CEdit::OnSize(nType, cx, cy);

	// 만약 윈도우로 생성된 상태라면
	if(IsWindowVisible() && m_btnBrowse.m_hWnd)
	{
		// 에디트 컨트롤의 클라이언트 크기를 다시 얻는다
		GetClientRect(&m_rcEntireArea);

		// 편집 영역과 버튼의 위치를 다시 계산한다
		m_rcButton = m_rcClipArea = m_rcEntireArea;
		m_rcClipArea.right -= CONST_BROWSE_BTN_WIDTH + 1;
		m_rcButton.left = m_rcClipArea.right + 1;

		// 버튼의 크기와 위치를 조정한다
		m_btnBrowse.SetWindowPos(NULL, m_rcButton.left, m_rcButton.top,
			m_rcButton.Width(), m_rcButton.Height(), SWP_NOZORDER);
	}
}

void CFileNameEdit::OnEnable(BOOL bEnable) 
{
	CEdit::OnEnable(bEnable);

	// 활성화 여부에 따라 버튼도 동일하게 처리한다
	m_btnBrowse.EnableWindow(bEnable);
}

void CFileNameEdit::OnDestroy() 
{
	CEdit::OnDestroy();

	// 버튼 윈도우를 소멸시킨다
	m_btnBrowse.DestroyWindow();
}

void CFileNameEdit::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 현재 버튼이 출력되지 않고 있는 상태이면
	if(!m_btnBrowse.IsWindowVisible())
	{
		// 편집 영역을 줄이고 
		SetRect(m_rcClipArea);

		// 만약 읽기 전용 모드이면
		if(m_bIsReadOnly)
			// 짧은 경로를 에디트 컨트롤에 설정한다
			SetShortText(m_strLongPath);

		// 버튼을 화면에 출력한다
		m_btnBrowse.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
	}

	BOOL bCapture = FALSE, bInEdit;

	// 마우스 이벤트를 에디트 컨트롤이 캡춰하고 있는지 확인한다
	if(GetCapture())
		if(GetCapture()->m_hWnd == m_hWnd)	bCapture = TRUE;

	// 마우스가 편집 영역 안에 있는지 확인한다
	bInEdit = m_rcClipArea.PtInRect(point);

	// 만약 에디트 컨트롤이 마우스 이벤트를 캡춰하고 있고
	if(bCapture)
	{
		// 편집 영역 밖에 마우스가 있다면
		if(!bInEdit)
		{
			// 마우스 이벤트 캡춰를 멈춘다
			ReleaseCapture();

			// 만약 마우스가 버튼 영역 안에 있다면
			if(m_rcButton.PtInRect(point))
			{
				// 버튼이 마우스 이벤트를 캡춰하게 한다
				m_btnBrowse.SetCapture();
				// 마우스 커서를 바꾸도록 한다
				m_btnBrowse.SendMessage(WM_SETCURSOR);
			}
			else
			{
				// 만약 마우스가 버튼 영역 안에도 없다면
				// 버튼을 감춘다
				m_btnBrowse.ShowWindow(SW_HIDE);
				// 편집 영역을 복원한다
				RestoreArea();
			}
		}
	}
	else
	{
		// 만약 에디트 컨트롤이 마우스 이벤트를 캡춰하지 않고
		// 마우스가 편집 영역 안에 있다면
		if(bInEdit)
		{
			// 에디트 컨트롤이 마우스 이벤트를 캡춰한다
			SetCapture();
		}
		else
		{
			// 마우스가 편집 영역 밖에 있고
			// 버튼 영역 안에 있다면
			if(m_rcButton.PtInRect(point))
			{
				// 버튼이 마우스 이벤트를 캡춰하게 한다
				m_btnBrowse.SetCapture();
				// 마우스 커서를 바꾸도록 한다
				m_btnBrowse.SendMessage(WM_SETCURSOR);
			}
		}
	}

	CEdit::OnMouseMove(nFlags, point);
}

// 에디트 컨트롤의 편집 영역을 전체 클라이언트로 조정하는 함수
void CFileNameEdit::RestoreArea()
{
	// 편집 영역을 전체 클라이언트 영역으로 설정한다
	SetRect(m_rcEntireArea);

	// 만약 읽기 전용 모드이면
	if(m_bIsReadOnly)
		// 짧은 경로를 에디트 컨트롤에 설정한다
		SetShortText(m_strLongPath);
}

// 폴더 선택 대화상자에서 초기 폴더를 선택 시키기 위한 함수
int CALLBACK FolderSelectProc(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	// 폴더 선택 대화상자 초기화 상태라면
	if(uMsg == BFFM_INITIALIZED)
		// 초기 폴더를 선택 시킨다
		::SendMessage(hWnd, BFFM_SETSELECTION, TRUE, lpData);

	return 0;
}

// 파일/폴더 선택 대화상자를 출력하는 함수
void CFileNameEdit::OnBrowse()
{
	// 만약 파일 경로라면
	if(m_bIsFileMode)
	{
		// 파일 선택 다이얼로그를 띄운다
		CFileDialog dlg(TRUE);

		dlg.m_ofn.hwndOwner = m_hWnd;

		if(dlg.DoModal() == IDOK)
		{
			CString strFile;

			// 선택된 파일들을 문자열에 추가한다
			POSITION pos = dlg.GetStartPosition();
			strFile += dlg.GetNextPathName(pos);

			while(pos)
			{
				strFile += "; " + dlg.GetNextPathName(pos);
			}

			// 에디트 컨트롤의 텍스트로 설정한다
			SetWindowText(strFile);
		}
	}
	else
	{
		CString strPath, strCurrent;

		// 현재 경로를 얻는다
		GetWindowText(strCurrent);
		// 짧은 경로를 생성한다
		if(!PathFileExists(strCurrent))	strCurrent.Empty();

		// 폴더 선택 다이얼로그 구조체를 초기화한다
		BROWSEINFO bi;
		::memset(&bi, 0, sizeof(BROWSEINFO));

		bi.hwndOwner		= m_hWnd;
		bi.lpszTitle		= "폴더 선택";
		bi.ulFlags			= BIF_RETURNONLYFSDIRS;
		bi.lpfn				= FolderSelectProc;
		bi.lParam			= (LPARAM)(LPCTSTR)strCurrent;	// 초기 폴더 설정

		// 폴더 선택 다이얼로그를 띄운다
		ITEMIDLIST *idl = ::SHBrowseForFolder(&bi);

		// 선택된 폴더가 있다면
		if(idl)
		{
			// 폴더 경로를 얻는다
			::SHGetPathFromIDList(idl, strPath.GetBuffer(MAX_PATH));
			strPath.ReleaseBuffer();

			// 에디트 컨트롤의 텍스트로 설정한다
			SetWindowText(strPath);
		}
	}
}

// 짧은 경로를 에디트 컨트롤에 설정하는 함수
void CFileNameEdit::SetShortText(LPCTSTR lpszString)
{
	// 만약 읽기전용이 아니라면 리턴
	if(!m_bIsReadOnly)		return;

	CString strShortText = lpszString;
	// 새로운 값을 멤버 변수에 저장한다
	m_strLongPath = lpszString;

	// 현재 편집 영역의 크기를 얻는다
	CRect rcRect;
	GetRect(&rcRect);

	// DC를 얻고 현재 윈도우 폰트를 설정한다
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// 편집 영역의 폭에 맞춰 짧은 경로를 생성한다
	::PathCompactPath(pDC->m_hDC, strShortText.GetBuffer(MAX_PATH), rcRect.Width());
	strShortText.ReleaseBuffer();

	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// 에디트 컨트롤에 설정한다
	CWnd::SetWindowText(strShortText);
}

// 읽기 전용 여부에 따라 에디트 컨트롤의 텍스트를 리턴하는 함수
int CFileNameEdit::GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const
{
	// 만약 읽기전용이라면
	if(m_bIsReadOnly)
	{
		// 현재 긴 경로의 문자열 길이만큼 버퍼가 확보되었는지 확인한다
		if(m_strLongPath.GetLength() >= nMaxCount)		return m_strLongPath.GetLength() + 1;
		// 긴 경로를 버퍼에 설정한다
		strcpy(lpszStringBuf, m_strLongPath);
		// 긴 경로의 문자열 길이를 리턴한다
		return m_strLongPath.GetLength();
	}
	else
		// CWnd의 GetWindowText()를 실행한다
		return CWnd::GetWindowText(lpszStringBuf, nMaxCount);
}

// 읽기 전용 여부에 따라 에디트 컨트롤의 텍스트를 리턴하는 함수
void CFileNameEdit::GetWindowText(CString& rString) const
{
	// 만약 읽기전용이라면
	if(m_bIsReadOnly)
		// 긴 경로를 버퍼에 설정한다
		rString = m_strLongPath;
	else
		// CWnd의 GetWindowText()를 실행한다
		CWnd::GetWindowText(rString);
}

// 읽기 전용 여부에 따라 에디트 컨트롤에 텍스트를 설정하는 함수
void CFileNameEdit::SetWindowText(LPCTSTR lpszString)
{
	// 만약 읽기전용이라면
	if(m_bIsReadOnly)
		// 짧은 경로를 에디트 컨트롤에 설정한다
		SetShortText(lpszString);
	else
		// CWnd의 SetWindowText()를 실행한다
		CWnd::SetWindowText(lpszString);
}

// CFileNameEdit를 사용하여 DDX/DDV를 실행하기 위한 함수
void AFXAPI DDX_FileName(CDataExchange* pDX, int nIDC, CString& strText)
{
	// DDX/DDV를 실행하려는 컨트롤의 핸들을 얻는다
	HWND hWnd = pDX->PrepareEditCtrl(nIDC);

	CFileNameEdit FileNameEdit;
	CFileNameEdit *pEdit;

	// 핸들을 통해 포인터를 얻는다
	CWnd *pWnd = CWnd::FromHandlePermanent(hWnd);

	// 포인터가 얻어졌다면
	if(pWnd)
	{
		// CFileNameEdit 클래스 포인터로 변경한다
		pEdit = (CFileNameEdit*)pWnd;
	}
	else
	{
		// 임시 CFileNameEdit 클래스 변수에 Attach()한다
		FileNameEdit.Attach(hWnd);
		// 임시 변수의 포인터를 설정한다
		pEdit = &FileNameEdit;
	}

	// 만약 값을 넘겨주어야 한다면
	if(pDX->m_bSaveAndValidate)
	{
		// 윈도우 텍스트를 얻는다
		pEdit->GetWindowText(strText);
	}
	else
	{
		// 에디트 컨트롤에 설정한다
		pEdit->SetWindowText(strText);
	}

	// 만약 임시 변수에 Attach()된 상태라면
	if(pWnd == NULL)
	{
		// Detach()한다
		FileNameEdit.Detach();
	}
}
