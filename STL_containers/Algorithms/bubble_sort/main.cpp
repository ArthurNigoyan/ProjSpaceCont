#include <iostream>
#include "vector.h"
#include "singleList.h"

// 

void sort (vectorclass<int>& cont)
{
		
	bool finished = false;
	for (auto it = cont.begin(); it != cont.end(); it++)
	{
		for (auto it1 = cont.begin(); it1 != cont.end(); it1++)
		{
			if (*it1>*(it1+1))
			{  
			  std::swap(*it1,*(it1+1));
			  finished = true;
			}
		}
		if (finished== false)
		{
			break;
		}
	}
}
//my_list

int main ()
{
	vectorclass<int> vect;
	
	for (int i=5;i!=0;i--) 
	{
	for (int i=0;i<10;i++)
	{
		vect.push_back(i);
	}
	}
	std::cout<<"before sort"<<std::endl;;
	vect.print();
	sort(vect);
	std::cout<<"after sort"<<std::endl;;
	vect.print();
	std::cout<<"end vector"<<std::endl;;
	my_list<int> llist;
	for (int i=5;i!=0;i--) 
	{
	for (int i=0;i<10;i++)
	{
		llist.push_back(i);
	}
	}
	std::cout<<"before sort"<<std::endl;;
	llist.print();
	
	llist.sort();
	std::cout<<"after sort"<<std::endl;;
	llist.print();
	return 0;
}