// Refined Card Class - console version
#pragma once
#include "Rect.h"
#include <memory>

class Card : public Rect
{
public:
	// ������ �Լ�
	Card(int, int, int, int);
	Card(int, int);
	// �Ҹ��� �Լ�
	virtual ~Card();
	// ����
//	virtual void draw(Application&);			// console version
	void flip();
	// ���� �Լ�
	int getSuit() const;
	int getRank() const;
	bool getFaceUp() const;
	// ���� �Լ�
	void setSuit(int);
	void setRank(int);
	void setFaceUp(bool);
	// ������ �Լ�
	friend bool operator==(const Card&, const Card&);
	// console version
	friend std::ostream& operator<<(std::ostream&, const Card&);
	// ���� ���
	static int getCardWidth();
	static int getCardHeight();
	static const int CardWidth = 75;
	static const int CardHeight = 100;
private:
	// ��� ����
	int suit;
	int rank;
	bool faceUp;
};

extern bool operator==(const Card&, const Card&);
// console version
extern std::ostream& operator<<(std::ostream&, const Card&);
typedef std::shared_ptr<Card> CardPtr;