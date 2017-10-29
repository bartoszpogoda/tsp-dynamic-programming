#include "Algorithm.h"
#include "SubsetGenerator.h"
#include "Printer.h"
#include "Instance.h"

Result * Algorithm::solve(Instance* instance) {
	Algorithm::ValuesMemory* memory = new Algorithm::ValuesMemory();

	calculateBestPaths(instance, memory);
	calculateBestEnclosingPath(instance, memory);

	return prepareResult(instance, memory);
}

void Algorithm::calculateBestPaths(Instance * instance, ValuesMemory * memory) {
	std::vector<int> verticles = SubsetGenerator::generateVerticleVector(instance->getNumberOfCities());
	std::vector<std::set<int>>* verticleSubsets = SubsetGenerator::generateVerticleSubsets(verticles);

	for (auto subset : *verticleSubsets) {
		for (auto verticle : verticles) {
			if (subset.find(verticle) == subset.end()) {

				int minDistance = INT_MAX;
				int lastVerticleForMinDistance = 0;

				for (auto lastVerticle : subset) {
					// subset:{1,2,3}	verticle:4		lastVerticle:3		{1,2} -> 3
					std::set<int> setWithoutLastVerticle = std::set<int>(subset);
					setWithoutLastVerticle.erase(lastVerticle);

					int distance = memory->getDistance(setWithoutLastVerticle, lastVerticle) + instance->getDistance(lastVerticle, verticle); // add actual 3 -> 4 distance

					if (distance < minDistance) {
						minDistance = distance;
						lastVerticleForMinDistance = lastVerticle;
					}
				}

				if (subset.size() == 0) {
					// empty subset
					minDistance = instance->getDistance(0, verticle);
					// parent stays 0
				}

				// save step result
				memory->putDistance(subset, verticle, minDistance);
				memory->putParent(subset, verticle, lastVerticleForMinDistance);
			}
		}
	}
}

void Algorithm::calculateBestEnclosingPath(Instance * instance, ValuesMemory * memory) {
	std::set<int> fullSubset = SubsetGenerator::generateFullSubset(instance->getNumberOfCities());
	int minDistance = INT_MAX;
	int lastVerticleForMinDistance = 0;
	for (auto lastVerticle : fullSubset) {
		std::set<int> setWithoutLastVerticle = std::set<int>(fullSubset);
		setWithoutLastVerticle.erase(lastVerticle);

		int distance = memory->getDistance(setWithoutLastVerticle, lastVerticle) + instance->getDistance(lastVerticle, 0);

		if (distance < minDistance) {
			minDistance = distance;
			lastVerticleForMinDistance = lastVerticle;
		}
	}

	memory->putDistance(fullSubset, 0, minDistance);
	memory->putParent(fullSubset, 0, lastVerticleForMinDistance);
}

Result * Algorithm::prepareResult(Instance * instance, ValuesMemory * memory) {
	Result::ResultBuilder resultBuilder;

	std::set<int> fullSubset = SubsetGenerator::generateFullSubset(instance->getNumberOfCities());

	// put min distance in result
	resultBuilder.setMinDistance(memory->getDistance(fullSubset, 0));

	// put min path in result
	resultBuilder.addPreviousVerticle(0);

	int currentParent = memory->getParent(fullSubset, 0);
	while (!fullSubset.empty() && currentParent != 0) {
		resultBuilder.addPreviousVerticle(currentParent);
		fullSubset.erase(currentParent);

		currentParent = memory->getParent(fullSubset, currentParent);
	}

	resultBuilder.addPreviousVerticle(0);
	
	return resultBuilder.build();
}

Algorithm::ValuesMemory::ValuesMemory() {
	distances = std::map<SetVerticleIndex, int>();
	parents = std::map<SetVerticleIndex, int>();
}

void Algorithm::ValuesMemory::putDistance(std::set<int> set, int verticle, int distance) {
	distances[SetVerticleIndex(set,verticle)] = distance;
}

int Algorithm::ValuesMemory::getDistance(std::set<int> set, int verticle) {
	return distances[SetVerticleIndex(set, verticle)];
}

void Algorithm::ValuesMemory::putParent(std::set<int> set, int verticle, int parent) {
	parents[SetVerticleIndex(set, verticle)] = parent;
}

int Algorithm::ValuesMemory::getParent(std::set<int> set, int verticle) {
	return parents[SetVerticleIndex(set, verticle)];
}
