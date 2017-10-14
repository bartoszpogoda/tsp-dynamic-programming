#include "SubsetGenerator.h"
#include <iostream>

void printSubsets(std::vector<std::set<int>*>* subsets);

int main() {
	SubsetGenerator generator = SubsetGenerator();

	std::vector<std::set<int>*>* verticleSubsets = generator.generateVerticleSubsets(4);

	printSubsets(verticleSubsets);

	int x;
	std::cin >> x;
}

void printSubsets(std::vector<std::set<int>*>* subsets) {
	std::vector<std::set<int>*>::iterator subsetIterator;
	std::set<int>::iterator elementIterator;

	for (subsetIterator = subsets->begin(); subsetIterator != subsets->end(); subsetIterator++) {
		std::cout << "{";
		for (elementIterator = (*subsetIterator)->begin(); elementIterator != (*subsetIterator)->end(); elementIterator++) {
			std::cout << (elementIterator != (*subsetIterator)->begin() ? ", " : "") <<  *elementIterator;
		}
		std::cout << "}" << std::endl;
	}
}