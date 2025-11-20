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
		Animal();
		Animal(const Animal &other) = delete;
		Animal &operator=(const Animal &other) = delete;
		Animal(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
			);
		virtual ~Animal();

		virtual void	sound() const;
};

class Lion : public Animal
{
	public:
		Lion();
		Lion(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Lion() override;
		void	sound() const override;
};

class Tiger : public Animal
{
	public:
		Tiger();
		Tiger(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Tiger() override;
		void	sound() const override;
};

class Cheetah : public Animal
{
	public:
		Cheetah();
		Cheetah(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Cheetah() override;
		void	sound() const override;
};

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Dog() override;
		void	sound() const override;
};

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Cat() override;
		void	sound() const override;
};

class SeaLion : public Animal
{
	public:
		SeaLion();
		SeaLion(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~SeaLion() override;
		void	sound() const override;
};

#endif