#pragma once
#include <vector>
#include <set>

class SubsetGenerator {
public:
	// Generates helper structure of verticle subsets (excluding 0) based on given number of cities (excluding full subset)
	static std::vector<std::set<int>>* generateVerticleSubsets(std::vector<int> verticleSet);

	// Generates verticles vector [1 , 2 , ... , n]
	static std::vector<int> generateVerticleVector(int n);

	// Generates verticle fullset
	static std::set<int> generateFullSubset(int n);
private:
	SubsetGenerator() {};

	// Sorts subsets ascending based on their size
	static void sortSubsets(std::vector<std::set<int>>* subsets);
};

