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
// �̺�Ʈ ��ü�� ���� ���� ���·� �����Ѵ�
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
	// �̹����� �����Ǿ��ٸ�
	if(m_pGIFImage)
	{
		// �ִϸ��̼� �����尡 ���� ���̶��
		if(m_hAnimationThread)
		{
			// ������ ���� �̺�Ʈ�� �����Ѵ�
			m_ExitEvent.SetEvent();
			// ������ ���Ḧ ����Ѵ�
			::WaitForSingleObject(m_hAnimationThread, INFINITE);
			m_hAnimationThread = NULL;
		}

		// �̹����� �����Ѵ�
		delete m_pGIFImage;
	}
	// �̹��� �������� �޸𸮸� �����Ѵ�
	if(m_hImageData)	::GlobalFree(m_hImageData);
	// �̹��� ���� �迭�� �����Ѵ�
	if(m_pProperty)		delete[] (char*)m_pProperty;
	// �̹��� ���� �迭�� �����Ѵ�
	if(m_pDimensionID)	delete[] m_pDimensionID;
	// ��� ������ �ʱ�ȭ�Ѵ�
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

// �ִϸ��̼� GIF ������ �ε��ϴ� �Լ�
BOOL CAnimGIF::LoadGIF(LPCTSTR pFileName)
{
	// �̹����� �����Ǿ��ٸ�
	if(m_pGIFImage)
	{
		// �ִϸ��̼� �����尡 ���� ���̶��
		if(m_hAnimationThread)
		{
			// ������ ���� �̺�Ʈ�� �����Ѵ�
			m_ExitEvent.SetEvent();
			// ������ ���Ḧ ����Ѵ�
			::WaitForSingleObject(m_hAnimationThread, INFINITE);
			m_hAnimationThread = NULL;
		}

		// �̹����� �����Ѵ�
		delete m_pGIFImage;
	}
	// �̹��� �������� �޸𸮸� �����Ѵ�
	if(m_hImageData)	::GlobalFree(m_hImageData);
	// �̹��� ���� �迭�� �����Ѵ�
	if(m_pProperty)		delete[] (char*)m_pProperty;
	// �̹��� ���� �迭�� �����Ѵ�
	if(m_pDimensionID)	delete[] m_pDimensionID;
	// ��� ������ �ʱ�ȭ�Ѵ�
	m_pGIFImage = NULL;
	m_hImageData = NULL;
	m_pProperty = NULL;
	m_pDimensionID = NULL;
	m_nFrameSize = 0;
	m_nCurFrame = 0;

	// �̺�Ʈ ��ü���� �ʱ�ȭ�Ѵ�
	m_ExitEvent.ResetEvent();
	m_RunEvent.ResetEvent();

	CFile InFile;

	// �ִϸ��̼� GIF ������ ����
	if(!InFile.Open(pFileName, CFile::modeRead | CFile::typeBinary))
		return FALSE;

	// �ִϸ��̼� GIF ũ�⸸ŭ �޸𸮸� Ȯ���Ѵ�
	int nSize = InFile.GetLength();
	char *pBuffer = new char[nSize];
	
	// �ִϸ��̼� GIF ������ �޸𸮷� �о�´�
	if(InFile.Read(pBuffer, nSize) <= 0)
	{
		InFile.Close();
		return FALSE;
	}

	// �ִϸ��̼� GIF ������ �ݴ´�
	InFile.Close();

	// �̹��� �����Ϳ��� Image ��ü�� �����
	if(!LoadGIFFromMemory(pBuffer, nSize))
	{
		delete[] pBuffer;

		return FALSE;
	}

	// �޸� ����
	delete[] pBuffer;

	return TRUE;
}

// �ִϸ��̼� GIF ���ҽ��� �ε��ϴ� �Լ�
BOOL CAnimGIF::LoadGIF(UINT nResourceID, LPCTSTR pResourceType)
{
	// �̹����� �����Ǿ��ٸ�
	if(m_pGIFImage)
	{
		// �ִϸ��̼� �����尡 ���� ���̶��
		if(m_hAnimationThread)
		{
			// ������ ���� �̺�Ʈ�� �����Ѵ�
			m_ExitEvent.SetEvent();
			// ������ ���Ḧ ����Ѵ�
			::WaitForSingleObject(m_hAnimationThread, INFINITE);
			m_hAnimationThread = NULL;
		}

		// �̹����� �����Ѵ�
		delete m_pGIFImage;
	}
	// �̹��� �������� �޸𸮸� �����Ѵ�
	if(m_hImageData)	::GlobalFree(m_hImageData);
	// �̹��� ���� �迭�� �����Ѵ�
	if(m_pProperty)		delete[] (char*)m_pProperty;
	// �̹��� ���� �迭�� �����Ѵ�
	if(m_pDimensionID)	delete[] m_pDimensionID;
	// ��� ������ �ʱ�ȭ�Ѵ�
	m_pGIFImage = NULL;
	m_hImageData = NULL;
	m_pProperty = NULL;
	m_pDimensionID = NULL;
	m_nFrameSize = 0;
	m_nCurFrame = 0;

	// �̺�Ʈ�� �ʱ�ȭ�Ѵ�
	m_ExitEvent.ResetEvent();
	m_RunEvent.ResetEvent();

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

	// ���ҽ� �����Ϳ��� Image ��ü�� �����
	if(!LoadGIFFromMemory(pBuffer, nSize))	return FALSE;

	return TRUE;
}

// �ε�� �����ͷκ��� �̹��� ��ü�� �����ϴ� �Լ�
BOOL CAnimGIF::LoadGIFFromMemory(LPCTSTR pBuffer, int nSize)
{
	// �̹��� �����͸�ŭ ���� �޸𸮸� Ȯ���Ѵ�
	m_hImageData = ::GlobalAlloc(GHND, nSize);
	if(m_hImageData == NULL)		return FALSE;

	// ���� �޸𸮸� �ᱺ��
	LPVOID pData = ::GlobalLock(m_hImageData);
	// �̹��� �����͸� �����Ѵ�
	::memcpy(pData, pBuffer, nSize);
	// ��� ���� �޸𸮸� Ǭ��
	::GlobalUnlock(m_hImageData);

	IStream *pStream = NULL;

	// �̹��� �����Ϳ� ���� IStream �������̽� ��ü�� �����Ѵ�
	if(::CreateStreamOnHGlobal(m_hImageData, TRUE, &pStream) != S_OK)
	{
		::GlobalFree(m_hImageData);
		m_hImageData = NULL;
		return FALSE;
	}

	// IStream�� �����͸� ����ؼ� Image ��ü�� �����
	m_pGIFImage = new Image(pStream, FALSE);

	// IStream �������̽��� �����Ѵ�
	pStream->Release();

	// GIF�� ������ ���� ũ�⸦ ��´�
	int nDimensionSize = m_pGIFImage->GetFrameDimensionsCount();

	// GIF�� ������ ���� ID���� ��´�
	m_pDimensionID = new GUID[nDimensionSize];
	m_pGIFImage->GetFrameDimensionsList(m_pDimensionID, nDimensionSize);

	// GIF�� ������ ������ ��´�
	m_nFrameSize = m_pGIFImage->GetFrameCount(m_pDimensionID);

	// �����ӵ��� ��� �ð� �Ӽ� ũ�⸦ ��´�
	int nPropertySize = m_pGIFImage->GetPropertyItemSize(PropertyTagFrameDelay);

	// ������ ��� �ð� �Ӽ����� ��´�
	m_pProperty = (PropertyItem*)(new char[nPropertySize]);
	m_pGIFImage->GetPropertyItem(PropertyTagFrameDelay, nPropertySize, m_pProperty);

	return TRUE;
}

// �ִϸ��̼��� �����ϴ� �Լ�
BOOL CAnimGIF::Play()
{
	if(m_pGIFImage == NULL)		return FALSE;

	// �ִϸ��̼� �����尡 ���� ���̶��
	if(m_hAnimationThread)
	{
		// ������ ���� �̺�Ʈ�� �����Ѵ�
		m_ExitEvent.SetEvent();
		// ������ ���Ḧ ����Ѵ�
		::WaitForSingleObject(m_hAnimationThread, INFINITE);
		m_hAnimationThread = NULL;
	}

	UINT nID;

	// �ִϸ��̼� �����带 �����Ѵ�
	m_hAnimationThread = (HANDLE)_beginthreadex(NULL, 0, AnimationProc, this, CREATE_SUSPENDED, &nID);

	if(m_hAnimationThread == NULL)	return FALSE;

	// ���� �̺�Ʈ�� Signal ���·� �����Ѵ�
	m_RunEvent.SetEvent();
	// �����带 �����Ѵ�
	::ResumeThread(m_hAnimationThread);

	return TRUE;
}

// �ִϸ��̼��� �Ͻ������ϴ� �Լ�
BOOL CAnimGIF::Pause()
{
	if(m_pGIFImage == NULL)		return FALSE;

	// ���� �̺�Ʈ�� Non-signal ���·� �ʱ�ȭ�Ѵ�
	m_RunEvent.ResetEvent();

	return TRUE;
}

// �Ͻ������� �ִϸ��̼��� �ٽ� �����ϴ� �Լ�
BOOL CAnimGIF::Resume()
{
	if(m_pGIFImage == NULL)		return FALSE;

	// ���� �̺�Ʈ�� Signal ���·� �����Ѵ�
	m_RunEvent.SetEvent();

	return TRUE;
}

// �ִϸ��̼� ��¿� ������ �Լ�
UINT WINAPI CAnimGIF::AnimationProc(LPVOID pParam)
{
	CAnimGIF *pAnimGIF = (CAnimGIF*)pParam;

	CRect rcClient;
	pAnimGIF->GetClientRect(&rcClient);

	// �̹����� ũ�⸦ ��´�
	int nWidth = pAnimGIF->m_pGIFImage->GetWidth();
	int nHeight = pAnimGIF->m_pGIFImage->GetHeight();

	// ȭ�� �߾����� �̹����� ����ϱ� ���� ��ġ�� ����Ѵ�
	int xPos = (rcClient.Width() - nWidth) / 2;
	int yPos = (rcClient.Height() - nHeight) / 2;
	LONG nWait;

	while(1)
	{
		// ���� �̺�Ʈ�� ������ ������ ����Ѵ�
		::WaitForSingleObject(pAnimGIF->m_RunEvent.m_hObject, INFINITE);

		// DC �ڵ�κ��� Graphics ��ü�� �����
		CDC *pDC = pAnimGIF->GetDC();
		Graphics graphics(pDC->m_hDC);

		// GIF�� �������� ����Ѵ�
		graphics.DrawImage(pAnimGIF->m_pGIFImage, xPos, yPos, nWidth, nHeight);

		pAnimGIF->ReleaseDC(pDC);

		// GIF�� �������� �̵��Ѵ�
		pAnimGIF->m_nCurFrame++;

		// GIF�� �� �������̶�� ó�� ���������� �̵��Ѵ�
		if(pAnimGIF->m_nCurFrame == pAnimGIF->m_nFrameSize)
			pAnimGIF->m_nCurFrame = 0;

		// ���� ������ ��ȣ�� ���� �������� �����Ѵ�
		pAnimGIF->m_pGIFImage->SelectActiveFrame(pAnimGIF->m_pDimensionID, pAnimGIF->m_nCurFrame);

		// ��� �ð��� ����Ѵ�
		nWait = ((LONG*)pAnimGIF->m_pProperty->value)[pAnimGIF->m_nCurFrame] * 10;

		// ��� �ð���ŭ ����Ѵ�
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

	// Graphics ��ü�� �����Ѵ�
	Graphics graphics(dc.m_hDC);
	Rect rectClient(0, 0, rcClient.Width(), rcClient.Height());

	// ������ �귯���� �����Ѵ�
	SolidBrush *pBlackBrush = new SolidBrush(Color.Black);

	// ����� ������ �귯���� ĥ�Ѵ�
	graphics.FillRectangle(pBlackBrush, rectClient);

	// �ִϸ��̼��� ������� �ʾҴٸ�
	if(m_hAnimationThread == NULL)
	{
		// �̹����� �ε�Ǿ� �ִٸ�
		if(m_pGIFImage)
		{
			// �̹����� ũ�⸦ ��´�
			int nWidth = m_pGIFImage->GetWidth();
			int nHeight = m_pGIFImage->GetHeight();
			// ȭ�� �߾����� �̹����� ����ϱ� ���� ��ġ�� ����Ѵ�
			int xPos = (rcClient.Width() - nWidth) / 2;
			int yPos = (rcClient.Height() - nHeight) / 2;

			// ���� �������� ȭ�鿡 ����Ѵ�
			graphics.DrawImage(m_pGIFImage, xPos, yPos, nWidth, nHeight);
		}
	}

	// ������ �귯���� �����Ѵ�
	delete pBlackBrush;
}

BOOL CAnimGIF::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CAnimGIF::OnDestroy() 
{
	CStatic::OnDestroy();

	// �̹����� �����Ǿ��ٸ�
	if(m_pGIFImage)
	{
		// �ִϸ��̼� �����尡 ���� ���̶��
		if(m_hAnimationThread)
		{
			// ������ ���� �̺�Ʈ�� �����Ѵ�
			m_ExitEvent.SetEvent();
			// ������ ���Ḧ ����Ѵ�
			::WaitForSingleObject(m_hAnimationThread, INFINITE);
			m_hAnimationThread = NULL;
		}

		// �̹����� �����Ѵ�
		delete m_pGIFImage;
	}
	// �̹��� �������� �޸𸮸� �����Ѵ�
	if(m_hImageData)	::GlobalFree(m_hImageData);
	// �̹��� ���� �迭�� �����Ѵ�
	if(m_pProperty)		delete[] (char*)m_pProperty;
	// �̹��� ���� �迭�� �����Ѵ�
	if(m_pDimensionID)	delete[] m_pDimensionID;
	// ��� ������ �ʱ�ȭ�Ѵ�
	m_pGIFImage = NULL;
	m_hImageData = NULL;
	m_pProperty = NULL;
	m_pDimensionID = NULL;
	m_nFrameSize = 0;
	m_nCurFrame = 0;
}
