#include "ConsoleProcessorUI.h"
#include <iostream>
#include <string>
#include "Utils.h"
#include "Object.h"
#include "ObjectListRepository.h"
#include "IGrouping.h"
#include "GroupingFactory.h"
#include <fstream>

using namespace std;

ConsoleProcessorUI::ConsoleProcessorUI(ObjectListRepository& repository) {
	this->menuCommands = { "Upload a file.", "Process the list of objects.", "Save the results to a file.", "Exit"};
    this->criteriaMenu = { "Group by distance." };

    this->repository = &repository;
};

void ConsoleProcessorUI::run() {
    showMenu();

    std::string commandNumber = "0";
    std::string groupingCriterion = "0";

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

                std::cout << "Enter the file name (f.e. data.txt), Enter - cancel: ";

                bool isWrongFileName = true;

                std::string fileName;
                std::getline(std::cin, fileName);

                if (fileName.empty()) {
                    cout << "Cancel." << endl;
                    commandNumber = "0";

                    break;
                }

                while (isWrongFileName) {
                    repository->setFileName(fileName);
                    repository->loadObjectList();

                    if (repository->loadObjectList()) {
                        isWrongFileName = false;
                        cout << "File was loaded!" << endl;

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

                showCriteriaMenu();

                cout << "Select an action. Enter the criterion (from 1 to " << this->criteriaMenu.size() << ") or just Enter to cancel : ";
                
                std::getline(std::cin, groupingCriterion);

                if (groupingCriterion.empty()) {
                    cout << "Cancel." << endl;
                    commandNumber = "0";

                    break;
                }

                if (isNumber(groupingCriterion) && stoi(groupingCriterion) > 0 && stoi(groupingCriterion) <= criteriaMenu.size()) {
                    processObjectList(groupingCriterion);

                    cout << "Object list was processed!" << endl;

                    commandNumber = "0";
                }
                else {
                    commandNumber = "0";

                    std::cerr << "Error: Wrong number dialed, try again." << endl;

                    break;
                }
                
                break;
            }
            case 3: {

                std::cout << "Enter the result file name (f.e. data_result.txt), Enter - cancel: ";

                bool isWrongFileName = true;

                std::string resultFileName;
                std::getline(std::cin, resultFileName);

                if (resultFileName.empty()) {
                    cout << "Cancel." << endl;
                    commandNumber = "0";

                    break;
                }

                while (isWrongFileName) {
                    if(isResultListLoaded(resultFileName) && !this->groups.empty()){
                        isWrongFileName = false;
                        cout << "The result list was written!" << endl;

                        commandNumber = "0";
                    }
                    else {
                        cerr << "Error: Something went wrong. Try again." << endl;
                        break;
                    }
                }

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

void ConsoleProcessorUI::showCriteriaMenu() {
    std::cout << std::endl;

    std::cout << "CRITERIA MENU:" << std::endl;

    std::cout << std::endl;

    for (int i = 0; i < this->criteriaMenu.size(); ++i) {
        std::cout << i + 1 << ". " << criteriaMenu[i] << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
}

void ConsoleProcessorUI::processObjectList(std::string& groupCriterion) {
    IGrouping* grouping = GroupingFactory(groupCriterion);

    if (grouping == nullptr) {
        cerr << "Error: Something went wrong." << endl;
        return;
    }

    this->groups = grouping->groupByCriterion(repository->getObjectList());

    delete grouping;
}

map<string, vector<int>>& ConsoleProcessorUI::getGroups() {
    return this->groups;
}

void ConsoleProcessorUI::setGroups(map<string, vector<int>>& groups) {
    this->groups = groups;
}

bool ConsoleProcessorUI::isResultListLoaded(string resultFileName) {
    
    std::ofstream out(resultFileName);

    if (out.is_open())
    {
        for (auto& group : groups) {

            out << group.first << ": " << endl;

            out << endl;

            for (int i = 0; i < group.second.size(); ++i) {
                out << repository->getObjectList()[group.second[i]].name << " "
                    << repository->getObjectList()[group.second[i]].x << " "
                    << repository->getObjectList()[group.second[i]].y << " "
                    << repository->getObjectList()[group.second[i]].type << " "
                    << repository->getObjectList()[group.second[i]].dateInSeconds << endl;
            }

            out << endl;
        }
    }
    else {
        cerr << "Error: something went wrong. Try again. " << endl;

        return false;
    }

    out.close();

    return true;
}