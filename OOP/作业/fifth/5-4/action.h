#include "animal.h"
#include <iostream>

void action(Animal* animal, std::vector<Dog> & dogzone, std::vector<Bird> & birdzone){
    Dog* t1 =dynamic_cast<Dog*>(animal);
    Bird* t2 =dynamic_cast<Bird*>(animal); 
    if(t1==nullptr){
        birdzone.push_back(std::move(*t2));
    }
    else {
        dogzone.push_back(std::move(*t1));
    }
}

