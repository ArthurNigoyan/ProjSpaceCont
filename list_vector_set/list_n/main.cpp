#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include "template.h"


int main ()
{
		
	// create and fill the file with integers
	std::ofstream ch;
	ch.open("sample.txt");
	for (int i=0; i<20;i++)
	{
		ch<<rand()%20<<" ";
	}
	ch.close();
	//
	std::list<int> listcont;
	std::vector<int> veccont;
	std::multiset<int> setcont;
	//read from file
	std::string line;
	std::ifstream ch1;
	
	ch1.open("sample.txt");
	getline(ch1, line);
	ch1.close();
	std::istringstream is(line);
	int num;
	int c=0;
	while (c!=20)
	{
		is>>num;
		// std::cout<<"num is : "<<num;
		listcont.push_back(num);
		veccont.push_back(num);
		setcont.insert(num);
		++c;
	}
	int n=10;
	remove_elements(listcont,n);
	remove_elements(veccont,n);
	remove_elements(setcont,n);
	print_all(listcont);
	std::cout<<std::endl;
	print_all(veccont);
	std::cout<<std::endl;
	print_all(setcont);
	std::cout<<std::endl;
	return 0;
}