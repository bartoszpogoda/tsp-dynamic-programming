#pragma once

#include "Timer.h"
#include "Instance.h"
#include "FullSearchTSP.h"
#include "HeldKarpTSP.h"

class PerformanceTester {
	// hard coded instance sizes for performance testing
	unsigned tspNFullSearchManyIterations[5] = { 4, 6, 8, 10, 11 };
	unsigned tspNFullSearchFewIterations[3] = { 12, 13, 14 };
	unsigned tspNDynamicManyIterations[5] = { 4, 8, 12, 14, 18 };
	unsigned tspNDynamicFewIterations[3] = { 21, 23, 25 };

	int iterationsMany = 100;
	int iterationsFew = 10;

	Timer timer;
	TSP* tspAlgorithm;

public:
	PerformanceTester() : tspAlgorithm(nullptr) {};
	~PerformanceTester();

	void runTSPFullSearch();
	void runTSPDynamic();
};