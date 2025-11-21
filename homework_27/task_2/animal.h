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
		/*Animal ctor/dtor*/
		Animal();
		Animal(const Animal &other) = delete;
		Animal(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
		);
		virtual ~Animal();

		/*Animal operators*/
		Animal &operator=(const Animal &other) = delete;

		/*Animal methods*/
		virtual void	sound() const;
};

class Lion : public Animal
{
	public:
		/*Lion ctor/dtor*/
		Lion();
		Lion(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Lion() override;

		/*Lion methods*/
		void	sound() const override;
};

class Tiger : public Animal
{
	public:
		/*Tiger ctor/dtor*/
		Tiger();
		Tiger(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Tiger() override;

		/*Tiger methods*/
		void	sound() const override;
};

class Cheetah : public Animal
{
	public:
		/*Cheetah ctor/dtor*/
		Cheetah();
		Cheetah(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Cheetah() override;

		/*Cheetah methods*/
		void	sound() const override;
};

class Dog : public Animal
{
	public:
		/*Dog ctor/dtor*/
		Dog();
		Dog(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Dog() override;

		/*Dog methods*/
		void	sound() const override;
};

class Cat : public Animal
{
	public:
		/*Cat ctor/dtor*/
		Cat();
		Cat(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~Cat() override;

		/*Cat methods*/
		void	sound() const override;
};

class SeaLion : public Animal
{
	public:
		/*SeaLion ctor/dtor*/
		SeaLion();
		SeaLion(const std::string &name, const std::string &breed,
				const std::string &color, int age,
				double weight, double height);
		~SeaLion() override;

		/*SeaLion methods*/
		void	sound() const override;
};

#endif