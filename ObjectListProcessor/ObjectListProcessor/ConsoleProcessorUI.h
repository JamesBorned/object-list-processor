#pragma once

#include <string>
#include <vector>

class ConsoleProcessorUI {
	public:
		ConsoleProcessorUI();

		void run();

	private:
		std::vector<std::string> menuCommands;

		void showMenu();

		void processObjectList(std::string& groupCriterion);
};
