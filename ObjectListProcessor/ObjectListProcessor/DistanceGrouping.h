#pragma once

#include "IGrouping.h"

class DistanceGrouping : IGrouping {
	map<string, vector<int>> groupByCriterion(const vector<Object>& objectList) override;
};