// AnimGIF.cpp : implementation file
//

#include "stdafx.h"
#include "animgifdemo.h"
#include "AnimGIF.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimGIF

CAnimGIF::CAnimGIF()
// 이벤트 객체를 수동 설정 형태로 생성한다
: m_RunEvent(NULL, TRUE, NULL, NULL), m_ExitEvent(NULL, TRUE, NULL, NULL)
{
	m_pGIFImage = NULL;
	m_hImageData = NULL;
	m_pProperty = NULL;
	m_pDimensionID = NULL;

	m_nFrameSize = 0;
	m_nCurFrame = 0;

	m_hAnimationThread = NULL;
}

CAnimGIF::~CAnimGIF()
{
	// 이미지가 생성되었다면
	if(m_pGIFImage)
	{
		// 애니메이션 스레드가 동작 중이라면
		if(m_hAnimationThread)
		{
			// 스레드 종료 이벤트를 설정한다
			m_ExitEvent.SetEvent();
			// 스레드 종료를 대기한다
			::WaitForSingleObject(m_hAnimationThread, INFINITE);
			m_hAnimationThread = NULL;
		}

		// 이미지를 제거한다
		delete m_pGIFImage;
	}
	// 이미지 데이터의 메모리를 해제한다
	if(m_hImageData)	::GlobalFree(m_hImageData);
	// 이미지 정보 배열을 제거한다
	if(m_pProperty)		delete[] (char*)m_pProperty;
	// 이미지 디멘션 배열을 제거한다
	if(m_pDimensionID)	delete[] m_pDimensionID;
	// 멤버 변수를 초기화한다
	m_pGIFImage = NULL;
	m_hImageData = NULL;
	m_pProperty = NULL;
	m_pDimensionID = NULL;
	m_nFrameSize = 0;
	m_nCurFrame = 0;
}


BEGIN_MESSAGE_MAP(CAnimGIF, CStatic)
	//{{AFX_MSG_MAP(CAnimGIF)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimGIF message handlers

// 애니메이션 GIF 파일을 로드하는 함수
BOOL CAnimGIF::LoadGIF(LPCTSTR pFileName)
{
	// 이미지가 생성되었다면
	if(m_pGIFImage)
	{
		// 애니메이션 스레드가 동작 중이라면
		if(m_hAnimationThread)
		{
			// 스레드 종료 이벤트를 설정한다
			m_ExitEvent.SetEvent();
			// 스레드 종료를 대기한다
			::WaitForSingleObject(m_hAnimationThread, INFINITE);
			m_hAnimationThread = NULL;
		}

		// 이미지를 제거한다
		delete m_pGIFImage;
	}
	// 이미지 데이터의 메모리를 해제한다
	if(m_hImageData)	::GlobalFree(m_hImageData);
	// 이미지 정보 배열을 제거한다
	if(m_pProperty)		delete[] (char*)m_pProperty;
	// 이미지 디멘션 배열을 제거한다
	if(m_pDimensionID)	delete[] m_pDimensionID;
	// 멤버 변수를 초기화한다
	m_pGIFImage = NULL;
	m_hImageData = NULL;
	m_pProperty = NULL;
	m_pDimensionID = NULL;
	m_nFrameSize = 0;
	m_nCurFrame = 0;

	// 이벤트 객체들을 초기화한다
	m_ExitEvent.ResetEvent();
	m_RunEvent.ResetEvent();

	CFile InFile;

	// 애니메이션 GIF 파일을 연다
	if(!InFile.Open(pFileName, CFile::modeRead | CFile::typeBinary))
		return FALSE;

	// 애니메이션 GIF 크기만큼 메모리를 확보한다
	int nSize = InFile.GetLength();
	char *pBuffer = new char[nSize];
	
	// 애니메이션 GIF 파일을 메모리로 읽어온다
	if(InFile.Read(pBuffer, nSize) <= 0)
	{
		InFile.Close();
		return FALSE;
	}

	// 애니메이션 GIF 파일을 닫는다
	InFile.Close();

	// 이미지 데이터에서 Image 객체를 만든다
	if(!LoadGIFFromMemory(pBuffer, nSize))
	{
		delete[] pBuffer;

		return FALSE;
	}

	// 메모리 해제
	delete[] pBuffer;

	return TRUE;
}

// 애니메이션 GIF 리소스를 로드하는 함수
BOOL CAnimGIF::LoadGIF(UINT nResourceID, LPCTSTR pResourceType)
{
	// 이미지가 생성되었다면
	if(m_pGIFImage)
	{
		// 애니메이션 스레드가 동작 중이라면
		if(m_hAnimationThread)
		{
			// 스레드 종료 이벤트를 설정한다
			m_ExitEvent.SetEvent();
			// 스레드 종료를 대기한다
			::WaitForSingleObject(m_hAnimationThread, INFINITE);
			m_hAnimationThread = NULL;
		}

		// 이미지를 제거한다
		delete m_pGIFImage;
	}
	// 이미지 데이터의 메모리를 해제한다
	if(m_hImageData)	::GlobalFree(m_hImageData);
	// 이미지 정보 배열을 제거한다
	if(m_pProperty)		delete[] (char*)m_pProperty;
	// 이미지 디멘션 배열을 제거한다
	if(m_pDimensionID)	delete[] m_pDimensionID;
	// 멤버 변수를 초기화한다
	m_pGIFImage = NULL;
	m_hImageData = NULL;
	m_pProperty = NULL;
	m_pDimensionID = NULL;
	m_nFrameSize = 0;
	m_nCurFrame = 0;

	// 이벤트를 초기화한다
	m_ExitEvent.ResetEvent();
	m_RunEvent.ResetEvent();

	// 리소스를 검색하여 리소스 핸들을 얻는다
	HRSRC hRes = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(nResourceID), pResourceType);
	if(hRes == NULL)					return FALSE;

	// 리소스를 로드한다
	HGLOBAL hGlobal = ::LoadResource(AfxGetResourceHandle(), hRes);
	if(hGlobal == NULL)					return FALSE;

	// 리소스 메모리를 잠궈 리소스 데이터를 얻는다
	char *pBuffer = (char*)::LockResource(hGlobal);
	if(pBuffer == NULL)					return FALSE;

	// 리소스의 사이즈를 얻는다
	int nSize = ::SizeofResource(AfxGetResourceHandle(), hRes);

	// 리소스 데이터에서 Image 객체를 만든다
	if(!LoadGIFFromMemory(pBuffer, nSize))	return FALSE;

	return TRUE;
}

// 로드된 데이터로부터 이미지 객체를 생성하는 함수
BOOL CAnimGIF::LoadGIFFromMemory(LPCTSTR pBuffer, int nSize)
{
	// 이미지 데이터만큼 전역 메모리를 확보한다
	m_hImageData = ::GlobalAlloc(GHND, nSize);
	if(m_hImageData == NULL)		return FALSE;

	// 전역 메모리를 잠군다
	LPVOID pData = ::GlobalLock(m_hImageData);
	// 이미지 데이터를 복사한다
	::memcpy(pData, pBuffer, nSize);
	// 잠긴 전역 메모리를 푼다
	::GlobalUnlock(m_hImageData);

	IStream *pStream = NULL;

	// 이미지 데이터에 대한 IStream 인터페이스 객체를 생성한다
	if(::CreateStreamOnHGlobal(m_hImageData, TRUE, &pStream) != S_OK)
	{
		::GlobalFree(m_hImageData);
		m_hImageData = NULL;
		return FALSE;
	}

	// IStream의 데이터를 사용해서 Image 객체를 만든다
	m_pGIFImage = new Image(pStream, FALSE);

	// IStream 인터페이스를 해제한다
	pStream->Release();

	// GIF의 프레임 디멘션 크기를 얻는다
	int nDimensionSize = m_pGIFImage->GetFrameDimensionsCount();

	// GIF의 프레임 디멘션 ID들을 얻는다
	m_pDimensionID = new GUID[nDimensionSize];
	m_pGIFImage->GetFrameDimensionsList(m_pDimensionID, nDimensionSize);

	// GIF의 프레임 갯수를 얻는다
	m_nFrameSize = m_pGIFImage->GetFrameCount(m_pDimensionID);

	// 프레임들의 대기 시간 속성 크기를 얻는다
	int nPropertySize = m_pGIFImage->GetPropertyItemSize(PropertyTagFrameDelay);

	// 프레임 대기 시간 속성들을 얻는다
	m_pProperty = (PropertyItem*)(new char[nPropertySize]);
	m_pGIFImage->GetPropertyItem(PropertyTagFrameDelay, nPropertySize, m_pProperty);

	return TRUE;
}

// 애니메이션을 실행하는 함수
BOOL CAnimGIF::Play()
{
	if(m_pGIFImage == NULL)		return FALSE;

	// 애니메이션 스레드가 동작 중이라면
	if(m_hAnimationThread)
	{
		// 스레드 종료 이벤트를 설정한다
		m_ExitEvent.SetEvent();
		// 스레드 종료를 대기한다
		::WaitForSingleObject(m_hAnimationThread, INFINITE);
		m_hAnimationThread = NULL;
	}

	UINT nID;

	// 애니메이션 스레드를 생성한다
	m_hAnimationThread = (HANDLE)_beginthreadex(NULL, 0, AnimationProc, this, CREATE_SUSPENDED, &nID);

	if(m_hAnimationThread == NULL)	return FALSE;

	// 실행 이벤트를 Signal 상태로 설정한다
	m_RunEvent.SetEvent();
	// 스레드를 실행한다
	::ResumeThread(m_hAnimationThread);

	return TRUE;
}

// 애니메이션을 일시정지하는 함수
BOOL CAnimGIF::Pause()
{
	if(m_pGIFImage == NULL)		return FALSE;

	// 실행 이벤트를 Non-signal 상태로 초기화한다
	m_RunEvent.ResetEvent();

	return TRUE;
}

// 일시정지된 애니메이션을 다시 시작하는 함수
BOOL CAnimGIF::Resume()
{
	if(m_pGIFImage == NULL)		return FALSE;

	// 실행 이벤트를 Signal 상태로 설정한다
	m_RunEvent.SetEvent();

	return TRUE;
}

// 애니메이션 출력용 스레드 함수
UINT WINAPI CAnimGIF::AnimationProc(LPVOID pParam)
{
	CAnimGIF *pAnimGIF = (CAnimGIF*)pParam;

	CRect rcClient;
	pAnimGIF->GetClientRect(&rcClient);

	// 이미지의 크기를 얻는다
	int nWidth = pAnimGIF->m_pGIFImage->GetWidth();
	int nHeight = pAnimGIF->m_pGIFImage->GetHeight();

	// 화면 중앙으로 이미지를 출력하기 위한 위치를 계산한다
	int xPos = (rcClient.Width() - nWidth) / 2;
	int yPos = (rcClient.Height() - nHeight) / 2;
	LONG nWait;

	while(1)
	{
		// 실행 이벤트가 설정될 때까지 대기한다
		::WaitForSingleObject(pAnimGIF->m_RunEvent.m_hObject, INFINITE);

		// DC 핸들로부터 Graphics 객체를 만든다
		CDC *pDC = pAnimGIF->GetDC();
		Graphics graphics(pDC->m_hDC);

		// GIF의 프레임을 출력한다
		graphics.DrawImage(pAnimGIF->m_pGIFImage, xPos, yPos, nWidth, nHeight);

		pAnimGIF->ReleaseDC(pDC);

		// GIF의 프레임을 이동한다
		pAnimGIF->m_nCurFrame++;

		// GIF의 끝 프레임이라면 처음 프레임으로 이동한다
		if(pAnimGIF->m_nCurFrame == pAnimGIF->m_nFrameSize)
			pAnimGIF->m_nCurFrame = 0;

		// 현재 프레임 번호에 따라 프레임을 설정한다
		pAnimGIF->m_pGIFImage->SelectActiveFrame(pAnimGIF->m_pDimensionID, pAnimGIF->m_nCurFrame);

		// 대기 시간을 계산한다
		nWait = ((LONG*)pAnimGIF->m_pProperty->value)[pAnimGIF->m_nCurFrame] * 10;

		// 대기 시간만큼 대기한다
		if(WaitForSingleObject(pAnimGIF->m_ExitEvent.m_hObject, nWait) == WAIT_OBJECT_0)
			break;
	}

	return 0;
}

void CAnimGIF::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rcClient;
	GetClientRect(&rcClient);

	// Graphics 객체를 생성한다
	Graphics graphics(dc.m_hDC);
	Rect rectClient(0, 0, rcClient.Width(), rcClient.Height());

	// 검은색 브러쉬를 생성한다
	SolidBrush *pBlackBrush = new SolidBrush(Color.Black);

	// 배경을 검은색 브러쉬로 칠한다
	graphics.FillRectangle(pBlackBrush, rectClient);

	// 애니메이션이 실행되지 않았다면
	if(m_hAnimationThread == NULL)
	{
		// 이미지가 로드되어 있다면
		if(m_pGIFImage)
		{
			// 이미지의 크기를 얻는다
			int nWidth = m_pGIFImage->GetWidth();
			int nHeight = m_pGIFImage->GetHeight();
			// 화면 중앙으로 이미지를 출력하기 위한 위치를 계산한다
			int xPos = (rcClient.Width() - nWidth) / 2;
			int yPos = (rcClient.Height() - nHeight) / 2;

			// 현재 프레임을 화면에 출력한다
			graphics.DrawImage(m_pGIFImage, xPos, yPos, nWidth, nHeight);
		}
	}

	// 검은색 브러쉬를 제거한다
	delete pBlackBrush;
}

BOOL CAnimGIF::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CAnimGIF::OnDestroy() 
{
	CStatic::OnDestroy();

	// 이미지가 생성되었다면
	if(m_pGIFImage)
	{
		// 애니메이션 스레드가 동작 중이라면
		if(m_hAnimationThread)
		{
			// 스레드 종료 이벤트를 설정한다
			m_ExitEvent.SetEvent();
			// 스레드 종료를 대기한다
			::WaitForSingleObject(m_hAnimationThread, INFINITE);
			m_hAnimationThread = NULL;
		}

		// 이미지를 제거한다
		delete m_pGIFImage;
	}
	// 이미지 데이터의 메모리를 해제한다
	if(m_hImageData)	::GlobalFree(m_hImageData);
	// 이미지 정보 배열을 제거한다
	if(m_pProperty)		delete[] (char*)m_pProperty;
	// 이미지 디멘션 배열을 제거한다
	if(m_pDimensionID)	delete[] m_pDimensionID;
	// 멤버 변수를 초기화한다
	m_pGIFImage = NULL;
	m_hImageData = NULL;
	m_pProperty = NULL;
	m_pDimensionID = NULL;
	m_nFrameSize = 0;
	m_nCurFrame = 0;
}
