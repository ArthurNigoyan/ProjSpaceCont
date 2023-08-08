#include <iostream>
#include "singleList.h"
int main()
{
	my_list<int> list;
	list.push_back(11);
	list.push_back(110);
	list.push_back(58);
	list.push_back(32);
	list.push_back(66);
	list.push_back(75);
	// list.print();
	// list.pop_back();
	// std::cout<<std::endl;
	list.print();
	list.reverse();
	list.print();
	std::cout<<std::endl;
	bool z = false;
	bool k =list.check_cycle();
	std::cout<<"klklklk "<<k<<std::endl;;
	std::cout<<"klklklk "<<std::endl;;
	std::cout<<std::endl;
	std::cout<<"2nd element is: "<<list.findN(2)<<std::endl;;
	return 0;
}