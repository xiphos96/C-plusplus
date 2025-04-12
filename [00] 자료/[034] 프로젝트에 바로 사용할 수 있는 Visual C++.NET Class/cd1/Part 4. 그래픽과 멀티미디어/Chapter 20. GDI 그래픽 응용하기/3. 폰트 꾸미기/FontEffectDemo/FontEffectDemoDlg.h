// FontEffectDemoDlg.h : 헤더 파일
//

#pragma once

#include "FontEffect.h"


// CFontEffectDemoDlg 대화 상자
class CFontEffectDemoDlg : public CDialog
{
// 생성
public:
	CFontEffectDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CFontEffectDemoDlg)
	enum { IDD = IDD_FONTEFFECTDEMO_DIALOG };
	CFontEffect	m_FontEffect;
	CButton	m_btnShape3;
	CButton	m_btnShape2;
	CButton	m_btnShape1;
	BOOL	m_bOutLine;
	int		m_nShapeType;
	CString	m_strText;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFontEffectDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL

	static void ShapeFunc1(int nSize, CPoint *pPoint, CSize TextSize);
	static void ShapeFunc2(int nSize, CPoint *pPoint, CSize TextSize);
	static void ShapeFunc3(int nSize, CPoint *pPoint, CSize TextSize);


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CFontEffectDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShapeButton1();
	afx_msg void OnShapeButton2();
	afx_msg void OnShapeButton3();
	afx_msg void OnOutlineCheck();
	afx_msg void OnRefreshButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
