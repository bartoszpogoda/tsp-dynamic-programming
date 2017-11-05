#include "CLInterface.h"
#include <iostream>
#include <conio.h>

#include "FileReader.h"
#include "FullSearchTSP.h"
#include "HeldKarpTSP.h"
#include "Printer.h"

FileReader* CLInterface::tspFileReader = nullptr;
PerformanceTester* CLInterface::performanceTester = nullptr;
using namespace std;

void CLInterface::enter() {
	viewMainMenu();

	delete tspFileReader;
	delete performanceTester;
}

int CLInterface::handleUserInput() {
	int c = 0;

	while ((c = getch())) {
		if (c == KEY_UP) {
			return -1;
		} else if (c == KEY_DOWN) {
			return 1;
		} else if (c == ENTER) {
			return 0;
		}
		c = 0;
	}
}

bool CLInterface::viewInputFilenameTS() {
	system("CLS");
	cout << " ++ TS algorithms demo ++ " << endl << endl;

	cout << " > Enter filename: ";

	string readFilename;
	cin >> readFilename;

	delete tspFileReader;
	tspFileReader = new FileReader(readFilename);

	if (tspFileReader->success()) {
		cout << " > Read success";
		handleUserInput();
		return true;
	} else {
		cout << " > " << tspFileReader->getErrorMessage();
		delete tspFileReader;
		tspFileReader = nullptr;
		handleUserInput();
		return false;
	}
}

void CLInterface::viewMainMenu() {
	int selected = 0, max = 4, selectedDelta = 0;

	system("CLS");
	while (selected != max) {
		do {
			if (selected + selectedDelta < 0)
				selected = max;
			else if (selected + selectedDelta > max)
				selected = 0;
			else
				selected += selectedDelta;

			system("CLS");
			cout << " ++ TS algorithms demo ++ " << endl << endl;
			cout << ((selected == 0) ? " > " : "   ") << "Dynamic Programming Held Karp - File input" << endl;
			cout << ((selected == 1) ? " > " : "   ") << "Dynamic Programming Held Karp- Random" << endl;
			cout << ((selected == 2) ? " > " : "   ") << "Full Search - File input" << endl;
			cout << ((selected == 3) ? " > " : "   ") << "Run performance tests" << endl;
			cout << ((selected == 4) ? " > " : "   ") << "Exit" << endl;
		} while ((selectedDelta = handleUserInput()) != 0);

		if (selected == 0) {
			while (!viewInputFilenameTS());
			viewExecuteHeldKarpTSP();
		} else if (selected == 1) {
			viewExecuteTSRandom();
		} else if (selected == 2) {
			while (!viewInputFilenameTS());
			viewExecuteFullSearchTSP();
		} else if (selected == 3) {
			viewPerformanceTests();
		}
	}
}

void CLInterface::viewExecuteHeldKarpTSP() {
	system("CLS");

	Instance* instance = tspFileReader->getInstance();

	std::cout << "-- TS Problem: " << std::endl;
	std::cout << "Number of cities: " << instance->getNumberOfCities() << std::endl << std::endl;
	
	Printer::print(instance);

	HeldKarpTSP tsp;

	Result* result = tsp.solve(instance);

	if (result == nullptr) {
		std::cout << "Max number of cities is 33";
	} else {
		Printer::print(result);
	}


	delete instance;
	delete result;

	handleUserInput();
}

void CLInterface::viewExecuteFullSearchTSP() {
	system("CLS");

	Instance* instance = tspFileReader->getInstance();

	std::cout << "-- TS Problem: " << std::endl;
	std::cout << "Number of cities: " << instance->getNumberOfCities() << std::endl << std::endl;

	Printer::print(instance);

	FullSearchTSP tsp;

	Result* result = tsp.solve(instance);

	Printer::print(result);

	delete instance;
	delete result;

	handleUserInput();
}

void CLInterface::viewExecuteTSRandom() {
	system("CLS");

	cout << " > Enter number of cities: ";

	int numberOfCities;
	cin >> numberOfCities;

	Instance* instance = Instance::generateRandom(numberOfCities);

	std::cout << "-- TS Problem: " << std::endl;
	std::cout << "Number of cities: " << instance->getNumberOfCities() << std::endl << std::endl;

	Printer::print(instance);

	HeldKarpTSP tsp;

	Result* result = tsp.solve(instance);

	if (result == nullptr) {
		std::cout << "Max number of cities is 33";
	} else {
		Printer::print(result);
	}

	delete instance;
	delete result;

	handleUserInput();
}

void CLInterface::viewPerformanceTests() {
	system("CLS");

	delete performanceTester;
	performanceTester = new PerformanceTester();

	performanceTester->runTSPFullSearch();
	performanceTester->runTSPDynamic();

	handleUserInput();
}
