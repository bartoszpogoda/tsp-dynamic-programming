#pragma once
#include "TSP.h"

class HeldKarpTSP : public TSP {
private:
	int** distances;
	int** parents;

	int solveSubproblem(Instance* instance, int numberOfMidpathCities, int subset, int destCity);

	Result* prepareResult(int startCity, int numberOfMidpathCities, int finalCity, int minDistance);

	void initResultStructures(int numberOfSubsets, int numberOfMidpathCities);
	void dealocateResultStructures(int numberOfSubsets);
public:
	Result* solve(Instance* instance);
};