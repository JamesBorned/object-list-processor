// ObjectListProcessor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Object.h"
#include <fstream>
#include "Utils.h"

std::vector<Object> readObjectListFile(std::string& objectListFilePath) {
    std::vector<Object> objectList;

    std::ifstream in(objectListFilePath);  

    if (!in.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл. " << objectListFilePath << std::endl;

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
        std::cerr << "Ошибка: Неверный формат данных. Загружено только " << objectList.size() << " объектов." << std::endl;
        
        objectList.clear();
        return objectList;
    }

    in.close();

    return objectList;
}

int main()
{
    std::string objectListFilePath = "data.txt";

    std::vector<Object> objectList = readObjectListFile(objectListFilePath);
}