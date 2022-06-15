#include "../../includes/map.hpp"

template <class Key, class T>
void print_datas_map(ft::map<Key, T> & map)
{
	std::cout << "Map size is : " << map.size() << " and map is empty ? " << map.empty() << std::endl;
	std::cout << "Datas of map : " << std::endl;
	for (typename ft::map<Key, T>::iterator it = map.begin() ; it != map.end() ; it++)
		std::cout << "Key = " << it->first << "   and value = " << it->second << std::endl;
	std::cout << std::endl << "******************************" << std::endl << std::endl;
}

int main(void)
{
/*	std::cout << "***********************************" << std::endl << std::endl;
	std::cout << "-------------RBT-------------" << std::endl << std::endl;
	ft::red_black_tree<int> rbt;

	rbt.insert(16);
	rbt.insert(20);
	rbt.insert(52);
	rbt.insert(55);
	rbt.insert(61);
	rbt.insert(85);
	rbt.insert(76);
	rbt.insert(71);
	rbt.insert(65);
	rbt.insert(81);
	rbt.insert(93);
	rbt.insert(90);
	rbt.insert(101);
	rbt.print_rbt();
	std::cout << std::endl << std::endl;

	std::cout << "empty : " << rbt.empty() << std::endl;
	std::cout << "size : " << rbt.size() << std::endl;
	std::cout << "max_size : " << rbt.max_size() << std::endl;
	std::cout << "search_tree (65) : " << rbt.search_tree(65) << std::endl;
	std::cout << "delete_node (101) : " << rbt.delete_node(101) << std::endl;
	std::cout << "delete_node (155) : " << rbt.delete_node(155) << std::endl << std::endl;
	std::cout << "New rbt is now : " << std::endl;
	rbt.print_rbt();

	std::cout << "Let's see how rbt is ordered, using iterators" << std::endl;
	ft::rbt_iterator<int> it;
	ft::rbt_iterator<int> it2;
	it = rbt.begin();
	it2 = rbt.end();
	while (it != it2)
	{
		std::cout << *it << std::endl;
		it++;
	}
*/
	std::cout << std::endl << "**********************************" << std::endl << std::endl;
	std::cout << "-------------MAP-CONSTRUCTORS-------------" << std::endl << std::endl;

	//default constructor
	std::cout << "Default constructor called named cons1" << std::endl;
	std::cout << "We insert some datas at keys 0 1 2 3 4 5" << std::endl;
	ft::map<int, std::string> cons1;
	cons1[0] = "Salut";
	cons1[1] = "les";
	cons1[2] = "amis";
	cons1[3] = "je";
	cons1[4] = "suis";
	cons1[5] = "etudiant";
	std::cout << std::endl << "cons1 : " << std::endl;;
	print_datas_map(cons1);

	//copy constructor
	ft::map<int, std::string> cons2(cons1);
	std::cout << "Copy constructor cons2(cons1)" << std::endl;
	std::cout << "cons2 : "; 
	print_datas_map(cons2);

	//assignation
	ft::map<int, std::string> cons3 = cons2;
	std::cout << "Assignation cons3 = cons2" << std::endl;
	std::cout << "cons3 = "; 
	print_datas_map(cons3);

	//begin et end avec iterator
	std::cout << "-------------------BEGIN-END--------------------" << std::endl << std::endl;
	ft::map<int, std::string>::iterator it3 = cons1.begin();
	ft::map<int, std::string>::iterator it4 = cons1.end();
	std::cout << "it3 = cons1.begin()" << std::endl;
	for ( ; it3 != it4 ; it3++)
		std::cout << "it3->first = " << it3->first << " and it3->second = " << it3->second << std::endl;

	//rbegin et rend avec reverse_iterator
	std::cout << std::endl << "-------------------RBEGIN-REND--------------------" << std::endl << std::endl;
	ft::map<int, std::string>::reverse_iterator rit = cons1.rbegin();
	ft::map<int, std::string>::reverse_iterator rit2 = cons1.rend();
	std::cout << "rit = cons1.rbegin()" << std::endl;
	for ( ; rit != rit2 ; rit++)
		std::cout << "rit->first = " << rit->first << " and rit->second = " << rit->second << std::endl;
	std::cout << std::endl << "**********************************" << std::endl << std::endl;

	//insert
	std::cout << "-------------------INSERT--------------------" << std::endl << std::endl;
	ft::map<int, std::string> cons4;
	cons4.insert(ft::pair<int, std::string>(0, "Salut"));

	ft::map<int, std::string>::iterator it5 = cons4.begin();
	cons4.insert(it5, ft::pair<int, std::string>(1, "les"));
	cons4.insert(it5, ft::pair<int, std::string>(2, "amis"));


	ft::map<int, std::string> cons5;
	cons5.insert(cons4.begin(), cons4.find(2));

	std::cout << "cons4 is now : " << std::endl;
	print_datas_map(cons4);

	std::cout << "cons5 is now : " << std::endl;
	print_datas_map(cons5);

	//erase
	std::cout << "-------------------ERASE--------------------" << std::endl << std::endl;
	std::cout << "cons1 is : " << std::endl;
	print_datas_map(cons1);

	cons1.erase(2);
	std::cout << "cons1 is now : " << std::endl;
	print_datas_map(cons1);

	it5 = cons1.begin();
	it5++;
	it5++;
	cons1.erase(it5);
	std::cout << "cons1 is now : " << std::endl;
	print_datas_map(cons1);

	it5 = cons1.begin();
	it5++;
	cons1.erase(it5, cons1.end());
	std::cout << "cons1 is now : " << std::endl;
	print_datas_map(cons1);
	
	//swap
	std::cout << "-------------------SWAP--------------------" << std::endl << std::endl;
	
	std::cout << "cons1 is : " << std::endl;
	print_datas_map(cons1);
	std::cout << "cons2 is : " << std::endl;
	print_datas_map(cons2);
	cons1.swap(cons2);

	std::cout << "cons1 is now : " << std::endl;
	print_datas_map(cons1);
	std::cout << "cons2 is now : " << std::endl;
	print_datas_map(cons2);

	//clear
	std::cout << "-------------------CLEAR--------------------" << std::endl << std::endl;

	std::cout << "cons1 is : " << std::endl;
	print_datas_map(cons1);
	
	cons1.clear();
	std::cout << "cons1 is now : " << std::endl;
	print_datas_map(cons1);

	//find
	std::cout << "-------------------FIND--------------------" << std::endl << std::endl;

	std::cout << "cons3 is : " << std::endl;
	print_datas_map(cons3);

	ft::map<int, std::string>::iterator it6;
	it6 = cons3.find(2);
	std::cout << "it6 = cons3.find(2);" << std::endl;
	std::cout << "it6->first = " << it6->first << " and it6->second = " << it6->second << std::endl;
	it6 = cons3.find(4);
	std::cout << "it6 = cons3.find(4);" << std::endl;
	std::cout << "it6->first = " << it6->first << " and it6->second = " << it6->second << std::endl;

	//count
	std::cout << std::endl << "-------------------COUNT--------------------" << std::endl << std::endl;

	ft::map<int, std::string> cons6;
	cons6[0] = "aaa";
	cons6[1] = "bbb";
	cons6[3] = "ddd";
	std::cout << "cons6 is : " << std::endl;
	print_datas_map(cons6);

	for (int i = 0 ; i < 4 ; i++)
	{
		std::cout << i;
		if (cons6.count(i) > 0)
			std::cout << " is an element of my map" << std::endl;
		else
			std::cout << " is not an element of my map" << std::endl;
	}

	//lower_bound et upper_bound
	std::cout << std::endl << "-------------------LOWER-UPPER-BOUND--------------------" << std::endl << std::endl;

	std::cout << "cons6 is : " << std::endl;
	cons6.erase(3);
	cons6[2] = "ccc";
	cons6[3] = "ddd";
	cons6[4] = "eee";
	print_datas_map(cons6);
	
	ft::map<int, std::string>::iterator itlow, itup;
	itlow = cons6.lower_bound(1); 
	itup = cons6.upper_bound(3); 
	cons6.erase(itlow);
	cons6.erase(itup);

	std::cout << "cons6 is now : " << std::endl;
	print_datas_map(cons6);


	//equal_range 
	std::cout << "-------------------EQUAL-RANGE--------------------" << std::endl << std::endl;

	cons2[1] = "les";
	cons2[2] = "amis";
	std::cout << "cons2 is : " << std::endl;
	print_datas_map(cons2);

	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ret;
	ret = cons2.equal_range(1);
	
	std::cout << "lower_bound points to : ";
	std::cout << ret.first->first << " => " << ret.first->second << std::endl;
	std::cout << "upper_bound points to : ";
	std::cout << ret.second->first << " => " << ret.second->second << std::endl;

	//relational operators
	std::cout << std::endl << "-------------------RELATIONAL-OPERATORS--------------------" << std::endl << std::endl;

	std::cout << "cons2 is : " << std::endl;
	print_datas_map(cons2);
	std::cout << "cons6 is : " << std::endl;
	print_datas_map(cons6);

	if (cons2 == cons6)

		std::cout << "cons2 and cons6 are ==" << std::endl;
	else
		std::cout << "cons2 and cons6 are not ==" << std::endl;
	if (cons2 != cons6)
		std::cout << "cons2 and cons6 are !=" << std::endl;
	else
		std::cout << "cons2 and cons6 are not !=" << std::endl;
	if (cons2 < cons6)
		std::cout << "cons2 < cons6" << std::endl;
	else
		std::cout << "cons2 is not < cons6" << std::endl;
	if (cons2 <= cons6)
		std::cout << "cons2 <= cons6" << std::endl;
	else
		std::cout << "cons2 is not <= cons6" << std::endl;
	if (cons2 > cons6)
		std::cout << "cons2 > cons6" << std::endl;
	else
		std::cout << "cons2 is not > cons6" << std::endl;
	if (cons2 >= cons6)
		std::cout << "cons2 >= cons6" << std::endl;
	else
		std::cout << "cons2 is not >= cons6" << std::endl;

	std::cout << std::endl << "**********************************" << std::endl << std::endl;
	return (0);
}
