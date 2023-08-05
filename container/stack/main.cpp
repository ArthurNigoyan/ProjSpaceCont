#include <iostream>
#include <stdlib.h>
#include "stack.h"




int main()
{
	stack<std::string> obj6;
	obj6.push("kuku");
	obj6.push("didi");
	obj6.push("guru");
	obj6.print();
	obj6.pop();
	obj6.print();
	std::cout<<obj6.top()<<std::endl;;

	return 0;
}