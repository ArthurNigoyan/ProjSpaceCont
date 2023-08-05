#include <iostream>
#include <stdlib.h>
#include "doubleList.h"




int main()
{
	stack<std::string> obj6;
	obj6.push("kuku");
	obj6.push("didi");
	obj6.push("guru");
	// obj6.printstack();
	// std::cout<<"end init"<<std::endl;
	// std::cout<<"before remove"<<std::endl;
	obj6.printstack();
	obj6.pop();
	
	std::cout<<"after remove"<<std::endl;
	obj6.printstack();
	std::cout<<std::endl;
	std::cout<<"front element"<<std::endl;
	std::cout<<obj6.front()<<std::endl;;
	std::cout<<"print again"<<std::endl;
	obj6.printstack();
std::cout<<"back element"<<std::endl;
	std::cout<<obj6.back()<<std::endl;;
	obj6.push("titi");
	obj6.push("kaka");
	obj6.push("aser");
	obj6.printstack();
	std::cout<<std::endl;
	obj6.pop();
	obj6.printstack();
	std::cout<<std::endl;
	std::cout<<"guru is back element"<<std::endl;
	std::cout<<obj6.back()<<std::endl;
	std::cout<<"aser is front element"<<std::endl;
	std::cout<<obj6.front()<<std::endl;;
	return 0;
}