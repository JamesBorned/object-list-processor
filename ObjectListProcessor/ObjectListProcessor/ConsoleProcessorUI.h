#pragma once

#include <string>
#include <vector>
#include "ObjectListRepository.h"

using namespace std;

class ConsoleProcessorUI {
	public:
		ConsoleProcessorUI(ObjectListRepository& repository);

		void run();

	private:
		std::vector<std::string> menuCommands;
		ObjectListRepository* repository;

		void showMenu();

		void processObjectList(std::string& groupCriterion);
};
