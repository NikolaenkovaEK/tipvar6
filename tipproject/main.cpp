#include <iostream>
#include <ctime> 
#include <cstdlib>

#include "RandomGenerator.h"

using namespace std;

int main(int argc, char * argv[]) {
	srand (time(NULL));
	RandomGenerator Generator;

	Street SomeStreet = Generator.CreateRandomStreet();
	SomeStreet.Print(cout);

	cout << "-----\nTotal " << SomeStreet.GetPersonsCount() << " persons, " 
		<< SomeStreet.GetPersonsCountWhoCanVote() << " can vote:\n-----\n";

	Street PersonsWhoCanVote = SomeStreet.FilterPersonsWhoCanVote();
	PersonsWhoCanVote.Print(cout);
	system("pause");
	return 0;
}
