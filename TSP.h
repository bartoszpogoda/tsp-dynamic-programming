#pragma once
#include "Instance.h"
#include "Result.h"

class TSP {
public:
	virtual Result* solve(Instance* instance) = 0;
};