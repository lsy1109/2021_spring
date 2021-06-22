#include "PerformStrategy.h"

PerformStrategy::PerformStrategy(double x) :bonus(x) {}

int sPerformStrategy::get_tot(int _base) {
	return _base + 1000;
}

int mPerformStrategy::get_tot(int _base) {
	return _base+_base*bonus;
}

int lPerformStrategy::get_tot(int _base) {
	return _base+_base*2*bonus;
}

PerformStrategy::~PerformStrategy() {}
