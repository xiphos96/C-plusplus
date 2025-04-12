#if !defined(AFX_SLIDEEDIT_H__222FBA88_426C_4152_A6A9_72CBF8E4927C__INCLUDED_)
#define AFX_SLIDEEDIT_H__222FBA88_426C_4152_A6A9_72CBF8E4927C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SlideEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSlideEdit window

// �����̵� �����쿡 ���� Ŭ���� ��� ����
#include "SlideWnd.h"

// CSlideEdit�� ����Ͽ� DDX/DDV�� �����ϱ� ���� �Լ�
void AFXAPI DDX_SlideEdit(CDataExchange* pDX, int nIDC, CString& strText);


// �����̵� ����Ʈ ��Ʈ�� Ŭ����
class CSlideEdit : public CEdit
{
// Construction
public:
	CSlideEdit();

// Attributes
public:
	int			m_nValue;					// ���� �Էµ� ��
	int			m_nMax;						// �ִ� ��
	int			m_nMin;						// �ּ� ��

	int			m_nButtonState;				// ���� ��ư�� ����
	CRect		m_rcButton;					// ��ư�� ����

	HCURSOR		m_hCursor;					// ȭ��ǥ ���콺 Ŀ��

	CSlideWnd	m_wndSlide;					// �����̵� ������

// Operations
public:
	// �����̵� ����Ʈ ��Ʈ���� ���� ����/�����ϴ� �Լ�
	int GetValue()							{ return m_nValue; }
	BOOL SetValue(int nValue);
	// �����̵� ����Ʈ ��Ʈ���� ������ ����/�����ϴ� �Լ�
	void GetRange(int &nMax, int &nMin)		{ nMax = m_nMax; nMin = m_nMin; }
	void SetRange(int nMax, int nMin);

	// �� ���� ��ư�� �׸��� �Լ�
	void DrawButton();
	// �����̵� �����츦 ���� �Լ�
	void PopupSlide();

	// �� ���� ��ư�� ���� ����
	enum { BUTTON_DISABLED = 0, BUTTON_UP, BUTTON_DOWN };

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlideEdit)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSlideEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSlideEdit)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChange();
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	//}}AFX_MSG
	// �����̵� �������� �޽����� ���� �ڵ鷯
	afx_msg LRESULT OnSlidePosChange(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSlideEndSelect(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDEEDIT_H__222FBA88_426C_4152_A6A9_72CBF8E4927C__INCLUDED_)
