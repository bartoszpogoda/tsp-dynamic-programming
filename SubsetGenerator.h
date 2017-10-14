#pragma once
#include <vector>
#include <set>

class SubsetGenerator {
public:
	// Generates helper structure of verticle subsets (excluding 0) based on given number of cities
	static std::vector<std::set<int>*>* generateVerticleSubsets(int numberOfCities);

private:
	SubsetGenerator() {};
	// Generates verticles set {1 , 2 , ... , n}
	static std::vector<int> generateVerticleSet(int n);

	// Sorts subsets ascending based on their size
	static void sortSubsets(std::vector<std::set<int>*>* subsets);
};

