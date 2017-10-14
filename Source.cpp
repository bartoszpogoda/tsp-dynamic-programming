#include "SubsetGenerator.h"
#include "Printer.h"
#include "Instance.h"
#include <iostream>

int main() {
	std::vector<std::set<int>*>* verticleSubsets = SubsetGenerator::generateVerticleSubsets(4);

	Printer::print(verticleSubsets);

	Instance::InstanceBuilder builder = Instance::InstanceBuilder(3);
	builder.addDistance(0, 1, 2);
	builder.addDistance(1, 0, 3);
	Instance* instance = builder.build();

	Printer::print(instance);
}
