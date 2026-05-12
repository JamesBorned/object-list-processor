// ObjectListProcessor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Object.h"
#include <fstream>
#include "Utils.h"
#include <string>
#include "ConsoleProcessorUI.h"

#define APP_NAME "Object List Processor"
#define APP_VERSION "1.0"

using namespace std;

int main()
{
    ObjectListRepository repository;
    ConsoleProcessorUI ConsoleUI(repository);

    ConsoleUI.run();

    return 0;
}