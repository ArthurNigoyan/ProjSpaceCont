#include <iostream>
#include <vector>
#include "odd_double.h"

int main()
{
	std::vector<int> obj;
	std::vector<int> obj1;
	
	for (int i=0;i<5;i++) 
	{
	for (int i=0;i<10;i++)
	{
		obj.push_back(i);
	}
	}
	
 std::cout<<"before"<<std::endl;;
 for (auto ir = obj.begin(); ir != obj.end(); ++ir)
        std::cout << *ir << " ";
	remove_odd_numbers(obj);
	std::cout<<std::endl;
	std::cout<<"after"<<std::endl;;
for (auto ir = obj.begin(); ir != obj.end(); ++ir)
        std::cout << *ir << " ";	
	std::cout<<std::endl;
	remove_duplicate_numbers(obj);
	std::cout<<std::endl;
for (auto ir = obj.begin(); ir != obj.end(); ++ir)
        std::cout << *ir << " ";		
	return 0;
}