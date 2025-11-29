#include <iostream>
#include <string>
#include "animal.h"

Animal::Animal()
{
	std::cout << "Animal default ctor." << std::endl;
}

Animal::Animal(
	const std::string &name, const std::string &breed,
	const std::string &color, int age,
	double weight, double height
	) : _name(name), _breed(breed), _color(color), _age(age), _weight(weight), _height(height)
{
	std::cout << "Animal parameterized ctor." << std::endl;
}

Animal::Animal(Animal&& other)
{
	this->_name = std::move(other._name);
	this->_breed = std::move(other._breed);
	this->_color = std::move(other._color);
	this->_age = other._age;
	this->_weight = other._weight;
	this->_height = other._height;
	std::cout << "Animal move ctor." << std::endl;
}

Animal::Animal(const Animal& other)
{
	this->_name = other._name;
	this->_breed = other._breed;
	this->_color = other._color;
	this->_age = other._age;
	this->_weight = other._weight;
	this->_height = other._height;
	std::cout << "Animal copy ctor." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal dtor." << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_breed = other._breed;
		this->_color = other._color;
		this->_age = other._age;
		this->_weight = other._weight;
		this->_height = other._height;
	}
	std::cout << "Animal copy assignment operator." << std::endl;
	return (*this);
}

Animal&	Animal::operator=(Animal&& other)
{
	if (this != &other)
	{
		this->_name = std::move(other._name);
		this->_breed = std::move(other._breed);
		this->_color = std::move(other._color);
		this->_age = other._age;
		this->_weight = other._weight;
		this->_height = other._height;
	}
	std::cout << "Animal move assignment operator." << std::endl;
	return (*this);
}

bool	Animal::operator==(const Animal& other) const
{
	return (this->_weight == other._weight);
}

bool	Animal::operator<(const Animal& other) const
{
	return (this->_weight < other._weight);
}

bool	Animal::operator>(const Animal& other) const
{
	return (this->_weight > other._weight);
}

std::string	Animal::getname() const
{
	return this->_name;
}

Lion::Lion() : Animal("LionName", "LionBreed", "Golden", 5, 420.0, 1.2)
{
	std::cout << "Lion ctor." << std::endl;
}

Lion::Lion(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Lion ctor." << std::endl;
}

Lion::~Lion()
{
	std::cout << "Lion dtor." << std::endl;
}

void	Lion::sound() const
{
	std::cout << this->_name << " the lion roars: Roarrr!" << std::endl;
}

Tiger::Tiger() : Animal("TigerName", "TigerBreed", "Orange with black stripes", 4, 300.0, 1.1)
{
	std::cout << "Tiger ctor." << std::endl;
}

Tiger::Tiger(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Tiger ctor." << std::endl;
}

Tiger::~Tiger()
{
	std::cout << "Tiger dtor." << std::endl;
}

void	Tiger::sound() const
{
	std::cout << this->_name << " the tiger growls: Grrr!" << std::endl;
}

Cheetah::Cheetah() : Animal("CheetahName", "CheetahBreed", "Tan with black spots", 3, 150.0, 0.9)
{
	std::cout << "Cheetah ctor." << std::endl;
}

Cheetah::Cheetah(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Cheetah ctor." << std::endl;
}

Cheetah::~Cheetah()
{
	std::cout << "Cheetah dtor." << std::endl;
}

void	Cheetah::sound() const
{
	std::cout << this->_name << " the cheetah chirps: Chirp chirp!" << std::endl;
}

Dog::Dog() : Animal("DogName", "DogBreed", "Brown", 2, 30.0, 0.6)
{
	std::cout << "Dog ctor." << std::endl;
}

Dog::Dog(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Dog ctor." << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog dtor." << std::endl;
}

void	Dog::sound() const
{
	std::cout << this->_name << " the dog barks: Woof woof!" << std::endl;
}

Cat::Cat() : Animal("CatName", "CatBreed", "Gray", 3, 10.0, 0.3)
{
	std::cout << "Cat ctor." << std::endl;
}

Cat::Cat(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Cat ctor." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat dtor." << std::endl;
}

void	Cat::sound() const
{
	std::cout << this->_name << " the cat meows: Meow!" << std::endl;
}

SeaLion::SeaLion() : Animal("SeaLionName", "SeaLionBreed", "Dark Brown", 6, 400.0, 1.5)
{
	std::cout << "Sea Lion ctor." << std::endl;
}

SeaLion::SeaLion(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Sea Lion ctor." << std::endl;
}

SeaLion::~SeaLion()
{
	std::cout << "Sea Lion dtor." << std::endl;
}

void	SeaLion::sound() const
{
	std::cout << this->_name << " the sea lion barks: Arf arf!" << std::endl;
}
