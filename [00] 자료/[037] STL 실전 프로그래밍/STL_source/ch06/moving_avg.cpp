//////////////////////////////////////////////////////////////
/// 
/// \file moving_avg.cpp
///
/// \brief
///  deque�� �̿��Ͽ� �̵� ����� ���ϴ� ��
///
/// deque�� �̿��Ͽ� �̵� ����� ���ϴ� ��. ť�� ��� 
/// �����͸� �����ϸ鼭 ���ο� �����ʹ� �� �ڿ�, �׸���
/// �� �տ� �ִ� ������ �����͸� ������ ������ ����� ����.
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

#include<deque>
#include<numeric>
#include<fstream>

template<typename t, size_t window_length=10>
class moving_average
{
private:
	std::deque<t> queue;
	
public:
	
	t operator () (const t &v)
	{
		queue.push_back(v);
		
		if(queue.size() > window_length)
			queue.pop_front();
		
		return 
			std::accumulate(
			queue.begin(), queue.end(), static_cast<t>(0))
			/queue.size();
	}
};

int main()
{
	double m;
	moving_average<double> average;
	std::ifstream motor_data("motor.txt");
	std::ofstream avg_data("motor_avg.txt");
	while(motor_data >> m)
	{
		avg_data<< average(m) << std::endl;
	}
	motor_data.close();
	avg_data.close();
}
