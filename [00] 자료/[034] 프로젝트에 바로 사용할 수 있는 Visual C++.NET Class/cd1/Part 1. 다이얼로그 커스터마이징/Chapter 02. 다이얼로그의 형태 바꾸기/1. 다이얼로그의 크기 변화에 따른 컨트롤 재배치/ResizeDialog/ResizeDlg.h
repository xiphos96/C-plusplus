#if !defined(AFX_RESIZEDLG_H__1BC3A745_2245_404D_A3DB_1BA0FBEB9D73__INCLUDED_)
#define AFX_RESIZEDLG_H__1BC3A745_2245_404D_A3DB_1BA0FBEB9D73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResizeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResizeDlg dialog

// CArray ����� ���� ��� ����
#include <afxtempl.h>

// �ڽ� ��������� ���ġ�ϴ� �ɼ� ����
#define RE_NONE		0			// ���ġ ���� ����
#define RE_X1		1			// ���� ���� ������� ���ġ
#define RE_Y1		2			// ���� ���� ������� ���ġ
#define RE_X2		4			// ���� ���� ������� ���ġ
#define RE_Y2		8			// �Ʒ��� ���� ������� ���ġ
#define RE_ALL		15			// ��� ���� ������� ���ġ. RE_ALL = RE_X1 | RE_Y1 | RE_X2 | RE_Y2
#define RE_INV_X1	16			// ���� ���� ���̾�α� ���� �������� ����
#define RE_INV_Y1	32			// ���� ���� ���̾�α� �Ʒ��� �������� ����
#define RE_INV_X2	64			// ���� ���� ���̾�α� ���� �������� ����
#define RE_INV_Y2	128			// �Ʒ��� ���� ���̾�α� �Ʒ��� �������� ����
#define RE_INV_ALL	240			// ��� ���� ���̾�α� ����/�Ʒ��� �������� ����. RE_INV_ALL = RE_INV_X1 | RE_INV_Y1 | RE_INV_X2 | RE_INV_Y2

// �ڽ� �����쿡 ���� ���ġ �ɼ� ���� ����ü
typedef struct tagCHILDRESIZE
{
	HWND	hChild;
	double	dPosX1;
	double	dPosY1;
	double	dPosX2;
	double	dPosY2;

	UINT	nResizeType;
} CHILDRESIZE, *LPCHILDRESIZE;


class CResizeDlg : public CDialog
{
// Construction
public:
	CResizeDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor
	virtual ~CResizeDlg();

// Dialog Data
	//{{AFX_DATA(CResizeDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CRect										m_rcClient;			// ���̾�α��� �⺻ ũ�� ���� ����
	CArray<LPCHILDRESIZE, LPCHILDRESIZE>		m_ChildArray;		// �ڽ� ������鿡 ���� ���ġ �ɼ� ���� �迭

	BOOL Reset();											// ��� �ڽ� ��������� ���ġ���� �ʵ��� �ʱ�ȭ
	BOOL SetAll();											// ��� �ڽ� ��������� ������� ���ġ�ϵ��� �ʱ�ȭ
	BOOL SetChildType(HWND hWnd, UINT nType);				// Ư�� �ڽ� �������� ���ġ �ɼ� ���� �Լ�
	BOOL SetChildType(CWnd *pWnd, UINT nType);				// Ư�� �ڽ� �������� ���ġ �ɼ� ���� �Լ�

	void RepositionAll();									// ��� �ڽ� ��������� ���ġ�ϴ� �Լ�
	void RepositionAt(int nChild, CRect *pClientRect);		// Ư�� �ڽ� �����츦 ���ġ�ϴ� �Լ�

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResizeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CResizeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESIZEDLG_H__1BC3A745_2245_404D_A3DB_1BA0FBEB9D73__INCLUDED_)
