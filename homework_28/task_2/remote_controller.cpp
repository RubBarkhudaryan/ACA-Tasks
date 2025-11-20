#include <iostream>
#include "remote_controller.h"

RemoteController::RemoteController()
{
	std::cout << "RemoteController interface ctor called." << std::endl;
}

RemoteController::~RemoteController()
{
	std::cout << "RemoteController interface dtor called." << std::endl;
}