//////////////////////////////////////////////////////////////
/// 
/// \file searchable_pq.cpp
///
/// \brief
///  찾기 기능이 있는 priority_queue
///
/// STLport의 PQ를 기반으로 찾기 기능을 추가하여 나만의 
/// PQ를 제공한다.
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
#include<iostream>
#include<iterator>
#include<string>
#include<functional>

template <class Tp, class Sequence = std::vector<Tp>, 
class Compare = std::less<typename Sequence::value_type> >
class  searchable_pqueue {
	
public:
	typedef typename Sequence::value_type      value_type;
	typedef typename Sequence::size_type       size_type;
	typedef            Sequence                    container_type;
	
protected:
	Sequence c;
	Compare comp;
	
public:
	
	explicit searchable_pqueue(
		const Compare& x = Compare(), const Sequence& s = Sequence()) 
		:  c(s), comp(x) 
	{
		std::make_heap(c.begin(), c.end(), comp);
	}
	
	template<class InputIterator>
		searchable_pqueue(
		InputIterator first, InputIterator last, 
		const Compare& x = Compare(), const Sequence& s = Sequence() )
		: c(s), comp(x)
	{ 
		c.insert(c.end(), first, last);
		std::make_heap(c.begin(), c.end(), comp);
	}
	bool empty() const; 
	size_type size() const;	
	const value_type& top() const
	{ 
		return c.front(); 
	}
	
	void push(const value_type& x) 
	{
		c.push_back(x); 
		std::push_heap(c.begin(), c.end(), comp);
	}
	
	void pop() 
	{
		std::pop_heap(c.begin(), c.end(), comp);
		c.pop_back();
	}
	
	bool find( const value_type &x )
	{
		std::sort_heap( c.begin(), c.end() );
		bool rst = std::binary_search( c.begin(), c.end(), x );
		std::make_heap( c.begin(), c.end() );
		return rst; 
	}
	
	template< typename char_t >
		void print( std::basic_ostream<char_t> &out)
	{
		std::copy(
			c.begin(), c.end(), std::ostream_iterator<value_type>(out, " "));
		out << std::endl;
	}
};

int main()
{
	searchable_pqueue<int> sq;
	
	sq.push(17);
	std::cout << "Insert 17" << std::endl;
	sq.print(std::cout);
	
	std::cout << "Find 17 - ";
	if(sq.find(17)) 
		std::cout<< "PQ has it." << std::endl;
}

