#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include "Person.h"
#include "Home.h"
#include "Street.h"

class RandomGenerator {
public:
	Person CreateRandomPerson();
	Home CreateRandomHome();
	Street CreateRandomStreet();
};

#endif // RANDOM_GENERATOR_H