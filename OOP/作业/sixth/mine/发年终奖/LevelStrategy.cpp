#include "LevelStrategy.h"

LevelStrategy::LevelStrategy() {}

int P1LStrategy::get_ba() {
	return 2000;
}

int P2LStrategy::get_ba() {
	return 5000;
}

int P3LStrategy::get_ba() {
	return 10000;
}

LevelStrategy::~LevelStrategy() {}