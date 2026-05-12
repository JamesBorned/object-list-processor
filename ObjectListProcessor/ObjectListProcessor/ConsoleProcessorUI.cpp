#include "ConsoleProcessorUI.h"
#include <iostream>
#include <string>
#include "Utils.h"
#include "Object.h"
#include "ObjectListRepository.h"

ConsoleProcessorUI::ConsoleProcessorUI(ObjectListRepository& repository) {
	this->menuCommands = { "Upload a file.", "Process the list of objects.", "Save the results to a file.", "Exit"};
    this->repository = &repository;
};

void ConsoleProcessorUI::run() {
    showMenu();

    bool isCanceled = false;

    std::string commandNumber = "0";

    while (commandNumber != "4") {

        switch (stoi(commandNumber)) {

            case 0: {

                std::cout << "Select an action. Enter the command number (from 1 to " << this->menuCommands.size() << ") or just Enter to cancel: ";

                std::getline(std::cin, commandNumber);

                if (commandNumber.empty()) {
                    std::cout << "Cancel." << std::endl;
                    commandNumber = "0";

                    break;
                }

                if (isNumber(commandNumber) && stoi(commandNumber) > 0 && stoi(commandNumber) <= menuCommands.size()) {
                    break;
                }
                else {
                    commandNumber = "0";

                    std::cerr << "Error: Wrong number dialed, try again." << endl;

                    break;
                }
            }
            case 1: {

                std::cout << "Enter the file name(f.e. data.txt), Enter - cancel: ";

                bool isWrongFileName = true;

                std::string fileName;
                std::getline(std::cin, fileName);

                if (fileName.empty()) {
                    cout << "Cancel.\n";
                    commandNumber = "0";

                    break;
                }

                while (isWrongFileName) {
                    repository->setFileName(fileName);
                    repository->loadObjectList();

                    if (!repository->getObjectList().empty()) {
                        isWrongFileName = false;
                        cout << "File is loaded!" << endl;

                        commandNumber = "0";
                    }
                    else {
                        cerr << "Error: Something went wrong. Try again." << endl;
                        break;
                    }
                }

                break;
            }
            case 2: {

                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
        }
    }

    
}

void ConsoleProcessorUI::showMenu() {
    std::cout << std::endl;

    std::cout << "MENU:" << std::endl;

    std::cout << std::endl;

    for (int i = 0; i < this->menuCommands.size(); ++i) {
        std::cout << i + 1 << ". " << menuCommands[i] << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
}

void processObjectList(std::string& groupCriterion) {

}