#pragma once

class Instance {
protected:
	int** adjacencyMatrix;
	int numberOfCities;
	Instance(int numberOfCities);

public:
	int getDistance(int startVertex, int endVertex) { return adjacencyMatrix[startVertex][endVertex]; }
	int getNumberOfCities() { return numberOfCities; }

	class InstanceBuilder;
};

class Instance::InstanceBuilder{
private:
	Instance* instance;
public:
	InstanceBuilder(int numberOfCities) : instance(new Instance(numberOfCities)) {};

	void addDistance(int startVertex, int endVertex, int distance) {
		instance->adjacencyMatrix[startVertex][endVertex] = distance;
	};

	Instance* build() { Instance* toReturn = instance; instance = new Instance(toReturn->numberOfCities); return toReturn; }
};
