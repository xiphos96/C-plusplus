#if !defined(AFX_CAMCAST_H__788A92EC_11DA_4DB3_A843_E96B645FA70B__INCLUDED_)
#define AFX_CAMCAST_H__788A92EC_11DA_4DB3_A843_E96B645FA70B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CamCast.h : header file
//

// Windows Media Encoder SDK
#include "wmencode.h"
#include "wmencvu.h"

// ATL : CComBSTR과 CComVariant를 사용하기 위한 헤더 파일
#include "Atlbase.h"


/////////////////////////////////////////////////////////////////////////////
// CCamCast window


// 동영상 녹화 방송 클래스
class CCamCast : public CStatic
{
// Construction
public:
	CCamCast();

// Attributes
public:
	IWMEncoder*					m_pEncoder;			// 미디어 인코더 인터페이스
	IWMEncDataView*				m_pPreview;			// 미리보기 인터페이스
	IWMEncDataViewCollection*	m_pPreviewColl;		// 미리보기 컬렉션 인터페이스
	long						m_lCookie;			// 미리보기 쿠키

	BOOL						m_bAudio;			// 오디오 소스 장치 존재 여부
	BOOL						m_bVideo;			// 비디오 소스 장치 존재 여부
	CComBSTR					m_strDeviceAudio;	// 오디오 장치의 이름
	CComBSTR					m_strDeviceVideo;	// 비디오 장치의 이름

// Operations
public:

	// 동영상 녹화 방송을 위한 초기화 함수
	BOOL Initialize();
	// 동영상 파일로 녹화하는 함수
	BOOL Record(LPCTSTR pFileName);
	// 인터넷으로 동영상을 방송하는 함수
	BOOL Cast(int nPort = 8080);
	// 동영상 녹화나 방송을 정지하는 함수
	BOOL Stop();
	// 동영상 녹화 방송에 대한 옵션 다이얼로그 출력 함수 
	BOOL Config();

	// 비디오 장치가 존재하는지 리턴하는 함수
	BOOL CanVideo()				{ return m_pEncoder && m_bVideo; }
	// 오디오 장치가 존재하는지 리턴하는 함수
	BOOL CanAudio()				{ return m_pEncoder && m_bAudio; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCamCast)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCamCast();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCamCast)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMCAST_H__788A92EC_11DA_4DB3_A843_E96B645FA70B__INCLUDED_)
