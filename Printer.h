#pragma once
#include "Instance.h"
#include <vector>
#include <set>

class Printer {
public:
	static void print(Instance* instance);
	static void print(std::vector<std::set<int>>* subsets);
};

