#pragma once

#include <vector>
#include <set>

class SubsetGenerator {
public:
	SubsetGenerator() {};

	// Generates helper structure of verticle subsets (excluding 0) based on given number of cities
	std::vector<std::set<int>*>* generateVerticleSubsets(int numberOfCities);

private:
	// Generates verticles set {1 , 2 , ... , n}
	std::vector<int> generateVerticleSet(int n);

	// Sorts subsets ascending based on their size
	void sortSubsets(std::vector<std::set<int>*>* subsets);
};

