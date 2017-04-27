#include <iostream>
#include <map>

int main() {

	std::cout << "Map" << std::endl;
	std::cout << "===" << std::endl;

	std::map<std::string, std::string> config;

	// dictionary style
	config["site.name"] = "www.google.com";

	// using std::make_pair
	auto pair = std::make_pair("site.name", "www.google.com");
	config.insert(pair);

	std::cout << config["site.name"] << std::endl;
	

	auto iter = config.find("missing.key");
	if (iter != config.end())
		std::cout << "Key 'missing.key' was found" << std::endl;
	else 
		std::cout << "Key 'missing.key' was not found" << std::endl;

	std::cout << "Am I empty? " << (config.empty() ? "Yes" : "No") << std::endl;
	std::cout << "My size is: " << config.size() << std::endl;
	std::cout << "My capacity is: " << config.max_size() << std::endl;


	config.insert(std::make_pair("raz", "1"));
	config.insert(std::make_pair("dwa", "2"));

	auto map_iter = config.begin();
	while (map_iter != config.end()) {
		std::cout << map_iter->first << "->" << map_iter->second << std::endl;
		++map_iter;
	}
}	
