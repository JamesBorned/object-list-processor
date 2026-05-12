#include "Utils.h"
#include <cmath>

double calculateDistance(double x, double y) {
	double distance = 0;

	distance = sqrt(pow(x, 2) + pow(y, 2));

	return distance;
}

bool isNumber(std::string& string) {
    for (char c : string) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    return true;  
}