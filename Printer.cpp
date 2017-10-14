#include "Printer.h"
#include <iostream>
#include <sstream>
#include <iomanip>

void Printer::print(Instance * instance) {
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
			out << std::setw(argWidth) << std::to_string(instance->getDistance(i, j)) << " ";

		out << std::endl;
	}

	out << std::endl;
	std::cout << out.str();
}

void Printer::print(std::vector<std::set<int>>* subsets) {
	std::vector<std::set<int>>::iterator subsetIterator;
	std::set<int>::iterator elementIterator;

	for (subsetIterator = subsets->begin(); subsetIterator != subsets->end(); subsetIterator++) {
		std::cout << "{";
		for (elementIterator = subsetIterator->begin(); elementIterator != subsetIterator->end(); elementIterator++) {
			std::cout << (elementIterator != subsetIterator->begin() ? ", " : "") << *elementIterator;
		}
		std::cout << "}" << std::endl;
	}
}
