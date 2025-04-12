#if !defined(AFX_WORDBOOK_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_)
#define AFX_WORDBOOK_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WordBook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWordBook window

// Speech API ����� ���� ��� ���� ��ũ���
#include <sapi.h>

// CArray ����� ���� ��� ���� ��ũ���
#include <afxtempl.h>


// �ܾ� �׸� ���� ����ü
struct SWordItem
{
	CString strEnglish;		// ���� �ܾ�
	CString strKorean;		// �ѱ� �ؼ�
	COleDateTime date;		// ���� ��¥
};


// �ܾ��� ����Ʈ �ڽ� Ŭ����
class CWordBook : public CListBox
{
// Construction
public:
	CWordBook();

// Attributes
public:
	CEdit			m_Edit;					// �ؽ�Ʈ ������ ����Ʈ ��Ʈ��
	int				m_nTrackItem;			// ���� ���콺�� ��ġ�� �׸� ��ȣ
	int				m_nEditItem;			// ���� ���� ���� �׸� ��ȣ
	BOOL			m_bEditEnglish;			// ���� �׸��� ���� �ܾ����� ����

	CBrush			m_NullBrush;			// ��� ��¿� �귯��
	CPen			m_ShadowPen;			// ����Ʈ �ڽ� �׵θ��� ��
	CPen			m_FocusPen;				// ���� �׸� �׵θ��� ��

	COLORREF		m_clrText;				// �ؽ�Ʈ ����
	COLORREF		m_clrHighlight;			// ���콺�� ��ġ�� �׸��� ����
	COLORREF		m_clrBkgnd;				// �Ϲ� ����
	COLORREF		m_clrSelected;			// ���õ� �׸��� ����

	int				m_nColumnWidth;			// ���� �ܾ� ���ĭ�� ��
	HCURSOR			m_hSizeCursor;			// �� ������ ǥ�ø� ���� ���콺 Ŀ��
	HCURSOR			m_hArrowCursor;			// �Ϲ� Ŀ��
	BOOL			m_bModified;			// �ܾ����� �����Ǿ����� ����
	BOOL			m_bCapture;				// ���콺 ĸ�� ����

	// ���� �ܾ� �迭
	CArray<SWordItem*, SWordItem*>	m_WordArray;

	ISpVoice		*m_pSpeechApi;			// Speech API �������̽�

// Operations
public:
	// ���� �ܾ��� ������ �ε��ϴ� �Լ�
	void ReadWordFile();
	// ���� �ܾ��� ������ �����ϴ� �Լ�
	void SaveWordFile();

	// �ܾ��忡 �ܾ �߰��ϴ� �Լ�
	void AddWord(LPCTSTR pEnglish, LPCTSTR pKorean);

	// �ؽ�Ʈ ������ �����ϴ� �Լ�
	void EndEdit();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordBook)
	public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWordBook();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWordBook)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcPaint();
	afx_msg void OnDblclk();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSelchange();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg void OnKillFocusEdit();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDBOOK_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_)
