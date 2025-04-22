//////////////////////////////////////////////////////////////
/// 
/// \file message_queue.cpp
///
/// \brief
///  메시지 큐
///
/// STLport의 queue를 기반으로 검색 기능을 갖는 searchable_queue를
/// 만들고, 이를 이용해 메시지 큐를 생성하는 예
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

#include<deque>
#include<iostream>
#include<algorithm>

namespace st 
{
	template <class value_t, class container_t = std::deque<value_t> >
	class searchable_queue 
	{
	public:
		typedef typename container_t::value_type      value_type;
		typedef typename container_t::size_type       size_type;
		typedef          container_t                  container_type;
		
	protected:
		container_t c;
		
	public:
		searchable_queue() : c() {}
		explicit searchable_queue(const container_t& __c) : c(__c) {}
		
		bool empty() const 
		{ 
			return c.empty(); 
		}
		
		size_type size() const 
		{ 
			return c.size(); 
		}
		
		value_type &front() 
		{ 
			return c.front(); 
		}
		
		const value_type &front() const 
		{ 
			return c.front(); 
		}
		
		value_type &back() 
		{ 
			return c.back(); 
		}
		
		const value_type &back() const 
		{ 
			return c.back(); 
		}
		
		void push(const value_type& x) 
		{ 
			c.push_back(x); 
		}
		
		void pop() 
		{ 
			c.pop_front(); 
		}
		
		bool find( const value_type& x)
		{
			if(std::find( c.begin(), c.end(), x ) == c.end())
				return false;
			return true;
		}
	};
	
	
	
	template<typename queue_arg_t >
		inline bool operator==(const st::searchable_queue<queue_arg_t>& x, 
					   const st::searchable_queue<queue_arg_t>& y)
	{
		return x.c == y.c;
	}
	
	template<typename queue_arg_t >
		inline bool operator<(const st::searchable_queue<queue_arg_t>& x,
		const st::searchable_queue<queue_arg_t>& y)
	{
		return x.c < y.c;
	}
}

struct message_t
{
	unsigned int msg;
	unsigned long w_param;
	unsigned long l_param;
};

inline bool operator==(const message_t &a, const message_t &b)
{
	if(a.msg == b.msg)
		return true;
	return false;
}

class message_queue
{
private:
	st::searchable_queue< message_t > queue;

public:
	bool add(const message_t &msg)
	{
		if( queue.find(msg) )
			return false;
		else 
			queue.push( msg );
		return true;
	}

	message_t pop()
	{
		message_t msg = queue.front();
		queue.pop();

		return msg;
	}
};

int main()
{
	message_queue my_msg_queue;

	message_t msg1;
	msg1.msg = 0x0001;
	msg1.w_param = 0x0000;
	msg1.l_param = 0x0000;
	my_msg_queue.add(msg1);
	
	message_t msg2;
	msg2.msg = 0x0002;
	msg2.w_param = 0x0000;
	msg2.l_param = 0x0000;
	my_msg_queue.add(msg2);
		
	message_t msg3;
	msg3.msg = 0x0003;
	msg3.w_param = 0x0000;
	msg3.l_param = 0x0000;
	my_msg_queue.add(msg3);
	
	
	message_t msg= my_msg_queue.pop();
	std::cout << msg.msg << "(" << msg.w_param << ", " << msg.l_param << ")";
	std::cout << std::endl;
	
	msg= my_msg_queue.pop();
	std::cout << msg.msg << "(" << msg.w_param << ", " << msg.l_param << ")";
	std::cout << std::endl;
	
	msg= my_msg_queue.pop();
	std::cout << msg.msg << "(" << msg.w_param << ", " << msg.l_param << ")";
	std::cout << std::endl;
}
