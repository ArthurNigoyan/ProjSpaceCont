#ifndef _INIT_FUNC_
#define _INIT_FUNC_
template <typename T>
void remove_elements(T& name, int n)
{
	for(auto it = name.begin(); it !=name.end();)
	{
		if (*it < n)
		{
			it=name.erase(it);
		}
		else 
		{
			++it;
		}
	}
	std::cout<<std::endl;
}
template <typename N>
void print_all(N& name)
{
	for (auto it = name.begin(); it!= name.end();++it)
	{
		std::cout<< *it <<" ";
	}
}
#endif