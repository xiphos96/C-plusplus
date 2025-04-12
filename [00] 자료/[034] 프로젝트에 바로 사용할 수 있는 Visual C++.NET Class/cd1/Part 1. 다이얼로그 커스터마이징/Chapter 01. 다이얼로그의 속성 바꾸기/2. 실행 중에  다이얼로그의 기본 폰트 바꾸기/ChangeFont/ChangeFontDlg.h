// ChangeFontDlg.h : 헤더 파일
//

#pragma once


// CChangeFontDlg 대화 상자
class CChangeFontDlg : public CDialog
{
// 생성
public:
	CChangeFontDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CChangeFontDlg)
	enum { IDD = IDD_CHANGEFONT_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CChangeFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL

	CString	m_strFontName;			// 폰트 대화상자에서 입력한 폰트 이름
	int		m_nFontSize;			// 폰트 대화상자에서 입력한 폰트 크기

// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CChangeFontDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFontButton();
	afx_msg void OnDomodalButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
