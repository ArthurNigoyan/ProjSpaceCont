#include <iostream>
#include <stdlib.h>
#include "singleList.h"




int main()
{
	stack<std::string> obj6;
	obj6.push("kuku");
	obj6.push("didi");
	obj6.push("guru");
	obj6.printstack();
	std::cout<<"end init"<<std::endl;
	obj6.pop();
	
	obj6.printstack();
	std::cout<<"after remove"<<std::endl;
	std::cout<<"top element"<<std::endl;
	std::cout<<obj6.top()<<std::endl;;

	return 0;
}