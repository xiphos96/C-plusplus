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
		// wp1을 통해 sp2를 sp3으로 복사
		shared_ptr<string> sp3 = wp1.lock();
		if (sp3) {
			cout << "wp1을 통해 sp3 복사 완료" << std::endl;
		}
		shared_ptr<int> sp4 = make_shared<int>(10);
		weak_ptr<string> wp2(sp1);
	} // sp3, sp4, wp2 자동 소멸
	cout << "sp1이 가리키는 문자열 출력: " << *sp1 << std::endl;
	sp1.reset();		// sp1 강제 소멸
	sp2 = nullptr;
	shared_ptr<string> sp5 = wp1.lock();
	if (sp5) {
		std::cout << "이 문장은 실행되지 않음!" << std::endl;
	}
	wp1.reset();

	return 0;
}