#if !defined(AFX_FONTEFFECT_H__3071E538_9EEC_4607_B73B_8B20A8CA7A52__INCLUDED_)
#define AFX_FONTEFFECT_H__3071E538_9EEC_4607_B73B_8B20A8CA7A52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FontEffect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFontEffect window

// ȿ�� �߰��� ���� �Լ� ������ Ÿ�� ����
typedef void (*LPPROCESSFUNC)(int nSize, CPoint *pPoint, CSize TextSize);


// ��Ʈ ȿ�� ����ƽ Ŭ����
class CFontEffect : public CStatic
{
// Construction
public:
	CFontEffect();

// Attributes
public:
	CFont			m_TextFont;				// �ؽ�Ʈ ��¿� ��Ʈ
	CString			m_strText;				// ��� �ؽ�Ʈ
	BOOL			m_bOutLine;				// �ܰ��� ��� ����

	int				m_nPointSize;			// ��θ� �����ϴ� ����Ʈ ����
	CPoint			*m_pPointArray;			// ��θ� �����ϴ� ����Ʈ �迭
	BYTE			*m_pTypeArray;			// ��θ� �����ϴ� ���� �迭
	CSize			m_TextSize;				// �⺻ �ؽ�Ʈ ������
	CRect			m_rcOutput;				// ȿ���� ����Ǿ� ��µǴ� ũ��

	LPPROCESSFUNC	m_pProcessFunc;			// ȿ�� �߰��� �Լ� ������

// Operations
public:
	// �ؽ�Ʈ�� �����ϴ� �Լ�
	void SetText(LPCTSTR pText, BOOL bRebuild = FALSE);
	// �߰� ȿ�� �Լ��� �����ϴ� �Լ�
	void SetFunction(LPPROCESSFUNC pFunc, BOOL bRebuild = FALSE);
	// �ܰ��� ��� ���θ� �����ϴ� �Լ�
	void SetOutLine(BOOL bOutLine);

	// �ؽ�Ʈ�� ���� ��θ� ����ϴ� �Լ�
	void BuildEffect();

	// ��θ� ����ϴ� �Լ�
	void DrawEffect(CDC *pDC, int cx, int cy);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontEffect)
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFontEffect();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFontEffect)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTEFFECT_H__3071E538_9EEC_4607_B73B_8B20A8CA7A52__INCLUDED_)
