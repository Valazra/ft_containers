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
	//		typedef const T* const_iterator;
	//		typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::const_reference const_reference;
	//		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	//		typedef std::ptrdiff_t difference_type;
	//		typedef T* iterator;
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
	
//peut etre InputOperator et pas InputIterator ?	
		template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
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

			reference operator[](size_type n)
			{
				return (_array[n]);
			}

			const reference operator[](size_type n) const
			{
				return (_array[n]);
			}
			
			bool empty(void) const
			{
				return (_size == 0 ? true : false);
			}

			size_type size(void) const
			{
				return (_size);
			}

			size_type capacity(void) const
			{
				return (_capacity);
			}
			
			void clear(void)
			{
				if (empty())
					return ;
				for (size_type i = 0, size = _size ; i < size ; i++)
					_allocator.destroy(_array + i);
				_size = 0;
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

			void push_back(value_type const & val)
			{
				if (_capacity == 0)
					reserve(1);
				else if (_capacity == _size)
					reserve(_capacity * 2);
				_allocator.construct(_array + _size, val);
				_size++;
			}

		private :
			size_type _size;
			size_type _capacity;
			pointer _array;
			allocator_type _allocator;	
			
	};
}

#endif
