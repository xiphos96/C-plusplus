//////////////////////////////////////////////////////////////
/// 
/// \file scramble_table.cpp
///
/// \brief
///  스크램블 테이블 생성
///
/// random_shuffle을 이용하여 이미 정해진 값들로 정해진 
/// 스크램블 테이블의 값을 뒤섞어 반환한다.
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

#include<algorithm>
#include<vector>
#include<functional>
#include<iostream>

bool legal_position(unsigned int pos)
{
	if( pos >=4 && pos <=7 ) return true;
	return false;
}

inline std::vector<unsigned short> 
scramble_table(std::vector<unsigned short> poses)
{
	enum { num_of_poses = 4 };
	
	if(poses.size() != num_of_poses) 
		throw std::logic_error("Invalid pos set");
	if(std::find_if(poses.begin(), poses.end(),
		std::not1(std::ptr_fun(legal_position)))
		!= poses.end())
		throw std::logic_error("Invalid scramble value");
	
	std::vector<unsigned short> new_poses(poses);
	
	std::random_shuffle(new_poses.begin(), new_poses.end());
	
	return new_poses;
}


int main()
{
	unsigned short temp_poses[] = { 4,5,6,7 };
	std::vector<unsigned short> stable;
	
	stable = scramble_table(
		std::vector<unsigned short>(temp_poses, temp_poses+4));
	
	for(size_t i(0); i< stable.size(); i++) std::cout << stable[i];
}