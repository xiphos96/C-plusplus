// ChangeShapeDlg.h : 헤더 파일
//

#pragma once


// CChangeShapeDlg 대화 상자

// 다이얼로그의 모양을 바꾸기 위해 CShapeDlg에서 상속 받는다
#include "ShapeDlg.h"

class CChangeShapeDlg : public CShapeDlg
{
// 생성
public:
	CChangeShapeDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CChangeShapeDlg)
	enum { IDD = IDD_CHANGESHAPE_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CChangeShapeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	CBitmap		m_bmpWindow;				// 다이얼로그 모양 변경에 사용하고, 배경에 출력할 이미지
	BITMAP		m_bmpInfo;					// m_bmpWindow의 정보 변수

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CChangeShapeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
