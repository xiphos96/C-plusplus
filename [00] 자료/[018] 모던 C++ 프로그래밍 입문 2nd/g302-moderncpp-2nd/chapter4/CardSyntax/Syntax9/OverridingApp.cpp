#include <iostream>
#include <memory>
using std::cout; using std::endl;
using std::shared_ptr;

class Parent
{
public:
	virtual void overload()
	{
		cout << "Parent's overload()" << endl;
	}
	virtual void overload(int i)
	{
		cout << "Parent's overload(int i)" << endl;
	}
};

class Child : public Parent
{
public:
	virtual void overload()
	{
		cout << "Child's overload()" << endl; 
	}
};

int main()
{
	Child myChild;
//	myChild.overload(2);			// 컴파일 오류
	shared_ptr<Parent> myParentPtr(&myChild, [](Child*) {});
	myParentPtr->overload(7);

	return 0;
}