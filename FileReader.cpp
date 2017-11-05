#include "FileReader.h"
#include <fstream>

void FileReader::read(std::string filename) {
	std::ifstream file = std::ifstream(filename);
	errorFlag = false;
	unsigned numberOfCities = 0;

	if (instanceBuilder != nullptr) {
		return;
	}

	if (file.is_open()) {

		file >> numberOfCities;
		if (file.fail()) {
			file.close();
			errorFlag = true;
			errorMessage = "File read error : number of cities";
			return;
		}


		instanceBuilder = new Instance::InstanceBuilder(numberOfCities);

		unsigned distance;
		for (int i = 0; i < numberOfCities; i++) {
			for (int j = 0; j < numberOfCities; j++) {
				file >> distance;
				if (file.fail()) {
					file.close();
					errorFlag = true;
					errorMessage = "File read error : cities data";

					delete instanceBuilder;
					return;
				} else
					instanceBuilder->addDistance(i, j, distance);
			}
		}

		file.close();
	} else {
		errorFlag = true;
		errorMessage = "File read error : file open";
	}
}

FileReader::FileReader(std::string filename) : instanceBuilder(nullptr), errorFlag(false) {
	read(filename);
}

Instance * FileReader::getInstance() {
	Instance* instance = instanceBuilder->build();
	delete instanceBuilder;
	instanceBuilder = nullptr;
	return instance;
}