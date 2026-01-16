#ifndef ANIMAL_COMPARE_H

# define ANIMAL_COMPARE_H
# include "./animal.h"

struct	AnimalCompare
{
	bool	operator()(const Animal& animal1, const Animal& animal2)
	{
		if (animal1.age() != animal2.age())
			return (animal1.age() < animal2.age());
		return (animal1.name() < animal2.name());
	}
};

#endif