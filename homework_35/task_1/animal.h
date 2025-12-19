#ifndef ANIMAL_H

# define ANIMAL_H

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
		/*Animal ctro/dtor*/
		Animal();
		Animal(const Animal& other);
		Animal(Animal&& other);
		Animal(
			const std::string& name, const std::string& breed,
			const std::string& color, int age,
			double weight, double height
		);
		virtual ~Animal();

		/*Animal operators*/
		Animal	&operator=(const Animal& other);
		Animal	&operator=(Animal&& other);
		bool	operator==(const Animal& other) const;
		bool	operator<(const Animal& other) const;
		bool	operator>(const Animal& other) const;

		/*Animal methods*/
		virtual void	sound() const = 0;
		std::string		getname() const;
};

class	Lion : public Animal
{
	public:
		Lion();
		Lion(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Lion() override;
		void	sound() const override;
};

class	Tiger : public Animal
{
	public:
		Tiger();
		Tiger(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Tiger() override;
		void	sound() const override;
};

#endif