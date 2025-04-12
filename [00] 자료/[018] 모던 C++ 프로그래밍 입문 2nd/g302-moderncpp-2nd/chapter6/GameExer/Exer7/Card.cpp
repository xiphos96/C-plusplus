#include "Card.h"
// GameApp의 cardBitmaps를 사용하기 위해 포함
// 헤더 파일의 순환 include를 피하기 위해 Card.cpp에 포함
#include "GameApp.h"
//#include "pclaf.h"

Card::Card(int xv, int yv, int s, int r)
	: Rect(xv, yv, xv + CardWidth, yv + CardHeight),
	suit(s), rank(r), faceUp(false)
{}

// 실습 과제
void Card::draw(Application& win)
{
	// 카드 이미지 선택
	int	which = faceUp ? ((suit - 1) * 13 + rank - 1) : 52;
	// 선택된 카드 이미지 그리기
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