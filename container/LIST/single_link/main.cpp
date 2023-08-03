#include <iostream>
#include "singleList.h"
int main()
{
	my_list<int> list;
	list.push_back(11);
	list.push_back(110);
	list.push_back(58);
	list.push_back(32);
	list.print();
	list.pop_back();
	std::cout<<std::endl;
	list.print();
	return 0;
}