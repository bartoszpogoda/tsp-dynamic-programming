#include "Algorithm.h"
#include "Printer.h"

#include <iostream>
int main() {
	/*Instance::InstanceBuilder builder = Instance::InstanceBuilder(4);
	builder.addDistance(0, 1, 1);
	builder.addDistance(0, 2, 15);
	builder.addDistance(0, 3, 6);
	builder.addDistance(1, 0, 2);
	builder.addDistance(1, 2, 7);
	builder.addDistance(1, 3, 3);
	builder.addDistance(2, 0, 9);
	builder.addDistance(2, 1, 6);
	builder.addDistance(2, 3, 12);
	builder.addDistance(3, 0, 10);
	builder.addDistance(3, 1, 4);
	builder.addDistance(3, 2, 8);
	Instance* instance = builder.build();*/

	Instance* instance = Instance::generateRandom(15);
	Printer::print(instance);

	Result* result = Algorithm::solve(instance);

	std::cout << "dist: " << result->getMinDistance() << "\n";
	std::list<int> minPath = result->getMinPath();
	for (auto vert : minPath) {
		std::cout << vert << "->";
	}

}
