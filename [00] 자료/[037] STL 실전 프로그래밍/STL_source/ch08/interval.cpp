//////////////////////////////////////////////////////////////
/// 
/// \file aligning.cpp
///
/// \brief
///  일정 구간 내에 있는 학생의 성적 데이터를 얻어오기
///
/// upper_bound와 lower_bound를 이용하여 일정한 구간 내에 있는
/// 학생들의 데이터를 얻어 오는 예
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
#include<iterator>
#include<iostream>

struct student_t
{
	unsigned short score;
	std::string name;
	
	bool operator < ( const student_t &l) const
	{
		if ( score < l.score ) return true;
		return false;
	}
	
	bool operator < ( const unsigned short s) const
	{
		if ( score < s ) return true;
		return false;
	}
	
};

bool operator < ( const unsigned short s, const student_t &r)
{
	if ( s < r.score ) return true;
	return false;
}

std::basic_ostream<char> &operator <<( std::basic_ostream<char> &out, const student_t &student)
{
	out << student.name << ": " << student.score ;
	
	return out;
}

template< typename sequence_t, typename value_t >
inline sequence_t interval( 
						   sequence_t c, value_t start, value_t end )
{
	typename sequence_t::iterator 
		first = std::lower_bound( c.begin(), c.end(), start );
	typename sequence_t::iterator 
		last = std::upper_bound( c.begin(), c.end(), end );
	
	sequence_t v;
	
	while(first != last)
	{
		v.push_back( *(first) ++ );
	}
	
	return v;
}

int main()
{
	std::vector< student_t > students;
	
	student_t stkim;
	stkim.score = 90;
	stkim.name = "stkim";
	students.push_back( stkim );
	
	student_t jtkim;
	jtkim.score = 96;
	jtkim.name = "jtkim";
	students.push_back( jtkim );
	
	student_t htkim;
	htkim.score = 73;
	htkim.name = "htkim";
	students.push_back( htkim );
	
	student_t skok;
	skok.score = 80;
	skok.name = "skok";
	students.push_back( skok );
	
	student_t swkim;
	swkim.score = 60;
	swkim.name = "swkim";
	students.push_back( swkim );
	
	std::stable_sort( students.begin(), students.end() );
	
	std::vector< student_t > from_80_to_90 =  interval( students, 80, 90);
	
	std::copy( 
		from_80_to_90.begin(), 
		from_80_to_90.end(), 
		std::ostream_iterator< student_t >(std::cout, "\n")
		);
}
