#if !defined(AFX_CUSTOMSLIDERCTRL_H__B4E88415_4E44_4B8E_B8C2_36B5DABD7730__INCLUDED_)
#define AFX_CUSTOMSLIDERCTRL_H__B4E88415_4E44_4B8E_B8C2_36B5DABD7730__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomSliderCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomSliderCtrl window


// ����� ���� �����̴� ��Ʈ�� Ŭ����
class CCustomSliderCtrl : public CSliderCtrl
{
// Construction
public:
	CCustomSliderCtrl();

// Attributes
public:
	COLORREF	m_clrThumb;					// �ڵ� ����
	COLORREF	m_clrSelection;				// ���õ� ���� ����
	COLORREF	m_clrChannel;				// ���õ��� ���� ���� ����
	CBrush		m_brsChannel;				// ���õ��� ���� ���� �귯��

	BOOL		m_bHorz;					// �������� �������� ����

// Operations
public:
	// �ڵ� ������ ����/�����ϴ� �Լ�
	COLORREF GetThumbColor()		{ return m_clrThumb; }
	void SetThumbColor(COLORREF clrThumb);
	// ���õ� ������ ������ ����/�����ϴ� �Լ�
	COLORREF GetSelectionColor()	{ return m_clrSelection; }
	void SetSelectionColor(COLORREF clrSelection);
	// ���õ��� ���� ������ ������ ����/�����ϴ� �Լ�
	COLORREF GetChannelColor()		{ return m_clrChannel; }
	void SetChannelColor(COLORREF clrChannel);

	// �ڵ��� �׸��� �Լ�
	void DrawThumb(CDC *pDC, CRect rcItem);
	// ������ �׸��� �Լ�
	void DrawChannel(CDC *pDC, CRect rcItem);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomSliderCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomSliderCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomSliderCtrl)
	afx_msg void OnCustomdraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMSLIDERCTRL_H__B4E88415_4E44_4B8E_B8C2_36B5DABD7730__INCLUDED_)
