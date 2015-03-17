#include "RandomGenerator.h"

Person RandomGenerator::CreateRandomPerson() {
	Person Man;

	Man.SetAge(rand() % 50 + 1);

	std::string Names[50] = {
		"Hugo Gonzales",
		"Yolanda Cannon",
		"Wilbur Torres",
		"Sally Schmidt",
		"Cindy Lloyd",
		"Darin Davidson",
		"Dale Peters",
		"Jason Woods",
		"Douglas Robinson",
		"Arlene Logan",
		"Victor Arnold",
		"Chelsea Lewis",
		"Emily Barker",
		"Carla Carpenter",
		"Marjorie Collins",
		"Terrell Lindsey",
		"Casey Dawson",
		"Caleb Barnes",
		"Johanna Berry",
		"Tracy Stephens",
		"Darnell Thomas",
		"Rick Dennis",
		"Loren Myers",
		"Blanca Ryan",
		"Lloyd Lawrence",
		"Pearl Gordon",
		"Donnie Henderson",
		"Myrtle Fletcher",
		"Glenda Franklin",
		"Raymond Rios",
		"Rogelio Mckenzie",
		"Brendan Nguyen",
		"Billy Weber",
		"Willard Gutierrez",
		"Cecelia Schultz",
		"Joey Farmer",
		"Melinda Wilkerson",
		"Clifford Riley",
		"Tabitha Miles",
		"Larry Jimenez",
		"Ray Smith",
		"Erma Perry",
		"Dewey Stevenson",
		"Clarence Rivera",
		"Sherri Little",
		"Curtis Erickson",
		"Irving Schneider",
		"Jody Love",
		"Gerald Holland",
		"Bryan Hines"
	};

	Man.SetName(Names[rand() % 50]);

	return Man;
}

Home RandomGenerator::CreateRandomHome() {
	Home SomeHome;
	unsigned int PersonCount = rand() % 4 + 1;
	for(unsigned int i = 0; i < PersonCount; i++) {
		SomeHome += CreateRandomPerson();
	}
	return SomeHome;
}

Street RandomGenerator::CreateRandomStreet() {
	Street SomeStreet;
	std::string Names[17] = {
		"Colonial Pony Stroll",
		"Log Park",
		"Lazy Highlands",
		"Prairie Glade",
		"Jagged Panda Lane",
		"Old Butterfly Manor",
		"Wishing Prairie Corner",
		"Clear Treasure Path",
		"Quaking Berry Landing",
		"Dusty Treasure Estates",
		"Gentle Dove Nook",
		"Ivory Holly Falls",
		"Happy Sky Falls",
		"Lone Jetty",
		"Sweet Hills Court",
		"Sleepy Zephyr Farms",
		"Rocky Turn",
	};
	SomeStreet.SetName(Names[rand() % 17]);
	unsigned int RandomHomesCount = rand() % 3 + 1;
	for(unsigned int i = 0; i < RandomHomesCount; i++) {
		Home SomeHome = CreateRandomHome();
		SomeHome.SetHomeNo(i+1);
		SomeStreet.Add(SomeHome);
	}
	return SomeStreet;
}
