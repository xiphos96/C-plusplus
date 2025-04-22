//////////////////////////////////////////////////////////////
/// 
/// \file aligning.cpp
///
/// \brief
///  map을 사용하여 PCS 연결 제어
///
/// map, vector 등을 이용해 PCS를 연결 제어하는 스테이션과 
/// 연결 요청 처리에 대한 예
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

#include<map>
#include<string>
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>

template<typename id_t, size_t aviable_num_of_channels=5>
class station
{
private:
	typedef std::map<id_t, bool> list_t;
	list_t phones;
	
public:
	
	static bool used(
		const typename list_t::value_type &phone)
	{
		return phone.second;
	}
	
	void add(const id_t &phone_id, bool state)
	{
		phones.insert(std::make_pair(phone_id, state));
	}
	
	void remove(const id_t &phone_id)
	{
		phones.erase(phones.find(phone_id));
	}
	
	bool have(const id_t &phone_id) const
	{
		if(phones.find(phone_id)!=phones.end())
			return true;
		return false;
	}
	
	bool connect(const id_t &phone_id)
	{
		typename list_t::iterator it;
		if((it = phones.find(phone_id)) != phones.end())
		{
			typename 
				list_t::difference_type used_num_of_channels;
			used_num_of_channels = 
				std::count_if(
				phones.begin(), phones.begin(), used);
			
			if(used_num_of_channels < aviable_num_of_channels 
				&&	it->second == false)
				return it->second = true;
		}
		return false;
	}
};

template<typename station_t, typename id_t>
struct have: 
public std::binary_function<station_t, const id_t *, bool>
{
	bool operator()(station_t s, const id_t *p_id) const
	{
		return s.have(*p_id);
	}
};

template<typename id_t, size_t num_of_stations=5>
class center
{
private:
	typedef station<id_t> station_t;
	std::vector<station_t> stations;
	
public:
	
	center()
	{
		stations.reserve(num_of_stations);
	}
	
	bool connect(const id_t &dest_phone_id)
	{
		typename std::vector<station_t>::iterator it = 
			std::find_if(stations.begin(), stations.end(), 
			std::bind2nd(
			have<station_t, id_t>(), &dest_phone_id));
		
		if(it != stations.end())
		{
			if(it->connect(dest_phone_id))
				return true;
		}
		return false;
	}
	
	void add_station(station_t &s)
	{
		stations.push_back(s);
	}
};

int main()
{
	using namespace std;
	
	station<std::string> keabong_1dong, kwang_myong_1dong;
	
	keabong_1dong.add("01X-XXX-XXXX", false);
	keabong_1dong.add("01X-YYY-YYYY", false);
	kwang_myong_1dong.add("01X-AAA-ZZZZ", false);
	
	center<std::string> center;
	
	center.add_station(keabong_1dong);
	center.add_station(kwang_myong_1dong);
	
	if(center.connect("01X-XXX-XXXX")) 
		cout<< "Success to connect to 01X-XXX-XXXX" << endl;
	else
		cout<< "Fail to connect to 01X-XXX-XXXX" << endl;
	if(center.connect("01X-ZZZ-ZZZZ"))
		cout<< "Success to connect to 01X-ZZZ-ZZZZ" << endl;
	else
		cout<< "Fail to connect to 01X-ZZZ-ZZZZ" << endl;
	if(center.connect("01X-XXX-XXXX"))
		cout<< "Success to connect to 01X-XXX-XXXX" << endl;
	else
		cout<< "Fail to connect to 01X-XXX-XXXX" << endl;
	
}
