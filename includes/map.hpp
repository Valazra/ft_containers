#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "red_black_tree.hpp"
# include "iterator.hpp"
# include "rbt_iterator.hpp"
# include "less.hpp"
# include "pair.hpp"
# include "make_pair.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"

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

			typedef Alloc allocator_type;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::reference reference;
			typedef typename ft::red_black_tree<value_type, value_compare> tree_type;
			typedef typename tree_type::iterator iterator;
			typedef typename tree_type::const_iterator const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef size_t size_type;

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rbt(tree_type(value_compare(comp))), _key(comp), _allocator(alloc)
			{
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rbt(tree_type(value_compare(comp))), _key(comp), _allocator(alloc)
			{
				for ( ; first != last ; first++)
					insert(*first);
			}

			map (const map& x)
			{
				*this = x;
			}

			~map(void)
			{
			}

			map& operator=(const map& x)
			{
				clear();
				_key = x._key;
				_value = x._value;
				_allocator = x._allocator;
				for (const_iterator it = x.begin() ; it != x.end() ; it++)
					insert(*it);
				return (*this);
			}

			iterator begin(void)
			{
				return (_rbt.begin());
			}

			const_iterator begin(void) const
			{
				return (_rbt.begin());
			}

			iterator end(void)
			{
				return (_rbt.end());
			}

			const_iterator end(void) const
			{
				return (_rbt.end());
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

			bool empty(void) const
			{
				return (_rbt.empty());
			}

			size_type size(void) const
			{
				return (_rbt.size());
			}

			size_type max_size(void) const
			{
				return (_rbt.max_size());
			}

			mapped_type& operator[](const key_type& k)
			{
				return ((*((insert(ft::make_pair(k, mapped_type()))).first)).second);
			}

			pair<iterator, bool> insert(const value_type& val)
			{
				return (_rbt.insert(val));
			}

			iterator insert(iterator position, const value_type& val)
			{
				(void)position;
				return (_rbt.insert(val).first);
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for ( ; first != last ; first++)
					insert(*first);
			}

			void erase (iterator position)
			{
				_rbt.delete_node(*position);
			}

			size_type erase (const key_type& k)
			{
				if (_rbt.delete_node(value_type(k, mapped_type())))
					return (1);
				return (0);
			}

			void erase(iterator first, iterator last)
			{
				iterator it;
				for ( ; first != last ; )
				{
					it = first;
					first++;
					_rbt.delete_node(*it);
				}
			}

			void swap(map& x)
			{
				_rbt.swap(x._rbt);

				key_compare tmp_key = x._key;
				value_compare tmp_value = x._value;
				allocator_type tmp_allocator = x._allocator;

				x._key = _key;
				x._value = _value;
				x._allocator = _allocator;

				_key = tmp_key;
				_value = tmp_value;
				_allocator = tmp_allocator;
			}

			void clear(void)
			{
				_rbt.clear();
			}

			key_compare key_comp(void) const
			{
				return (_key);
			}

			value_compare value_comp(void) const
			{
				return (_value);
			}

			iterator find(const key_type& k)
			{
				return (iterator(_rbt.search_tree(value_type(k, mapped_type()))));
			}

			const_iterator find(const key_type& k) const
			{
				return (const_iterator(_rbt.search_tree(value_type(k, mapped_type()))));
			}

			size_type count(const key_type& k) const
			{
				if (_rbt.count(value_type(k, mapped_type())))
					return (1);
				return (0);
			}

			iterator lower_bound(const key_type& k)
			{
				iterator ite = begin();
				for ( ; ite != end() ; ite++)
				{
					if (!_key(ite->first, k))
						break ;
				}
				return (ite);
			}

			const_iterator lower_bound(const key_type& k) const
			{
				const_iterator ite = begin();
				for ( ; ite != end() ; ite++)
				{
					if (!_key(ite->first, k))
						break ;
				}
				return (ite);
			}

			iterator upper_bound(const key_type& k)
			{
				iterator ite = begin();
				for ( ; ite != end() ; ite++)
				{
					if (_key(k, ite->first))
						break ;
				}
				return (ite);
			}

			const_iterator upper_bound(const key_type& k) const
			{
				const_iterator ite = begin();
				for ( ; ite != end() ; ite++)
				{
					if (_key(k, ite->first))
						break ;
				}
				return (ite);
			}

			pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<iterator, iterator> equal_range(const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			allocator_type get_allocator(void) const
			{
				return (_allocator);
			}

		private :
			tree_type _rbt;
			key_compare _key;
			value_compare _value;
			allocator_type _allocator;
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(rhs > lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
