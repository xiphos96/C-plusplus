//////////////////////////////////////////////////////////////
/// 
/// \file remove_if_less_then_7.cpp
///
/// \brief
///  ���������� 7������ ���� ����
///
/// ���������� 7������ ���� ������ ���Ҹ� ������ ������ ���Ҹ�
/// ���. ���� ������ ���Ҹ� �����Ϸ��� last���� Past-the-end������
/// ���Ҹ� erase ���� �̿��� ���� �����ؾ� �Ѵ�.
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

#include<algorithm>
#include<cstdlib>
#include<vector>
#include<iterator>
#include<iostream>
#include<functional>

template<typename value_t, value_t max>
struct random_gen
{
	value_t operator () ()
	{
		return static_cast<value_t>(
			(static_cast<long>(rand())*(max))
			/
			(RAND_MAX+1)
			);
	}
};

int main()
{
	std::vector<int> v(10);
	std::vector<int>::iterator last;
	std::generate( v.begin(), v.end(), random_gen<int, 10>() );
	
	std::cout << "Total: ";
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
	std::cout << std::endl;
	
	last = 
		std::remove_if( 
		v.begin(), v.end(), 
		std::not1( std::bind2nd( std::less<int>(), 7 ) ) );
	
	std::cout << "After removed: ";
	std::copy(v.begin(), last, std::ostream_iterator<int>(std::cout));
}