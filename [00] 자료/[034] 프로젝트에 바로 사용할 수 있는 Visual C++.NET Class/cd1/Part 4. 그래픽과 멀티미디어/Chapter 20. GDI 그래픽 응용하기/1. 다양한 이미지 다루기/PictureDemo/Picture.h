#pragma once


// 이미지 출력 클래스
// 지원 파일 형식 : BMP, DIB, EMF, GIF, ICO, JPG, WMF

class CPicture
{
public:
	IPicture				*m_pIPicture;			// IPicture 인터페이스 포인터

	int						m_nWidth;				// 이미지의 폭 : 단위 픽셀
	int						m_nHeight;				// 이미지의 높이 : 단위 픽셀
	OLE_XSIZE_HIMETRIC		m_nOleWidth;
	OLE_YSIZE_HIMETRIC		m_nOleHeight;

	CPicture();
	virtual ~CPicture();

	// 이미지 파일을 로드하는 함수
	BOOL Load(LPCTSTR pFileName);
	// 이미지 리소스를 로드하는 함수
	BOOL Load(UINT nResourceID, LPCSTR pResourceType);
	// 이미지 데이터에서 로드하는 함수
	BOOL LoadFromMemory(LPCTSTR pBuffer, int nSize);

	// 메모리를 초기화하는 함수
	void ReleasePicture();

	// 화면 출력 함수
	BOOL Draw(CDC *pDC);
	BOOL Draw(CDC *pDC, CRect rcRect);

	// 이미지 폭을 리턴하는 함수
	int GetWidth()					{ return m_nWidth; }
	// 이미지 높이를 리턴하는 함수
	int GetHeight()					{ return m_nHeight; }
	// 이미지가 현재 로딩되어 있는지 리턴하는 함수
	BOOL IsLoaded()					{ return (m_pIPicture != NULL); }
	// 이미지에 대한 비트맵 핸들을 리턴하는 함수
	HBITMAP GetHBITMAP();

protected:
	// IPicture 객체를 생성하는 내부 함수
	BOOL LoadPicture(LPCTSTR pBuffer, int nSize);
};
