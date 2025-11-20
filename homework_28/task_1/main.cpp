#include <iostream>
#include "animal.h"

int main()
{

	Lion lion("Simba", "African Lion", "Golden", 5, 420.0, 1.2);
	lion.sound();

	Tiger tiger("Shere Khan", "Bengal Tiger", "Orange with black stripes", 4, 300.0, 1.1);
	tiger.sound();

	Cheetah cheetah("Chester", "Asiatic Cheetah", "Tan with black spots", 3, 150.0, 0.9);
	cheetah.sound();

	Dog dog("Buddy", "Golden Retriever", "Golden", 3, 30.0, 0.6);
	dog.sound();

	Cat cat("Whiskers", "Siberian", "Gray", 2, 10.0, 0.3);
	cat.sound();

	SeaLion seaLion("Sammy", "California Sea Lion", "Dark Brown", 6, 400.0, 1.5);
	seaLion.sound();

	return (0);
}