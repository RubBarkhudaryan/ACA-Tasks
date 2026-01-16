#include <iostream>
#include <string>
#include "animal.h"

Animal::Animal()
{}

Animal::Animal(
	const std::string &name, const std::string &breed,
	const std::string &color, int age,
	double weight, double height
	) : _name(name), _breed(breed), _color(color), _age(age), _weight(weight), _height(height)
{
}

Animal::Animal(const Animal& other)
{
	_name = other._name;
	_breed = other._breed;
	_color = other._color;
	_age = other._age;
	_weight = other._weight;
	_height = other._height;
}

Animal::Animal(Animal&& other) noexcept
{
	_name = std::move(other._name);
	_breed = std::move(other._breed);
	_color =  std::move(other._color);
	_age = other._age;
	_weight = other._weight;
	_height = other._height;
}

Animal::~Animal()
{}

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
	return (*this);
}

void	Animal::sound(std::string _sound) const
{
	std::cout << this->_name << " says: " << _sound << "\n";
};

int	Animal::age() const
{
	return (this->_age);
}

std::string	Animal::name() const
{
	return (this->_name);
}
