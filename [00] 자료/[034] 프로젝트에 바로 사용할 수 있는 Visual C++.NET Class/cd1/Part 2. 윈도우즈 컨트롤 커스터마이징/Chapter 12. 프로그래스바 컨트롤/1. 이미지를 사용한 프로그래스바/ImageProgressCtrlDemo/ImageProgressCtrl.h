#if !defined(AFX_IMAGEPROGRESSCTRL_H__8439D6D5_7B03_4FC2_BD38_F4AAC0A55F0F__INCLUDED_)
#define AFX_IMAGEPROGRESSCTRL_H__8439D6D5_7B03_4FC2_BD38_F4AAC0A55F0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageProgressCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImageProgressCtrl window

// �̹��� ���α׷����ٿ��� ���� ���� ǥ�� ���
enum TEXT_TYPE { TEXT_NONE = 0, TEXT_PERCENT, TEXT_FORMAT };
// �̹��� ������ �̹����� ��ġ
enum BMP_TYPE { BMP_LEFT = 0, BMP_CENTER, BMP_RIGHT };


// �̹��� ���α׷����� ��Ʈ�� Ŭ����
class CImageProgressCtrl : public CProgressCtrl
{
// Construction
public:
	CImageProgressCtrl();

// Attributes
public:
	// ��� �׵θ� ��Ʈ��
	CBitmap		m_bmpBorderLeft;
	CBitmap		m_bmpBorderCenter;
	CBitmap		m_bmpBorderRight;

	// ����� ��Ʈ��
	CBitmap		m_bmpPosLeft;
	CBitmap		m_bmpPosCenter;
	CBitmap		m_bmpPosRight;

	// ��� �׵θ� ��Ʈ�� ����
	BITMAP		m_infoBorderLeft;
	BITMAP		m_infoBorderCenter;
	BITMAP		m_infoBorderRight;

	// ����� ��Ʈ�� ����
	BITMAP		m_infoPosLeft;
	BITMAP		m_infoPosCenter;
	BITMAP		m_infoPosRight;

	// �̹����� �������� �ʾ��� ��� ��� �׵θ��� ����ٸ� �׸� �����
	COLORREF	m_clrLight;					// �׵θ� ����� ���� ���� ����
	COLORREF	m_clrShadow;				// �׵θ� ����� ���� ��ο� ����
	COLORREF	m_clrBkgnd;					// ����
	COLORREF	m_clrPos;					// ����� ����

	COLORREF	m_clrText;					// �ؽ�Ʈ ����
	TEXT_TYPE	m_nTextType;				// ���� ���� ��� ����
	CString		m_strFormat;				// ���ڿ� ������ ����� ��� ���� ���ڿ�
	CString		m_strFontName;				// �ؽ�Ʈ ��¿� ��Ʈ �̸�
	int			m_nFontSize;				// �ؽ�Ʈ ��¿� ��Ʈ ũ��
	CFont		m_TextFont;					// �ؽ�Ʈ ��¿� ��Ʈ

	BOOL		m_bHorz;					// ���α׷����ٰ� �������� �������� ����
	CRect		m_rcClient;					// Ŭ���̾�Ʈ ����

// Operations
public:
	// ���� ���� ��� ������ ����/�����ϴ� �Լ�
	TEXT_TYPE GetTextType()				{ return m_nTextType; }
	void SetTextType(TEXT_TYPE nType);
	// ���ڿ� ������ ����/�����ϴ� �Լ�
	LPCTSTR GetTextFormat()				{ return m_strFormat; }
	void SetTextFormat(LPCTSTR pFormat);

	// �׵θ� ���� ���� ����/���� �Լ�
	COLORREF GetLightColor()			{ return m_clrLight; }
	void SetLightColor(COLORREF clrLight);
	// �׵θ� ��ο� ���� ����/���� �Լ�
	COLORREF GetShadowColor()			{ return m_clrShadow; }
	void SetShadowColor(COLORREF clrShadow);
	// ���� ����/���� �Լ�
	COLORREF GetBkgndColor()			{ return m_clrBkgnd; }
	void SetBkgndColor(COLORREF clrBkgnd);
	// ����� ���� ����/���� �Լ�
	COLORREF GetPosColor()				{ return m_clrPos; }
	void SetPosColor(COLORREF clrPos);

	// �ؽ�Ʈ ���� ����/���� �Լ�
	COLORREF GetTextColor()				{ return m_clrText; }
	void SetTextColor(COLORREF clrText);

	// ��Ʈ �̸� ���� �Լ�
	LPCTSTR GetFontName()				{ return m_strFontName; }
	// ��Ʈ ũ�� ���� �Լ�
	int GetFontSize()					{ return m_nFontSize; }
	// ��Ʈ ���� �Լ�
	void SetTextFont(int nSize, LPCTSTR pFontName);

	// ��� �׵θ� ��Ʈ�� ����/���� �Լ�
	HBITMAP GetBorderBitmap(BMP_TYPE nType);
	void SetBorderBitmap(BMP_TYPE nType, UINT nBmpID);
	void SetBorderBitmap(BMP_TYPE nType, HBITMAP hBmp);
	// ����� ��Ʈ�� ����/���� �Լ�
	HBITMAP GetPosBitmap(BMP_TYPE nType);
	void SetPosBitmap(BMP_TYPE nType, UINT nBmpID);
	void SetPosBitmap(BMP_TYPE nType, HBITMAP hBmp);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageProgressCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageProgressCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImageProgressCtrl)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnNcPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEPROGRESSCTRL_H__8439D6D5_7B03_4FC2_BD38_F4AAC0A55F0F__INCLUDED_)
