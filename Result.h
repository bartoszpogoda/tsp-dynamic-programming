#pragma once
class Result {
private:
	int minDistance;
	int* path;
	int pathSize;
	Result(unsigned pathSize) : pathSize(pathSize), path(new int[pathSize]) {}

public:
	int getMinDistance() { return minDistance; }
	int getPathSize() { return pathSize; }
	int getPathElem(int elem) { return path[elem]; }

	class ResultBuilder;
};

class Result::ResultBuilder {
private:
	Result* result;
	int currentPathSize;
public:
	ResultBuilder(unsigned pathSize) : result(new Result(pathSize)), currentPathSize(pathSize-1) {};

	void setMinDistance(int minDistance) { result->minDistance = minDistance; }
	void addCityFromEnd(int anotherCityFromEnd) { result->path[currentPathSize--] = anotherCityFromEnd; }
	
	Result* build() { Result* toReturn = result; result = new Result(toReturn->pathSize); return toReturn; }
};
