#include <iostream>
#include <vector>

template < typename T >
void print_datas_vector(std::vector<T> const & vect)
{
	std::cout << "Vector size is : " << vect.size() << " and capacity is : " << vect.capacity() << " and it is empty ? " << vect.empty() << std::endl << std::endl;
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
	std::vector<int> cons1;
	print_datas_vector(cons1);
	cons1.push_back(5);
	cons1.push_back(10);
	cons1.push_back(15);
	print_datas_vector(cons1);

	//copy constructor
	std::vector<int> cons2(cons1);
	print_datas_vector(cons2);

	//assignation
	std::vector<int> cons3;
	cons3 = cons1;
	print_datas_vector(cons3);

	//constructor with 5 copies of default T
	std::vector<int> cons4 = std::vector<int>(5);
	print_datas_vector(cons4);

	//constructor with 5 copies of 526
	std::vector<int> cons5 = std::vector<int>(5, 526);
	print_datas_vector(cons5);
	
	//constructor with InputIterator
	std::vector<int> cons6 = std::vector<int>(cons3.begin(), cons3.end());
	print_datas_vector(cons6);

	std::cout << std::endl << "******************************" << std::endl << std::endl;

	std::cout << "-------------MAX_SIZE-RESIZE-------------" << std::endl << std::endl;

	//max size
	std::vector<int> cons7;
	cons7.push_back(1);
	cons7.push_back(2);
	cons7.push_back(3);
	cons7.push_back(4);
	print_datas_vector(cons7);

	std::cout << "cons7.max_size() = " << cons7.max_size() << std::endl;

	//resize
	cons7.resize(2);
	print_datas_vector(cons7);
	cons7.resize(5, 33);
	print_datas_vector(cons7);

	//at
	std::cout << "-------------AT-FRONT-BACK-------------" << std::endl << std::endl;
	try
	{
		print_datas_vector(cons1);
		std::cout << "cons1.at(1) = " << cons1.at(1) << std::endl;
		std::cout << "cons1.at(6) = " << cons1.at(6) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	//front et back
	std::cout << "cons1.front = " << cons1.front() << std::endl;
	std::cout << "cons1.back = " << cons1.back() << std::endl;

	std::cout << std::endl << "******************************" << std::endl << std::endl;
	//assign
	std::cout << "-------------ASSIGN-------------" << std::endl << std::endl;
	print_datas_vector(cons3);
	std::cout << "cons3.assign(5,555) and now cons3 is : " << std::endl;
	cons3.assign(5, 555);
	print_datas_vector(cons3);
	std::cout << "cons3.assign(1,111) and now cons3 is : " << std::endl;
	cons3.assign(1, 111);
	print_datas_vector(cons3);
	std::cout << "cons1 is : " << std::endl;
	print_datas_vector(cons1);
	std::cout << "cons3.assign(cons1.begin(), cons1.end()) and now cons3 is : " << std::endl;
	cons3.assign(cons1.begin(), cons1.end());
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
	std::cout << "cons5.insert(cons5.begin(), 12) and cons5.insert(cons5.end(), 13)" << std::endl;
	std::cout << "cons5 is now : " << std::endl;
	cons5.insert(cons5.begin(), 12);
	cons5.insert(cons5.end(), 13);
	print_datas_vector(cons5);
	std::cout << "cons5.insert(cons5.begin() + 3, 2, 99)" << std::endl;
	cons5.insert(cons5.begin() + 3, 2, 99);
	print_datas_vector(cons5);

	std::vector<int> cons8(10, 3528);
	std::cout << "cons8 is : " << std::endl;
	print_datas_vector(cons8);
	std::cout << "cons5.insert(cons5.end(), cons8.begin(), cons8.end())" << std::endl;
	cons5.insert(cons5.end(), cons8.begin(), cons8.end());
	print_datas_vector(cons5);

	//erase
	std::cout << "-------------ERASE-------------" << std::endl << std::endl;
	cons1.push_back(20);
	std::cout << "cons1 is : " << std::endl;	
	print_datas_vector(cons1);
	std::cout << "cons1.erase(cons1.begin())" << std::endl;
	cons1.erase(cons1.begin());
	print_datas_vector(cons1);
	std::cout << "cons1.erase(cons1.begin() + 1, cons1.end() - 1)" << std::endl;
	std::cout << "cons1 is now : " << std::endl;
	cons1.erase(cons1.begin() + 1, cons1.end() - 1);
	print_datas_vector(cons1);

	std::cout << "cons5 is : " << std::endl;
	print_datas_vector(cons5);
	std::cout << "cons5.erase(cons1.begin() + 2, cons5.end() - 2)" << std::endl;
	std::cout << "cons5 is now : " << std::endl;
	cons5.erase(cons5.begin() + 2, cons5.end() - 2);
	print_datas_vector(cons5);

	//swap
	std::cout << "-------------SWAP-------------" << std::endl << std::endl;
	std::cout << "cons1 is : " << std::endl;
	print_datas_vector(cons1);
	std::cout << "cons5 is : " << std::endl;
	print_datas_vector(cons5);
	std::cout << "cons1.swap(cons5) " << std::endl;
	cons1.swap(cons5);
	std::cout << "cons1 is now : " << std::endl;
	print_datas_vector(cons1);
	std::cout << "and cons5 is now : " << std::endl;
	print_datas_vector(cons5);

	//iterators 
	std::cout << "-------------ITERATORS-------------" << std::endl << std::endl;
	std::vector<int>::iterator it = cons1.begin();
	std::cout << "it = " << *it << std::endl;
	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "--it = " << *--it << std::endl;
	std::cout << "*(it + 2) = " << *(it + 2) << std::endl;
	std::cout << std::endl << "******************************" << std::endl << std::endl;

	std::vector<int>::reverse_iterator rit = cons1.rbegin();
	std::cout << "rit = " << *rit << std::endl;
	std::cout << "++rit = " << *++rit << std::endl;
	std::cout << "--rit = " << *--rit << std::endl;
	std::cout << "(rit + 2) = " << *(rit + 2) << std::endl;
	std::cout << std::endl << "******************************" << std::endl << std::endl;

	//relational operators
	std::cout << "-------------RELATIONAL-OPERATORS-------------" << std::endl << std::endl;
	std::cout << "cons1 is : " << std::endl;
	print_datas_vector(cons1);
	std::cout << "cons2 is : " << std::endl;
	print_datas_vector(cons2);
	if (cons1 == cons2)
		std::cout << "cons1 and cons2 are ==" << std::endl;
	else
		std::cout << "cons1 and cons2 are not ==" << std::endl;
	if (cons1 != cons2)
		std::cout << "cons1 and cons2 are !=" << std::endl;
	else
		std::cout << "cons1 and cons2 are not !=" << std::endl;
	if (cons1 < cons2)
		std::cout << "cons1 < cons2" << std::endl;
	else
		std::cout << "cons1 is not < cons2" << std::endl;
	if (cons1 <= cons2)
		std::cout << "cons1 <= cons2" << std::endl;
	else
		std::cout << "cons1 is not <= cons2" << std::endl;
	if (cons1 > cons2)
		std::cout << "cons1 > cons2" << std::endl;
	else
		std::cout << "cons1 is not > cons2" << std::endl;
	if (cons1 >= cons2)
		std::cout << "cons1 >= cons2" << std::endl;
	else
		std::cout << "cons1 is not >= cons2" << std::endl;

	std::cout << std::endl << "***************************" << std::endl << std::endl;
	return (0);
}
