#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public :

//TYPEDEFS	
			typedef Alloc allocator_type;
			typedef const T* const_iterator;
	//		typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::const_reference const_reference;
	//		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef T* iterator;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::reference reference;
	//		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef std::size_t size_type;
			typedef T value_type; 

			explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _array(NULL), _allocator(alloc)
			{
			}
		
			explicit vector(size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()) : _size(n), _capacity(n), _array(NULL), _allocator(alloc)
			{
				if (n > 0)
				{
					_array = _allocator.allocate(_capacity);
					for (size_type i = 0 ; i < n ; i++)
						_allocator.construct(_array + i, val);
				}
			}
	
	/*	template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _array(NULL),  _allocator(alloc)
			{
				(void)first;
				(void)last;
			}*/

			vector(const vector& x) : _size(x._size), _capacity(x._capacity), _array(NULL), _allocator(x._allocator)
			{
				if (x._size > 0)
				{
					_array = _allocator.allocate(_capacity);
					for (size_type i = 0, size = x._size ; i < size ; i++)
						_allocator.construct(_array + i, x._array[i]);
				}
			}

			virtual ~vector(void)
			{
				clear();
				if (_capacity != 0)
					_allocator.deallocate(_array, _capacity);
			}

			vector & operator=(vector const & src)
			{
				if (this != &src)
				{
					clear();
					if (_capacity < src._size)
					{
						_allocator.deallocate(_array, _capacity);
						_capacity = src._size;
						if (_capacity > 0)
							_array = _allocator.allocate(_capacity);
						else
							return (*this);
					}
					_size = src._size;
					for(size_type i = 0 ; i < src._size ; i++)
						_allocator.construct(_array + i, src._array[i]);
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

	//rbegin

	//const rbegin

	//rend

	//const rend

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

//mettre les erreurs comme pour les vrais vectors
			reference at(size_type n)
			{
				if (n < 0 || n >= _size)
					throw std::out_of_range("Error for 'at' ");
				return (_array[n]);
			}

//mettre les erreurs comme pour les vrais vectors
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

	//template<InputIterator> assign

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
	
			void push_back(value_type const & val)
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

	//template <InputIterator> insert

			iterator erase(iterator position)
			{
				if (empty() || position == end())
					return (end());
				_allocator.destroy(position);
				for (pointer it = position, ite = end() - 1 ; it != ite ; it++)
				{
					_allocator.construct(it, *(it + 1));
					_allocator.destroy(it + 1);
				}
				_size--;
				return (position);
			}

			iterator erase(iterator first, iterator last)
			{
				if (empty() || first == last)
					return (end());
				size_type n = 0;
				for (iterator it = first ; it != last ; it++)
					n++;
				for (pointer it = first ; it != last ; it++)
					_allocator.destroy(it);
				for (pointer it = first, ite = end() - n ; it != ite ; it++)
				{
					_allocator.construct(it, *(it + n));
					_allocator.destroy(it + n);
				}
				_size -= n;
				return (first);
			}

			void swap (vector & src)
			{
				allocator_type tmp_all = src._allocator;
				size_type tmp_size = src._size;
				size_type tmp_cap = src._capacity;
				pointer tmp_arr = src._arr;

				src._allocator = _allocator;
				src._size = _size;
				src._capacity = _capacity;
				src._array = _array;

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

//a mettre avec les inputiterator
/*	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}*/

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
	void swap(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
