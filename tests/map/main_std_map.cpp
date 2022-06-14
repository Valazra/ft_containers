#include <iostream>
#include <map>

template <class Key, class T>
void print_datas_map(std::map<Key, T> & map)
{
	std::cout << "Map size is : " << map.size() << std::endl;
	std::cout << "Datas of map : " << std::endl;
	for (typename std::map<Key, T>::iterator it = map.begin() ; it != map.end() ; it++)
		std::cout << "Key = " << it->first << "   and value = " << it->second << std::endl;
	std::cout << std::endl << "******************************" << std::endl << std::endl;
}

int main(void)
{
	std::cout << std::endl << "**********************************" << std::endl << std::endl;
	std::cout << "-------------MAP-CONSTRUCTORS-------------" << std::endl << std::endl;

	//default constructor
	std::cout << "Default constructor called named cons1" << std::endl;
	std::cout << "We insert some datas at keys 0 1 2 3 4 5" << std::endl;
	std::map<int, std::string> cons1;
	cons1[0] = "Salut";
	cons1[1] = "les";
	cons1[2] = "amis";
	cons1[3] = "je";
	cons1[4] = "suis";
	cons1[5] = "etudiant";
	std::cout << std::endl << "cons1 : " << std::endl;;
	print_datas_map(cons1);

	//copy constructor
	std::map<int, std::string> cons2(cons1);
	std::cout << "Copy constructor cons2(cons1)" << std::endl;
	std::cout << "cons2 : "; 
	print_datas_map(cons2);

	//assignation
	std::map<int, std::string> cons3 = cons2;
	std::cout << "Assignation cons3 = cons2" << std::endl;
	std::cout << "cons3 = "; 
	print_datas_map(cons3);

	//begin et end
	std::map<int, std::string>::iterator it3 = cons1.begin();
	std::map<int, std::string>::iterator it4 = cons1.end();
	std::map<int, std::string>::const_iterator cit = cons1.begin();
	std::map<int, std::string>::const_iterator cit2 = cons1.end();
	std::cout << "it3 = cons1.begin(); it3->first = " << it3->first << " and it3->second = " << it3->second << std::endl;
	it3++;
	std::cout << "it3 = cons1.begin(); it3->first = " << it3->first << " and it3->second = " << it3->second << std::endl;
	it3++;
	std::cout << "it3 = cons1.begin(); it3->first = " << it3->first << " and it3->second = " << it3->second << std::endl;
	it3++;
	std::cout << "it3 = cons1.begin(); it3->first = " << it3->first << " and it3->second = " << it3->second << std::endl;
	it3++;
	std::cout << "it3 = cons1.begin(); it3->first = " << it3->first << " and it3->second = " << it3->second << std::endl;
	it3++;
	std::cout << "it3 = cons1.begin(); it3->first = " << it3->first << " and it3->second = " << it3->second << std::endl;
	std::cout << "it4 = cons1.end(); it4->first = " << it4->first << std::endl;
/*	std::cout << "cit = cons1.begin(); cit->first = " << cit->first << " and cit->second = " << cit->second << std::endl;
	std::cout << "cit2 = cons1.end(); cit2->first = " << cit2->first << " and cit2->second = " << cit2->second << std::endl;*/

	std::cout << std::endl << "**********************************" << std::endl << std::endl;
	return (0);
}
