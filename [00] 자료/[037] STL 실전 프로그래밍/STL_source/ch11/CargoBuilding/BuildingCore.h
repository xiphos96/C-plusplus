#if !defined(BUILDINGCORE_H)
#define BUILDINGCORE_H

#include<string>
#include<vector>
#include<utility>
#include<ctime>
#include<map>


// 방 정보를 담고 있다.
struct room_info_t
{
	// 방 ID
	std::string id;

	// 주차중인 자동차 번호
	std::string car_id;

	// 차가 주차해 있는가?
	bool in_car;

	// 주차가 시작된 시간.
	time_t start_time;
};

typedef std::map< std::string, room_info_t > rooms_t;

// 층 정보를 담고 잇다. 
struct floor_info_t
{
	std::string id;
	rooms_t rooms;
};

// 건물에 대한 정보를 담고 있다.
// : RAII를 만족하지 않는다.
class building_core
{
private:
	std::vector<floor_info_t> floors;
	
	// 총 지상층의 수
	size_t number_of_ground;
	// 총 지하층의 수
	size_t number_of_underground;

public:

	building_core(){}
	void create(size_t ground, size_t underground, const std::vector<size_t> &room_numbers);
	std::pair<std::string, bool> get_next_room() const ;
	bool set_room( const std::string &room_id, const std::string &car_id, time_t start_time );
	std::pair<time_t, bool> reset_room( const std::string &room_id );	
	std::vector<room_info_t> stay( time_t curr_time, time_t term ) const;
		
	std::pair< 
		std::vector<floor_info_t>::const_iterator,
		std::vector<floor_info_t>::const_iterator
		> get_building() const;
	std::pair<std::vector<floor_info_t>::const_iterator, bool> 
		get_floor( const std::string &floor_id ) const;
	std::pair<room_info_t, bool> get_room( const std::string &room_id ) const;
	std::pair<room_info_t, bool> get_car( const std::string &car_id ) const;

private:

	std::pair<std::string, bool> find_empty_room(std::string floor_id) const;
	std::vector<floor_info_t>::const_iterator floor_index( const std::string &floor_id ) const;
};

#endif // BUILDINGCORE_H