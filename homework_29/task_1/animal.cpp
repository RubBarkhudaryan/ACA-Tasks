#include <iostream>
#include <string>
#include "animal.h"

Animal::Animal()
{
	std::cout << "\nAnimal default ctor called." << std::endl;
}

Animal::Animal(
	const std::string &name, const std::string &breed,
	const std::string &color, int age,
	double weight, double height
	) : _name(name), _breed(breed), _color(color), _age(age), _weight(weight), _height(height)
{
	std::cout << "\nAnimal parameterized ctor called." << std::endl;
}

Animal::Animal(const Animal& other)
{
	_name = other._name;
	_breed = other._breed;
	_color = other._color;
	_age = other._age;
	_weight = other._weight;
	_height = other._height;
	std::cout << "\nAnimal copy ctor called." << std::endl;
}

Animal	&Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_name = other._name;
		_breed = other._breed;
		_color = other._color;
		_age = other._age;
		_weight = other._weight;
		_height = other._height;
	}
	std::cout << "\nAnimal assign operator called." << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal dtor called.\n" << std::endl;
}

LandAnimal::LandAnimal() : Animal()
{
	std::cout << "LandAnimal default ctor called.\n";
}

LandAnimal::LandAnimal(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height) : Animal(name, breed, color, age, weight, height)
{
	std::cout << "LandAnimal parameterized ctor called.\n";
}

LandAnimal::LandAnimal(const LandAnimal& other) : Animal(other)
{
	std::cout << "LandAnimal copy ctor called.\n";
}

LandAnimal&	LandAnimal::operator=(const LandAnimal& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_breed = other._breed;
		this->_color = other._color;
		this->_age = other._age;
		this->_height = other._height;
		this->_weight = other._weight;
	}
	std::cout << "LandAnimal assign operator called.\n";
	return (*this);
}

LandAnimal::~LandAnimal()
{
	std::cout << "LandAnimal dtor called.\n";
}

WaterAnimal::WaterAnimal() : Animal()
{
	std::cout << "WaterAnimal default ctor called.\n";
}

WaterAnimal::WaterAnimal(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height) : Animal(name, breed, color, age, weight, height)
{
	std::cout << "WaterAnimal parameterized ctor called.\n";
}

WaterAnimal::WaterAnimal(const WaterAnimal& other) : Animal(other)
{
	std::cout << "WaterAnimal copy ctor called.\n";
}

WaterAnimal&	WaterAnimal::operator=(const WaterAnimal& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_breed = other._breed;
		this->_color = other._color;
		this->_age = other._age;
		this->_height = other._height;
		this->_weight = other._weight;
	}
	std::cout << "WaterAnimal assign operator called.\n";
	return (*this);
}

WaterAnimal::~WaterAnimal()
{
	std::cout << "WaterAnimal dtor called.\n";
}

Reptile::Reptile() :  Animal(),  WaterAnimal(), LandAnimal()
{
	std::cout << "Reptile default ctor called.\n";
}

Reptile::Reptile(
	const std::string &name, const std::string &breed,
	const std::string &color, int age,
	double weight, double height
) : Animal(name, breed, color, age, weight, height),
	WaterAnimal(name, breed, color, age, weight, height),
	LandAnimal(name, breed, color, age, weight, height)
{
	std::cout << "Reptile parameterized ctor called.\n";
}

Reptile::Reptile(const Reptile& other)
	: Animal(other), WaterAnimal(other), LandAnimal(other) 
{
	std::cout << "Reptile copy ctor called.\n";
}

Reptile&	Reptile::operator=(const Reptile& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_breed = other._breed;
		this->_color = other._color;
		this->_age = other._age;
		this->_height = other._height;
		this->_weight = other._weight;
	}
	std::cout << "Reptile assign operator called.\n";
	return (*this);
}

Reptile::~Reptile()
{
	std::cout << "Reptile dtor called.\n";
}

Frog::Frog() : Reptile()
{
	std::cout << "Frog default ctor called.\n";
}

Frog::Frog(
	const std::string &name, const std::string &breed,
	const std::string &color, int age,
	double weight, double height
	) : Animal(name, breed, color, age, weight, height),
		Reptile(name, breed, color, age, weight, height)
{
	std::cout << "Frog parameterized ctor called.\n";
}

Frog::Frog(const Frog& other) : Animal(other), Reptile(other)
{
	std::cout << "Frog copy ctor called.\n";
}

Frog&	Frog::operator=(const Frog& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_breed = other._breed;
		this->_color = other._color;
		this->_age = other._age;
		this->_height = other._height;
		this->_weight = other._weight;
	}
	std::cout << "Frog assign operator called.\n";
	return (*this);
}

Frog::~Frog()
{
	std::cout << "Frog dtor called.\n";
}

void	Frog::sound() const
{
	std::cout << _name << " the frog says: Ribbit Ribbit!\n";
}

void	Frog::run() const
{
	std::cout << _name << " the frog is hopping on land.\n";
}

void	Frog::jump() const
{
	std::cout << _name << " the frog is jumping high!\n";
}

void	Frog::swim() const
{
	std::cout << _name << " the frog is swimming in the water.\n";
}

void	Frog::dive() const
{
	std::cout << _name << " the frog is diving underwater.\n";
}

void	Frog::crawl() const
{
	std::cout << _name << " the frog is crawling slowly.\n";
}
