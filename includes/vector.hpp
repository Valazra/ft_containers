#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"
# include "iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public :

			typedef T value_type; 
			typedef Alloc allocator_type;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::const_reference const_reference;
			typedef ptrdiff_t difference_type;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::reference reference;
			typedef ft::random_access_iterator<value_type> iterator;
			typedef ft::random_access_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef size_t size_type;

			explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _array(NULL), _allocator(alloc)
			{
			}
		
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _array(NULL), _allocator(alloc)
			{
				if (n > 0)
				{
					_array = _allocator.allocate(_capacity);
					for (size_type i = 0 ; i < n ; i++)
						_allocator.construct(_array + i, val);
				}
			}
	
		template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = 0) : _size(0), _capacity(0), _array(NULL),  _allocator(alloc)
			{
				size_type size = 0;
				for (InputIterator it = first ; it != last ; it++)
					size++;
				_size = size;
				_capacity = size;
				if (size > 0)
				{
					_array = _allocator.allocate(_capacity);
					pointer it2 = _array;
					for ( ; first != last ; first++)
					{
						_allocator.construct(it2, *first);
						it2++;
					}
				}
			}

			vector(const vector& x) : _size(x._size), _capacity(x._capacity), _array(NULL), _allocator(x._allocator)
			{
				if (x._size > 0)
				{
					_array = _allocator.allocate(_capacity);
					for (size_type i = 0, size = x._size ; i < size ; i++)
						_allocator.construct(_array + i, x._array[i]);
				}
			}

			~vector(void)
			{
				clear();
				if (_capacity != 0)
					_allocator.deallocate(_array, _capacity);
			}

			vector& operator=(const vector& x)
			{
				if (this != &x)
				{
					clear();
					if (_capacity < x._size)
					{
						_allocator.deallocate(_array, _capacity);
						_capacity = x._size;
						if (_capacity > 0)
							_array = _allocator.allocate(_capacity);
						else
							return (*this);
					}
					_size = x._size;
					for(size_type i = 0 ; i < x._size ; i++)
						_allocator.construct(_array + i, x._array[i]);
				}
				return (*this);
			}

			iterator begin(void)
			{
				return (iterator(_array));
			}
	
			const_iterator begin(void) const
			{
				return (const_iterator(_array));
			}
			
			iterator end(void)
			{
				return (iterator(_array + _size));
			}
	
			const_iterator end(void) const
			{
				return (const_iterator(_array + _size));
			}

			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(end()));
			}
	
			const_reverse_iterator rbegin(void) const
			{
				return (const_reverse_iterator(end()));
			}
	
			reverse_iterator rend(void)
			{
				return (reverse_iterator(begin()));
			}
	
			const_reverse_iterator rend(void) const
			{
				return (const_reverse_iterator(begin()));
			}

			size_type size(void) const
			{
				return (_size);
			}

			size_type max_size(void) const
			{
				return (_allocator.max_size());
			}

			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
					_size = n;
				else
					insert(end(), n - _size, val);
			}

			size_type capacity(void) const
			{
				return (_capacity);
			}
		
			bool empty(void) const
			{
				return (_size == 0 ? true : false);
			}

			//utilisé dans push_back
			void reserve(size_type n)
			{
				if (n <= _capacity)
					return ;
				pointer ptr_new = _allocator.allocate(n);
				for (size_type i = 0 ; i < _size ; i++)
				{
					_allocator.construct(ptr_new + i, _array[i]);
					_allocator.destroy(_array + i);
				}
				if (_capacity != 0)
					_allocator.deallocate(_array, _capacity);
				_capacity = n;
				_array = ptr_new;
			}

			reference operator[](size_type n)
			{
				return (_array[n]);
			}

			const reference operator[](size_type n) const
			{
				return (_array[n]);
			}

			reference at(size_type n)
			{
				if (n < 0 || n >= _size)
					throw std::out_of_range("Exception out_of_range for function at ");
				return (_array[n]);
			}

			const_reference at(size_type n) const
			{
				if (n < 0 || n >= _size)
					throw std::out_of_range("Error for 'at' ");
				return (_array[n]);
			}

			reference front(void)
			{
				return (_array[0]);
			}
			
			const_reference front(void) const
			{
				return (_array[0]);
			}
			
			reference back(void)
			{
				if (_size == 0)
					return (_array[0]);
				else
					return (_array[_size - 1]);
			}
			
			const_reference back(void) const
			{
				if (_size == 0)
					return (_array[0]);
				else
					return (_array[_size - 1]);
			}

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				clear();
				size_type size = 0;
				for (InputIterator it = first ; it != last ; it++)
					size++;
				_size = size;
				if (_capacity < size)
				{
					_allocator.deallocate(_array, _capacity);
					_capacity = size;
					if (size > 0)
						_array = _allocator.allocate(_capacity);
					else
						return ;
				}
				pointer it2 = _array;
				while (first != last)
				{
					_allocator.construct(it2, *first);
					first++;
					it2++;
				}
			}

			void assign(size_type n, const value_type& val)
			{
				clear();
				_size = n;
				if (_capacity < n)
				{
					_allocator.deallocate(_array, _capacity);
					_capacity = n;
					if (n > 0)
						_array = _allocator.allocate(_capacity);
					else
						return ;
				}
				for (size_type i = 0 ; i < n ; i++)
					_allocator.construct(_array + i, val);
			}
	
			void push_back(const value_type& val)
			{
				if (_capacity == 0)
					reserve(1);
				else if (_capacity == _size)
					reserve(_capacity * 2);
				_allocator.construct(_array + _size, val);
				_size++;
			}

			void pop_back(void)
			{
				_size--;
				_allocator.destroy(_array + _size);
			}

			iterator insert(iterator position, const value_type& val)
			{
				difference_type tmp = position - _array;
				insert(position, 1, val);
				return (iterator(begin() + tmp));
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				difference_type tmp = position - _array;
				if (n == 0)
					return ;
				if (_size + n > _capacity)
					reserve(_size * 2);
				else if (_size + n > _size * 2)
					reserve(_size + n);
				for (pointer it = _array + _size + n - 1, ite = _array + tmp + n - 1 ; it != ite ; --it)
				{
					_allocator.construct(it, *(it - n));
					_allocator.destroy(it - n);
				}
				_size += n;
				while (n > 0)
				{
					_allocator.construct(_array + tmp - 1 + n, val);
					n--;
				}
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				if (first == last)
					return ;
				difference_type tmp = position - _array;
				size_type size = 0;
				for (InputIterator it = first ; it != last ; it++)
					size++;
				if (_size + size > _size * 2)
					reserve(_size + size);
				else if (_size + size > _capacity)
					reserve(_size * 2);
				for (pointer it2 = _array + _size + size - 1, ite = _array + tmp + size - 1 ;it2 != ite ; it2--)
				{
					_allocator.construct(it2, *(it2 - size));
					_allocator.destroy(it2 - size);
				}
				_size += size;
				while (size > 0)
				{
					last--;
					_allocator.construct(_array + tmp + size - 1, *last);
					size--;
				}
			}

			iterator erase(iterator position)
			{
				return (erase(position, position + 1));
			}

			iterator erase(iterator first, iterator last)
			{
				size_type i = last - first;
				size_type j = first - _array;
				if (i > 0)
				{
					for ( ; j < _size - i ; j++)
					{
						_allocator.destroy(_array + j);
						_allocator.construct (_array + j, _array[j + i]);
					}
					for ( ; j < _size ; j++)
						_allocator.destroy(_array + j);
					_size -= i;
				}
				return (iterator(first));
			}

			void swap (vector& x)
			{
				allocator_type tmp_all = x._allocator;
				size_type tmp_size = x._size;
				size_type tmp_cap = x._capacity;
				pointer tmp_arr = x._array;

				x._allocator = _allocator;
				x._size = _size;
				x._capacity = _capacity;
				x._array = _array;

				_allocator = tmp_all;
				_size = tmp_size;
				_capacity = tmp_cap;
				_array = tmp_arr;
			}

			void clear(void)
			{
				if (empty())
					return ;
				for (size_type i = 0, size = _size ; i < size ; i++)
					_allocator.destroy(_array + i);
				_size = 0;
			}

			allocator_type get_allocator(void) const
			{
				return (_allocator);
			}

		private :
			size_type _size;
			size_type _capacity;
			pointer _array;
			allocator_type _allocator;	
			
	};

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0 ; i < lhs.size() ; i++)
			{
				if (lhs[i] != rhs[i])
					return (false);
			}
			return (true);
		}
		return (false);
	}
	
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
