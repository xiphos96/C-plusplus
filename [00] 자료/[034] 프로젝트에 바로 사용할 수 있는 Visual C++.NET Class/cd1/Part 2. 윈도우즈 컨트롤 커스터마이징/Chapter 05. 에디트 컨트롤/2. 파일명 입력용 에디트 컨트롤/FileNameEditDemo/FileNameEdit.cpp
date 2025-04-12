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

// ����/���� ���� ��ư�� ���ҽ� ID
#define ID_FILENAMEEDIT_BROWSE_BTN		100

CFileNameEdit::CFileNameEdit()
{
	// �ʱ⿡�� ���� ����, �б������� �ƴ� ���·� �ʱ�ȭ
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
	// SetRect()�� ����ϱ� ���ؼ��� �ݵ�� Multiline �Ӽ��� �����Ǿ�� �Ѵ�
	// �ڵ�δ� ��ǻ� �������� �ʴ´�
	// ���ҽ� �����Ϳ��� �����ؾ� �Ѵ�
	ModifyStyle(0, ES_MULTILINE);

	// ���� �б� ���� ������� Ȯ���Ѵ�
	m_bIsReadOnly = GetStyle() & ES_READONLY;

	// ����Ʈ ��Ʈ���� Ŭ���̾�Ʈ ũ�⸦ ��´�
	GetClientRect(&m_rcEntireArea);

	// ��ư�� ��ġ��, ��ư�� ������ ���� ���� ������ ����Ѵ�
	m_rcButton = m_rcClipArea = m_rcEntireArea;
	m_rcClipArea.right -= CONST_BROWSE_BTN_WIDTH + 1;
	m_rcButton.left = m_rcClipArea.right + 1;

	// ��ư�� �����Ѵ�
	m_btnBrowse.Create("", WS_CHILD | BS_OWNERDRAW,
		m_rcButton, this, ID_FILENAMEEDIT_BROWSE_BTN);

	CEdit::PreSubclassWindow();
}

void CFileNameEdit::OnSize(UINT nType, int cx, int cy) 
{
	CEdit::OnSize(nType, cx, cy);

	// ���� ������� ������ ���¶��
	if(IsWindowVisible() && m_btnBrowse.m_hWnd)
	{
		// ����Ʈ ��Ʈ���� Ŭ���̾�Ʈ ũ�⸦ �ٽ� ��´�
		GetClientRect(&m_rcEntireArea);

		// ���� ������ ��ư�� ��ġ�� �ٽ� ����Ѵ�
		m_rcButton = m_rcClipArea = m_rcEntireArea;
		m_rcClipArea.right -= CONST_BROWSE_BTN_WIDTH + 1;
		m_rcButton.left = m_rcClipArea.right + 1;

		// ��ư�� ũ��� ��ġ�� �����Ѵ�
		m_btnBrowse.SetWindowPos(NULL, m_rcButton.left, m_rcButton.top,
			m_rcButton.Width(), m_rcButton.Height(), SWP_NOZORDER);
	}
}

void CFileNameEdit::OnEnable(BOOL bEnable) 
{
	CEdit::OnEnable(bEnable);

	// Ȱ��ȭ ���ο� ���� ��ư�� �����ϰ� ó���Ѵ�
	m_btnBrowse.EnableWindow(bEnable);
}

void CFileNameEdit::OnDestroy() 
{
	CEdit::OnDestroy();

	// ��ư �����츦 �Ҹ��Ų��
	m_btnBrowse.DestroyWindow();
}

void CFileNameEdit::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���� ��ư�� ��µ��� �ʰ� �ִ� �����̸�
	if(!m_btnBrowse.IsWindowVisible())
	{
		// ���� ������ ���̰� 
		SetRect(m_rcClipArea);

		// ���� �б� ���� ����̸�
		if(m_bIsReadOnly)
			// ª�� ��θ� ����Ʈ ��Ʈ�ѿ� �����Ѵ�
			SetShortText(m_strLongPath);

		// ��ư�� ȭ�鿡 ����Ѵ�
		m_btnBrowse.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
	}

	BOOL bCapture = FALSE, bInEdit;

	// ���콺 �̺�Ʈ�� ����Ʈ ��Ʈ���� ĸ���ϰ� �ִ��� Ȯ���Ѵ�
	if(GetCapture())
		if(GetCapture()->m_hWnd == m_hWnd)	bCapture = TRUE;

	// ���콺�� ���� ���� �ȿ� �ִ��� Ȯ���Ѵ�
	bInEdit = m_rcClipArea.PtInRect(point);

	// ���� ����Ʈ ��Ʈ���� ���콺 �̺�Ʈ�� ĸ���ϰ� �ְ�
	if(bCapture)
	{
		// ���� ���� �ۿ� ���콺�� �ִٸ�
		if(!bInEdit)
		{
			// ���콺 �̺�Ʈ ĸ�縦 �����
			ReleaseCapture();

			// ���� ���콺�� ��ư ���� �ȿ� �ִٸ�
			if(m_rcButton.PtInRect(point))
			{
				// ��ư�� ���콺 �̺�Ʈ�� ĸ���ϰ� �Ѵ�
				m_btnBrowse.SetCapture();
				// ���콺 Ŀ���� �ٲٵ��� �Ѵ�
				m_btnBrowse.SendMessage(WM_SETCURSOR);
			}
			else
			{
				// ���� ���콺�� ��ư ���� �ȿ��� ���ٸ�
				// ��ư�� �����
				m_btnBrowse.ShowWindow(SW_HIDE);
				// ���� ������ �����Ѵ�
				RestoreArea();
			}
		}
	}
	else
	{
		// ���� ����Ʈ ��Ʈ���� ���콺 �̺�Ʈ�� ĸ������ �ʰ�
		// ���콺�� ���� ���� �ȿ� �ִٸ�
		if(bInEdit)
		{
			// ����Ʈ ��Ʈ���� ���콺 �̺�Ʈ�� ĸ���Ѵ�
			SetCapture();
		}
		else
		{
			// ���콺�� ���� ���� �ۿ� �ְ�
			// ��ư ���� �ȿ� �ִٸ�
			if(m_rcButton.PtInRect(point))
			{
				// ��ư�� ���콺 �̺�Ʈ�� ĸ���ϰ� �Ѵ�
				m_btnBrowse.SetCapture();
				// ���콺 Ŀ���� �ٲٵ��� �Ѵ�
				m_btnBrowse.SendMessage(WM_SETCURSOR);
			}
		}
	}

	CEdit::OnMouseMove(nFlags, point);
}

// ����Ʈ ��Ʈ���� ���� ������ ��ü Ŭ���̾�Ʈ�� �����ϴ� �Լ�
void CFileNameEdit::RestoreArea()
{
	// ���� ������ ��ü Ŭ���̾�Ʈ �������� �����Ѵ�
	SetRect(m_rcEntireArea);

	// ���� �б� ���� ����̸�
	if(m_bIsReadOnly)
		// ª�� ��θ� ����Ʈ ��Ʈ�ѿ� �����Ѵ�
		SetShortText(m_strLongPath);
}

// ���� ���� ��ȭ���ڿ��� �ʱ� ������ ���� ��Ű�� ���� �Լ�
int CALLBACK FolderSelectProc(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	// ���� ���� ��ȭ���� �ʱ�ȭ ���¶��
	if(uMsg == BFFM_INITIALIZED)
		// �ʱ� ������ ���� ��Ų��
		::SendMessage(hWnd, BFFM_SETSELECTION, TRUE, lpData);

	return 0;
}

// ����/���� ���� ��ȭ���ڸ� ����ϴ� �Լ�
void CFileNameEdit::OnBrowse()
{
	// ���� ���� ��ζ��
	if(m_bIsFileMode)
	{
		// ���� ���� ���̾�α׸� ����
		CFileDialog dlg(TRUE);

		dlg.m_ofn.hwndOwner = m_hWnd;

		if(dlg.DoModal() == IDOK)
		{
			CString strFile;

			// ���õ� ���ϵ��� ���ڿ��� �߰��Ѵ�
			POSITION pos = dlg.GetStartPosition();
			strFile += dlg.GetNextPathName(pos);

			while(pos)
			{
				strFile += "; " + dlg.GetNextPathName(pos);
			}

			// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����Ѵ�
			SetWindowText(strFile);
		}
	}
	else
	{
		CString strPath, strCurrent;

		// ���� ��θ� ��´�
		GetWindowText(strCurrent);
		// ª�� ��θ� �����Ѵ�
		if(!PathFileExists(strCurrent))	strCurrent.Empty();

		// ���� ���� ���̾�α� ����ü�� �ʱ�ȭ�Ѵ�
		BROWSEINFO bi;
		::memset(&bi, 0, sizeof(BROWSEINFO));

		bi.hwndOwner		= m_hWnd;
		bi.lpszTitle		= "���� ����";
		bi.ulFlags			= BIF_RETURNONLYFSDIRS;
		bi.lpfn				= FolderSelectProc;
		bi.lParam			= (LPARAM)(LPCTSTR)strCurrent;	// �ʱ� ���� ����

		// ���� ���� ���̾�α׸� ����
		ITEMIDLIST *idl = ::SHBrowseForFolder(&bi);

		// ���õ� ������ �ִٸ�
		if(idl)
		{
			// ���� ��θ� ��´�
			::SHGetPathFromIDList(idl, strPath.GetBuffer(MAX_PATH));
			strPath.ReleaseBuffer();

			// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����Ѵ�
			SetWindowText(strPath);
		}
	}
}

// ª�� ��θ� ����Ʈ ��Ʈ�ѿ� �����ϴ� �Լ�
void CFileNameEdit::SetShortText(LPCTSTR lpszString)
{
	// ���� �б������� �ƴ϶�� ����
	if(!m_bIsReadOnly)		return;

	CString strShortText = lpszString;
	// ���ο� ���� ��� ������ �����Ѵ�
	m_strLongPath = lpszString;

	// ���� ���� ������ ũ�⸦ ��´�
	CRect rcRect;
	GetRect(&rcRect);

	// DC�� ��� ���� ������ ��Ʈ�� �����Ѵ�
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());

	// ���� ������ ���� ���� ª�� ��θ� �����Ѵ�
	::PathCompactPath(pDC->m_hDC, strShortText.GetBuffer(MAX_PATH), rcRect.Width());
	strShortText.ReleaseBuffer();

	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);

	// ����Ʈ ��Ʈ�ѿ� �����Ѵ�
	CWnd::SetWindowText(strShortText);
}

// �б� ���� ���ο� ���� ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϴ� �Լ�
int CFileNameEdit::GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const
{
	// ���� �б������̶��
	if(m_bIsReadOnly)
	{
		// ���� �� ����� ���ڿ� ���̸�ŭ ���۰� Ȯ���Ǿ����� Ȯ���Ѵ�
		if(m_strLongPath.GetLength() >= nMaxCount)		return m_strLongPath.GetLength() + 1;
		// �� ��θ� ���ۿ� �����Ѵ�
		strcpy(lpszStringBuf, m_strLongPath);
		// �� ����� ���ڿ� ���̸� �����Ѵ�
		return m_strLongPath.GetLength();
	}
	else
		// CWnd�� GetWindowText()�� �����Ѵ�
		return CWnd::GetWindowText(lpszStringBuf, nMaxCount);
}

// �б� ���� ���ο� ���� ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϴ� �Լ�
void CFileNameEdit::GetWindowText(CString& rString) const
{
	// ���� �б������̶��
	if(m_bIsReadOnly)
		// �� ��θ� ���ۿ� �����Ѵ�
		rString = m_strLongPath;
	else
		// CWnd�� GetWindowText()�� �����Ѵ�
		CWnd::GetWindowText(rString);
}

// �б� ���� ���ο� ���� ����Ʈ ��Ʈ�ѿ� �ؽ�Ʈ�� �����ϴ� �Լ�
void CFileNameEdit::SetWindowText(LPCTSTR lpszString)
{
	// ���� �б������̶��
	if(m_bIsReadOnly)
		// ª�� ��θ� ����Ʈ ��Ʈ�ѿ� �����Ѵ�
		SetShortText(lpszString);
	else
		// CWnd�� SetWindowText()�� �����Ѵ�
		CWnd::SetWindowText(lpszString);
}

// CFileNameEdit�� ����Ͽ� DDX/DDV�� �����ϱ� ���� �Լ�
void AFXAPI DDX_FileName(CDataExchange* pDX, int nIDC, CString& strText)
{
	// DDX/DDV�� �����Ϸ��� ��Ʈ���� �ڵ��� ��´�
	HWND hWnd = pDX->PrepareEditCtrl(nIDC);

	CFileNameEdit FileNameEdit;
	CFileNameEdit *pEdit;

	// �ڵ��� ���� �����͸� ��´�
	CWnd *pWnd = CWnd::FromHandlePermanent(hWnd);

	// �����Ͱ� ������ٸ�
	if(pWnd)
	{
		// CFileNameEdit Ŭ���� �����ͷ� �����Ѵ�
		pEdit = (CFileNameEdit*)pWnd;
	}
	else
	{
		// �ӽ� CFileNameEdit Ŭ���� ������ Attach()�Ѵ�
		FileNameEdit.Attach(hWnd);
		// �ӽ� ������ �����͸� �����Ѵ�
		pEdit = &FileNameEdit;
	}

	// ���� ���� �Ѱ��־�� �Ѵٸ�
	if(pDX->m_bSaveAndValidate)
	{
		// ������ �ؽ�Ʈ�� ��´�
		pEdit->GetWindowText(strText);
	}
	else
	{
		// ����Ʈ ��Ʈ�ѿ� �����Ѵ�
		pEdit->SetWindowText(strText);
	}

	// ���� �ӽ� ������ Attach()�� ���¶��
	if(pWnd == NULL)
	{
		// Detach()�Ѵ�
		FileNameEdit.Detach();
	}
}
