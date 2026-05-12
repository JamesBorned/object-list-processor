#pragma once

#include "IGrouping.h"

class DistanceGrouping : IGrouping {
	map<string, vector<int>> groupByCriterion(vector<Object>& objectList) override;
	
	void sortByDistance(vector<int>& distanceGroupVector, vector<Object>& objectList);
};