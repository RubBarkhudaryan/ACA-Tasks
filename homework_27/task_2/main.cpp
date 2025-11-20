#include <iostream>
#include "animal.h"
#include "zoo.h"

int main()
{
	Zoo myZoo(5);

	Animal* lion = new Lion("Simba", "African Lion", "Golden", 4, 420.0, 4.0);
	Animal* tiger = new Tiger("Shere Khan", "Bengal Tiger", "Orange with Black Stripes", 5, 500.0, 3.5);
	Animal* cheetah = new Cheetah("Cheeto", "Asiatic Cheetah", "Tan with Black Spots", 3, 150.0, 3.0);

	myZoo.addAnimal(lion);
	myZoo.addAnimal(tiger);
	myZoo.addAnimal(cheetah);

	for (int i = 0; i < myZoo.getCount(); ++i)
		myZoo[i].sound();

	return (0);
}