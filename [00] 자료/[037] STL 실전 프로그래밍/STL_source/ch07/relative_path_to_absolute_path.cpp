//////////////////////////////////////////////////////////////
/// 
/// \file relative_path_to_absolute_path.cpp
///
/// \brief
///  상대 경로를 절대 경로로 변환
///
/// 현재 경로와 상대 경로를 입력받은 후 이를 절대 경로로 
/// 변환하는 예
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
#include<string>
#include<vector>
#include<iostream>
#include<exception>


template<typename char_t>
std::basic_string<char_t> 
move(const std::basic_string<char_t> &current, 
	 const std::basic_string<char_t> &relative)
{
	typedef std::basic_string<char_t> string_t;
	
	const string_t delim("/");
	const string_t up_to("..");
	
	if( current.empty() ) throw std::logic_error("Invalid path");
	if( relative.empty() ) throw std::logic_error("Invalid path");
	
	string_t curr_path(current);
	string_t rel_path(relative);
	
	if( delim.compare(curr_path.c_str()-delim.size()) != 0 )
		curr_path += delim;
	if( delim.compare(rel_path)!= 0 )
		rel_path.insert(
		rel_path.begin(), delim.begin(), delim.end());
	std::vector<string_t> current_;
	typename string_t::size_type current_pos(0), new_current_pos;
	while(
		(new_current_pos=curr_path.find(delim, current_pos)) 
		!= string_t::npos )
	{
		string_t temp( 
			curr_path.begin() + current_pos, 
			curr_path.begin() + new_current_pos);
		
		current_.push_back( temp );
		
		current_pos = new_current_pos + delim.size();
	}
	
	std::vector<string_t> relative_;
	typename string_t::size_type 
		relative_pos(string_t::npos), new_relative_pos;
	while( 
		(new_relative_pos=rel_path.rfind(delim, relative_pos)) 
		!= string_t::npos )
	{
		if(relative_pos == string_t::npos)
		{
			string_t temp(
				rel_path.begin() + new_relative_pos + delim.size(), 
				rel_path.end() );
			relative_.push_back( temp );
		}
		else
		{
			string_t temp(
				rel_path.begin() + new_relative_pos + delim.size(), 
				rel_path.begin() + relative_pos + delim.size());
			relative_.push_back( temp );
		}
		
		if( new_relative_pos == 0 )
			break;
		else
			relative_pos = new_relative_pos - delim.size();
	}
	while( !relative_.empty() )
	{
		if( relative_.back() == up_to )
		{
			if(current_.empty())
				throw std::logic_error("Invalid relative path");
			else
			{
				current_.pop_back();
				relative_.pop_back();
			}
		}
		else
			break;
	}
	std::basic_string<char_t> next_path;
	for( size_t i(0); i<current_.size(); ++i )
	{
		next_path += current_[i] + delim;
	}
	for( size_t j(relative_.size()); j>0; --j )
	{
		next_path += relative_[j-1] + delim;
	}
	
	return next_path;
}

int main()
{
	try
	{
		std::cout << move(std::string("A/B/C/D"), std::string("../dkj/D1")) << std::endl;	
	}
	catch(...)
	{
		std::cout << "Error" << std::endl;
	}
}
