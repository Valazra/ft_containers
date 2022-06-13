#include <iostream>
#include <stack>

int	main(void)
{
	std::cout << "***************************" << std::endl << std::endl;
	std::stack<int> cons1;

	std::cout << "cons1 : is empty ? " << cons1.empty() << std::endl;
	std::cout << "cons1 : size is : " << cons1.size() << std::endl;

	std::cout << std::endl << "***************************" << std::endl << std::endl;
	
	cons1.push(5);
	cons1.push(10);
	cons1.push(15);
	cons1.push(20);

	std::cout << "cons1 : size is : " << cons1.size() << std::endl;
	std::cout << "cons1 : top is : " << cons1.top() << std::endl;
	std::cout << "cons1 : is empty ? " << cons1.empty() << std::endl;

	std::cout << std::endl << "***************************" << std::endl << std::endl;

	cons1.pop();

	std::cout << "cons1 : size is : " << cons1.size() << std::endl;
	std::cout << "cons1 : top is : " << cons1.top() << std::endl;
	std::cout << "cons1 : is empty ? " << cons1.empty() << std::endl;

	std::cout << std::endl << "***************************" << std::endl << std::endl;

	std::stack<int> cons2;
	std::stack<int> cons3;

	if (cons2 == cons3)
		std::cout << "cons2 and cons3 are ==" << std::endl;
	else
		std::cout << "cons2 and cons3 are not ==" << std::endl;

	std::cout << std::endl << "***************************" << std::endl << std::endl;

	cons2.push(5);
	cons3.push(5);

	if (cons2 == cons3)
		std::cout << "cons2 and cons3 are ==" << std::endl;
	else
		std::cout << "cons2 and cons3 are not ==" << std::endl;
	if (cons2 != cons3)
		std::cout << "cons2 and cons3 are !=" << std::endl;
	else
		std::cout << "cons2 and cons3 are not !=" << std::endl;
	if (cons2 < cons3)
		std::cout << "cons2 < cons3" << std::endl;
	else
		std::cout << "cons2 is not < cons3" << std::endl;
	if (cons2 <= cons3)
		std::cout << "cons2 <= cons3" << std::endl;
	else
		std::cout << "cons2 is not <= cons3" << std::endl;
	if (cons2 > cons3)
		std::cout << "cons2 > cons3" << std::endl;
	else
		std::cout << "cons2 is not > cons3" << std::endl;
	if (cons2 >= cons3)
		std::cout << "cons2 >= cons3" << std::endl;
	else
		std::cout << "cons2 is not >= cons3" << std::endl;

	std::cout << std::endl << "***************************" << std::endl << std::endl;

	cons2.push(8);
	cons3.push(9);

	if (cons2 == cons3)
		std::cout << "cons2 and cons3 are ==" << std::endl;
	else
		std::cout << "cons2 and cons3 are not ==" << std::endl;
	if (cons2 < cons3)
		std::cout << "cons2 < cons3" << std::endl;
	else
		std::cout << "cons2 is not < cons3" << std::endl;
	if (cons2 <= cons3)
		std::cout << "cons2 <= cons3" << std::endl;
	else
		std::cout << "cons2 is not <= cons3" << std::endl;
	if (cons2 > cons3)
		std::cout << "cons2 > cons3" << std::endl;
	else
		std::cout << "cons2 is not > cons3" << std::endl;
	if (cons2 >= cons3)
		std::cout << "cons2 >= cons3" << std::endl;
	else
		std::cout << "cons2 is not >= cons3" << std::endl;


	std::cout << std::endl << "***************************" << std::endl;
}
