#pragma once

#include <string>
#include <vector>
#include "ObjectListRepository.h"
#include "IGrouping.h"

using namespace std;

class ConsoleProcessorUI {
	public:
		ConsoleProcessorUI(ObjectListRepository& repository);

		void run();

		map<string, vector<int>>& getGroups();
		void setGroups(map<string, vector<int>>& groups);

	private:
		std::vector<std::string> menuCommands;
		std::vector<std::string> criteriaMenu;

		ObjectListRepository* repository;

		void showMenu();
		void showCriteriaMenu();

		void processObjectList(std::string& groupCriterion);

		bool isResultListLoaded(string resultFileName);

		map<string, vector<int>> groups;
};
