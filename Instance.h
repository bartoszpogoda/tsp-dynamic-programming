#pragma once

class Instance {
private:
	int** adjacencyMatrix;
	int numberOfCities;
	Instance(int numberOfCities);

public:
	int getDistance(int startVertex, int endVertex) { return adjacencyMatrix[startVertex][endVertex]; }
	int getNumberOfCities() { return numberOfCities; }

	static Instance* generateRandom(int numberOfCities);

	class InstanceBuilder;
};

class Instance::InstanceBuilder{
private:
	Instance* instance;
public:
	InstanceBuilder(int numberOfCities) : instance(new Instance(numberOfCities)) {};

	InstanceBuilder* addDistance(int startVertex, int endVertex, int distance) {
		instance->adjacencyMatrix[startVertex][endVertex] = distance;
		return this;
	};

	Instance* build() { Instance* toReturn = instance; instance = new Instance(toReturn->numberOfCities); return toReturn; }
};
