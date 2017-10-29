#include "SubsetGenerator.h"
#include <algorithm>

std::vector<std::set<int>>* SubsetGenerator::generateVerticleSubsets(std::vector<int> verticleSet) {
	std::vector<std::set<int>>* verticleSubsets = new std::vector<std::set<int>>();

	int numberOfSubsets = 1 << verticleSet.size();

	// iterate over binary subset masks 0 - doesnt contain, 1 - does contain
	for (unsigned i = 0; i < numberOfSubsets - 1; i++) {
		std::set<int>* newSubset = new std::set<int>();

		for (unsigned p = 0; p < verticleSet.size(); p++) {
			// for each vertex compare its binary position with current subset mask
			if (i & (1 << p)) {
				newSubset->insert(verticleSet[p]);
			}
		}

		verticleSubsets->push_back(*newSubset);
	}

	sortSubsets(verticleSubsets);

	return verticleSubsets;
}

std::vector<int> SubsetGenerator::generateVerticleVector(int n) {
	std::vector<int> result;

	for (unsigned i = 1; i < n; i++) { 
		result.push_back(i);
	}

	return result;
}

std::set<int> SubsetGenerator::generateFullSubset(int n) {
	std::set<int> result;

	for (unsigned i = 1; i < n; i++) {
		result.insert(i);
	}

	return result;
}

void SubsetGenerator::sortSubsets(std::vector<std::set<int>>* subsets) {
	struct {
		bool operator()(std::set<int> setA, std::set<int> setB) const {
			return setA.size() < setB.size();
		}
	} setSizeComparison;

	std::sort(subsets->begin(), subsets->end(), setSizeComparison);
}
