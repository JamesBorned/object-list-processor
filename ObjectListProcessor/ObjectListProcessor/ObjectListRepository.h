#pragma once

#include <string>
#include <vector>
#include "Object.h"
#include <map>

using namespace std;

class ObjectListRepository {
	public:
		string& getFileName();
		void setFileName(string& fileName);

		vector<Object>& getObjectList();
		void setObjectList(vector<Object>& objectList);

		bool loadObjectList();

	private:
		string fileName;
		vector<Object> objectList;

		vector<Object> readObjectListFile(string& objectListFilePath);
};