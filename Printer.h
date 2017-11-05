#pragma once
#include "Instance.h"
#include "Result.h"

class Printer {
public:
	static void print(Instance* instance);
	static void print(Result* result);
};

