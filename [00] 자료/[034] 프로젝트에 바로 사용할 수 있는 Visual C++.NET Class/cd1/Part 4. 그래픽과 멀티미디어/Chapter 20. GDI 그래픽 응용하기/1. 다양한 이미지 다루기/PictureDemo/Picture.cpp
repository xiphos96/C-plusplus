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
	// �޸𸮸� �ʱ�ȭ ��Ų��
	ReleasePicture();
}

// �̹��� ������ �ε��ϴ� �Լ�
BOOL CPicture::Load(LPCTSTR pFileName)
{
	// �̹� �ε�� �̹����� ������ �ʱ�ȭ�Ѵ�
	if(m_pIPicture != NULL)		ReleasePicture();

	CFile InFile;

	// �̹��� ������ ����
	if(!InFile.Open(pFileName, CFile::modeRead | CFile::typeBinary))
		return FALSE;

	// �̹��� ũ�⸸ŭ �޸𸮸� Ȯ���Ѵ�
	int nSize = InFile.GetLength();
	char *pBuffer = new char[nSize];
	
	// �̹��� ������ �޸𸮷� �о�´�
	if(InFile.Read(pBuffer, nSize) <= 0)
		return FALSE;

	// �̹��� ������ �ݴ´�
	InFile.Close();

	// �̹��� �����Ϳ��� IPicture ��ü�� �����
	if(!LoadPicture(pBuffer, nSize))
	{
		delete[] pBuffer;

		return FALSE;
	}

	delete[] pBuffer;

	// �̹��� ũ�⸦ ���Ѵ� : ������ OLE_XSIZE_HIMETRIC�̴�
	// OLE_XSIZE_HIMETRIC�� 1/2540��ġ
	m_pIPicture->get_Width((long*)&m_nOleWidth);
	m_pIPicture->get_Height((long*)&m_nOleHeight);

	HDC hDC = ::GetDC(NULL);

	// OLE_XSIZE_HIMETRIC ������ ���� �ȼ� ������ �����Ѵ�
	m_nWidth = MulDiv(m_nOleWidth, ::GetDeviceCaps(hDC, LOGPIXELSX), HIMETRIC_INCH);
	// OLE_XSIZE_HIMETRIC ������ ���̸� �ȼ� ������ �����Ѵ�
	m_nHeight = MulDiv(m_nOleHeight, ::GetDeviceCaps(hDC, LOGPIXELSY), HIMETRIC_INCH);

	::ReleaseDC(NULL, hDC);

	return TRUE;
}

// �̹��� ���ҽ��� �ε��ϴ� �Լ�
BOOL CPicture::Load(UINT nResourceID, LPCSTR pResourceType)
{
	// �̹� �ε�� �̹����� ������ �ʱ�ȭ�Ѵ�
	if(m_pIPicture != NULL)		ReleasePicture();

	// ���ҽ��� �˻��Ͽ� ���ҽ� �ڵ��� ��´�
	HRSRC hRes = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(nResourceID), pResourceType);
	if(hRes == NULL)					return FALSE;

	// ���ҽ��� �ε��Ѵ�
	HGLOBAL hGlobal = ::LoadResource(AfxGetResourceHandle(), hRes);
	if(hGlobal == NULL)					return FALSE;

	// ���ҽ� �޸𸮸� ��� ���ҽ� �����͸� ��´�
	char *pBuffer = (char*)::LockResource(hGlobal);
	if(pBuffer == NULL)					return FALSE;

	// ���ҽ��� ����� ��´�
	int nSize = ::SizeofResource(AfxGetResourceHandle(), hRes);

	// ���ҽ� �����Ϳ��� IPicture ��ü�� �����
	if(!LoadPicture(pBuffer, nSize))	return FALSE;

	// �̹��� ũ�⸦ ���Ѵ� : ������ OLE_XSIZE_HIMETRIC�̴�
	// OLE_XSIZE_HIMETRIC�� 1/2540��ġ
	m_pIPicture->get_Width((long*)&m_nOleWidth);
	m_pIPicture->get_Height((long*)&m_nOleHeight);

	HDC hDC = ::GetDC(NULL);

	// OLE_XSIZE_HIMETRIC ������ ���� �ȼ� ������ �����Ѵ�
	m_nWidth = MulDiv(m_nOleWidth, ::GetDeviceCaps(hDC, LOGPIXELSX), HIMETRIC_INCH);
	// OLE_XSIZE_HIMETRIC ������ ���̸� �ȼ� ������ �����Ѵ�
	m_nHeight = MulDiv(m_nOleHeight, ::GetDeviceCaps(hDC, LOGPIXELSY), HIMETRIC_INCH);

	::ReleaseDC(NULL, hDC);

	return TRUE;
}

// �̹��� �����Ϳ��� �ε��ϴ� �Լ�
BOOL CPicture::LoadFromMemory(LPCTSTR pBuffer, int nSize)
{
	// �̹� �ε�� �̹����� ������ �ʱ�ȭ�Ѵ�
	if(m_pIPicture != NULL)		ReleasePicture();

	// �̹��� �����Ϳ��� IPicture ��ü�� �����
	if(!LoadPicture(pBuffer, nSize))	return FALSE;

	// �̹��� ũ�⸦ ���Ѵ� : ������ OLE_XSIZE_HIMETRIC�̴�
	// OLE_XSIZE_HIMETRIC�� 1/2540��ġ
	m_pIPicture->get_Width((long*)&m_nOleWidth);
	m_pIPicture->get_Height((long*)&m_nOleHeight);

	HDC hDC = ::GetDC(NULL);

	// OLE_XSIZE_HIMETRIC ������ ���� �ȼ� ������ �����Ѵ�
	m_nWidth = MulDiv(m_nOleWidth, ::GetDeviceCaps(hDC, LOGPIXELSX), HIMETRIC_INCH);
	// OLE_XSIZE_HIMETRIC ������ ���̸� �ȼ� ������ �����Ѵ�
	m_nHeight = MulDiv(m_nOleHeight, ::GetDeviceCaps(hDC, LOGPIXELSY), HIMETRIC_INCH);

	::ReleaseDC(NULL, hDC);

	return TRUE;
}

// IPicture ��ü�� �����ϴ� ���� �Լ�
BOOL CPicture::LoadPicture(LPCTSTR pBuffer, int nSize)
{
	// �̹��� �����͸�ŭ ���� �޸𸮸� Ȯ���Ѵ�
	HGLOBAL hGlobal = ::GlobalAlloc(GHND, nSize);
	if(hGlobal == NULL)		return FALSE;

	// ���� �޸𸮸� �ᱺ��
	LPVOID pData = ::GlobalLock(hGlobal);
	// �̹��� �����͸� �����Ѵ�
	::memcpy(pData, pBuffer, nSize);
	// ��� ���� �޸𸮸� Ǭ��
	::GlobalUnlock(hGlobal);

	IStream *pStream = NULL;

	// �̹��� �����Ϳ� ���� IStream �������̽� ��ü�� �����Ѵ�
	if(::CreateStreamOnHGlobal(hGlobal, TRUE, &pStream) != S_OK)
	{
		::GlobalFree(hGlobal);
		return FALSE;
	}

	// IStream �������̽��� ���� �̹����� ����� �� �ִ� IPicture ��ü�� �����
	HRESULT hr = ::OleLoadPicture(pStream, nSize, FALSE, IID_IPicture, (LPVOID *)&m_pIPicture);
	if(hr != S_OK)		m_pIPicture = NULL;

	// IStream �������̽��� �����Ѵ�
	pStream->Release();
	// ���� �޸𸮸� �����Ѵ�
	::GlobalFree(hGlobal);

	return (hr == S_OK);
}

// �޸𸮸� �ʱ�ȭ�ϴ� �Լ�
void CPicture::ReleasePicture()
{
	if(m_pIPicture != NULL)
	{
		// IPicture ��ü�� �����Ѵ�
		m_pIPicture->Release();
		m_pIPicture = NULL;

		m_nHeight	= 0;
		m_nWidth	= 0;
		m_nOleWidth		= 0;
		m_nOleHeight	= 0;
	}
}

// ȭ�� ��� �Լ�
BOOL CPicture::Draw(CDC *pDC)
{
	if(m_pIPicture == NULL)		return FALSE;

	CRect rcRect(0, 0, m_nWidth, m_nHeight);

	// IPicture ��ü�� ���� �ִ� �̹����� ȭ�鿡 ����Ѵ�
	HRESULT hr = m_pIPicture->Render(pDC->m_hDC,
		0, 0, m_nWidth, m_nHeight,
		0, m_nOleHeight, m_nOleWidth, -m_nOleHeight, &rcRect);

	return (hr == S_OK);
}

// ȭ�� ��� �Լ�
BOOL CPicture::Draw(CDC *pDC, CRect rcRect)
{
	if(m_pIPicture == NULL)		return FALSE;

	// IPicture ��ü�� ���� �ִ� �̹����� ȭ���� Ư�� ������ ����Ѵ�
	HRESULT hr = m_pIPicture->Render(pDC->m_hDC,
		rcRect.left, rcRect.top, rcRect.Width(), rcRect.Height(),
		0, m_nOleHeight, m_nOleWidth, -m_nOleHeight, &rcRect);

	return (hr == S_OK);
}

// �̹����� ���� ��Ʈ�� �ڵ��� �����ϴ� �Լ�
HBITMAP CPicture::GetHBITMAP()
{
	if(m_pIPicture == NULL)		return NULL;

	short nType = PICTYPE_UNINITIALIZED;

	// IPicture ��ü�� ���� �ִ� �̹����� Ÿ���� ��´�
	m_pIPicture->get_Type(&nType);

	// �̹��� Ÿ���� ��Ʈ������ Ȯ���Ѵ�
	if(nType != PICTYPE_BITMAP)	return NULL;

	OLE_HANDLE hBitmap;

	// �̹����� ���� OLE ������ �ڵ��� ��´�
	m_pIPicture->get_Handle(&hBitmap);

	// ��Ʈ�� �ڵ� Ÿ������ �����Ѵ�
	return (HBITMAP)hBitmap;
}
