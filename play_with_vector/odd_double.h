#include <iostream>
#include <set>
#ifndef _INIT_CLASS_
#define _INIT_CLASS_
void remove_odd_numbers (std::vector<int>& vect)
{
	int size = vect.size();
	for (int i=0; i<size;i++)
	{
		if (vect[i]%2!=0)
		{
			vect.erase(vect.begin()+i);
			i--;
			size=vect.size();
		}
	}
}
void remove_duplicate_numbers(std::vector<int>& vect)
{
	
	// auto itend = vect.end();
    // for (auto it = vect.begin(); it != itend; ++it) {
        // itend = std::remove(it + 1, itend, *it);
    // }
    // vect.erase(itend, vect.end());
	std::set<int> ss;
	for (auto it = vect.begin(); it != vect.end(); ++it) {
		ss.insert(*it);
    }
	vect.clear();
	for (auto it = ss.begin(); it != ss.end(); ++it) {
		vect.push_back(*it);
    }
}
#endif