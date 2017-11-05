#pragma once
#include "TSP.h"
#include <math.h>

class FullSearchTSP : public TSP {
private:
	class RecursionStepResult;
	RecursionStepResult recStep(Instance* instance, int* unvisited, int unvisitedSize, int previousCity, int startCity);
	Result* prepareResult(RecursionStepResult& result, int numberOfCities, int startCity);
public:
	Result* solve(Instance* instance);
};

class FullSearchTSP::RecursionStepResult {
public:
	int* path;
	int pathSize;
	int distance;

	RecursionStepResult(int* path, int pathSize, int distance) : path(path), pathSize(pathSize), distance(distance) {};
	~RecursionStepResult() { delete[] path; }
};