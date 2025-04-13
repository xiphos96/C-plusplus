#pragma warning(disable: 4786) 

#include"BuildingCore.h"
#include<exception>
#include<iomanip>
#include<limits>
#include<algorithm>
#include<sstream>
#include<functional>

namespace
{
	// 차가 주차해 있다면 true를 반환한다.
	struct is_in_car: public std::unary_function< const rooms_t::value_type, bool>
	{
		bool operator() (const rooms_t::value_type room) const
		{
			return room.second.in_car;
		}
	};

	struct is_floor: public std::binary_function< const floor_info_t , const std::string , bool >
	{
		bool operator () (const floor_info_t floor, const std::string id) const
		{
			if( floor.id == id ) 
				return true;
			else 
				return false;
		}
	};
}


std::pair< 
	std::vector<floor_info_t>::const_iterator,
	std::vector<floor_info_t>::const_iterator
	> building_core::get_building() const
{
	return std::make_pair( floors.begin(), floors.end() );
}

std::pair<std::vector<floor_info_t>::const_iterator, bool>
building_core::get_floor( const std::string &floor_id ) const
{
	std::vector<floor_info_t>::const_iterator it = 
		std::find_if( floors.begin(), floors.end(), std::bind2nd(is_floor(), floor_id));

	if( it == floors.end() )
		return std::make_pair( it, false );
	return std::make_pair( it, true );
}

std::pair<room_info_t, bool> building_core::get_room( const std::string &room_id ) const
{	
	// 모든 층을 뒤져가며 
	for( size_t i(0); i<floors.size(); ++i )
	{
		rooms_t::const_iterator it = floors[i].rooms.find(room_id);
		if( it != floors[i].rooms.end() )
		{
			return std::make_pair( it->second, true );
		}
	}
	return std::make_pair( room_info_t(), false );
}

std::pair<room_info_t, bool> building_core::get_car( const std::string &car_id ) const
{	
	// 모든 층을 뒤져가며 
	for( size_t i(0); i<floors.size(); ++i )
	{
		// 모든 방을 뒤져가며
		for( rooms_t::const_iterator 
			it = floors[i].rooms.begin(); it != floors[i].rooms.end(); ++it)
		{
			if( car_id == it->second.car_id )
				return std::make_pair( it->second, true );
		}
	}
	return std::make_pair( room_info_t(), false );
}

// 생성자
// : 입력된 매개변수를 바탕으로 건물을 세운다.
void building_core::create(size_t ground, size_t underground, 
							 const std::vector<size_t> &room_numbers)
{
	if( ground + underground != room_numbers.size() ) 
		throw std::logic_error("Invalid Parameters");
	
	number_of_ground = ground;
	number_of_underground = underground;

	// 층마다 방을 할당하고, 번호를 매긴다.
	for(size_t i(1); i<=room_numbers.size(); ++i)
	{	
		// 층 id를 만든다. 
		std::stringstream floor_id;		
		if(i<=number_of_underground)
		{
			floor_id << "B" << underground-(i-1);
		}
		else
		{
			// 4층은 F로 표시한다.
			if( (i- underground)==4 )
				floor_id << "F" ;
			else
				floor_id << i - underground;
		}

		// 방을 만든다.
		rooms_t rooms;
		for(size_t j(1); j<=room_numbers[i-1]; ++j)
		{
			// 방 id를 만든다.
			// : id 형식은 [층][방번호: 3자리]
			std::stringstream room_id;			
			room_id << floor_id.str() << std::setw(3) << std::setfill('0') << j;

			room_info_t room;
			room.id = room_id.str();
			room.in_car = false;

			rooms.insert( std::make_pair( room_id.str(), room ) );
		}

		floor_info_t floor;

		floor.id = floor_id.str();
		floor.rooms = rooms;

		floors.push_back( floor );
	}
}

// floor_id층에서 빈 첫 번째 방을 찾아 빈방의 ID를 반환한다. 
// 만일 빈방이 없으면 second는 false가 된다. 만일 floor_id가 잘못되었다면, 
// first는 빈방의 ID가 아닌 floor_id가 된다.
std::pair<std::string, bool> building_core::find_empty_room(std::string floor_id) const
{
	std::pair<std::vector<floor_info_t>::const_iterator, bool> 
		rst = get_floor( floor_id );
		
	if( !rst.second )
		return std::make_pair( floor_id, false );

	rooms_t::const_iterator it = 
		std::find_if( rst.first->rooms.begin(), rst.first->rooms.end(), std::not1(is_in_car()));
	
	if( it == rst.first->rooms.end() )
		return std::make_pair( std::string(), false);

	return std::make_pair(it->first, true);
}


// 아래와 같은 원칙으로 다음 차가 입고할 위치를 가리킨다.
// 
// 1. 층간 이동을 최소화 할 것.
// 2. 룸간 최소화 할 것.
//
// 그리고 pair의 first 멤버로 방의 번호를, second로 방위치를 성공적으로
// 반환했는지 여부를 표시한다.
std::pair<std::string, bool> building_core::get_next_room() const
{
	if( floors.empty() )
		return std::make_pair( std::string(), false );

	// 1층, 2층, 지하 1층, 3층, 지하 2층, ... 과 같은 순서로 찾는다.
	std::pair<std::string, bool> rst;

	// 1층
	rst = find_empty_room( floors[number_of_underground].id );
	if( rst.second )
		return std::make_pair( rst.first, true );
	
	// VC++6.0에서 std::max를 지원하지 않는 관계로 아래처럼 임시로 작성.
	size_t max = number_of_underground<number_of_ground ? number_of_ground:number_of_underground;

	// 2층, 지하 1층, 3층, 지하 2층 ...
	for(size_t i(0); i<max; ++i)
	{
		// 지상
		if( i+1<number_of_ground )
		{
			rst = find_empty_room( floors.at(i+number_of_underground+1).id );
			if( rst.second )
				return std::make_pair( rst.first, true );
		}

		// 지하
		// 1, 0
		if( i<number_of_underground )
		{
			rst = find_empty_room( floors.at(number_of_underground-(i+1)).id );
				if( rst.second )
				return std::make_pair( rst.first, true );
		}
	}
	return std::make_pair( std::string(), false );
}

// room_id를 가진 방이 비어 있다면 차를 주차 시킨다.
bool building_core::set_room(const std::string &room_id, const std::string &car_id, time_t start_time)
{
	// 모든 층을 뒤져가며 
	for( size_t i(0); i<floors.size(); ++i )
	{
		rooms_t::iterator it = floors[i].rooms.find(room_id);
		if( it != floors[i].rooms.end() )
		{
			if( !it->second.in_car )
			{
				it->second.in_car = true;
				it->second.car_id = car_id;
				it->second.start_time = start_time;
				return true;
			}
		}
	}

	return false;
}

// room_id를 가진 방이 비어 있다면 차를 뺀다.
std::pair<time_t, bool> building_core::reset_room(const std::string &room_id)
{
	// 모든 층을 뒤져가며 
	for( size_t i(0); i<floors.size(); ++i )
	{
		rooms_t::iterator it = floors[i].rooms.find(room_id);
		if( it != floors[i].rooms.end() )
		{
			if( it->second.in_car )
			{
				it->second.in_car = false;
				return std::make_pair(it->second.start_time, true);
			}
		}
	}
	
	return std::make_pair(0, false);
}

// term 보다 오랜 동안 주차되어 있는 모든 주차 정보를 반환.
std::vector<room_info_t> building_core::stay( time_t curr_time, time_t term ) const
{
	std::vector<room_info_t> list;

	// 모든 층을 뒤져가며 
	for( size_t i(0); i<floors.size(); ++i )
	{
		// 모든 방을 뒤져가며
		for( rooms_t::const_iterator 
			it = floors[i].rooms.begin(); it != floors[i].rooms.end(); ++it)
		{
			if( it->second.in_car && curr_time - it->second.start_time > term )
				list.push_back(it->second);
		}
	}
	
	return list;
}