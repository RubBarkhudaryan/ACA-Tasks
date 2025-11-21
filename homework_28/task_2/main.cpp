#include <iostream>
#include "remote_controller.h"

int main()
{
	TVRemoteController	tv_remote;
	ACRemoteController	ac_remote;
	CarRemoteController	car_remote;

	std::cout << std::endl;

	tv_remote.turnOn();
	tv_remote.turnOn();
	tv_remote.increaseVolume(15);
	tv_remote.mute();
	tv_remote.mute();
	tv_remote.decreaseVolume(5);
	tv_remote.turnOff();

	std::cout << std::endl;

	ac_remote.turnOn();
	ac_remote.increaseVolume(10);
	ac_remote.decreaseVolume(5);
	ac_remote.turnOff();
	ac_remote.turnOff();
	ac_remote.mute();

	std::cout << std::endl;

	car_remote.turnOn();
	car_remote.turnOn();
	car_remote.turnOff();
	car_remote.turnOff();

	std::cout << std::endl;

	return (0);
}