// ObjectListProcessor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Object.h"
#include <fstream>
#include "Utils.h"

std::vector<Object> readObjectListFile(std::string& objectListFilePath) {
    std::vector<Object> objectList;

    try {
        std::ifstream in(objectListFilePath);
        

        if (in.is_open())
        {
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
        }

        in.close();

        for (const Object& object: objectList)
        {
            std::cout << object.name << object.x << object.y << object.type << object.dateInSeconds << object.distance << std::endl;

        }

        std::cout << "Successfully read " << objectList.capacity() << " data rows from '" << objectListFilePath << "'." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "An unexpected standard error occurred: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unknown and unexpected error occurred." << std::endl;
    }

    return objectList;
}

int main()
{
    std::string objectListFilePath = "data.txt";

    std::vector<Object> objectList = readObjectListFile(objectListFilePath);
}