#pragma once
#include <string>

// source: http://staff.iiar.pwr.wroc.pl/antoni.sterna/sdizo/SDiZO_time.pdf

class Timer {
private:
	volatile long long int frequency, start, elapsed, memory;
public:
	Timer() : frequency(0), start(0), elapsed(0), memory(0) {};
	long long int read_QPC();

	void startTimer();
	void endTimer();
	void resetMemory();
	void divideMemory(int divisor) { memory /= divisor; }

	std::string timeSeconds();
	std::string timeMiliSeconds();
	std::string timeMicroSeconds();

	std::string timeSecondsMemory();
	std::string timeMiliSecondsMemory();
	std::string timeMicroSecondsMemory();
};