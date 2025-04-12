#if !defined(AFX_COOLBUTTON_H__98EA5DF5_CFAA_438E_AA18_FE5413E3164E__INCLUDED_)
#define AFX_COOLBUTTON_H__98EA5DF5_CFAA_438E_AA18_FE5413E3164E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CoolButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCoolButton window

// ��ư�� ������ �̹��� Ÿ��
enum ENUM_IMAGE_TYPE		{ IMG_BMP = 0, IMG_ICON };

// ��ư���� �ؽ�Ʈ�� ��ġ Ÿ��
enum ENUM_TEXT_ALIGN		{ ALIGN_LEFT = 0, ALIGN_RIGHT, ALIGN_TOP, ALIGN_BOTTOM, ALIGN_OVER };

// ��ư�� ������ ������ �� ����ϴ� ���� Ÿ��
enum ENUM_COLOR_TYPE		{ COLOR_TEXT = 0, COLOR_BKGND, COLOR_TEXT_IN, COLOR_BKGND_IN, COLOR_MAX };


// ��Ʈ�ʰ� �������� ������ �� �ִ� ��ư
class CCoolButton : public CButton
{
// Construction
public:
	CCoolButton();

// Attributes
public:
	HCURSOR				m_hCursor;					// �ո�� Ŀ��

	BITMAP				m_bmpInfo;					// ���� �̹����� ����
	CBitmap				m_bmpImage;					// ��ư�� ��Ʈ�� ��ü
	CBitmap				m_bmpMask;					// ��ư�� ��Ʈ�� ��ü���� ���� ó���� ���� ����ũ ��Ʈ��
	HICON				m_hIcon;					// ��ư�� ������ ��ü
	CPoint				m_ptImage;					// ��ư���� �̹��� ��� ��ġ
	ENUM_IMAGE_TYPE		m_nImageType;				// ���� ������ �̹��� Ÿ��

	BOOL				m_bFlat;					// ��� ��ư���� ��ü ��ư���� ����
	BOOL				m_bHover;					// ���콺�� ��ư ���� �ִ��� ����
	CRect				m_rcClient;					// ��ư�� Ŭ���̾�Ʈ ũ��

	CString				m_strText;					// ��ư�� �ؽ�Ʈ
	CRect				m_rcText;					// ��ư���� �ؽ�Ʈ ��� ��ġ

	COLORREF			m_clrColors[COLOR_MAX];		// ��ư�� ���Ǵ� ���� �迭
	COLORREF			m_clrTransparent;			// ���� ó���� ����

	ENUM_TEXT_ALIGN		m_nTextAlign;				// ��ư���� �ؽ�Ʈ�� ��ġ

	CString				m_strToolTip;				// ���� �ؽ�Ʈ
	CToolTipCtrl		m_wndToolTip;				// ���� ��Ʈ��

// Operations
public:
	void SetButtonBmp(UINT nBitmapID);				// ��ư�� ��Ʈ���� �����ϴ� �Լ�
	void SetButtonBmp(UINT nBitmapID, COLORREF clrTransparent);
													// ��ư�� ��Ʈ���� �����ϰ� ������� �����ϴ� �Լ�
	void SetButtonIcon(UINT nIconID);				// ��ư�� �������� �����ϴ� �Լ�
	void RepositionAll();							// ��ư���� �̹����� �ؽ�Ʈ�� ��ġ�� ����ϴ� �Լ�

	// ��� ��ư���� ����/�����ϴ� �Լ�
	BOOL IsFlat()						{ return m_bFlat; }
	void SetFlat(BOOL bFlat);

	// ��ư�� �ؽ�Ʈ�� ����/�����ϴ� �Լ�
	LPCTSTR GetButtonText()				{ return m_strText; }
	void SetButtonText(LPCTSTR pText);

	// ��ư�� ������ ����/�����ϴ� �Լ�
	COLORREF GetButtonColor(ENUM_COLOR_TYPE nColor);
	void SetButtonColor(ENUM_COLOR_TYPE nColor, COLORREF clrColor);

	// ��ư���� �ؽ�Ʈ ��ġ�� ����/�����ϴ� �Լ�
	ENUM_TEXT_ALIGN GetTextAlign()		{ return m_nTextAlign; }
	void SetTextAlign(ENUM_TEXT_ALIGN nAlign);

	// ��ư�� ������ ����/�����ϴ� �Լ�
	LPCTSTR GetToolTipText()			{ return m_strToolTip; }
	void SetToolTipText(LPCTSTR pTip);

	// ����� �׸��� �Լ�
	virtual void DrawBkgnd(CDC *pDC, BOOL bPressed, BOOL bEnable);
	// �׵θ��� �׸��� �Լ�
	virtual void DrawBorder(CDC *pDC, BOOL bPressed, BOOL bFocus);
	// �̹����� �׸��� �Լ�
	virtual void DrawImage(CDC *pDC, BOOL bPressed);
	// �ؽ�Ʈ�� �׸��� �Լ�
	virtual void DrawText(CDC *pDC, BOOL bPressed, BOOL bEnable);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoolButton)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCoolButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCoolButton)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COOLBUTTON_H__98EA5DF5_CFAA_438E_AA18_FE5413E3164E__INCLUDED_)
