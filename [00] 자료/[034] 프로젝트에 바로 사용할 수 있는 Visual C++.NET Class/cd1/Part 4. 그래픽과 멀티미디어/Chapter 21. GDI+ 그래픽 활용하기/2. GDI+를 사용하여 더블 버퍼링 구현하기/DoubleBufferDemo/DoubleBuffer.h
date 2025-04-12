#ifndef DOUBLE_BUFFER_H
#define DOUBLE_BUFFER_H

// GDI+�� ���� ���۸� Ŭ����
class CGraphics
{
	HWND			m_hWnd;				// ���� ���۸��� ������ ������ �ڵ�
	Graphics*		m_pGraphics;		// ���� ���۸��� Graphics ������
	Bitmap*			m_pMemBmp;			// �޸� ��Ʈ�� ������

public:
	// ������ : �ݵ�� ������ �ڵ��� ���ڷ� �����ؾ� �Ѵ�
	CGraphics(HWND hWnd);
	// �Ҹ��� : ���ۿ� ��µ� �׷����� ȭ�鿡 ����Ѵ�
	virtual ~CGraphics();

	// ���� ���۸��� Graphics �����͸� �����ϴ� �Լ�
	Graphics* GetGraphics()		{ return m_pGraphics; }
};

#endif