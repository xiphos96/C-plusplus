//////////////////////////////////////////////////////////////
/// 
/// \file moving_avg.cpp
///
/// \brief
///  deque를 이용하여 이동 평균을 구하는 예
///
/// deque를 이용하여 이동 평균을 구하는 예. 큐에 계속 
/// 데이터를 유지하면서 새로운 데이터는 맨 뒤에, 그리고
/// 맨 앞에 있는 오래된 데이터를 버리고 현재의 평균을 구함.
///
/// \테스트환경
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
