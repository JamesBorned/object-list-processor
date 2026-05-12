#pragma once

#include <string>
#include <vector>

using namespace std;

class ConsoleProcessorUI {
	public:
		ConsoleProcessorUI();

		void run();

	private:
		std::vector<std::string> menuCommands;

		void showMenu();

		void processObjectList(std::string& groupCriterion);
};
