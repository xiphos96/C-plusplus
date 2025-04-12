#if !defined(AFX_ANIMGIF_H__68369C47_E3B7_4ACA_AC8F_2F216012034F__INCLUDED_)
#define AFX_ANIMGIF_H__68369C47_E3B7_4ACA_AC8F_2F216012034F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnimGIF.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnimGIF window

// CEvent 클래스 사용을 위한 헤더 파일
#include <afxmt.h>
// _beginthreadex() 함수 사용을 위한 헤더 파일
#include <process.h>


// 애니메이션 GIF 출력용 클래스
class CAnimGIF : public CStatic
{
// Construction
public:
	CAnimGIF();

// Attributes
public:
	Image					*m_pGIFImage;			// 애니메이션 GIF 출력용 이미지 클래스
	HGLOBAL					m_hImageData;			// 로드된 애니메이션 GIF 데이터

	UINT					m_nFrameSize;			// 애니메이션의 프레임 수
	UINT					m_nCurFrame;			// 현재 출력 프레임 번호
	PropertyItem			*m_pProperty;			// 프레임 지속 시간 정보
	GUID					*m_pDimensionID;		// 애니메이션 디멘션 ID

	HANDLE					m_hAnimationThread;		// 애니메이션 스레드 핸들
	CEvent					m_RunEvent;				// 스레드 실행 이벤트 객체
	CEvent					m_ExitEvent;			// 스레드 종료용 이벤트 객체

// Operations
public:
	// 애니메이션 GIF 파일을 로드하는 함수
	BOOL LoadGIF(LPCTSTR pFileName);
	// 애니메이션 GIF 리소스를 로드하는 함수
	BOOL LoadGIF(UINT nResourceID, LPCTSTR pResourceType);

	// 로드된 데이터로부터 이미지 객체를 생성하는 함수
	BOOL LoadGIFFromMemory(LPCTSTR pBuffer, int nSize);

	// 애니메이션을 실행하는 함수
	BOOL Play();
	// 애니메이션을 일시정지하는 함수
	BOOL Pause();
	// 일시정지된 애니메이션을 다시 시작하는 함수
	BOOL Resume();

	// 애니메이션 출력용 스레드 함수
	static UINT WINAPI AnimationProc(LPVOID pParam);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimGIF)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAnimGIF();

	// Generated message map functions
protected:
	//{{AFX_MSG(CAnimGIF)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMGIF_H__68369C47_E3B7_4ACA_AC8F_2F216012034F__INCLUDED_)
