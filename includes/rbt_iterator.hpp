#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{

	template <class T>
	struct Node
	{
		T _data;
		Node *_parent;
		Node *_left;
		Node *_right;
		int _color;	//0 for black and 1 for red

		Node(T data, Node *parent, Node *left, Node *right, int color) : _data(data), _parent(parent), _left(left), _right(right), _color(color)
		{
		}
	};

	template <class T>
	Node<T> *minimum(Node<T> *node)
	{
		while (node && node->_left != NULL)
			node = node->_left;
		return (node);
	}

	template <class T>
	Node<T> *maximum(Node<T> *node)
	{
		while (node && node->_right != NULL)
			node = node->_right;
		return (node);
	}

	template <class T>
	class rbt_iterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef rbt_iterator iterator_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::reference node_reference;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::pointer node_ptr;
			typedef typename iterator<ft::bidirectional_iterator_tag, T>::reference reference;
			typedef typename iterator<ft::bidirectional_iterator_tag, T>::pointer pointer;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::difference_type difference_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::iterator_category iterator_category;

			rbt_iterator(void) : _ptr(NULL)
			{
			}
		
			rbt_iterator(node_ptr const &ptr) : _ptr(ptr)
			{
			}

			rbt_iterator(rbt_iterator const &src) : _ptr(src._ptr)
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
				return (_ptr->_data);
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			iterator_type &operator++()
			{
				if (_ptr->_right == _ptr->_left && _ptr->_parent->_parent == _ptr)
				{
					if (!_ptr->_right)
						_ptr = _ptr->_parent;
					else
						_ptr = maximum(_ptr->_right);
				}
				else if (_ptr->_right)
				{
					_ptr = _ptr->_right;
					while (_ptr->_left)
						_ptr = _ptr->_left;
				}
				else
				{
					node_ptr y = _ptr->_parent;
					while (y && _ptr == y->_right)
					{
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_right != y)
						_ptr = y;
				}
				return (*this);
			}

			iterator_type operator++(int)
			{
				iterator_type _tmp = *this;
				operator++();
				return (_tmp);
			}

			iterator_type &operator--()
			{
				if (_ptr->_left)
				{
					_ptr = _ptr->_left;
					while (_ptr->_right)
						_ptr = _ptr->_right;
				}
				else
				{
					node_ptr y = _ptr->_parent;
					while (_ptr == y->_left)
					{
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_left != y)
						_ptr = y;
				}
				return (*this);
			}

			iterator_type operator--(int)
			{
				iterator_type _tmp = *this;
				operator--();
				return (_tmp);
			}

		private :
			node_ptr _ptr;
	};

	template <class T1, class T2>
	bool operator==(const rbt_iterator<T1> &rbt1, const rbt_iterator<T2> &rbt2)
	{
		return (rbt1.base() == rbt2.base());
	}

	template <class T1, class T2>
	bool operator!=(const rbt_iterator<T1> &rbt1, const rbt_iterator<T2> &rbt2)
	{
		return (rbt1.base() != rbt2.base());
	}

	template <class T>
	class const_rbt_iterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef const_rbt_iterator iterator_type;
			typedef T value_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::reference node_reference;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::pointer node_ptr;
			typedef const T &reference;
			typedef const T *pointer;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::difference_type difference_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::iterator_category iterator_category;

			const_rbt_iterator(void) : _ptr(NULL)
			{
			}
		
			const_rbt_iterator(node_ptr const &ptr) : _ptr(ptr)
			{
			}

			const_rbt_iterator(rbt_iterator<T> const &src) : _ptr(src.base())
			{
			}

			const_rbt_iterator(const_rbt_iterator const &src) : _ptr(src._ptr)
			{
			}

			~const_rbt_iterator(void)
			{
			}

			node_ptr base(void) const
			{
				return (_ptr);
			}

			reference operator*() const
			{
				return (_ptr->_data);
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			iterator_type &operator++()
			{
				if (_ptr->_right == _ptr->_left && _ptr->_parent->_parent == _ptr)
				{
					if (!_ptr->_right)
						_ptr = _ptr->_parent;
					else
						_ptr = maximum(_ptr->_right);
				}
				else if (_ptr->_right)
				{
					_ptr = _ptr->_right;
					while (_ptr->_left)
						_ptr = _ptr->_left;
				}
				else
				{
					node_ptr y = _ptr->_parent;
					while (y && _ptr == y->_right)
					{
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_right != y)
						_ptr = y;
				}
				return (*this);
			}

			iterator_type operator++(int)
			{
				iterator_type _tmp = *this;
				operator++();
				return (_tmp);
			}

			iterator_type &operator--()
			{
				if (_ptr->_left)
				{
					_ptr = _ptr->_left;
					while (_ptr->_right)
						_ptr = _ptr->_right;
				}
				else
				{
					node_ptr y = _ptr->_parent;
					while (_ptr == y->_left)
					{
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_left != y)
						_ptr = y;
				}
				return (*this);
			}

			iterator_type operator--(int)
			{
				iterator_type _tmp = *this;
				operator--();
				return (_tmp);
			}

			bool operator==(const const_rbt_iterator rbt2) const
			{
				return (base() == rbt2.base());
			}

			bool operator!=(const const_rbt_iterator rbt2) const
			{
				return (base() != rbt2.base());
			}

		private :
			node_ptr _ptr;
	};

	template <class T1, class T2>
	bool operator==(const rbt_iterator<T1> &rbt1, const const_rbt_iterator<T2> rbt2)
	{
		return (rbt1.base() == rbt2.base());
	}

	template <class T1, class T2>
	bool operator==(const const_rbt_iterator<T1> &rbt1, const rbt_iterator<T2> rbt2)
	{
		return (rbt1.base() == rbt2.base());
	}

	template <class T1, class T2>
	bool operator!=(const rbt_iterator<T1> &rbt1, const const_rbt_iterator<T2> rbt2)
	{
		return (rbt1.base() != rbt2.base());
	}

	template <class T1, class T2>
	bool operator!=(const const_rbt_iterator<T1> &rbt1, const rbt_iterator<T2> rbt2)
	{
		return (rbt1.base() != rbt2.base());
	}
}

#endif
