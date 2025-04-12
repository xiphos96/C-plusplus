#include "Card.h"
// GameApp�� cardBitmaps�� ����ϱ� ���� ����
// ��� ������ ��ȯ include�� ���ϱ� ���� Card.cpp�� ����
#include "GameApp.h"
//#include "pclaf.h"

Card::Card(int xv, int yv, int s, int r)
	: Rect(xv, yv, xv + CardWidth, yv + CardHeight),
	suit(s), rank(r), faceUp(false)
{}

// �ǽ� ����
void Card::draw(Application& win)
{
	// ī�� �̹��� ����
	int	which = faceUp ? ((suit - 1) * 13 + rank - 1) : 52;
	// ���õ� ī�� �̹��� �׸���
	win.drawBitmap(GameApp::cardBitmaps[which], upperLeftX,
		upperLeftY, CardWidth, CardHeight);
}

void Card::flip()
{
	if (faceUp)
		faceUp = false;
	else
		faceUp = true;
}