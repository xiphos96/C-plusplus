//////////////////////////////////////////////////////////////
/// 
/// \file auto_ptr.cpp
///
/// \brief
///  Ŭ���� ����� �����͸� ����
///
/// auto_ptr�� �̿��ؼ� Ŭ������ ������ ����� �����ϴ� ��
///
/// \�׽�Ʈȯ��
///  Gcc3.2.2, Comeau4.3.3, VC++6.0, VC++.NET 2003
///
/// \author 
///  Kim, Seungtai( stkim@yujinrobot.com )
/// 
/// \date
///  - 2004-08-10, Kim, Seungtai, Create
/// 
/// \see
///
//////////////////////////////////////////////////////////////

#include<iostream>
#include<memory>

template<typename value_t>
class A
{
private:
	
	std::auto_ptr<value_t> p;
	
public:
	
	A() : p( new int(0) ){}
	
	void set( std::auto_ptr<value_t> n )
	{
		p = n;
	}
	
	value_t get() const
	{
		return *p;
	}
	
	std::auto_ptr<value_t> retrive()
	{
		value_t *pv = p.release();
		
		p = std::auto_ptr<value_t>( new int(0) );
		
		return std::auto_ptr<value_t> (pv);
	}
};

int main()
{
	A<int> m;
	std::cout << m.get() << std::endl;
	
	std::auto_ptr<int> p(new int(10));
	m.set(p);
	std::cout << m.get() << std::endl;
	
	p = m.retrive();
	std::cout << *p << std::endl;
}
