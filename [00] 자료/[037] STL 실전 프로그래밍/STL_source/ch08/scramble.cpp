//////////////////////////////////////////////////////////////
/// 
/// \file scramble.cpp
///
/// \brief
///  스크램블
///
/// bitset을 이용해 한 바이트 내의 비트를 섞어 반환하는 예.
/// descramble은 섞여 있는 바이트를 원 상태로 회복 시켜 준다.
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
#include<iostream>
#include<bitset>
#include<exception>
#include<vector>
#include<functional>

inline bool legal_position(unsigned int pos)
{
	if( pos >=4 && pos <=7 ) return true;
	return false;
}

template<typename byte_t>
inline byte_t scramble(
					   std::vector<unsigned short> table, byte_t byte)
{
	enum { num_of_bit_per_byte = 8 };
	typedef std::bitset<num_of_bit_per_byte> mybitset;
	
	if(table.size() != 4) 
		throw std::logic_error("Invalid scramble table");
	if(num_of_bit_per_byte != 8) 
		throw std::logic_error("Invalid number of bits per byte");
	if(std::find_if(table.begin(), table.end(),
		std::not1(std::ptr_fun(legal_position)))
		!= table.end())
		throw std::logic_error("Invalid scramble value");
	
	mybitset tbyte(byte);
	
	for(size_t i(0); i<table.size(); ++i)
	{
		bool temp = tbyte[i];
		tbyte[i] = tbyte[table[i]];
		tbyte[table[i]] = temp;
	}
	
	return static_cast<byte_t>(tbyte.to_ulong());
}

template<typename byte_t>
inline byte_t descramble(
						 std::vector<unsigned short> table, byte_t byte)
{
	return scramble(table, byte);
}

int main()
{
	unsigned char t(119), scrambled_t;
	
	std::cout << "Original: " << t << std::endl;
	
	unsigned short stable[] = { 5,7,6,4 };
	
	std::cout 
		<< "Scrambled: "
		<< int(scrambled_t = scramble(std::vector<unsigned short>(stable, stable+4), t) )
		<< std::endl;
	
	std::cout 
		<< "Descrambled: "
		<< int(descramble(std::vector<unsigned short>(stable, stable+4), scrambled_t))
		<< std::endl;
}