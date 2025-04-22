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
	// ���� ������ �ִٸ� true�� ��ȯ�Ѵ�.
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
	// ��� ���� �������� 
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
	// ��� ���� �������� 
	for( size_t i(0); i<floors.size(); ++i )
	{
		// ��� ���� ��������
		for( rooms_t::const_iterator 
			it = floors[i].rooms.begin(); it != floors[i].rooms.end(); ++it)
		{
			if( car_id == it->second.car_id )
				return std::make_pair( it->second, true );
		}
	}
	return std::make_pair( room_info_t(), false );
}

// ������
// : �Էµ� �Ű������� �������� �ǹ��� �����.
void building_core::create(size_t ground, size_t underground, 
							 const std::vector<size_t> &room_numbers)
{
	if( ground + underground != room_numbers.size() ) 
		throw std::logic_error("Invalid Parameters");
	
	number_of_ground = ground;
	number_of_underground = underground;

	// ������ ���� �Ҵ��ϰ�, ��ȣ�� �ű��.
	for(size_t i(1); i<=room_numbers.size(); ++i)
	{	
		// �� id�� �����. 
		std::stringstream floor_id;		
		if(i<=number_of_underground)
		{
			floor_id << "B" << underground-(i-1);
		}
		else
		{
			// 4���� F�� ǥ���Ѵ�.
			if( (i- underground)==4 )
				floor_id << "F" ;
			else
				floor_id << i - underground;
		}

		// ���� �����.
		rooms_t rooms;
		for(size_t j(1); j<=room_numbers[i-1]; ++j)
		{
			// �� id�� �����.
			// : id ������ [��][���ȣ: 3�ڸ�]
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

// floor_id������ �� ù ��° ���� ã�� ����� ID�� ��ȯ�Ѵ�. 
// ���� ����� ������ second�� false�� �ȴ�. ���� floor_id�� �߸��Ǿ��ٸ�, 
// first�� ����� ID�� �ƴ� floor_id�� �ȴ�.
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


// �Ʒ��� ���� ��Ģ���� ���� ���� �԰��� ��ġ�� ����Ų��.
// 
// 1. ���� �̵��� �ּ�ȭ �� ��.
// 2. �밣 �ּ�ȭ �� ��.
//
// �׸��� pair�� first ����� ���� ��ȣ��, second�� ����ġ�� ����������
// ��ȯ�ߴ��� ���θ� ǥ���Ѵ�.
std::pair<std::string, bool> building_core::get_next_room() const
{
	if( floors.empty() )
		return std::make_pair( std::string(), false );

	// 1��, 2��, ���� 1��, 3��, ���� 2��, ... �� ���� ������ ã�´�.
	std::pair<std::string, bool> rst;

	// 1��
	rst = find_empty_room( floors[number_of_underground].id );
	if( rst.second )
		return std::make_pair( rst.first, true );
	
	// VC++6.0���� std::max�� �������� �ʴ� ����� �Ʒ�ó�� �ӽ÷� �ۼ�.
	size_t max = number_of_underground<number_of_ground ? number_of_ground:number_of_underground;

	// 2��, ���� 1��, 3��, ���� 2�� ...
	for(size_t i(0); i<max; ++i)
	{
		// ����
		if( i+1<number_of_ground )
		{
			rst = find_empty_room( floors.at(i+number_of_underground+1).id );
			if( rst.second )
				return std::make_pair( rst.first, true );
		}

		// ����
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

// room_id�� ���� ���� ��� �ִٸ� ���� ���� ��Ų��.
bool building_core::set_room(const std::string &room_id, const std::string &car_id, time_t start_time)
{
	// ��� ���� �������� 
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

// room_id�� ���� ���� ��� �ִٸ� ���� ����.
std::pair<time_t, bool> building_core::reset_room(const std::string &room_id)
{
	// ��� ���� �������� 
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

// term ���� ���� ���� �����Ǿ� �ִ� ��� ���� ������ ��ȯ.
std::vector<room_info_t> building_core::stay( time_t curr_time, time_t term ) const
{
	std::vector<room_info_t> list;

	// ��� ���� �������� 
	for( size_t i(0); i<floors.size(); ++i )
	{
		// ��� ���� ��������
		for( rooms_t::const_iterator 
			it = floors[i].rooms.begin(); it != floors[i].rooms.end(); ++it)
		{
			if( it->second.in_car && curr_time - it->second.start_time > term )
				list.push_back(it->second);
		}
	}
	
	return list;
}