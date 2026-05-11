#pragma once

#include <string>

struct Object {
	//Object(std::string name, unsigned age) : name{ name }, age{ age };
	
	std::string name;

	double x;
	double y;

	std::string type;

	double dateInSeconds;

	double distance;
};
