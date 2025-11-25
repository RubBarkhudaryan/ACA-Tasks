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

Animal::Animal(Animal&& other) noexcept
{
	_name = std::move(other._name);
	_breed = std::move(other._breed);
	_color =  std::move(other._color);
	_age = other._age;
	_weight = other._weight;
	_height = other._height;
	std::cout << "\nAnimal move ctor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal dtor called.\n" << std::endl;
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

Animal&	Animal::operator=(Animal&& other) noexcept
{
	if (this != &other)
	{
		_name = std::move(other._name);
		_breed = std::move(other._breed);
		_color =  std::move(other._color);
		_age = other._age;
		_weight = other._weight;
		_height = other._height;
	}
	std::cout << "\nAnimal move assign operator called." << std::endl;
	return (*this);
}

Lion::Lion() : Animal()
{
	std::cout << "Lion default ctor called." << std::endl;
}

Lion::Lion(
	const std::string &name, const std::string &breed,
	const std::string &color, int age,
	double weight, double height
	) : Animal(name, breed, color, age, weight, height)
{
	std::cout << "Lion parameterized ctor called." << std::endl;
}

Lion::Lion(const Lion& other) : Animal(other)
{
	std::cout << "Lion copy ctor called." << std::endl;
}

Lion::Lion(Lion&& other) noexcept : Animal(std::move(other))
{
	std::cout << "Lion move ctor called." << std::endl;
}

Lion::~Lion()
{
	std::cout << "Lion dtor called." << std::endl;
}

Lion&	Lion::operator=(const Lion& other)
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
	std::cout << "Lion assign operator called." << std::endl;
	return (*this);
}

Lion&	Lion::operator=(Lion&& other) noexcept
{
	if (this != &other)
	{
		this->_name = std::move(other._name);
		this->_breed = std::move(other._breed);
		this->_color =  std::move(other._color);
		this->_age = other._age;
		this->_weight = other._weight;
		this->_height = other._height;
	}
	std::cout << "Lion move assign operator called." << std::endl;
	return (*this);
}

void	Lion::sound() const
{
	std::cout << this->_name << " the Lion says: Roar!" << std::endl;
}

void	Lion::run() const
{
	std::cout << this->_name << " the Lion is running." << std::endl;
}

void	Lion::jump() const
{
	std::cout << this->_name << " the Lion is jumping." << std::endl;
}
