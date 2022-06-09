#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "less.hpp"
# include "node.hpp"

namespace ft
{

	template <class T, class Compare = ft::less<T> >
	class red_black_tree
	{
		public :
			typedef Node<T> *node_ptr;
			typedef Node<T> node;
//			typedef tree_iterator<T> iterator;
//			typedef const_tree_iterator<T> const_iterator;
			typedef T data_type;
			typedef Compare key_compare;

			red_black_tree(const key_compare &comp = key_compare()) : _root(NULL), _size(0), _comp(comp)
			{
				_end = malloc_node();
				_end->_parent = _root;
				_end->_right = _root;
				_end->_left = _root;
			}

			~red_black_tree(void)
			{
				clear();
				free_node(_end);
			}

			red_black_tree &operator=(const red_black_tree &src)
			{
				_allocator = src._allocator;
				_comp = src._comp;
				clear();
		//////////////////////////////////////////////
		//////////////////////////////////////////////
				return (*this);
			}

			bool empty(void) const
			{
				return (_size == 0);
			}

			size_t size(void) const
			{
				return (_size);
			}

			size_t max_size(void) const
			{
				return (_allocator.max_size());
			}

		/*
			iterator begin(void)
			{
				if (!_root)
					return (end());
				return (iterator(miminum(_root));
			}

			const_iterator begin(void) const
			{
				if (!_root)
					return (end());
				return (const_iterator(mimum(_root));
			}

			iterator end(void)
			{
				return (iterator(_end));
			}

			const_iterator end(void) const
			{
				return (const_iterator(_end));
			}
		*/
			void clear(void)
			{
				clear_helper(_root);
			}

			private : 
				node_ptr _root;
				node_ptr _end;
				size_t _size;
				std::allocator<Node<T> > _allocator;
				key_compare _comp;

			node_ptr malloc_node(data_type data = data_type(), node_ptr parent = NULL, node_ptr left = NULL, node_ptr right = NULL, int color = 0)
			{
				node_ptr new_node;
				new_node = _allocator.allocate(1);
				_allocator.construct(new_node, node(data, parent, left, right, color));
				return (new_node);
			}

			void clear_helper(node_ptr &curr)
			{
				if (!curr)
					return ;
				clear_helper(curr->_left);
				clear_helper(curr->_right);
				free_node(curr);
				_size--;
			}

			void free_node(node_ptr curr)
			{
				_allocator.destroy(curr);
				_allocator.deallocate(curr, 1);
			}
	};
}

#endif
