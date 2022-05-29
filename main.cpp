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
	print_datas_vector(cons1);

	//copy constructor
	ft::vector<int> cons2(cons1);
	print_datas_vector(cons2);

	//assignation
	ft::vector<int> cons3;
	cons3 = cons1;
	print_datas_vector(cons3);

	//constructor with 5 copies of default T
	ft::vector<int> cons4 = ft::vector<int>(5);
	print_datas_vector(cons4);

	//constructor with 5 copies of 526
	ft::vector<int> cons5 = ft::vector<int>(5, 526);
	print_datas_vector(cons5);
	
	
	return (0);
}
