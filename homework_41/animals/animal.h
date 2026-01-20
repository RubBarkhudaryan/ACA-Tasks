#ifndef ANIMAL_H

# define ANIMAL_H

# include <iostream>
# include <string>

class	Animal
{
	protected:
		std::string	_name;
		std::string	_breed;
		std::string	_color;
		int			_age;
		double		_weight;
		double		_height;

	public:
		/*Animal ctor/dtor*/
		Animal();
		Animal(const Animal &other);
		Animal(Animal &&other) noexcept;
		Animal(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
		);
		~Animal();

		/*Animal operators*/
		Animal			&operator=(const Animal &other);
		Animal			&operator=(Animal &&other) noexcept;
		bool			operator==(const Animal& other) const;

		/*Animal methods*/
		void			sound(std::string _sound) const;
		int				age() const;
		std::string		name() const;
};

# include "./animal.tpp"

#endif