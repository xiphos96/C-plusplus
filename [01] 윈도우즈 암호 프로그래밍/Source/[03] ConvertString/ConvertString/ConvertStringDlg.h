﻿
// ConvertStringDlg.h: 헤더 파일
//

#pragma once

#include "../Files/Include/gmp.h"
#include "../Files/Include/crylib/byte_string.h"

// CConvertStringDlg 대화 상자
class CConvertStringDlg : public CDialogEx
{
// 생성입니다.
public:
	CConvertStringDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONVERTSTRING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnConvertToNumber();
private:
	void mympz_inp_raw(mpz_t z, const unsigned char* c, int n);
	void mympz_out_raw(mpz_t x, unsigned char* c, int n);
	int mympz_sizeinbytes(mpz_t x);
public:
	afx_msg void OnBnClickedBtnConvertToCharacter();
};
