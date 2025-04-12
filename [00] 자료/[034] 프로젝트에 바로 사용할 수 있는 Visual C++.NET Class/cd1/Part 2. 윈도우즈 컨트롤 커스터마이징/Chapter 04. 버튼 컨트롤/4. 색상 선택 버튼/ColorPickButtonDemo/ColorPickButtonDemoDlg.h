// ColorPickButtonDemoDlg.h : 헤더 파일
//

#pragma once

// 색상 선택 버튼 클래스 헤더 파일
#include "ColorPickButton.h"


// CColorPickButtonDemoDlg 대화 상자
class CColorPickButtonDemoDlg : public CDialog
{
// 생성
public:
	CColorPickButtonDemoDlg(CWnd* pParent = NULL);	// 표준 생성자
	virtual ~CColorPickButtonDemoDlg();

// 대화 상자 데이터
	//{{AFX_DATA(CColorPickButtonDemoDlg)
	enum { IDD = IDD_COLORPICKBUTTONDEMO_DIALOG };
	CColorPickButton	m_btnTextDefault;			// 기본 글자 색상 선택 버튼
	CColorPickButton	m_btnBkgndDefault;			// 기본 배경 색상 선택 버튼
	CColorPickButton	m_btnText;					// 글자 색상 선택 버튼
	CColorPickButton	m_btnBkgnd;					// 배경 색상 선택 버튼
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CColorPickButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL

	COLORREF	m_clrTextDefault;					// 현재 기본 글자 색상
	COLORREF	m_clrBkgndDefault;					// 현재 기본 배경 색상
	COLORREF	m_clrText;							// 현재 글자 색상
	COLORREF	m_clrBkgnd;							// 현재 배경 색상

	CBrush		m_BkgndBrush;						// 배경 출력용 브러쉬

// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CColorPickButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	afx_msg LRESULT OnSelEndOKColor(WPARAM wParam, LPARAM lParam);	// 색상 선택 완료 메시지 핸들러
	DECLARE_MESSAGE_MAP()
};
