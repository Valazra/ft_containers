#include "../../includes/map.hpp"

int main(void)
{
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
	rbt.print_rbt();

/*	ft::map<int, std::string> test;
	for (size_t i = 0 ; i < 5 ; i++)
		test[i] = "coco";

	for (size_t k = 0 ; k < 5 ; k++)
		std::cout << test[k] << std::endl;
*/
	return (0);
}
