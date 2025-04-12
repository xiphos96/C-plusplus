#if !defined(AFX_SYMBOLPREVIEWSTATIC_H__73372676_AED2_4BED_AFC2_46BD25858CDD__INCLUDED_)
#define AFX_SYMBOLPREVIEWSTATIC_H__73372676_AED2_4BED_AFC2_46BD25858CDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SymbolPreviewStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSymbolPreviewStatic window

// ���õ� Ư�� ���ڸ� ũ�� �����ִ� ��Ʈ��
class CSymbolPreviewStatic : public CStatic
{
// Construction
public:
	CSymbolPreviewStatic();

// Attributes
public:
	BOOL			m_bIsUnicode;			// �����ڵ����� ����
	CRect			m_ClientRect;			// ��Ʈ���� Ŭ���̾�Ʈ ����

	unsigned char	m_cHighByte;			// Ư�� ������ ���� ����Ʈ
	unsigned char	m_cLowByte;				// Ư�� ������ ���� ����Ʈ
	wchar_t			m_strUni[2];			// �����ڵ� ����� ����
	char			m_strAscii[2];			// �ƽ�Ű �ڵ� ����� ����

	CFont			m_DisplayFont;			// ȭ�� ��¿� ���Ǵ� ��Ʈ
	CString			m_FontName;				// ȭ�� ��¿� ���Ǵ� ��Ʈ �̸�

// Operations
public:
	void InitPreview();						// Ŭ���̾�Ʈ ������ ���ϰ� ��Ʈ�� �����ϴ� �Լ�
	// ���ο� Ư�� ���ڸ� ����ϴ� �Լ�
	void RefreshCode(unsigned char cHighByte, unsigned char cLowByte);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSymbolPreviewStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSymbolPreviewStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSymbolPreviewStatic)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYMBOLPREVIEWSTATIC_H__73372676_AED2_4BED_AFC2_46BD25858CDD__INCLUDED_)
