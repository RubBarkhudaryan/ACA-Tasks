#include <iostream>
#include <string>
#include "animal.h"

Animal::Animal()
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(
	const std::string &name, const std::string &breed,
	const std::string &color, int age,
	double weight, double height
	) : _name(name), _breed(breed), _color(color), _age(age), _weight(weight), _height(height)
{
	std::cout << "Animal created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

void	Animal::sound() const
{
	std::cout << this->_name << " makes a sound." << std::endl;
}

Lion::Lion() : Animal("LionName", "LionBreed", "Golden", 5, 420.0, 1.2)
{
	std::cout << "Lion created" << std::endl;
}

Lion::Lion(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Lion created" << std::endl;
}

Lion::~Lion()
{
	std::cout << "Lion destroyed" << std::endl;
}

void	Lion::sound() const
{
	std::cout << this->_name << " the lion roars: Roarrr!" << std::endl;
}

Tiger::Tiger() : Animal("TigerName", "TigerBreed", "Orange with black stripes", 4, 300.0, 1.1)
{
	std::cout << "Tiger created" << std::endl;
}

Tiger::Tiger(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Tiger created" << std::endl;
}

Tiger::~Tiger()
{
	std::cout << "Tiger destroyed" << std::endl;
}

void	Tiger::sound() const
{
	std::cout << this->_name << " the tiger growls: Grrr!" << std::endl;
}

Cheetah::Cheetah() : Animal("CheetahName", "CheetahBreed", "Tan with black spots", 3, 150.0, 0.9)
{
	std::cout << "Cheetah created" << std::endl;
}

Cheetah::Cheetah(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Cheetah created" << std::endl;
}

Cheetah::~Cheetah()
{
	std::cout << "Cheetah destroyed" << std::endl;
}

void	Cheetah::sound() const
{
	std::cout << this->_name << " the cheetah chirps: Chirp chirp!" << std::endl;
}

Dog::Dog() : Animal("DogName", "DogBreed", "Brown", 2, 30.0, 0.6)
{
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Dog created" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
}

void	Dog::sound() const
{
	std::cout << this->_name << " the dog barks: Woof woof!" << std::endl;
}

Cat::Cat() : Animal("CatName", "CatBreed", "Gray", 3, 10.0, 0.3)
{
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Cat created" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
}

void	Cat::sound() const
{
	std::cout << this->_name << " the cat meows: Meow!" << std::endl;
}

SeaLion::SeaLion() : Animal("SeaLionName", "SeaLionBreed", "Dark Brown", 6, 400.0, 1.5)
{
	std::cout << "Sea Lion created" << std::endl;
}

SeaLion::SeaLion(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height)
	: Animal(name, breed, color, age, weight, height)
{
	std::cout << "Sea Lion created" << std::endl;
}

SeaLion::~SeaLion()
{
	std::cout << "Sea Lion destroyed" << std::endl;
}

void	SeaLion::sound() const
{
	std::cout << this->_name << " the sea lion barks: Arf arf!" << std::endl;
}
