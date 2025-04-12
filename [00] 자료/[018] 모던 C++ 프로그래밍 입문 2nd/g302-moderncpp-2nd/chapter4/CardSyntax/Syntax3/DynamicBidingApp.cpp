#include <iostream>
#include <memory>
using std::cout; using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::static_pointer_cast;

class A {
public:
	void x() {
		cout << "A::x" << endl;
	}
	virtual void y() {
		cout << "A::y" << endl;
	}
};

class B : public A {
public:
	void z() {
		cout << "B::z" << endl;
	}
};

class C : public A {
public:
	void x() {
		cout << "C::x" << endl;
	}
	virtual void z() {
		cout << "C::z" << endl;
	}
};

class D : public C {
public:
	virtual void z() {
		cout << "D::z" << endl;
	}
};

class E : public C {
public:
	void m() {
		cout << "E::m" << endl;
	}
};

int main()
{
	D d1;
	d1.y();
	D d2;
	d2.z();
	// 업캐스팅(D->C) - 포인터와 레퍼런스: OK
	shared_ptr<C> cptr1 = make_shared<D>();
	cptr1->z();
	C& cref = d1;
	cref.z();
	// 업캐스팅(D->C) - 일반 변수: 슬라이싱 발생
	C c1 = d1;
	c1.z();
	// 다운캐스팅(C->D) - 포인터와 레퍼런스: C::z 호출
	shared_ptr<C> cptr2 = make_shared<C>();
	shared_ptr<D> dptr = static_pointer_cast<D>(cptr2);
	dptr->z();
	// 다운캐스팅(C->D) - 일반 변수: 컴파일 오류 발생
	C c2;
//	d2 = static_cast<D>(c2);

	return 0;
}