#if !defined(AFX_IMAGEPROGRESSCTRL_H__8439D6D5_7B03_4FC2_BD38_F4AAC0A55F0F__INCLUDED_)
#define AFX_IMAGEPROGRESSCTRL_H__8439D6D5_7B03_4FC2_BD38_F4AAC0A55F0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageProgressCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImageProgressCtrl window

// 이미지 프로그레스바에서 진행 상태 표시 방법
enum TEXT_TYPE { TEXT_NONE = 0, TEXT_PERCENT, TEXT_FORMAT };
// 이미지 설정시 이미지의 위치
enum BMP_TYPE { BMP_LEFT = 0, BMP_CENTER, BMP_RIGHT };


// 이미지 프로그레스바 컨트롤 클래스
class CImageProgressCtrl : public CProgressCtrl
{
// Construction
public:
	CImageProgressCtrl();

// Attributes
public:
	// 배경 테두리 비트맵
	CBitmap		m_bmpBorderLeft;
	CBitmap		m_bmpBorderCenter;
	CBitmap		m_bmpBorderRight;

	// 진행바 비트맵
	CBitmap		m_bmpPosLeft;
	CBitmap		m_bmpPosCenter;
	CBitmap		m_bmpPosRight;

	// 배경 테두리 비트맵 정보
	BITMAP		m_infoBorderLeft;
	BITMAP		m_infoBorderCenter;
	BITMAP		m_infoBorderRight;

	// 진행바 비트맵 정보
	BITMAP		m_infoPosLeft;
	BITMAP		m_infoPosCenter;
	BITMAP		m_infoPosRight;

	// 이미지가 설정되지 않았을 경우 배경 테두리와 진행바를 그릴 색상들
	COLORREF	m_clrLight;					// 테두리 출력을 위한 밝은 색상
	COLORREF	m_clrShadow;				// 테두리 출력을 위한 어두운 색상
	COLORREF	m_clrBkgnd;					// 배경색
	COLORREF	m_clrPos;					// 진행바 색상

	COLORREF	m_clrText;					// 텍스트 색상
	TEXT_TYPE	m_nTextType;				// 진행 상태 출력 형식
	CString		m_strFormat;				// 문자열 포맷을 사용할 경우 포맷 문자열
	CString		m_strFontName;				// 텍스트 출력용 폰트 이름
	int			m_nFontSize;				// 텍스트 출력용 폰트 크기
	CFont		m_TextFont;					// 텍스트 출력용 폰트

	BOOL		m_bHorz;					// 프로그레스바가 수평인지 수직인지 여부
	CRect		m_rcClient;					// 클라이언트 영역

// Operations
public:
	// 진행 상태 출력 형식을 리턴/설정하는 함수
	TEXT_TYPE GetTextType()				{ return m_nTextType; }
	void SetTextType(TEXT_TYPE nType);
	// 문자열 포맷을 리턴/설정하는 함수
	LPCTSTR GetTextFormat()				{ return m_strFormat; }
	void SetTextFormat(LPCTSTR pFormat);

	// 테두리 밝은 색상 리턴/설정 함수
	COLORREF GetLightColor()			{ return m_clrLight; }
	void SetLightColor(COLORREF clrLight);
	// 테두리 어두운 색상 리턴/설정 함수
	COLORREF GetShadowColor()			{ return m_clrShadow; }
	void SetShadowColor(COLORREF clrShadow);
	// 배경색 리턴/설정 함수
	COLORREF GetBkgndColor()			{ return m_clrBkgnd; }
	void SetBkgndColor(COLORREF clrBkgnd);
	// 진행바 색상 리턴/설정 함수
	COLORREF GetPosColor()				{ return m_clrPos; }
	void SetPosColor(COLORREF clrPos);

	// 텍스트 색상 리턴/설정 함수
	COLORREF GetTextColor()				{ return m_clrText; }
	void SetTextColor(COLORREF clrText);

	// 폰트 이름 리턴 함수
	LPCTSTR GetFontName()				{ return m_strFontName; }
	// 폰트 크기 리턴 함수
	int GetFontSize()					{ return m_nFontSize; }
	// 폰트 설정 함수
	void SetTextFont(int nSize, LPCTSTR pFontName);

	// 배경 테두리 비트맵 리턴/설정 함수
	HBITMAP GetBorderBitmap(BMP_TYPE nType);
	void SetBorderBitmap(BMP_TYPE nType, UINT nBmpID);
	void SetBorderBitmap(BMP_TYPE nType, HBITMAP hBmp);
	// 진행바 비트맵 리턴/설정 함수
	HBITMAP GetPosBitmap(BMP_TYPE nType);
	void SetPosBitmap(BMP_TYPE nType, UINT nBmpID);
	void SetPosBitmap(BMP_TYPE nType, HBITMAP hBmp);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageProgressCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageProgressCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImageProgressCtrl)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnNcPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEPROGRESSCTRL_H__8439D6D5_7B03_4FC2_BD38_F4AAC0A55F0F__INCLUDED_)
