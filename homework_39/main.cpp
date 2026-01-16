#include "./animal.h"
#include "./animal_compare.h"
#include <set>
#include <iostream>

int main()
{
	std::set<Animal, AnimalCompare> animals;

	animals.insert(Animal("Dog", "Rottweiler", "Black", 5, 20, 150.5));
	animals.insert(Animal("Cat", "Siamese", "White", 3, 10, 50.0));
	animals.insert(Animal("Horse", "Arabian", "Brown", 10, 30, 300.0));
	animals.insert(Animal("Bird", "Parrot", "Green", 3, 5, 1.5));

	for (const Animal& a : animals)
		std::cout << a.name() << " - " << a.age() << std::endl;
}
