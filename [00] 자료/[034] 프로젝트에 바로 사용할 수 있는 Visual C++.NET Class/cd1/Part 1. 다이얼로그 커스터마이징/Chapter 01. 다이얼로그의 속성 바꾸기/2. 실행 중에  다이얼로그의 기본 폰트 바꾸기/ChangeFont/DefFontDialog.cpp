// DefFontDialog.cpp : implementation file
//

#include "stdafx.h"
#include "changefont.h"
#include "DefFontDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDefFontDialog dialog

// �������� ���� �ݵ�� ��ũ��� �ؾ� �ϴ� ����
#include <afxpriv.h>

CDefFontDialog::CDefFontDialog(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CDefFontDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// �⺻ �� ����
	m_nResourceID = nResourceID;
	m_strFontName = "����ü";
	m_nFontSize = 10;
}


void CDefFontDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDefFontDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDefFontDialog, CDialog)
	//{{AFX_MSG_MAP(CDefFontDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDefFontDialog message handlers

int CDefFontDialog::DoModal() 
{
	CDialogTemplate DlgTemplate;
	INT_PTR             nResult;

	// �⺻ ���̾�α� ���ҽ��� �ε��Ѵ�.
	if (!DlgTemplate.Load(MAKEINTRESOURCE(m_nResourceID))) return -1;

	// ���ο� ��Ʈ�� �����Ѵ�.
	DlgTemplate.SetFont(m_strFontName, m_nFontSize);

	// �޸� ��ġ�� ��ٴ�
	LPSTR pData = (LPSTR)GlobalLock(DlgTemplate.m_hTemplate);

	m_lpszTemplateName = NULL;
	// ���� ������ ���̾�α� ���ҽ��� ����� ��� ���̾�α׸� �ʱ�ȭ�Ѵ�
	InitModalIndirect(pData);

	// ���̾�α׸� ��޷� ����
	nResult = CDialog::DoModal();

	// �޸� ��ġ�� Ǭ��
	GlobalUnlock(DlgTemplate.m_hTemplate);

	return nResult;	
}

LPCTSTR CDefFontDialog::GetFontName()
{
	return LPCTSTR(m_strFontName);
}

void CDefFontDialog::SetFontName(CString strFontName)
{
	m_strFontName = strFontName;
}

int CDefFontDialog::GetFontSize()
{
	return m_nFontSize;
}

void CDefFontDialog::SetFontSize(int nSize)
{
	m_nFontSize = nSize;
}
