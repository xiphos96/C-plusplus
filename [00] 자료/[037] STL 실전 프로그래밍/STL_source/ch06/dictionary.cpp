//////////////////////////////////////////////////////////////
/// 
/// \file dictionary.cpp
///
/// \brief
///  multimap을 이용한 사전 서비스
///
/// multimap을 이용하여 사전 서비스를 제공하는 예. 키는 단어가 
/// 되고, 데이터는 뜻이 된다.
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

#include<string>
#include<map>
#include<utility>
#include<vector>
#include<iostream>

template<typename str_t>
class dictionary_t
{
private:
	
	typedef std::multimap<str_t, str_t> word_list_t;
	word_list_t word_list;
	
public:
	
	void add(const str_t &word, const str_t &mean)
	{
		word_list.insert( std::make_pair(word, mean) );
	}
	
	std::vector<str_t> query(const str_t &word) const
	{
		typename word_list_t::const_iterator start =
			word_list.lower_bound(word);
		typename word_list_t::const_iterator end =
			word_list.upper_bound(word);
		typename word_list_t::difference_type size =
			std::distance(start, end);
		
		std::vector<str_t> means(size);
		for(typename std::vector<str_t>::size_type i(0); 
		start != end; ++start, ++i)
			means[i] = start->second;
		
		return means;
	}
};

int main()
{
	using namespace std;
	
	dictionary_t<std::string> dictionary;
	
	dictionary.add("add", "1. To combine to form a sum");
	dictionary.add("add", "2. To join or unite");
	
	vector<string> add = dictionary.query("add");
	cout<< "add: " <<  endl;
	copy(
		add.begin(), add.end(),
		ostream_iterator<string>(cout,"\n")
		);
}
