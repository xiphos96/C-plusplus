#include <iostream>
#include <string>
#include <memory>
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::cout;
using std::endl;
using std::string;

int main()
{
	shared_ptr<string> sp1(new string("doohun"));
	shared_ptr<string> sp2 = sp1;
	weak_ptr<string> wp1 = sp2;
	{
		// wp1�� ���� sp2�� sp3���� ����
		shared_ptr<string> sp3 = wp1.lock();
		if (sp3) {
			cout << "wp1�� ���� sp3 ���� �Ϸ�" << std::endl;
		}
		shared_ptr<int> sp4 = make_shared<int>(10);
		weak_ptr<string> wp2(sp1);
	} // sp3, sp4, wp2 �ڵ� �Ҹ�
	cout << "sp1�� ����Ű�� ���ڿ� ���: " << *sp1 << std::endl;
	sp1.reset();		// sp1 ���� �Ҹ�
	sp2 = nullptr;
	shared_ptr<string> sp5 = wp1.lock();
	if (sp5) {
		std::cout << "�� ������ ������� ����!" << std::endl;
	}
	wp1.reset();

	return 0;
}