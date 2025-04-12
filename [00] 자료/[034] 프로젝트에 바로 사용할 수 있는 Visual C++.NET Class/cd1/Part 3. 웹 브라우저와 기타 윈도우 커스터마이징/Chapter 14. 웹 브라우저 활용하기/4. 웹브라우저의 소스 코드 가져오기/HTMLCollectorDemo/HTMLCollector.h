#if !defined(AFX_HTMLCOLLECTOR_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_)
#define AFX_HTMLCOLLECTOR_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HTMLCollector.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHTMLCollector window

// CArray�� ����ϱ� ���� �������
#include "afxtempl.h"
// �ͽ��÷η� ���� �������̽��� ����ϱ� ���� ��� ����
#include "Mshtml.h"


// HTML �ҽ� ȹ�� Ŭ������ �θ� �����쿡�� �������� ���� ���¸� �˸��� ���� �޽��� ����
#define WM_IE_FINDER_START			(WM_USER + 367)		// �������� ���� ���� �޽���
#define WM_IE_FINDER_END			(WM_USER + 368)		// �������� ���� ���� �޽���
#define WM_IE_FINDER_SELECT			(WM_USER + 369)		// HTML �ҽ� ȹ�� ���� �޽���


// �������� �˻� �� �������� ������ ���� ����ü
struct SIEWnd
{
	HWND		hExplorer;			// ���������� ������ �ڵ�
	CString		strTitle;			// ���������� ����ϴ� �������� Ÿ��Ʋ
	CString		strAddress;			// ���������� ����ϴ� �������� �ּ�
};


// HTML �ҽ� ȹ�� Ŭ����
class CHTMLCollector : public CStatic
{
// Construction
public:
	CHTMLCollector();

// Attributes
public:
	// ����ƽ ��¿� ��Ʈ��
	CBitmap						m_bmpFinder;			// �������� ���� �� ������ ��Ʈ��
	CBitmap						m_bmpFinderButton;		// �������� ���� ������ ��Ʈ��

	HWND						m_hLastHWND;			// �������� ���ý� ������ ���콺�� �̵��� ������ �ڵ�
	HCURSOR						m_hFinderCursor;		// �������� ���ý� ���콺 Ŀ��

	CString						m_strSource;			// ���õǰų� �˻��� ���������� �ҽ�

	CArray<SIEWnd*, SIEWnd*>	m_IEWndArray;			// �˻��� �������� �迭


// Operations
public:
	// ȹ��� �ҽ��� �����ϴ� �Լ�
	LPCTSTR GetSource()					{ return m_strSource; }
	// �˻��� �������� �߿��� Ư�� ���������� �ҽ��� ȹ���Ͽ� ���� �ϴ� �Լ�
	LPCTSTR GetSource(int nIndex);
	// Ư�� ���������� �ҽ��� ȹ���Ͽ� �����ϴ� �Լ�
	LPCTSTR GetSource(HWND hWnd);

	// ���������� IHTMLDocument2 �������̽��� �ҽ��� ȹ���ϴ� �Լ�
	void CheckDocument(IHTMLDocument2 *pIDocument2);

	// Ư�� �������� �ܰ��� �׵θ��� �׸��� �Լ�
	void InvertWindowEdge(HWND hWnd);

	// �˻��� �������� �迭�� ����� ���� �������� ������������ �˻��ϴ� �Լ�
	int RefreshIEArray();
	// �˻��� �������� �迭�� ũ�⸦ �����ϴ� �Լ�
	int GetIEArrayCount();
	// �˻��� �������� �迭���� Ư�� �׸��� �����ϴ� �Լ�
	SIEWnd* GetIEWnd(int nIndex);

	// ������ �˻��� ȣ��Ǵ� �ݹ� �Լ�
	static BOOL CALLBACK EnumWindowCallBack(HWND hWnd, LPARAM lParam);
	// Ư�� ���μ����� ���� ���� �̸��� �����ϴ� �Լ�
	static CString GetProcessName(DWORD pid);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTMLCollector)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHTMLCollector();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHTMLCollector)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLCOLLECTOR_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_)
