#pragma once

#include <map>
#include <vector>
#include <string>
#include "Object.h"

using namespace std;

class IGrouping {
	public:
		virtual map<string, vector<int>> groupByCriterion(const vector<Object>& objectList) = 0;
		virtual ~IGrouping() = default;
};