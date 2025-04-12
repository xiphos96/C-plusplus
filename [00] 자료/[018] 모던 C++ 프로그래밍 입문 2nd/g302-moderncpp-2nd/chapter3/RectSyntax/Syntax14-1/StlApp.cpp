#include "Rect.h"
#include <memory>
#include <vector>

int main()
{
	// �簢���� ���� vector
	cout << "-- �簢�� ���� --" << endl;
	std::vector<Rect> rectVector;
	Rect aRect(10, 10, 130, 130);
	Rect bRect(20, 20, 100, 110);
	Rect cRect(30, 30, 70, 70);
	rectVector.push_back(aRect);
	rectVector.push_back(bRect);
	rectVector.push_back(cRect);
	// �簢���� ����
	cout << "�簢���� ����" << endl;
	int rectCount = rectVector.size();
	cout << rectCount << endl;
	// �ݺ��ڷ� ���� - ������
	cout << "�ݺ��� - ������" << endl;
	for (std::vector<Rect>::iterator it = rectVector.begin();
			it != rectVector.end(); ++it)
		cout << *it << endl;
	// �ݺ��ڷ� ���� - ������(�Ϻ�)
	cout << "�ݺ��� - ������(�Ϻ�)" << endl;
	std::vector<Rect>::iterator iter = rectVector.begin() + 2;
	for (std::vector<Rect>::iterator it = rectVector.begin();
			it != iter; ++it)
		cout << *it << endl;
	// �ݺ��ڷ� ���� - ������
	cout << "�ݺ��� - ������" << endl;
	for (std::vector<Rect>::reverse_iterator it = rectVector.rbegin();
			it != rectVector.rend(); ++it) {
		it->moveTo(150, 150);
		cout << *it << endl;
	}
	// �迭 ������� ����
	cout << "�迭 ������� ����" << endl;
	for (int i = 0; i < rectCount; ++i) {
		rectVector[i].moveTo(300, 300);
		cout << rectVector[i] << endl;
	}
	// ù ��° �簢���� ����
	cout << "ù ��° �簢���� ���� �� �������� x ��ǥ" << endl;
	Rect& firstRect = rectVector.front();
	cout << firstRect.getUpperLeftX() << endl;
	// ������ �簢���� ����
	cout << "������ �簢���� ������ �Ʒ� �������� x ��ǥ" << endl;
	Rect& lastRect = rectVector.back();
	cout << lastRect.getLowerRightX() << endl;
	// at�� ����ؼ� �� ��° �簢���� ����
	cout << "�� ��° �簢���� ������ �Ʒ� �������� y ��ǥ" << endl;
	Rect& secondRect = rectVector.at(1);
	cout << secondRect.getLowerRightY() << endl;
	// ������ �簢�� ����
	cout << "������ �簢�� ����" << endl;
	rectVector.pop_back();
	cout << "�簢���� ����" << endl;
	rectCount = rectVector.size();
	cout << rectCount << endl;
	// �簢���� �ִٸ� ��� ����
	cout << "�簢�� ��� ����" << endl;
	if (!rectVector.empty()) {
		rectVector.clear();
		rectCount = rectVector.size();
		cout << "�簢���� ����" << endl;
		cout << rectCount << endl;
	}
	// �簢�� �����͸� ���� vector
	cout << "-- �簢�� ������ ���� --" << endl;
	typedef std::shared_ptr<Rect> RectPtr;
	std::vector<RectPtr> rectPtrVector;
	RectPtr aRectPtr(new Rect(510, 110, 630, 230));
	rectPtrVector.push_back(aRectPtr);
	rectPtrVector.push_back(std::make_shared<Rect>(520, 120, 600, 210));
	rectPtrVector.push_back(std::make_shared<Rect>(530, 130, 570, 170));
	// �ݺ��ڷ� ���� - ������
	cout << "�ݺ��� - ������" << endl;
	for (std::vector<RectPtr>::iterator it = rectPtrVector.begin();
			it != rectPtrVector.end(); ++it) {
		cout << *(*it) << endl;			// RectPtr& rp = *it; cout << *rp << endl;
		cout << "area : " << (*it)->area() << endl;
	}
	/*
	for (auto it = rectPtrVector.begin(); it != rectPtrVector.end(); ++it) {
		cout << *(*it) << endl;
		cout << "area : " << (*it)->area() << endl;
	}
	*/
	rectPtrVector.clear();

	return 0;
}