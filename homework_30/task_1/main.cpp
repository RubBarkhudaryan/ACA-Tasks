#include <iostream>
#include "animal.h"

int main()
{

	Lion	lion1("Simba", "African Lion", "Golden", 5, 420.5, 1.2);
	lion1.sound();
	lion1.run();
	lion1.jump();

	Lion	lion2 = std::move(lion1);
	lion2.sound();

	return (0);
}


/*
Hayk Poghosyan
66: Մեր կողմից գրված շախմատի տախտակ և animal class-ներում ավելացնել move constructor և move operator =; 
*/