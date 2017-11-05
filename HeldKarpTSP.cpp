#include "HeldKarpTSP.h"
#include "SubsetUtil.h"
#include <climits>

Result * HeldKarpTSP::solve(Instance * instance) {
	// 32-bit subset representation can't handle instances of size 33 and more
	if (instance->getNumberOfCities() > 32) {
		return nullptr;
	}

	int startCity = instance->getNumberOfCities() - 1;

	// number of cities excluding the start one
	int numberOfMidpathCities = instance->getNumberOfCities() - 1;

	// total number of midpath city subsets
	int numberOfSubsets = SubsetUtil::getNumberOfSubsets(numberOfMidpathCities);

	initResultStructures(numberOfSubsets, numberOfMidpathCities);

	// fill direct paths from the start city to every other city (empty subset of visited cities), these values will stop the recursion
	for (int i = 0; i < numberOfMidpathCities; i++) {
		distances[0][i] = instance->getDistance(startCity, i);
		parents[0][i] = startCity;
	}

	int minDistance = INT_MAX;
	int minFinalCity = -1;
	int allMidpathCities = SubsetUtil::getFullSubset(numberOfMidpathCities);

	// final city is the city which will be visited before comming back to start city
	for (int finalCity = 0; finalCity < numberOfMidpathCities; finalCity++) {
		int distance = solveSubproblem(instance, numberOfMidpathCities, SubsetUtil::subsetWithoutCity(allMidpathCities, finalCity), finalCity) + instance->getDistance(finalCity, startCity);

		if (distance < minDistance) {
			minDistance = distance;
			minFinalCity = finalCity;
		}
	}

	// use collected data to prepare the result
	Result* result = prepareResult(startCity, numberOfMidpathCities, minFinalCity, minDistance);

	dealocateResultStructures(numberOfSubsets);
	return result;
}

void HeldKarpTSP::initResultStructures(int numberOfSubsets, int numberOfMidpathCities) {
	distances = new int*[numberOfSubsets];
	parents = new int*[numberOfSubsets];

	for (int i = 0; i < numberOfSubsets; i++) {
		distances[i] = new int[numberOfMidpathCities];
		parents[i] = new int[numberOfMidpathCities];

		for (int j = 0; j < numberOfMidpathCities; j++) {
			distances[i][j] = -1;
		}
	}
}

int HeldKarpTSP::solveSubproblem(Instance * instance, int numberOfMidpathCities, int subset, int destCity) {
	if (distances[subset][destCity] != -1) {
		// If the sub problem was solved before do not solve it again - just return the result
		return distances[subset][destCity];
	} else {
		// Otherwise find the city that visited before destCity will give the best path
		int minDistance = INT_MAX;
		int minParent = -1;

		for (int preDestCity = 0; preDestCity < numberOfMidpathCities; preDestCity++) {
			if (SubsetUtil::isCityInSubset(subset, preDestCity)) {
				int subsetWithoutPreDestCity = SubsetUtil::subsetWithoutCity(subset, preDestCity);
				int distance = solveSubproblem(instance, numberOfMidpathCities, subsetWithoutPreDestCity, preDestCity) + instance->getDistance(preDestCity, destCity);

				if (distance < minDistance) {
					minDistance = distance;
					minParent = preDestCity;
				}
			} 
		}

		// Save results
		distances[subset][destCity] = minDistance;
		parents[subset][destCity] = minParent;

		return minDistance;
	}
}

Result * HeldKarpTSP::prepareResult(int startCity, int numberOfMidpathCities, int finalCity, int minDistance) {
	Result::ResultBuilder resultBuilder = Result::ResultBuilder(numberOfMidpathCities + 2);

	resultBuilder.setMinDistance(minDistance);

	resultBuilder.addCityFromEnd(startCity);
	
	int currentSubset = SubsetUtil::getFullSubset(numberOfMidpathCities);
	int currentCity = finalCity;
	while (currentCity != startCity) {
		resultBuilder.addCityFromEnd(currentCity);
		currentSubset = SubsetUtil::subsetWithoutCity(currentSubset, currentCity);

		currentCity = parents[currentSubset][currentCity];
	}

	resultBuilder.addCityFromEnd(startCity);

	return resultBuilder.build();
}

void HeldKarpTSP::dealocateResultStructures(int numberOfSubsets) {
	for (int i = 0; i < numberOfSubsets; i++) {
		delete[] distances[i];
		delete[] parents[i];
	}

	delete[] distances;
	delete[] parents;
}