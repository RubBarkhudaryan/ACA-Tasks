#include <iostream>
#include "animal.h"
#include "zoo.h"

Zoo::Zoo(int capacity) : capacity(capacity)
{
	this->animals = new Animal*[capacity]{nullptr};
	this->count = 0;
	std::cout << "\nZoo created with capacity " << capacity << std::endl;
}

Zoo::Zoo(const Zoo &other) : capacity(other.capacity), count(other.count)
{
	this->animals = new Animal*[other.capacity]{nullptr};
	for (int i = 0; i < other.count; ++i)
		this->animals[i] = other.animals[i];
	std::cout << "\nZoo copied" << std::endl;
}

Zoo::~Zoo()
{
	for (int i = 0; i < this->count; ++i)
		delete this->animals[i];
	delete[] this->animals;
	std::cout << "\nZoo destroyed" << std::endl;
}

Zoo&	Zoo::operator=(const Zoo &other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->count; ++i)
			delete this->animals[i];
		delete[] this->animals;

		this->capacity = other.capacity;
		this->count = other.count;
		this->animals = new Animal*[this->capacity]{nullptr};
		for (int i = 0; i < this->count; ++i)
			this->animals[i] = other.animals[i];
	}
	std::cout << "\nZoo assigned" << std::endl;
	return (*this);
}

Animal&	Zoo::operator[](int index) const
{
	return (*(this->animals[index]));
}

bool	Zoo::addAnimal(Animal* animal)
{
	if (this->count >= this->capacity)
	{
		std::cout << "Zoo is at full capacity. Cannot add more animals." << std::endl;
		return (false);
	}
	this->animals[this->count++] = animal;
	return (true);
}

int	Zoo::getCount() const
{
	return (this->count);
}

Animal*	Zoo::getAnimal(int index) const
{
	if (index < 0 || index >= this->count)
		return (nullptr);
	return (this->animals[index]);
}
