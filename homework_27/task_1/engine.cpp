#include <string>
#include <iostream>
#include "./engine.h"


Engine::Engine()
{
	std::cout << "Engine default ctor called.\n";
	this->model = "K7M";
	this->shape = "Inline-4";
	this->fuel_type = "Gasoline";
	this->piston_count = 4;
	this->liter = 1.6;
}

Engine::Engine(std::string model, std::string shape, std::string fuel_type, int piston_count, int liter)
{
	std::cout << "Engine parameterized ctor called.\n";
	this->model = model;
	this->shape = shape;
	this->fuel_type = fuel_type;
	this->piston_count = piston_count;
	this->liter = liter;
}

Engine::~Engine()
{
	std::cout << "Engine dtor called.\n";
}

void	Engine::print()
{
	std::cout << std::endl;
	std::cout << "Engine data" << std::endl;
	std::cout << "\t|-- Model: " << this->model << std::endl;
	std::cout << "\t|-- Shape: " << this->shape << std::endl;
	std::cout << "\t|-- Fuel type: " << this->fuel_type << std::endl;
	std::cout << "\t|-- Pistons count: " << this->piston_count << std::endl;
	std::cout << "\t|-- Volume: " << this->liter << " liters" << std::endl;
	std::cout << std::endl;
}

