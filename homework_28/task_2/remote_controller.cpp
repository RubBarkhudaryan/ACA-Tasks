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

TVRemoteController::TVRemoteController()
	: is_on(false), is_muted(false), before_mute_volume(10), volume_level(10)
{
	std::cout << "TVRemoteController ctor called." << std::endl;
}

TVRemoteController::~TVRemoteController()
{
	std::cout << "TVRemoteController dtor called." << std::endl;
}

void	TVRemoteController::turnOn()
{
	if (!this->is_on)
	{
		std::cout << "TV turned on.\n";
		this->is_on = true;
	}
	else
		std::cout << "TV is already on.\n";
}

void	TVRemoteController::turnOff()
{
	if (this->is_on)
	{
		std::cout << "TV turned off.\n";
		this->is_on = false;
	}
	else
		std::cout << "TV is already off.\n";
}

void	TVRemoteController::increaseVolume(int volume)
{
	if (volume > 0)
	{
		if (this->volume_level + volume > 100)
			this->volume_level = 100;
		else
			this->volume_level += volume;
	}
	else
		std::cout << "Given value is negative\n";
	std::cout << "Current volume is " << this->volume_level << ".\n";
}

void	TVRemoteController::decreaseVolume(int volume)
{
	if (volume > 0)
	{
		if (this->volume_level - volume < 0)
			this->volume_level = 0;
		else
			this->volume_level -= volume;
	}
	else
		std::cout << "Given value is negative\n";
	std::cout << "Current volume is " << this->volume_level << ".\n";
}

void	TVRemoteController::mute()
{
	if (this->is_muted)
	{
		this->is_muted = false;
		this->volume_level = this->before_mute_volume;
		this->before_mute_volume = 0;
		std::cout << "TV unmuted. Current volume is " << this->volume_level << ".\n";
	}
	else
	{
		this->is_muted = true;
		this->before_mute_volume = this->volume_level;
		this->volume_level = 0;
		std::cout << "TV muted. Current volume is " << this->volume_level << ".\n";
	}
}


ACRemoteController::ACRemoteController()
	: is_on(false), volume_level(20)
{
	std::cout << "ACRemoteController ctor called." << std::endl;
}

ACRemoteController::~ACRemoteController()
{
	std::cout << "ACRemoteController dtor called." << std::endl;
}

void	ACRemoteController::turnOn()
{
	if (!this->is_on)
	{
		std::cout << "AC turned on.\n";
		this->is_on = true;
	}
	else
		std::cout << "AC is already on.\n";
}

void	ACRemoteController::turnOff()
{
	if (this->is_on)
	{
		std::cout << "AC turned off.\n";
		this->is_on = false;
	}
	else
		std::cout << "AC is already off.\n";
}

void	ACRemoteController::increaseVolume(int volume)
{
	if (volume > 0)
	{
		if (this->volume_level + volume > 40)
			this->volume_level = 40;
		else
			this->volume_level += volume;
	}
	else
		std::cout << "Given value is negative\n";
	std::cout << "Current volume is " << this->volume_level << ".\n";
}

void	ACRemoteController::decreaseVolume(int volume)
{
	if (volume > 0)
	{
		if (this->volume_level - volume < 0)
			this->volume_level = 0;
		else
			this->volume_level -= volume;
	}
	else
		std::cout << "Given value is negative\n";
	std::cout << "Current volume is " << this->volume_level << ".\n";
}

void	ACRemoteController::mute() {}

CarRemoteController::CarRemoteController()
	: is_locked(true)
{
	std::cout << "CarRemoteController ctor called." << std::endl;
}

CarRemoteController::~CarRemoteController()
{
	std::cout << "CarRemoteController dtor called." << std::endl;
}

void	CarRemoteController::turnOn()
{
	if (this->is_locked)
	{
		std::cout << "Car unlocked.\n";
		this->is_locked = false;
	}
	else
		std::cout << "Car is already unlocked.\n";
}

void	CarRemoteController::turnOff()
{
	if (!this->is_locked)
	{
		std::cout << "Car locked.\n";
		this->is_locked = true;
	}
	else
		std::cout << "Car is already locked.\n";
}

void	CarRemoteController::increaseVolume(int volume)
{
	(void)volume;
}
void	CarRemoteController::decreaseVolume(int volume)
{
	(void)volume;
}
void	CarRemoteController::mute() {}