// Engine.hpp
#pragma once
#include <string>

class Engine {
private:
    std::string type;
    int horsepower;
public:
    Engine(const std::string& type, int hp);
    ~Engine();
    // getters / setters
};

// Parking.hpp
#pragma once
#include <string>

class Parking {
private:
    std::string location;
    int capacity;
public:
    Parking(const std::string& loc, int cap);
    ~Parking();
    // getters / setters
};

// Car.hpp
#pragma once
#include <string>
// #include "Engine.hpp"
// #include "Parking.hpp"

class Car {
private:
    std::string model;
    Engine engine;           // Composition: Car "has-a" Engine
    Parking* parkingSpot;    // Association: Car "uses" Parking
public:
    Car(const std::string& model, const Engine& eng);
    void setParking(Parking* park);
    ~Car();
    // other methods
};

// Driver.hpp
#pragma once
#include <string>
// #include "Car.hpp"

class Driver {
private:
    std::string name;
    Car* car;       // Association: Driver "has" a Car
public:
    Driver(const std::string& name);
    void assignCar(Car* c);
    ~Driver();
    // other methods
};
