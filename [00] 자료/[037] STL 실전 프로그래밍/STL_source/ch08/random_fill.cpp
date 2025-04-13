//////////////////////////////////////////////////////////////
/// 
/// \file random_fill.cpp
///
/// \brief
///  �������� ������ ������ ä��� ��
///
/// �˰��� generate�� �̿��Ͽ� �������� ������ ������ ä���
/// ��
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
	std::generate( v.begin(), v.end(), random_gen<int, 10>());
}