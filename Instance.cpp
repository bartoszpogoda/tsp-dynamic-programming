#include "Instance.h"
#include <random>
#include <time.h>

Instance::Instance(int numberOfCities) : numberOfCities(numberOfCities), adjacencyMatrix(new int*[numberOfCities]) {
	for (int i = 0; i < numberOfCities; i++) {
		adjacencyMatrix[i] = new int[numberOfCities];
	}
}

Instance::~Instance() {
	for (int i = 0; i < numberOfCities; i++) {
		delete[] adjacencyMatrix[i];
	}

	delete[] adjacencyMatrix;
}

Instance * Instance::generateRandom(int numberOfCities) {
	InstanceBuilder* builder = new InstanceBuilder(numberOfCities);
	
	unsigned distanceRange = 10000;

	srand(time(NULL));

	for (size_t i = 0; i < numberOfCities; i++) {
		for (size_t j = 0; j < numberOfCities; j++) {
			if (i != j) 
				builder->addDistance(i, j, 1 + rand() % distanceRange);
			else {
				builder->addDistance(i, j, INT_MAX);
			};
		}
	}

	Instance* builtInstance = builder->build();
	delete builder;

	return builtInstance;
}
