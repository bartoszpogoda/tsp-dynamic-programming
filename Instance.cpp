#include "Instance.h"

Instance::Instance(int numberOfCities) : numberOfCities(numberOfCities), adjacencyMatrix(new int*[numberOfCities]) {
	for (int i = 0; i < numberOfCities; i++) {
		adjacencyMatrix[i] = new int[numberOfCities];
	}
}
