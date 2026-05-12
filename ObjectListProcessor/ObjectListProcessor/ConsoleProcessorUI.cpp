#include "ConsoleProcessorUI.h"
#include <iostream>

ConsoleProcessorUI::ConsoleProcessorUI() {
		this->menuCommands = { "Upload a file.", "Process the list of objects.", "Save the results to a file." };
};

void ConsoleProcessorUI::run() {

}

void ConsoleProcessorUI::showMenu() {
    for (int i = 0; i < this->menuCommands.size(); ++i) {
        std::cout << i + 1 << ". " << menuCommands[i] << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
}

void processObjectList(std::string& groupCriterion) {

}