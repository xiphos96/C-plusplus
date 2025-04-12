// Refined Rect Class- console version
#pragma once
#include <iostream>
using std::cout; using std::endl;

class Rect
{
public:
	// ������ �Լ�
	Rect(int, int, int, int);
	Rect();
	// Ÿ�� ��ȯ
	Rect(int);
	operator int();
	// �Ҹ��� �Լ�
	virtual ~Rect();
	// ����
	void moveTo(int, int);
	bool includes(const int, const int);
	int area() const;
	// ������ �����ε�
	bool operator>(const Rect&);
	Rect& operator++();
	Rect operator++(int);
	// ���� �Լ�
	int getUpperLeftX() const;
	int getUpperLeftY() const;
	int getLowerRightX() const;
	int getLowerRightY() const;
	// ���� �Լ�
	void setUpperLeftX(int);
	void setUpperLeftY(int);
	void setLowerRightX(int);
	void setLowerRightY(int);
protected:
	// ��� ����
	int upperLeftX;
	int upperLeftY;
	int lowerRightX;
	int lowerRightY;
};

extern bool operator<(const Rect&, const Rect&);
extern Rect& operator--(Rect&);
extern Rect operator--(Rect&, int);
extern std::ostream& operator<<(std::ostream&, const Rect&);