#include <iostream>
#include <map>

int main ()
{
	std::map<std::string, std::string> map;
	map["Armenia"] ="Yerevan";
	map["Russia"] ="Moscow";
	map["USA"] ="Vashington";
	map["Brazil"] ="Brazil";
	map["Sudan"] ="Khartoum";
	map["Ethiopia"] ="Addis-Ababa";
	map["Sweden"] ="Stockholm";
	map["Switzerland"] ="Bern";
	map["Germany"] ="Berlin";
	
	
	
	std::map<std::string, std::string>::iterator it = map.begin();
	while (it != map.end())
  {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    ++it;
  }
	return 0;
}