#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
//PROTOTYPES FOR FRIENDS
	template < class T, class Container = vector<T> >
	class stack;

	template <class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

	template <class T, class Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

	template <class T, class Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

	template < class T, class Container>
	class stack
	{
		public :
			typedef T value_type;
			typedef Container container_type;
			typedef std::size_t size_type;

			explicit stack(const container_type& ctnr = container_type())
			{
				_c = ctnr;
			}
			
			virtual ~stack(void)
			{
			}

			bool empty(void) const
			{
				return (_c.empty());
			}

			size_type size(void) const 
			{
				return (_c.size());
			}

			value_type& top(void)
			{
				return (_c.back());
			}

			const value_type& top(void) const
			{
				return (_c.back());
			}

			void push(const value_type& val)
			{
				_c.push_back(val);
			}

			void pop(void)
			{
				_c.pop_back();
			}

			friend bool operator== <T, Container>(stack const& lhs, stack const& rhs);
			friend bool operator!= <T, Container>(stack const& lhs, stack const& rhs);
			friend bool operator< <T, Container>(stack const& lhs, stack const& rhs);
			friend bool operator<= <T, Container>(stack const& lhs, stack const& rhs);
			friend bool operator> <T, Container>(stack const& lhs, stack const& rhs);
			friend bool operator>= <T, Container>(stack const& lhs, stack const& rhs);

		protected : 
			container_type _c;
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs._c == rhs._c);
	}

	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs._c != rhs._c);
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs._c < rhs._c);
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs._c <= rhs._c);
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs._c > rhs._c);
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs._c >= rhs._c);
	}
}

#endif
