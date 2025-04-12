#include "stdafx.h"
#include "Picture.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define HIMETRIC_INCH 2540


CPicture::CPicture()
{
	m_pIPicture		= NULL;
	m_nHeight		= 0;
	m_nWidth		= 0;
	m_nOleWidth		= 0;
	m_nOleHeight	= 0;
}

CPicture::~CPicture()
{
	// 메모리를 초기화 시킨다
	ReleasePicture();
}

// 이미지 파일을 로드하는 함수
BOOL CPicture::Load(LPCTSTR pFileName)
{
	// 이미 로드된 이미지가 있으면 초기화한다
	if(m_pIPicture != NULL)		ReleasePicture();

	CFile InFile;

	// 이미지 파일을 연다
	if(!InFile.Open(pFileName, CFile::modeRead | CFile::typeBinary))
		return FALSE;

	// 이미지 크기만큼 메모리를 확보한다
	int nSize = InFile.GetLength();
	char *pBuffer = new char[nSize];
	
	// 이미지 파일을 메모리로 읽어온다
	if(InFile.Read(pBuffer, nSize) <= 0)
		return FALSE;

	// 이미지 파일을 닫는다
	InFile.Close();

	// 이미지 데이터에서 IPicture 객체를 만든다
	if(!LoadPicture(pBuffer, nSize))
	{
		delete[] pBuffer;

		return FALSE;
	}

	delete[] pBuffer;

	// 이미지 크기를 구한다 : 단위는 OLE_XSIZE_HIMETRIC이다
	// OLE_XSIZE_HIMETRIC는 1/2540인치
	m_pIPicture->get_Width((long*)&m_nOleWidth);
	m_pIPicture->get_Height((long*)&m_nOleHeight);

	HDC hDC = ::GetDC(NULL);

	// OLE_XSIZE_HIMETRIC 단위의 폭을 픽셀 단위로 변경한다
	m_nWidth = MulDiv(m_nOleWidth, ::GetDeviceCaps(hDC, LOGPIXELSX), HIMETRIC_INCH);
	// OLE_XSIZE_HIMETRIC 단위의 높이를 픽셀 단위로 변경한다
	m_nHeight = MulDiv(m_nOleHeight, ::GetDeviceCaps(hDC, LOGPIXELSY), HIMETRIC_INCH);

	::ReleaseDC(NULL, hDC);

	return TRUE;
}

// 이미지 리소스를 로드하는 함수
BOOL CPicture::Load(UINT nResourceID, LPCSTR pResourceType)
{
	// 이미 로드된 이미지가 있으면 초기화한다
	if(m_pIPicture != NULL)		ReleasePicture();

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

	// 리소스 데이터에서 IPicture 객체를 만든다
	if(!LoadPicture(pBuffer, nSize))	return FALSE;

	// 이미지 크기를 구한다 : 단위는 OLE_XSIZE_HIMETRIC이다
	// OLE_XSIZE_HIMETRIC는 1/2540인치
	m_pIPicture->get_Width((long*)&m_nOleWidth);
	m_pIPicture->get_Height((long*)&m_nOleHeight);

	HDC hDC = ::GetDC(NULL);

	// OLE_XSIZE_HIMETRIC 단위의 폭을 픽셀 단위로 변경한다
	m_nWidth = MulDiv(m_nOleWidth, ::GetDeviceCaps(hDC, LOGPIXELSX), HIMETRIC_INCH);
	// OLE_XSIZE_HIMETRIC 단위의 높이를 픽셀 단위로 변경한다
	m_nHeight = MulDiv(m_nOleHeight, ::GetDeviceCaps(hDC, LOGPIXELSY), HIMETRIC_INCH);

	::ReleaseDC(NULL, hDC);

	return TRUE;
}

// 이미지 데이터에서 로드하는 함수
BOOL CPicture::LoadFromMemory(LPCTSTR pBuffer, int nSize)
{
	// 이미 로드된 이미지가 있으면 초기화한다
	if(m_pIPicture != NULL)		ReleasePicture();

	// 이미지 데이터에서 IPicture 객체를 만든다
	if(!LoadPicture(pBuffer, nSize))	return FALSE;

	// 이미지 크기를 구한다 : 단위는 OLE_XSIZE_HIMETRIC이다
	// OLE_XSIZE_HIMETRIC는 1/2540인치
	m_pIPicture->get_Width((long*)&m_nOleWidth);
	m_pIPicture->get_Height((long*)&m_nOleHeight);

	HDC hDC = ::GetDC(NULL);

	// OLE_XSIZE_HIMETRIC 단위의 폭을 픽셀 단위로 변경한다
	m_nWidth = MulDiv(m_nOleWidth, ::GetDeviceCaps(hDC, LOGPIXELSX), HIMETRIC_INCH);
	// OLE_XSIZE_HIMETRIC 단위의 높이를 픽셀 단위로 변경한다
	m_nHeight = MulDiv(m_nOleHeight, ::GetDeviceCaps(hDC, LOGPIXELSY), HIMETRIC_INCH);

	::ReleaseDC(NULL, hDC);

	return TRUE;
}

// IPicture 객체를 생성하는 내부 함수
BOOL CPicture::LoadPicture(LPCTSTR pBuffer, int nSize)
{
	// 이미지 데이터만큼 전역 메모리를 확보한다
	HGLOBAL hGlobal = ::GlobalAlloc(GHND, nSize);
	if(hGlobal == NULL)		return FALSE;

	// 전역 메모리를 잠군다
	LPVOID pData = ::GlobalLock(hGlobal);
	// 이미지 데이터를 복사한다
	::memcpy(pData, pBuffer, nSize);
	// 잠긴 전역 메모리를 푼다
	::GlobalUnlock(hGlobal);

	IStream *pStream = NULL;

	// 이미지 데이터에 대한 IStream 인터페이스 객체를 생성한다
	if(::CreateStreamOnHGlobal(hGlobal, TRUE, &pStream) != S_OK)
	{
		::GlobalFree(hGlobal);
		return FALSE;
	}

	// IStream 인터페이스가 갖는 이미지를 출력할 수 있는 IPicture 객체를 만든다
	HRESULT hr = ::OleLoadPicture(pStream, nSize, FALSE, IID_IPicture, (LPVOID *)&m_pIPicture);
	if(hr != S_OK)		m_pIPicture = NULL;

	// IStream 인터페이스를 해제한다
	pStream->Release();
	// 전역 메모리를 해제한다
	::GlobalFree(hGlobal);

	return (hr == S_OK);
}

// 메모리를 초기화하는 함수
void CPicture::ReleasePicture()
{
	if(m_pIPicture != NULL)
	{
		// IPicture 객체를 해제한다
		m_pIPicture->Release();
		m_pIPicture = NULL;

		m_nHeight	= 0;
		m_nWidth	= 0;
		m_nOleWidth		= 0;
		m_nOleHeight	= 0;
	}
}

// 화면 출력 함수
BOOL CPicture::Draw(CDC *pDC)
{
	if(m_pIPicture == NULL)		return FALSE;

	CRect rcRect(0, 0, m_nWidth, m_nHeight);

	// IPicture 객체가 갖고 있는 이미지를 화면에 출력한다
	HRESULT hr = m_pIPicture->Render(pDC->m_hDC,
		0, 0, m_nWidth, m_nHeight,
		0, m_nOleHeight, m_nOleWidth, -m_nOleHeight, &rcRect);

	return (hr == S_OK);
}

// 화면 출력 함수
BOOL CPicture::Draw(CDC *pDC, CRect rcRect)
{
	if(m_pIPicture == NULL)		return FALSE;

	// IPicture 객체가 갖고 있는 이미지를 화면의 특정 영역에 출력한다
	HRESULT hr = m_pIPicture->Render(pDC->m_hDC,
		rcRect.left, rcRect.top, rcRect.Width(), rcRect.Height(),
		0, m_nOleHeight, m_nOleWidth, -m_nOleHeight, &rcRect);

	return (hr == S_OK);
}

// 이미지에 대한 비트맵 핸들을 리턴하는 함수
HBITMAP CPicture::GetHBITMAP()
{
	if(m_pIPicture == NULL)		return NULL;

	short nType = PICTYPE_UNINITIALIZED;

	// IPicture 객체가 갖고 있는 이미지의 타입을 얻는다
	m_pIPicture->get_Type(&nType);

	// 이미지 타입이 비트맵인지 확인한다
	if(nType != PICTYPE_BITMAP)	return NULL;

	OLE_HANDLE hBitmap;

	// 이미지에 대한 OLE 데이터 핸들을 얻는다
	m_pIPicture->get_Handle(&hBitmap);

	// 비트맵 핸들 타입으로 리턴한다
	return (HBITMAP)hBitmap;
}
