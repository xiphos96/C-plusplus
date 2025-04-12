#if !defined(AFX_SECTIONLINE_H__D0973981_D6E7_4001_9DC4_2C6FFAE68338__INCLUDED_)
#define AFX_SECTIONLINE_H__D0973981_D6E7_4001_9DC4_2C6FFAE68338__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SectionLine.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSectionLine window


// ���м� ����ƽ ��Ʈ�� Ŭ����
class CSectionLine : public CStatic
{
// Construction
public:
	CSectionLine();

// Attributes
public:
	BOOL			m_bHorz;					// ���� ���� �ؽ�Ʈ ��� ����
	CRect			m_rcText;					// �ؽ�Ʈ�� ��µǴ� �簢 ����
	CRect			m_rcLineLeft;				// ���� ���м��� ��µǴ� �簢 ����
	CRect			m_rcLineRight;				// ������ ���м��� ��µǴ� �簢 ����

	COLORREF		m_clrText;					// �ؽ�Ʈ ����
	COLORREF		m_clrBkgnd;					// ��� ����
	COLORREF		m_clrHighlight;				// ���� ����
	COLORREF		m_clrShadow;				// ��ο� ����

	CFont			m_VertFont;					// ���� �ؽ�Ʈ ��¿� ��Ʈ

// Operations
public:
	// �ؽ�Ʈ�� ������ ���м��� ������ ����ϴ� �Լ�
	void RecalcSectionLine(LPCTSTR pText);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSectionLine)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSectionLine();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSectionLine)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	afx_msg LONG OnSetText(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECTIONLINE_H__D0973981_D6E7_4001_9DC4_2C6FFAE68338__INCLUDED_)
