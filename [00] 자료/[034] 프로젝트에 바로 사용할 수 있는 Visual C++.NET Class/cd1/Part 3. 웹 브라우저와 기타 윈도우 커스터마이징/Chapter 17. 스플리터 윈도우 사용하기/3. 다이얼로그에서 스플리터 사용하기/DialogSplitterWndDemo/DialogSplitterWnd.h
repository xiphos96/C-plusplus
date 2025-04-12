#if !defined(AFX_DIALOGSPLITTERWND_H__938FB453_F60E_4541_BF43_8EABAAE32A8A__INCLUDED_)
#define AFX_DIALOGSPLITTERWND_H__938FB453_F60E_4541_BF43_8EABAAE32A8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogSplitterWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogSplitterWnd window


// CArray�� ����ϱ� ���� ��� ����
#include "afxtempl.h"


// ��Ʈ���� ��ġ�� ������ �����ϴ� ���� ���
enum CONTROL_POS	{ POS_LEFT, POS_TOP, POS_RIGHT, POS_BOTTOM };
// ���ø����� ������ �����ϴ� ���� ���
enum SPLITTER_DIR	{ DIR_HORZ, DIR_VERT };


// ���ø��Ϳ� �����Ǵ� ��Ʈ�ѿ� ���� ���� ����ü
struct SControlInfo
{
	CWnd	*pWnd;					// ��Ʈ���� ������ ������
	int		nPos;					// ��Ʈ���� �ʱ� ��ġ : ��Ʈ���� ��ġ ���⿡ ���� �ٸ� ���� ����ȴ�
	BOOL	bStretch;				// ���ø����� �̵��� ���� ��Ʈ���� Ȯ���� ������ ����
};


// ���̾�α׿� ���ø��� Ŭ����
class CDialogSplitterWnd : public CStatic
{
// Construction
public:
	CDialogSplitterWnd();

// Attributes
public:
	SPLITTER_DIR			m_nDirection;		// ���ø����� ����
	BOOL					m_bCapture;			// ���� ���콺 �̺�Ʈ�� ĸ���ϰ� �ִ��� ����

	int						m_nInitPos;			// ���ø����� �ʱ� ��ġ(���� - top ��ǥ, ���� left ��ǥ)
	int						m_nLeftRange;		// ���ø��Ͱ� ���� Ȥ�� ������� �̵��� �� �ִ� �Ÿ�
	int						m_nRightRange;		// ���ø��Ͱ� ���� Ȥ�� �ϴ����� �̵��� �� �ִ� �Ÿ�

	CArray<SControlInfo*, SControlInfo*>	m_LeftControls;		// ���ø����� ���� Ȥ�� ��ܿ� ��ġ�� ��Ʈ�ѵ� �迭
	CArray<SControlInfo*, SControlInfo*>	m_RightControls;	// ���ø����� ���� Ȥ�� �ϴܿ� ��ġ�� ��Ʈ�ѵ� �迭

	COLORREF				m_clrSplitter;		// ���ø����� ������

	HCURSOR					m_hHorzCursor;		// ���� ���ø��Ϳ� ���� ���콺 Ŀ��
	HCURSOR					m_hVertCursor;		// ���� ���ø��Ϳ� ���� ���콺 Ŀ��

// Operations
public:
	// ���ø����� ������ �����ϴ� �Լ�
	void SetDirection(SPLITTER_DIR nDir);
	// ���ø����� �̵� ������ �����ϴ� �Լ�
	void SetRange(int nLeft, int nRight);
	// ���ø��Ϳ� ��Ʈ���� �߰��ϴ� �Լ�
	int AddControl(CONTROL_POS nPos, CWnd *pControl, BOOL bStretch = TRUE);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogSplitterWnd)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDialogSplitterWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDialogSplitterWnd)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSPLITTERWND_H__938FB453_F60E_4541_BF43_8EABAAE32A8A__INCLUDED_)
