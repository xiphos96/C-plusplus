#if !defined(AFX_SYMBOLCHART_H__E0729224_2431_11D5_AA4B_0000B4C34F32__INCLUDED_)
#define AFX_SYMBOLCHART_H__E0729224_2431_11D5_AA4B_0000B4C34F32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SymbolChart.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSymbolChart window

class CSymbolPreviewStatic;

// Ư�� ����ǥ ��� ��Ʈ��

class CSymbolChart : public CStatic
{
// Construction
public:
	CSymbolChart();

// Attributes
public:
	BOOL			m_bIsUnicode;				// �����ڵ����� ����
	BOOL			m_bIsUpper;					// ���� ����Ʈ�� 0~127 �κ����� 128~255 �κ����� ����
	char			m_SelectedCode;				// ���� ���õ� �ڵ� �� ��ȣ

	unsigned char	m_cHighByte;				// Ư�� ������ ���� ����Ʈ

	CRect			m_ClientRect;				// ��Ʈ���� Ŭ���̾�Ʈ ����
	int				m_nItemWidth;				// �� ���� ��
	int				m_nItemHeight;				// �� ���� ����

	CFont			m_DisplayFont;				// ȭ�� ��¿� ���Ǵ� ��Ʈ
	CString			m_FontName;					// ȭ�� ��¿� ���Ǵ� ��Ʈ �̸�

	CEdit			*m_pEdit;					// Ư�� ������ �ڵ带 ����� ����Ʈ ��Ʈ�� ������
	CSymbolPreviewStatic	*m_pPreview;		// Ư�� ���� �̸����� ��Ʈ�� ������

	wchar_t			m_strUni[2];				// �����ڵ� ����� ����
	char			m_strAscii[2];				// �ƽ�Ű �ڵ� ����� ����

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSymbolChart)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSymbolChart();

	void InitCodeChart();							// Ư�� ����ǥ ���� �������� �ʱ�ȭ�ϴ� �Լ�
	void UpdateCodeEdit();							// ���� ���õ� Ư�� ������ �ڵ带 ����Ʈ �ڽ��� �����ϴ� �Լ�
	void RedrawCode(CDC *pDC, int nRow, int nCol);	// Ư�� Ư�� ���ڸ� ȭ�鿡 ����ϴ� �Լ�

	unsigned char GetSelectedLowCode();				// ���� ���õ� Ư�� ������ ���� ����Ʈ�� �����ϴ� �Լ�

	// Generated message map functions
protected:
	//{{AFX_MSG(CSymbolChart)
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYMBOLCHART_H__E0729224_2431_11D5_AA4B_0000B4C34F32__INCLUDED_)
