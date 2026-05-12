#include "GroupingFactory.h"
#include "IGrouping.h"
#include <iostream>
#include "DistanceGrouping.h"

IGrouping* GroupingFactory(std::string& processingCriterion)
{
	IGrouping* grouping = nullptr;

	if (processingCriterion == "1")
	{
		grouping = new DistanceGrouping();

		return grouping;
	}
	/*else if (processingCriterion == "2")
	{
		grouping = new NameGrouping();

		return grouping;
	}
	else if (processingCriterion == "3")
	{
		grouping = new DateGrouping();

		return grouping;
	}
	else if (processingCriterion == "4")
	{
		grouping = new TypeGrouping();

		return grouping;
	}*/
	else {
		cerr << "Error: Something went wrong. Try again." << '\n';
		return nullptr;
	}

	return grouping;
}