#pragma once

class SubsetUtil {
public:
	static int getNumberOfSubsets(int numberOfMidpathCities) { return (1 << numberOfMidpathCities); }
	static int getFullSubset(int numberOfMidpathCities) { return (1 << numberOfMidpathCities) - 1; }
	static int subsetWithoutCity(int subset, int city) { return subset & ~(1 << city); }
	static bool isCityInSubset(int subset, int city) { return (subset & (1 << city)) != 0; }
};