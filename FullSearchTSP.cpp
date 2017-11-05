#include "FullSearchTSP.h"
#include <climits>

Result* FullSearchTSP::solve(Instance* instance) {
	int startCity = instance->getNumberOfCities() - 1;

	// all cities (except for start (last one)) are unvisited at the beginning
	int unvisitedSize = instance->getNumberOfCities() - 1;
	int *unvisited = new int[unvisitedSize];
	for (size_t i = 0; i < unvisitedSize; i++) {
		unvisited[i] = i;
	}

	// call recursion and prepare result
	Result* result = prepareResult(recStep(instance, unvisited, unvisitedSize, startCity, startCity), instance->getNumberOfCities(), startCity);

	delete[] unvisited;

	return result;
}

FullSearchTSP::RecursionStepResult FullSearchTSP::recStep(Instance* instance, int* unvisited, int unvisitedSize, int previousCity, int startCity) {
	if (unvisitedSize == 0) {
		return RecursionStepResult(nullptr, 0, instance->getDistance(previousCity, startCity));
	}

	int bestDistance = INT_MAX;
	int *bestPath = nullptr;
	int bestPathSize;

	for (size_t i = 0; i < unvisitedSize; i++) {
		int city = unvisited[i];
		unvisited[i] = unvisited[unvisitedSize - 1];

		// recursion with unvisitedSize - 1
		RecursionStepResult result = recStep(instance, unvisited, unvisitedSize - 1, city, startCity);

		if (result.distance + instance->getDistance(previousCity, city) < bestDistance) {
			bestDistance = result.distance + instance->getDistance(previousCity, city);

			bestPathSize = result.pathSize + 1;
			delete[] bestPath;
			bestPath = new int[bestPathSize];
			for (size_t j = 0; j < bestPathSize - 1; j++) {
				bestPath[j] = result.path[j];
			}
			bestPath[bestPathSize - 1] = city;
		}

		// restore state of unvisited before next iteration
		unvisited[i] = city;
	}

	return RecursionStepResult(bestPath, bestPathSize, bestDistance);
}

Result * FullSearchTSP::prepareResult(RecursionStepResult& result, int numberOfCities, int startCity) {
	Result::ResultBuilder resultBuilder = Result::ResultBuilder(numberOfCities + 1);

	resultBuilder.setMinDistance(result.distance);

	resultBuilder.addCityFromEnd(startCity);
	for (int i = 0 ; i < result.pathSize ; i++) {
		resultBuilder.addCityFromEnd(result.path[i]);
	}
	resultBuilder.addCityFromEnd(startCity);

	return resultBuilder.build();
}