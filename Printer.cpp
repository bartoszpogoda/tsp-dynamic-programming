#include "Printer.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>

void Printer::print(Instance* instance) {
	std::stringstream out;

	int argWidth = 4;
	int n = instance->getNumberOfCities();

	// indexes row
	out << std::setw(argWidth) << std::setfill(' ') << "" << "|";
	for (size_t i = 0; i < n; i++)
		out << std::setw(argWidth) << i << "|";
	out << std::endl;

	// +---+.... row
	for (int i = -1; i < n; i++)
		out << std::setw(argWidth) << std::setfill('-') << "" << "+";
	out << std::endl;

	// main data loop
	for (size_t i = 0; i < n; i++) {
		out << std::setw(argWidth) << std::setfill(' ') << i << "|";

		for (size_t j = 0; j < n; j++)
			out << std::setw(argWidth) << (instance->getDistance(i, j) < INT_MAX ?  std::to_string(instance->getDistance(i, j)) : "oo") << " ";

		out << std::endl;
	}

	out << std::endl;
	std::cout << out.str();
}

void Printer::print(Result * result) {
	std::stringstream out;

	int argWidth = 2;

	out << std::left << std::setw(7) << "Length" << "= " << result->getMinDistance() << std::endl;
	out << std::left << std::setw(7) << "Path" << "= ";
	out << std::setfill(' ');
	for (size_t i = 0; i < result->getPathSize(); i++) {
		out << std::setw(argWidth) << result->getPathElem(i) << (i != result->getPathSize() - 1 ? " - " : " ");
	}

	out << std::endl;
	std::cout << out.str();
}
