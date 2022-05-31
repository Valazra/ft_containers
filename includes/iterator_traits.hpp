#ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS

# include <iterator>

namespace ft
{
	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
	};
}

#endif
