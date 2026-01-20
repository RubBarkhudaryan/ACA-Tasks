#ifndef ANIMAL_COMPARE_H

# define ANIMAL_COMPARE_H
# include "./animal.h"

struct	Hasher
{
	std::size_t	operator()(const Animal& animal) const
	{
		std::size_t	_hash = 0;

		_hash = (animal.age() + animal.name().length()) >> 4;
		return (_hash);
	};
};

struct	AnimalCompare
{
	bool	operator() (const Animal& animal1, const Animal& animal2) const
	{
		return (animal1 == animal2);
	}
};

#endif