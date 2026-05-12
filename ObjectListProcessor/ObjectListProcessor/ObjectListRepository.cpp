#include "ObjectListRepository.h"
#include "Utils.h"
#include <iostream>
#include <fstream>

vector<Object> ObjectListRepository::readObjectListFile(string& objectListFilePath) {
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

string& ObjectListRepository::getFileName() {
	return this->fileName;
}

void ObjectListRepository::setFileName(string& fileName) {
	this->fileName = fileName;
}

vector<Object>& ObjectListRepository::getObjectList() {
    return this->objectList;
}

void ObjectListRepository::setObjectList(vector<Object>& objectList) {
    this->objectList.assign(objectList.begin(), objectList.end());
}

bool ObjectListRepository::loadObjectList() {
    this->objectList = readObjectListFile(this->fileName);

    return !objectList.empty();
}
