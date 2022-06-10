#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "less.hpp"
# include "rbt_iterator.hpp"
# include "pair.hpp"

namespace ft
{

	template <class T, class Compare = ft::less<T> >
	class red_black_tree
	{
		public :
			typedef Node<T> *node_ptr;
			typedef Node<T> node;
			typedef rbt_iterator<T> iterator;
			typedef const_rbt_iterator<T> const_iterator;
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

		
			iterator begin(void)
			{
				if (!_root)
					return (end());
				return (iterator(miminum(_root)));
			}

			const_iterator begin(void) const
			{
				if (!_root)
					return (end());
				return (const_iterator(mimum(_root)));
			}

			iterator end(void)
			{
				return (iterator(_end));
			}

			const_iterator end(void) const
			{
				return (const_iterator(_end));
			}
		
			void clear(void)
			{
				clear_helper(_root);
			}

			node_ptr malloc_node(data_type data = data_type(), node_ptr parent = NULL, node_ptr left = NULL, node_ptr right = NULL, int color = 0)
			{
				node_ptr new_node = _allocator.allocate(1);
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

			void left_rotation(node_ptr nd)
			{
				node_ptr nd2 = nd->_right;
				nd->_right = nd2->_left;
				if (nd2->_left)
					nd2->_left->_parent = nd;
				nd2->_parent = nd->_parent;
				if (nd->_parent == _end)
				{
					_root = nd2;
					_root->_parent = _end;
					_end->_right = _root;
					_end->_left = _root;
					_end->_parent = _root;
				}
				else if (nd == nd->_parent->_left)
					nd->_parent->_left = nd2;
				else
					nd->_parent->_right = nd2;
				nd2->_left = nd;
				nd->_parent = nd2;
			}

			void right_rotation(node_ptr nd)
			{
				node_ptr nd2 = nd->_left;
				nd->_left = nd2->_right;
				if (nd2->_right)
					nd2->_right->_parent = nd;
				nd2->_parent = nd->_parent;
				if (nd->_parent == _end)
				{
					_root = nd2;
					_root->_parent = _end;
					_end->_right = _root;
					_end->_left = _root;
					_end->_parent = _root;
				}
				else if (nd == nd->_parent->_right)
					nd->_parent->_right = nd2;
				else
					nd->_parent->_left = nd2;
				nd2->_right = nd;
				nd->_parent = nd2;
			}

			pair<iterator, bool> insert(const data_type &key)
			{
				node_ptr node = malloc_node(key, NULL, NULL, NULL, 1);
				node_ptr nd = _root;
				node_ptr nd2 = NULL;

				while (nd)
				{
					nd2 = nd;
					if (_comp(node->_data, nd->_data))
						nd = nd->_left;
					else if (_comp(nd->_data, node->_data))
						nd = nd->_right;
					else
					{
						free_node(node);
						return (pair<iterator, bool>(iterator(nd), false));
					}
				}
				_size++;
				node->_parent = nd2;
				if (!nd2)
				{
					_root = node;
					_root->_parent = _end;
					_end->_right = _root,
					_end->_left = _root;
					_end->_parent = _root;
				}
				else if (_comp(node->_data, nd2->_data))
					nd2->_left = node;
				else
					nd2->_right = node;
				if (node->_parent == _end)
				{
					node->_color = 0;
					return (pair<iterator, bool>(iterator(node), true));
				}

				if (node->_parent->_parent == _end)
					return (pair<iterator, bool>(iterator(node), true));
				fix_insert(node);
				return (pair<iterator, bool>(iterator(node), true));
			}

			void fix_insert(node_ptr nd)
			{
				node_ptr nd2;
				while (nd->_parent->_color == 1)
				{
					if (nd->_parent == nd->_parent->_parent->_right)
					{
						nd2 = nd->_parent->_parent->_left;
						if (nd2 && nd2->_color == 1)
						{
							nd2->_color = 0;
							nd->_parent->_color = 0;
							nd->_parent->_parent->_color = 1;
							nd = nd->_parent->_parent;
						}
						else
						{
							if (nd == nd->_parent->_left)
							{
								nd = nd->_parent;
								right_rotation(nd);
							}
							nd->_parent->_color = 0;
							nd->_parent->_parent->_color = 1;
							left_rotation(nd->_parent->_parent);
						}
					}
					else
					{
						nd2 = nd->_parent->_parent->_right;
						if (nd2 && nd2->_color == 1)
						{
							nd2->_color = 0;
							nd->_parent->_color = 0;
							nd->_parent->_parent->_color = 1;
							nd = nd->_parent->_parent;
						}
						else
						{
							if (nd == nd->_parent->_right)
							{
								nd = nd->_parent;
								left_rotation(nd);
							}
							nd->_parent->_color = 0;
							nd->_parent->_parent->_color = 1;
							right_rotation(nd->_parent->_parent);
						}
					}
					if (nd == _root)
						break ;
				}
				_root->_color = 0;
				_allocator.destroy(_end);
				_allocator.construct(_end, node(maximum(_root)->_data, _root, _root, _root, 0));
			}

			void print_nodes(node_ptr curr, int distance)
			{
				if (!curr)
					return ;
				distance += 5;

				print_nodes(curr->_right, distance);

				std::cout << std::endl;
				for (int i = 5 ; i < distance ; i++)
					std::cout << " ";
				if (curr->_color)
					std::cout << "\033[1;31m";
				std::cout << curr->_data << "\033[0m\n" << std::endl;
				print_nodes(curr->_left, distance);
			}

			void print_rbt(void)
			{
				print_nodes(_root, 0);
			}

			private : 
				node_ptr _root;
				node_ptr _end;
				size_t _size;
				std::allocator<Node<T> > _allocator;
				key_compare _comp;

	};
}

#endif
