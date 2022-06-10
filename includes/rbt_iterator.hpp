#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "iterator.hpp"
# include "red_black_tree.hpp"

namespace ft
{

	template <class T>
	class rbt_iterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef tree_iterator iterator_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::reference node_reference;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::pointer node_ptr;
			typedef typename iterator<ft::bidirectional_iterator_tag, T>::reference reference;
			typedef typename iterator<ft::bidirectional_iterator_tag, T>::pointer pointer;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::iterator_category iterator_category;

			rbt_iterator(void) : _ptr(NULL)
			{
			}
		
			rbt_iterator(const node_ptr &ptr) : _ptr(ptr)
			{
			}

			rbt_iterator(const tree_iterator &src) : _ptr(src._ptr)
			{
			}

			~rbt_iterator(void)
			{
			}

			node_ptr base(void) const
			{
				return (_ptr);
			}

			reference operator*() const
			{
				return (_ptr->data);
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			iterator_type operator++(int)
			{
				iterator_type _tmp = *this;
				operator++();
				return (_tmp);
			}

	};

}

#endif
