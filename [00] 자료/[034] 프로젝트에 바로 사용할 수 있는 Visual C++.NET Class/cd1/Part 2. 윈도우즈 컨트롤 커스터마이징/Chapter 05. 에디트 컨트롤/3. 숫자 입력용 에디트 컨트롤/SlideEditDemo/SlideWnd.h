#if !defined(AFX_SLIDEWND_H__89551372_EA59_46DE_B4C5_2831A41AE59D__INCLUDED_)
#define AFX_SLIDEWND_H__89551372_EA59_46DE_B4C5_2831A41AE59D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SlideWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSlideWnd window

// �����̵� ������ ���� ������ �޽��� ����
#define WM_SLIDE_POS_CHANGE			(WM_USER + 1)	// �����̵忡���� �� �̵�
#define WM_SLIDE_END_SELECT			(WM_USER + 2)	// �����̵带 ����� �� ���� �Ϸ�


// �����̵� ������ Ŭ����
class CSlideWnd : public CWnd
{
// Construction
public:
	CSlideWnd();

// Attributes
public:
	CPen		m_LinePen;				// ������ �׸��� ���� ��
	CPen		m_ShadowPen;			// ������ �׸��ڸ� �׸��� ���� ��
	CBrush		m_BkgndBrush;			// ����� ĥ�� �귯��

	HCURSOR		m_hCursor;				// ȭ��ǥ ���콺 Ŀ��

	CWnd		*m_pParent;				// �����̵� ����Ʈ ��Ʈ�ѿ� ���� ������
	CRect		m_rcClient;				// �����̵� �������� Ŭ���̾�Ʈ ����

	int			m_nCurPos;				// ���� ��ġ
	int			m_nMax;					// �ִ� ��
	int			m_nMin;					// �ּ� ��

// Operations
public:
	// �����̵� �����츦 �����ϴ� �Լ�
	BOOL PopupSlide(CWnd *pParent, CRect &rcWindow, int nMax, int nMin, int nPos);

	// ���� ������ �߻��� ��� �θ� �����쿡�� �˸��� �Լ�
	void OnPosChange();
	// �� ������ �Ϸ�� ��� �θ� �����쿡�� �˸��� �Լ�
	void OnEndSelect();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlideWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSlideWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSlideWnd)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	//}}AFX_MSG
#if _MSC_VER <= 1200
	// VC++ 6.0������ �ڵ�
	afx_msg void OnActivateApp(BOOL bActive, HTASK dwThreadID);
#else
	// VC++.Net������ �ڵ�
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
#endif
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDEWND_H__89551372_EA59_46DE_B4C5_2831A41AE59D__INCLUDED_)
