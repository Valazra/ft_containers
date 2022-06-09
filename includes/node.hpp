#ifndef NODE_HPP 
# define NODE_HPP

# include <iostream>

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
		while (node && node->left != NULL)
			node = node->left;
		return (node);
	}

	template <class T>
	Node<T> *maximum(Node<T> *node)
	{
		while (node && node->right != NULL)
			node = node->right;
		return (node);
	}
}

#endif
