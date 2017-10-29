#pragma once
#include "Result.h"
#include "Instance.h"
#include <set>
#include <map>

class Algorithm {
public:
	static Result* solve(Instance* instance);
private:
	class ValuesMemory;
	// Calculates best paths form start verticle to each of remaining verticles (going through all the verticles)
	static void calculateBestPaths(Instance* instance, ValuesMemory* memory);

	// Calculates best enclosing path going through all the verticles (hamilton cycle)
	// Returns distance for min path
	static void calculateBestEnclosingPath(Instance* instance, ValuesMemory* memory);

	static Result* prepareResult(Instance * instance, ValuesMemory * memory);
	
};

class Algorithm::ValuesMemory{
private:
	class SetVerticleIndex;
	std::map<SetVerticleIndex, int> distances;
	std::map<SetVerticleIndex, int> parents;
public:
	ValuesMemory();

	void putDistance(std::set<int> set, int verticle, int distance);
	int getDistance(std::set<int> set, int verticle);

	void putParent(std::set<int> set, int verticle, int parent);
	int getParent(std::set<int> set, int verticle);
};

class Algorithm::ValuesMemory::SetVerticleIndex {
	int verticle;
	std::set<int> set;
public:
	SetVerticleIndex(std::set<int> set, int verticle) : set(set), verticle(verticle)  {}

	bool operator <(const SetVerticleIndex& rhs) const { return verticle == rhs.verticle ? set < rhs.set : verticle < rhs.verticle; }
};
