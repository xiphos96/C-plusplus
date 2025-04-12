#include "stdafx.h"
#include "DoubleBuffer.h"

// ������ : �ݵ�� ������ �ڵ��� ���ڷ� �����ؾ� �Ѵ�
CGraphics::CGraphics(HWND hWnd)
{
	// ��� ���� �ʱ�ȭ
	m_hWnd = hWnd;
	m_pGraphics = NULL;
	m_pMemBmp = NULL;	

	CRect rcClient;
	::GetClientRect(hWnd, &rcClient);

	// �޸� ��Ʈ���� �����Ѵ�
	m_pMemBmp = new Bitmap(rcClient.Width(), rcClient.Height());
	// �޸� ��Ʈ�ʿ� �׷����� ����� �� �ִ� Graphics ��ü�� �����Ѵ�
	m_pGraphics = Graphics::FromImage(m_pMemBmp);
}

// �Ҹ��� : ���ۿ� ��µ� �׷����� ȭ�鿡 ����Ѵ�
CGraphics::~CGraphics()
{
	// ���� ��ü���� �����Ǿ� �ִٸ�
	if(m_pGraphics && m_pMemBmp)
	{
		// �������� DC�� ��´�
		HDC hDC = ::GetDC(m_hWnd);
		// �������� ȭ�� Graphics ��ü�� �����Ѵ�
		Graphics graphics(hDC);

		// ȭ�� Graphics ��ü�� ����Ͽ� �޸� ��Ʈ���� ������ �����Ͽ� ĳ�� ��Ʈ���� �����Ѵ�
		CachedBitmap *pCachedBmp =  new CachedBitmap(m_pMemBmp, &graphics);

		// ĳ�� ��Ʈ���� ȭ�鿡 ����Ѵ�
		graphics.DrawCachedBitmap(pCachedBmp, 0, 0);

		// ĳ�� ��Ʈ���� �����Ѵ�
		delete pCachedBmp;
		// DC�� ��ȯ�Ѵ�
		::ReleaseDC(m_hWnd, hDC);
	}

	// ��ü���� �����Ѵ�
	if(m_pGraphics)		delete m_pGraphics;
	if(m_pMemBmp)		delete m_pMemBmp;	
}
