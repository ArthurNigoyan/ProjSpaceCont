#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


int main()
{
	
	
	// create and fill file with integer numbers
	std::ofstream ch;
	ch.open("sample.txt");
	for (int i=0; i<1000;i++)
	{
		ch<<rand()%100<<" ";
	}
	ch.close();
	//
	
	// open file and fill the the numbers to vector
	std::vector<int> vec;
	int arr[1000]={0};
	std::string line;
	std::ifstream fin;
	fin.open("sample.txt");
	std::vector<int> vec1;
	getline(fin, line);
	fin.close();
	std::istringstream is(line);
	int num;
	int c=0;
	  while (c!=1000)
	  {
		is>>num;
		vec.push_back(num);
		++c;
	 }
	for(auto it: vec)
	{
		arr[it]=++arr[it];
	}
	for (int i=0; i<1000;i++)
	{
		for (int j=0;j<arr[i]; j++)
			if(arr[i]!=0)
			vec1.push_back(i);
	}
	for(auto it: vec1)
	{
		std::cout<<it<<" ";	
	}
std::cout<<std::endl;

	return 0;
}




