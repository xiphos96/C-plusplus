#if !defined(AFX_WARPTEXT_H__23D25ED7_D6EA_42B6_86D9_EB456C03D09C__INCLUDED_)
#define AFX_WARPTEXT_H__23D25ED7_D6EA_42B6_86D9_EB456C03D09C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WarpText.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWarpText window


// �ؽ�Ʈ ���� Ŭ����
class CWarpText : public CStatic
{
// Construction
public:
	CWarpText();

// Attributes
public:
	BSTR			m_bstrText;				// ������ �ؽ�Ʈ 
	BSTR			m_bstrFontName;			// �ؽ�Ʈ�� ����� ��Ʈ
	Color			m_clrFontColor;			// �ؽ�Ʈ�� ĥ�� ����
	Color			m_clrOutline;			// �ؽ�Ʈ �ܰ��� ����

	CRect			m_rcClient;				// ��Ʈ���� ����

	RectF			m_rcText;				// �ؽ�Ʈ ��¿� �ʿ��� ����
	PointF			*m_ptWarp;				// ���ο� ���� ��ǥ �迭
	GraphicsPath	m_TextPath;				// �ؽ�Ʈ�� ���� ��� ��ü

	BOOL			m_bShowGuideLine;		// ���̵� ������ ������� ����

// Operations
public:
	// ������ �ؽ�Ʈ�� ��Ʈ�� �����ϴ� �Լ�
	void SetText(LPCTSTR pText, LPCTSTR pFontName = NULL);
	// �ؽ�Ʈ�� ĥ�ϴ� ���� ���� �Լ�
	void SetFontColor(COLORREF clrFont);
	// �ؽ�Ʈ �ܰ����� ĥ�ϴ� ���� ���� �Լ�
	void SetOutlineColor(COLORREF clrOutline);
	// ���̵� ���� ��� ���θ� �����ϴ� �Լ�
	void ShowGuideLine(BOOL bShow);

	// ���� ��ǥ�� �����ϴ� �Լ�
	BOOL SetWarpPoint(CPoint *pWarpPoint);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWarpText)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWarpText();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWarpText)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WARPTEXT_H__23D25ED7_D6EA_42B6_86D9_EB456C03D09C__INCLUDED_)
