// ResizeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resizedialog.h"
#include "ResizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResizeDlg dialog


CResizeDlg::CResizeDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CResizeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CResizeDlg::~CResizeDlg()
{
	// �ڽ� ������鿡 ���� �ɼ� �Ҹ�
	int i, nSize = m_ChildArray.GetSize();
	for(i = 0; i < nSize; i++)
	{
		delete m_ChildArray.GetAt(i);
	}
	m_ChildArray.RemoveAll();
}

void CResizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResizeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResizeDlg, CDialog)
	//{{AFX_MSG_MAP(CResizeDlg)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResizeDlg message handlers

// �ڽ� �����쿡 ���� �ɼ� �ʱ�ȭ �Լ�
BOOL CALLBACK EnumChildProc(HWND hChild, LPARAM lParam)
{
	CResizeDlg *pParent = (CResizeDlg*)lParam;
	LPCHILDRESIZE pChildType = new CHILDRESIZE;

	CRect rcChild;
	::GetWindowRect(hChild, &rcChild);
	pParent->ScreenToClient(&rcChild);

	// �ʱ� ���� ����
	pChildType->hChild		= hChild;
	pChildType->dPosX1		= double(rcChild.left) / pParent->m_rcClient.Width();
	pChildType->dPosY1		= double(rcChild.top) / pParent->m_rcClient.Height();
	pChildType->dPosX2		= double(rcChild.right) / pParent->m_rcClient.Width();
	pChildType->dPosY2		= double(rcChild.bottom) / pParent->m_rcClient.Height();
	pChildType->nResizeType = RE_NONE;

	// �迭�� �߰�
	pParent->m_ChildArray.Add(pChildType);

	return TRUE;
}

BOOL CResizeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// �ʱ� ���̾�α� ũ�� ����
	GetClientRect(&m_rcClient);

	// �ڽ� ��������� ã�ư��� �ɼ� �ʱ�ȭ
	::EnumChildWindows(m_hWnd, EnumChildProc, (LPARAM)this);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// ��� �ڽ� ��������� ���ġ���� �ʵ��� �ʱ�ȭ
BOOL CResizeDlg::Reset()
{
	int i, nSize = m_ChildArray.GetSize();
	LPCHILDRESIZE pChild;

	// ��� �ڽ� ������鿡 ����
	for(i = 0; i < nSize; i++)
	{
		pChild = m_ChildArray.GetAt(i);
		// ���ġ ���� �Ӽ� ����
		pChild->nResizeType = RE_NONE;
	}

	// ȭ�鿡 ���ġ
	if(::IsWindow(m_hWnd))		RepositionAll();

	return TRUE;
}

// ��� �ڽ� ��������� ������� ���ġ�ϵ��� �ʱ�ȭ
BOOL CResizeDlg::SetAll()
{
	int i, nSize = m_ChildArray.GetSize();
	LPCHILDRESIZE pChild;

	// ��� �ڽ� ������鿡 ����
	for(i = 0; i < nSize; i++)
	{
		pChild = m_ChildArray.GetAt(i);
		// ������� ���ġ �Ӽ� ����
		pChild->nResizeType = RE_ALL;
	}

	// ȭ�鿡 ���ġ
	if(::IsWindow(m_hWnd))		RepositionAll();

	return TRUE;
}

// Ư�� �ڽ� �������� ���ġ �ɼ� ���� �Լ�
BOOL CResizeDlg::SetChildType(HWND hWnd, UINT nType)
{
	int i, nSize = m_ChildArray.GetSize();
	LPCHILDRESIZE pChild;

	for(i = 0; i < nSize; i++)
	{
		pChild = m_ChildArray.GetAt(i);

		// ������ �ڵ��� ������ �׸� ã��
		if(pChild->hChild == hWnd)
		{
			// �ɼ� �缳��
			pChild->nResizeType = nType;
			// ȭ�鿡 ���ġ
			if(::IsWindow(hWnd))		RepositionAt(i, NULL);

			return TRUE;
		}
	}

	return FALSE;
}

// Ư�� �ڽ� �������� ���ġ �ɼ� ���� �Լ�
BOOL CResizeDlg::SetChildType(CWnd *pWnd, UINT nType)
{
	ASSERT(pWnd);

	return SetChildType(pWnd->m_hWnd, nType);
}

// ��� �ڽ� ��������� ���ġ�ϴ� �Լ�
void CResizeDlg::RepositionAll()
{
	int i, nSize = m_ChildArray.GetSize();
	CRect rcClient;

	GetClientRect(&rcClient);

	for(i = 0; i < nSize; i++)
	{
		RepositionAt(i, &rcClient);
	}
}

// Ư�� �ڽ� �����츦 ���ġ�ϴ� �Լ�
void CResizeDlg::RepositionAt(int nChild, CRect *pClientRect)
{
	CRect rcClient, rcChild;
	LPCHILDRESIZE pChild;
	pChild = m_ChildArray.GetAt(nChild);

	if(pClientRect == NULL)
	{
		GetClientRect(&rcClient);
		pClientRect = &rcClient;
	}

	if(pChild->nResizeType & RE_X1)
		// ���� ���� ������� ���ġ
		rcChild.left		= (int)(pClientRect->Width() * pChild->dPosX1);
	else
		if(pChild->nResizeType & RE_INV_X1)
			// ���� ���� ���̾�α� ���� �������� ����
			rcChild.left	= (int)(pClientRect->right - (m_rcClient.Width() * (1.0 - pChild->dPosX1)));
		else
			rcChild.left	= (int)(m_rcClient.Width() * pChild->dPosX1);

	if(pChild->nResizeType & RE_Y1)
		// ���� ���� ������� ���ġ
		rcChild.top			= (int)(pClientRect->Height() * pChild->dPosY1);
	else
		if(pChild->nResizeType & RE_INV_Y1)
			// ���� ���� ���̾�α� �Ʒ��� �������� ����
			rcChild.top		= (int)(pClientRect->bottom - (m_rcClient.Height() * (1.0 - pChild->dPosY1)));
		else
			rcChild.top		= (int)(m_rcClient.Height() * pChild->dPosY1);

	if(pChild->nResizeType & RE_X2)
		// ���� ���� ������� ���ġ
		rcChild.right		= (int)(pClientRect->Width() * pChild->dPosX2);
	else
		if(pChild->nResizeType & RE_INV_X2)
			// ���� ���� ���̾�α� ���� �������� ����
			rcChild.right	= (int)(pClientRect->right - (m_rcClient.Width() * (1.0 - pChild->dPosX2)));
		else
			rcChild.right	= (int)(m_rcClient.Width() * pChild->dPosX2);

	if(pChild->nResizeType & RE_Y2)
		// �Ʒ��� ���� ������� ���ġ
		rcChild.bottom	= (int)(pClientRect->Height() * pChild->dPosY2);
	else
		if(pChild->nResizeType & RE_INV_Y2)
			// �Ʒ��� ���� ���̾�α� �Ʒ��� �������� ����
			rcChild.bottom	= (int)(pClientRect->bottom - (m_rcClient.Height() * (1.0 - pChild->dPosY2)));
		else
			rcChild.bottom	= (int)(m_rcClient.Height() * pChild->dPosY2);

	::SetWindowPos(pChild->hChild, NULL, rcChild.left, rcChild.top,
		rcChild.Width(), rcChild.Height(), SWP_NOZORDER | SWP_SHOWWINDOW);
	::InvalidateRect(pChild->hChild, NULL, FALSE);
}

void CResizeDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// ���̾�α� ũ�Ⱑ ����Ǹ� ��Ʈ�ѵ��� ���ġ�Ѵ�
	if(::IsWindow(m_hWnd))		RepositionAll();
}
