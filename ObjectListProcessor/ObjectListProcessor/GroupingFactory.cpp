#include "GroupingFactory.h"
#include "IGrouping.h"
#include <iostream>

IGrouping* GroupingFactory(std::string& processingCriterion)
{
	IGrouping* grouping = nullptr;

	if (processingCriterion == "Distance")
	{
		grouping = new DistanceGrouping();

		return grouping;
	}
	/*else if (processingCriterion == "Name")
	{
		grouping = new NameGrouping();

		return grouping;
	}
	else if (processingCriterion == "Date")
	{
		grouping = new DateGrouping();

		return grouping;
	}
	else if (processingCriterion == "Type")
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