// Refined Card Class - console version
#pragma once
#include "Rect.h"
#include <memory>

class Card : public Rect
{
public:
	// 생성자 함수
	Card(int, int, int, int);
	Card(int, int);
	// 소멸자 함수
	virtual ~Card();
	// 연산
//	virtual void draw(Application&);			// console version
	void flip();
	// 접근 함수
	int getSuit() const;
	int getRank() const;
	bool getFaceUp() const;
	// 변경 함수
	void setSuit(int);
	void setRank(int);
	void setFaceUp(bool);
	// 프렌드 함수
	friend bool operator==(const Card&, const Card&);
	// console version
	friend std::ostream& operator<<(std::ostream&, const Card&);
	// 정적 멤버
	static int getCardWidth();
	static int getCardHeight();
	static const int CardWidth = 75;
	static const int CardHeight = 100;
private:
	// 멤버 변수
	int suit;
	int rank;
	bool faceUp;
};

extern bool operator==(const Card&, const Card&);
// console version
extern std::ostream& operator<<(std::ostream&, const Card&);
typedef std::shared_ptr<Card> CardPtr;