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
	// ��ĳ����(D->C) - �����Ϳ� ���۷���: OK
	shared_ptr<C> cptr1 = make_shared<D>();
	cptr1->z();
	C& cref = d1;
	cref.z();
	// ��ĳ����(D->C) - �Ϲ� ����: �����̽� �߻�
	C c1 = d1;
	c1.z();
	// �ٿ�ĳ����(C->D) - �����Ϳ� ���۷���: C::z ȣ��
	shared_ptr<C> cptr2 = make_shared<C>();
	shared_ptr<D> dptr = static_pointer_cast<D>(cptr2);
	dptr->z();
	// �ٿ�ĳ����(C->D) - �Ϲ� ����: ������ ���� �߻�
	C c2;
//	d2 = static_cast<D>(c2);

	return 0;
}