#pragma once
#include <list>
class Result {
private:
	int minDistance;
	std::list<int> minPath;
	Result();

public:
	int getMinDistance() { return minDistance; }
	std::list<int> getMinPath() { return std::list<int>(minPath); }

	class ResultBuilder;
};

class Result::ResultBuilder {
private:
	Result* result;
public:
	ResultBuilder() : result(new Result()) {};

	void setMinDistance(int minDistance) { result->minDistance = minDistance; }
	void addPreviousVerticle(int previousVerticle) { result->minPath.push_front(previousVerticle); }
	
	Result* build() { Result* toReturn = result; result = new Result(); return toReturn; }
};
