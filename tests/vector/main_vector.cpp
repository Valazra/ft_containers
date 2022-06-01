#include "../../includes/vector.hpp"

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

	std::cout << "-------------CONSTRUCTORS-------------" << std::endl << std::endl;
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

	//constructor with assignation
	ft::vector<int> cons3;
	cons3 = cons1;
	print_datas_vector(cons3);

	//constructor with 5 copies of default T
	ft::vector<int> cons4 = ft::vector<int>(5);
	print_datas_vector(cons4);

	//constructor with 5 copies of 526
	ft::vector<int> cons5 = ft::vector<int>(5, 526);
	print_datas_vector(cons5);
	
//	ft::vector<int> cons6 = ft::vector<int>(cons3.begin(), cons3.end());
//	print_datas_vector(cons6);

	//iterators
	std::cout << "-------------ITERATORS-------------" << std::endl << std::endl;
	ft::vector<int>::iterator it = cons1.begin();
	std::cout << "it = " << *it << std::endl;
	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "--+it = " << *--it << std::endl;
	std::cout << "*(it + 2) = " << *(it + 2) << std::endl;
	std::cout << std::endl << "******************************" << std::endl << std::endl;

	//at
	std::cout << "-------------AT-------------" << std::endl << std::endl;
	try
	{
		std::cout << cons1.at(1) << std::endl;
		std::cout << cons1.at(6) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "******************************" << std::endl << std::endl;

	//assign
	std::cout << "-------------ASSIGN-------------" << std::endl << std::endl;
	print_datas_vector(cons3);
	cons3.assign(5, 555);
	print_datas_vector(cons3);
	cons3.assign(1, 111);
	print_datas_vector(cons3);

	//insert
	std::cout << "-------------INSERT-------------" << std::endl << std::endl;
	cons5.pop_back();	
	cons5.pop_back();	
	cons5.pop_back();	
	cons5.push_back(22);	
	cons5.push_back(25);	
	cons5.push_back(28);	
	print_datas_vector(cons5);
	cons5.insert(cons5.begin(), 12);
	cons5.insert(cons5.end(), 13);
	cons5.insert(cons5.begin() + 3, 2, 99);
	print_datas_vector(cons5);

//marche pas pour des vectors vides
//	ft::vector<int> insert1;
//	ft::vector<int> insert2;
//	insert1.insert(insert1.begin(), 1);
//	insert2.insert(insert2.end(), 1);
//	print_datas_vector(insert1);
//	print_datas_vector(insert2);

	//erase
	std::cout << "-------------ERASE-------------" << std::endl << std::endl;
	cons1.push_back(20);	
	print_datas_vector(cons1);
	cons1.erase(cons1.begin());
	print_datas_vector(cons1);
	cons1.erase(cons1.begin() + 1, cons1.end() - 1);
	print_datas_vector(cons1);

	print_datas_vector(cons5);
	cons5.erase(cons5.begin() + 2, cons5.end() - 2);
	print_datas_vector(cons5);

	return (0);
}
