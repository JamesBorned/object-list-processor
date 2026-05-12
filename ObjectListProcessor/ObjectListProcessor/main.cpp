// ObjectListProcessor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Object.h"
#include <fstream>
#include "Utils.h"

#define APP_NAME "Object List Processor"
#define APP_VERSION "1.0"

using namespace std;

std::vector<Object> readObjectListFile(std::string& objectListFilePath) {
    std::vector<Object> objectList;

    std::ifstream in(objectListFilePath);  

    if (!in.is_open()) {
        std::cerr << "Error: The file could not be opened. " << objectListFilePath << std::endl;

        return objectList;
    }
  
    std::string name;

    double x;
    double y;

    std::string type;

    double dateInSeconds = 0;

    double distance = 0;

    while (in >> name >> x >> y >> type >> dateInSeconds)
    {
        distance = calculateDistance(x, y);

        Object object = { name, x, y, type, dateInSeconds, distance };

        objectList.push_back(object);
    }

    if (in.fail() && !in.eof()) {
        std::cerr << "Error: Invalid data format. Only " << objectList.size() << " objects are loaded." << std::endl;
        
        objectList.clear();
        return objectList;
    }

    in.close();

    return objectList;
}

int main()
{
    //std::string objectListFilePath = "data.txt";

    //std::vector<Object> objectList = readObjectListFile(objectListFilePath);
    std::cout << APP_NAME << ", version " << APP_VERSION << std::endl;

    std::cout << std::endl;

    std::cout << "MENU:" << endl;

    cout << endl;

    vector<string> menuCommands;

    menuCommands.push_back("Upload a file.");
    menuCommands.push_back("Process the list of objects.");
    menuCommands.push_back("Save the results to a file.");

    for (int i = 0; i < menuCommands.size(); ++i) {
        cout << i + 1 << ". " << menuCommands[i] << endl;
        cout << "---------------------------" << endl;
    }

    cout << "Select an action. Enter the command number (from 1 to " << menuCommands.size() << "): ";

    int commandNumber = 0;
    bool isWrongCommandNumber = true;

    while (isWrongCommandNumber) {
        cin >> commandNumber;

        if (commandNumber > 0 && commandNumber <= menuCommands.size()) {
            isWrongCommandNumber = false;
        }
        else if (commandNumber == '/n') {
            cerr << "Error: Wrong number dialed, try again: ";
        }
        else {
            cerr << "Error: Wrong number dialed, try again: ";
        }
    }

    if (commandNumber == 1) {
        cout << endl;
        cout << "Enter the file name (f.e. data.txt): ";

        bool isWrongFileName = true;

        string fileName;
        cin >> fileName;

        std::vector<Object> objectList;

        while (isWrongFileName) {
            objectList = readObjectListFile(fileName);

            if (!objectList.empty()) {
                isWrongFileName = false;
            }
            else {
                cout << "Error: Something went wrong. Enter the file name again: ";
            }
        }
    }
    /*else if (commandNumber == 2) {
        cout << 
    }*/
}