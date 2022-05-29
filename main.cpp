#include "includes/vector.hpp"
#include "includes/stack.hpp"
#include "includes/map.hpp"

template < typename T >
void print_datas_vector(ft::vector<T> const & vect)
{
	std::cout << "Vector size is : " << vect.size() << " and capacity is : " << vect.capacity() << std::endl << std::endl;
	std::cout << "Datas of vector : " << std::endl;
	for (size_t i = 0 ; i < vect.size() ; i++)
		std::cout << i << " : " << vect[i] << std::endl;
	std::cout << std::endl << "******************************" << std::endl << std::endl;
}

int	main(void)
{
	std::cout << "***************************" << std::endl << std::endl;

	//default constructor
	ft::vector<int> cons1;
	print_datas_vector(cons1);
	cons1.push_back(5);
	cons1.push_back(10);
	cons1.push_back(15);
	cons1.push_back(15);
	cons1.push_back(15);
	print_datas_vector(cons1);

	//copy constructor
	ft::vector<int> cons2(cons1);
	print_datas_vector(cons2);
	
	return (0);
}
