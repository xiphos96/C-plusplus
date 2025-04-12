#include "Rect.h"
#include <list>

int main()
{
	// �簢���� ���� list
	std::list<Rect> rectList;
	Rect aRect(10, 10, 130, 130);
	Rect bRect(20, 20, 100, 110);
	Rect cRect(30, 30, 70, 70);
	rectList.push_back(aRect);
	rectList.push_front(bRect);
	rectList.push_front(cRect);
	// ���� ��� for�� - ������
	cout << "���� ��� for - ������" << endl;
	for (auto& r : rectList)
		cout << r << endl;
	// �ݺ��ڷ� ���� - ������
	cout << "�ݺ��� - ������" << endl;
	std::list<Rect>::reverse_iterator it;
	for (it = rectList.rbegin(); it != rectList.rend(); ++it) {
		it->moveTo(150, 150);
		cout << *it << endl;
	}
	// ù ��° �簢���� ����
	cout << "ù ��° �簢���� ���� �� �������� x ��ǥ" << endl;
	Rect& firstRect = rectList.front();
	cout << firstRect.getUpperLeftX() << endl;
	// ù ��° �簢�� ����
	rectList.pop_front();
	// ������ �簢�� ����
	rectList.pop_back();
	cout << "ù ��°�� ������ �簢�� ����" << endl;
	cout << "�簢���� ����" << endl;
	int rectCount = rectList.size();
	cout << rectCount << endl;
	// �簢���� �ִٸ� ��� ����
	cout << "�簢�� ��� ����" << endl;
	if (!rectList.empty()) {
		rectList.clear();
		cout << "�簢���� ����" << endl;
		rectCount = rectList.size();
		cout << rectCount << endl;
	}

	return 0;
}