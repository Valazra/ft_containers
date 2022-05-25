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
	//		typedef typename allocator_type::const_reference const_reference;
	//		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	//		typedef std::ptrdiff_t difference_type;
	//		typedef T* iterator;
			typedef typename allocator_type::pointer pointer;
	//		typedef typename allocator_type::reference reference;
	//		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef std::size_t size_type;
			typedef T value_type; 

			explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _array(NULL), _allocator(alloc)
			{
			}
		
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _array(NULL), _allocator(alloc)
			{
			}
		
		template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
			}

			vector(const vector& x) : _size(x._size), _capacity(x._capacity), _array(NULL), _allocator(x._allocator)
			{
			}

			virtual ~vector(void)
			{
			}

			vector & operator=(vector const & src)
			{
			}

		private :
			size_type _size;
			size_type _capacity;
			pointer _array;
			allocator_type _allocator;	
			
	};
}

#endif
