#if !defined(AFX_WORDBOOK_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_)
#define AFX_WORDBOOK_H__82D1059A_4397_4AB4_9867_3EFF9EBC449A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WordBook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWordBook window

// Speech API 사용을 위한 헤더 파일 인크루드
#include <sapi.h>

// CArray 사용을 위한 헤더 파일 인크루드
#include <afxtempl.h>


// 단어 항목에 대한 구조체
struct SWordItem
{
	CString strEnglish;		// 영어 단어
	CString strKorean;		// 한글 해석
	COleDateTime date;		// 저장 날짜
};


// 단어장 리스트 박스 클래스
class CWordBook : public CListBox
{
// Construction
public:
	CWordBook();

// Attributes
public:
	CEdit			m_Edit;					// 텍스트 편집용 에디트 컨트롤
	int				m_nTrackItem;			// 현재 마우스가 위치한 항목 번호
	int				m_nEditItem;			// 현재 편집 중인 항목 번호
	BOOL			m_bEditEnglish;			// 편집 항목이 영어 단어인지 여부

	CBrush			m_NullBrush;			// 배경 출력용 브러쉬
	CPen			m_ShadowPen;			// 리스트 박스 테두리용 펜
	CPen			m_FocusPen;				// 선택 항목 테두리용 펜

	COLORREF		m_clrText;				// 텍스트 색상
	COLORREF		m_clrHighlight;			// 마우스가 위치한 항목의 배경색
	COLORREF		m_clrBkgnd;				// 일반 배경색
	COLORREF		m_clrSelected;			// 선택된 항목의 배경색

	int				m_nColumnWidth;			// 영어 단어 출력칸의 폭
	HCURSOR			m_hSizeCursor;			// 열 구분자 표시를 위한 마우스 커서
	HCURSOR			m_hArrowCursor;			// 일반 커서
	BOOL			m_bModified;			// 단어장이 수정되었는지 여부
	BOOL			m_bCapture;				// 마우스 캡춰 상태

	// 영어 단어 배열
	CArray<SWordItem*, SWordItem*>	m_WordArray;

	ISpVoice		*m_pSpeechApi;			// Speech API 인터페이스

// Operations
public:
	// 영어 단어장 파일을 로드하는 함수
	void ReadWordFile();
	// 영어 단어장 파일을 저장하는 함수
	void SaveWordFile();

	// 단어장에 단어를 추가하는 함수
	void AddWord(LPCTSTR pEnglish, LPCTSTR pKorean);

	// 텍스트 편집을 종료하는 함수
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
