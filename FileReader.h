#pragma once
#include "Instance.h"
#include <string>

class FileReader {
	Instance::InstanceBuilder* instanceBuilder;
	bool errorFlag;
	std::string errorMessage;

	void read(std::string filename);

public:
	FileReader(std::string filename);
	~FileReader() { delete instanceBuilder; }

	Instance* getInstance();

	// read status
	bool success() { return !errorFlag; }
	std::string getErrorMessage() { return errorMessage; }
};