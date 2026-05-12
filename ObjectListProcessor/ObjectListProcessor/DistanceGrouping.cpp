#include "DistanceGrouping.h"
#include "Object.h"
#include <algorithm>
#include "Utils.h"
#include <iostream>

using namespace std;

map<string, vector<int>> DistanceGrouping::groupByCriterion(vector<Object>& objectList) {
	map<string, vector<int>> groupByDistanceList;

	vector<int> lessThan100;
	vector<int> lessThan1000;
	vector<int> lessThan10000;
	vector<int> tooFar;

	//Start point is {0, 0}
	for (int i = 0; i < objectList.size(); ++i) {
		if (objectList[i].distance >= 10000) {
			tooFar.push_back(i);
		}
		else if (objectList[i].distance >= 1000) {
			lessThan10000.push_back(i);
		}
		else if (objectList[i].distance >= 100) {
			lessThan1000.push_back(i);
		}
		else if (objectList[i].distance >= 0) {
			lessThan100.push_back(i);
		}
	}

	sortByDistance(lessThan100, objectList);
	sortByDistance(lessThan1000, objectList);
	sortByDistance(lessThan10000, objectList);
	sortByDistance(tooFar, objectList);

	groupByDistanceList.insert({ "less than 100", lessThan100 });
	groupByDistanceList.insert({ "less than 1000", lessThan1000 });
	groupByDistanceList.insert({ "less than 10000", lessThan10000 });
	groupByDistanceList.insert({ "too far", tooFar });

	return groupByDistanceList;
}

void DistanceGrouping::sortByDistance(vector<int>& distanceGroupVector, vector<Object>& objectList) {
	std::sort(begin(distanceGroupVector), end(distanceGroupVector), [&objectList](int a, int b) {
		return objectList[a].distance < objectList[b].distance;
	});
}