#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "less.hpp"
# include "red_black_tree.hpp"
# include "iterator.hpp"
# include "make_pair.hpp"

namespace ft
{

	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public :
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::const_reference const_reference;
		//	typedef ft::iterator_traits<iterator>::difference_type difference_type;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::reference reference;
		//	typedef ft::tree_type::iterator iterator;
		//	typedef ft::tree_type::const_iterator const_iterator;
		//	typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		//	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef size_t size_type;


		class value_compare
		{
			public :
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;

				value_compare(key_compare c = key_compare()) : _comp(c)
				{
				}

				bool operator()(const value_type& x, const value_type& y) const
				{
					return (_comp(x.first, y.first));
				}		

			protected :
				key_compare _comp;
		};
	};
}

#endif
