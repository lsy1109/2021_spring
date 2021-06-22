#include "PerformStrategy.h"


PerformStrategy::PerformStrategy(double _perform):Perform(_perform){}
PerformStrategy::~PerformStrategy(){};

int sPerformStrategy::getbonus(int base){return 1000;}

int mPerformStrategy::getbonus(int base){return base*Perform;}

int lPerformStrategy::getbonus(int base){return base*Perform*2;}
