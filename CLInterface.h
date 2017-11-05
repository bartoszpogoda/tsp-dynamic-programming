#pragma once

#include "FileReader.h"
#include "PerformanceTester.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

class CLInterface {
private:
	static FileReader* tspFileReader;
	static PerformanceTester* performanceTester;

	CLInterface() {};
public:
	static void enter();
	static int handleUserInput();

	static bool viewInputFilenameTS();
	static void viewMainMenu();

	static void viewExecuteHeldKarpTSP();
	static void viewExecuteFullSearchTSP();
	static void viewExecuteTSRandom();
	static void viewPerformanceTests();
};