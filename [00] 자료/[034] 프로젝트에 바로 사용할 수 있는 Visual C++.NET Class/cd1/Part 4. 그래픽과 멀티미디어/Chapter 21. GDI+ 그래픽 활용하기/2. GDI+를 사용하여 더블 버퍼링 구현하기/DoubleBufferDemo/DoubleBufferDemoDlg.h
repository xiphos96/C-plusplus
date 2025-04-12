// DoubleBufferDemoDlg.h : 헤더 파일
//

#pragma once


// CDoubleBufferDemoDlg 대화 상자
class CDoubleBufferDemoDlg : public CDialog
{
// 생성
public:
	CDoubleBufferDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

	CRect		m_rcClient;			// 다이얼로그 클라이언트 영역
	CString		m_strMessage;		// 출력 메시지 텍스트
	CSize		m_TextSize;			// 텍스트 출력에 필요한 크기
	int			m_nCurPos;			// 현재 텍스트 출력 위치

// 대화 상자 데이터
	//{{AFX_DATA(CDoubleBufferDemoDlg)
	enum { IDD = IDD_DOUBLEBUFFERDEMO_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDoubleBufferDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CDoubleBufferDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
