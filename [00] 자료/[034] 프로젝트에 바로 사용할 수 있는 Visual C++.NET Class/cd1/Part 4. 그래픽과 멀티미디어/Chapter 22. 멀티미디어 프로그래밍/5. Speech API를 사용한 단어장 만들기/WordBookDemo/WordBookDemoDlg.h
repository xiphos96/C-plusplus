// WordBookDemoDlg.h : 헤더 파일
//

#pragma once

// 단어장 클래스 헤더 파일 인크루드
#include "WordBook.h"


// CWordBookDemoDlg 대화 상자
class CWordBookDemoDlg : public CDialog
{
// 생성
public:
	CWordBookDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

	// 클라이언트 영역
	CRect		m_rcClient;

// 대화 상자 데이터
	//{{AFX_DATA(CWordBookDemoDlg)
	enum { IDD = IDD_WORDBOOKDEMO_DIALOG };
	CWordBook	m_WordBook;
	CString	m_strEnglish;
	CString	m_strKorean;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CWordBookDemoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CWordBookDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnAddButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
