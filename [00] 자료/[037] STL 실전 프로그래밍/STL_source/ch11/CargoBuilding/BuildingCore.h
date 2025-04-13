#if !defined(BUILDINGCORE_H)
#define BUILDINGCORE_H

#include<string>
#include<vector>
#include<utility>
#include<ctime>
#include<map>


// �� ������ ��� �ִ�.
struct room_info_t
{
	// �� ID
	std::string id;

	// �������� �ڵ��� ��ȣ
	std::string car_id;

	// ���� ������ �ִ°�?
	bool in_car;

	// ������ ���۵� �ð�.
	time_t start_time;
};

typedef std::map< std::string, room_info_t > rooms_t;

// �� ������ ��� �մ�. 
struct floor_info_t
{
	std::string id;
	rooms_t rooms;
};

// �ǹ��� ���� ������ ��� �ִ�.
// : RAII�� �������� �ʴ´�.
class building_core
{
private:
	std::vector<floor_info_t> floors;
	
	// �� �������� ��
	size_t number_of_ground;
	// �� �������� ��
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