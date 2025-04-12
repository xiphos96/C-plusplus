#pragma once


// �̹��� ��� Ŭ����
// ���� ���� ���� : BMP, DIB, EMF, GIF, ICO, JPG, WMF

class CPicture
{
public:
	IPicture				*m_pIPicture;			// IPicture �������̽� ������

	int						m_nWidth;				// �̹����� �� : ���� �ȼ�
	int						m_nHeight;				// �̹����� ���� : ���� �ȼ�
	OLE_XSIZE_HIMETRIC		m_nOleWidth;
	OLE_YSIZE_HIMETRIC		m_nOleHeight;

	CPicture();
	virtual ~CPicture();

	// �̹��� ������ �ε��ϴ� �Լ�
	BOOL Load(LPCTSTR pFileName);
	// �̹��� ���ҽ��� �ε��ϴ� �Լ�
	BOOL Load(UINT nResourceID, LPCSTR pResourceType);
	// �̹��� �����Ϳ��� �ε��ϴ� �Լ�
	BOOL LoadFromMemory(LPCTSTR pBuffer, int nSize);

	// �޸𸮸� �ʱ�ȭ�ϴ� �Լ�
	void ReleasePicture();

	// ȭ�� ��� �Լ�
	BOOL Draw(CDC *pDC);
	BOOL Draw(CDC *pDC, CRect rcRect);

	// �̹��� ���� �����ϴ� �Լ�
	int GetWidth()					{ return m_nWidth; }
	// �̹��� ���̸� �����ϴ� �Լ�
	int GetHeight()					{ return m_nHeight; }
	// �̹����� ���� �ε��Ǿ� �ִ��� �����ϴ� �Լ�
	BOOL IsLoaded()					{ return (m_pIPicture != NULL); }
	// �̹����� ���� ��Ʈ�� �ڵ��� �����ϴ� �Լ�
	HBITMAP GetHBITMAP();

protected:
	// IPicture ��ü�� �����ϴ� ���� �Լ�
	BOOL LoadPicture(LPCTSTR pBuffer, int nSize);
};
