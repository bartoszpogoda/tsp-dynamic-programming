#include "PerformanceTester.h"
#include <iostream>

PerformanceTester::~PerformanceTester() {
	delete tspAlgorithm;
}

void PerformanceTester::runTSPFullSearch() {
	delete tspAlgorithm;
	tspAlgorithm = new FullSearchTSP();

	std::cout << "TSP FullSearch" << std::endl;
	for each (unsigned n in tspNFullSearchManyIterations) {
		timer.resetMemory();

		for (size_t i = 0; i < iterationsMany; i++) {
			Instance* randomInstance = Instance::generateRandom(n);

			timer.startTimer();
			Result* result = tspAlgorithm->solve(randomInstance);
			timer.endTimer();

			delete result;
			delete randomInstance;
		}
		timer.divideMemory(iterationsMany);

		std::cout << timer.timeMiliSecondsMemory() << ";";
	}

	for each (unsigned n in tspNFullSearchFewIterations) {
		timer.resetMemory();

		for (size_t i = 0; i < iterationsFew; i++) {
			Instance* randomInstance = Instance::generateRandom(n);

			timer.startTimer();
			Result* result = tspAlgorithm->solve(randomInstance);
			timer.endTimer();

			delete result;
			delete randomInstance;
		}
		timer.divideMemory(iterationsFew);

		std::cout << timer.timeMiliSecondsMemory() << ";";
	}

	std::cout << std::endl;
}


void PerformanceTester::runTSPDynamic() {
	delete tspAlgorithm;
	tspAlgorithm = new HeldKarpTSP();

	std::cout << "TSP HeldKarp" << std::endl;
	for each (unsigned n in tspNDynamicManyIterations) {
		timer.resetMemory();

		for (size_t i = 0; i < iterationsMany; i++) {
			Instance* randomInstance = Instance::generateRandom(n);

			timer.startTimer();
			Result* result = tspAlgorithm->solve(randomInstance);
			timer.endTimer();

			delete result;
			delete randomInstance;
		}
		timer.divideMemory(iterationsMany);

		std::cout << timer.timeMiliSecondsMemory() << ";";
	}

	for each (unsigned n in tspNDynamicFewIterations) {
		timer.resetMemory();

		for (size_t i = 0; i < iterationsFew; i++) {
			Instance* randomInstance = Instance::generateRandom(n);

			timer.startTimer();
			Result* result = tspAlgorithm->solve(randomInstance);
			timer.endTimer();

			delete result;
			delete randomInstance;
		}
		timer.divideMemory(iterationsFew);

		std::cout << timer.timeMiliSecondsMemory() << ";";
	}

	std::cout << std::endl;
}
