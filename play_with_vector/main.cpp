#include <iostream>
#include <vector>
#include <algorithm>
#include "odd_double.h"

// void remove_odd_numbers (std::vector<int>& vect)
// {
	// int size = vect.size();
	// for (int i=0; i<size;i++)
	// {
		// if (vect[i]%2!=0)
		// {
			// vect.erase(vect.begin()+i);
			// i--;
			// size=vect.size();
		// }
	// }
// }
// void remove_duplicate_numbers(std::vector<int>& vect)
// {
	
	// auto itend = vect.end();
    // for (auto it = vect.begin(); it != itend; ++it) {
        // itend = std::remove(it + 1, itend, *it);
    // }
 
    // vect.erase(itend, vect.end()); 
// }
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
	std::cout<<"after"<<std::endl;;
for (auto ir = obj.begin(); ir != obj.end(); ++ir)
        std::cout << *ir << " ";	
	std::cout<<std::endl;
	remove_duplicate_numbers(obj);
	std::cout<<std::endl;
	// std::cout<<"after sort"<<std::endl
for (auto ir = obj.begin(); ir != obj.end(); ++ir)
        std::cout << *ir << " ";		
	return 0;
}