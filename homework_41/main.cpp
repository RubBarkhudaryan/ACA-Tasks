#include "./animals/animal.h"
#include "./animals/animal_compare.h"
#include "hash_table.h"

int	main(void)
{
	rub::hash_table<Animal, Hasher, AnimalCompare> animals(26);

	Animal dog("Dog", "Rottweiler", "Black", 5, 20, 150.5);
	Animal cat("Cat", "Siamese", "White", 3, 10, 50.0);
	Animal horse("Horse", "Arabian", "Brown", 10, 30, 300.0);
	Animal bird("Bird", "Parrot", "Green", 3, 5, 1.5);

	// ---- Insert ----
	animals.insert(dog);
	animals.insert(cat);
	animals.insert(horse);
	animals.insert(bird);

	// ---- Duplicate insert (should NOT be added) ----
	animals.insert(dog);

	// ---- Contains tests ----
	std::cout << "Dog exists: " << animals.contains(dog) << std::endl;

	std::cout << "Cat exists: " << animals.contains(cat) << std::endl;

	std::cout << "Horse exists: " << animals.contains(horse) << std::endl;

	std::cout << "Bird exists: " << animals.contains(bird) << std::endl;

	// ---- Non-existing animal ----
	Animal fish("Fish", "Goldfish", "Gold", 1, 2, 0.2);

	std::cout << "Fish exists: " << animals.contains(fish) << std::endl;

	return (0);
}