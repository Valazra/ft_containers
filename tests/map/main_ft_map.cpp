#include "../../includes/map.hpp"

template <class Key, class T>
void print_datas_map(ft::map<Key, T> & map)
{
	std::cout << "Map size is : " << map.size() << std::endl;
	std::cout << "Datas of map : " << std::endl;
	for (typename ft::map<Key, T>::iterator it = map.begin() ; it != map.end() ; it++)
		std::cout << "Key = " << it->first << "   and value = " << it->second << std::endl;
	std::cout << std::endl << "******************************" << std::endl << std::endl;
}

int main(void)
{
	std::cout << "***********************************" << std::endl << std::endl;
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
	return (0);
}
