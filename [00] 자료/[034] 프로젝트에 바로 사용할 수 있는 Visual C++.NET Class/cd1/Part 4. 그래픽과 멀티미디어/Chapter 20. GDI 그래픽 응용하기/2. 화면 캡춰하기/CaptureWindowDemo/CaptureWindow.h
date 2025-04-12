#if !defined(AFX_CAPTUREWINDOW_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_)
#define AFX_CAPTUREWINDOW_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CaptureWindow.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCaptureWindow window

// ������ ���� �� ĸ�� ��Ȳ�� �˸��� ���� �޽��� ����
#define WM_SELECT_START				(WM_USER + 400)		// ������ ���� ���� �޽���
#define WM_SELECT_END				(WM_USER + 401)		// ������ ���� ���� �޽���
#define WM_CAPTURE_FINISH			(WM_USER + 402)		// ĸ�� �Ϸ� �޽���


// ������ ĸ�� Ŭ����
class CCaptureWindow : public CStatic
{
// Construction
public:
	CCaptureWindow();

// Attributes
public:
	// ����ƽ ��¿� ��Ʈ��
	CBitmap						m_bmpSelector;			// ������ ���� �� ������ ��Ʈ��
	CBitmap						m_bmpSelectorButton;	// ������ ���� ������ ��Ʈ��

	HWND						m_hLastHWND;			// ������ ���ý� ������ ���콺�� �̵��� ������ �ڵ�
	HCURSOR						m_hSelectorCursor;		// ������ ���ý� ���콺 Ŀ��

	CBitmap						m_bmpCapture;			// ĸ��� ������ ȭ��

// Operations
public:
	// ĸ��� ��Ʈ���� �����ϴ� �Լ�
	CBitmap* GetCapturedBitmap()		{ return &m_bmpCapture; }

	// Ư�� �������� �ܰ��� �׵θ��� �׸��� �Լ�
	void InvertWindowEdge(HWND hWnd);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptureWindow)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCaptureWindow();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCaptureWindow)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTUREWINDOW_H__D9F07177_E232_49F4_A86A_73D27F47912B__INCLUDED_)
