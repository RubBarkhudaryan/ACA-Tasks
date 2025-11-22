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
		Animal(const Animal &other);
		Animal(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
		);
		virtual ~Animal();

		/*Animal operators*/
		Animal			&operator=(const Animal &other);

		/*Animal methods*/
		virtual void	sound() const = 0;
};

class	LandAnimal : virtual public Animal
{
	public:
		/*LandAnimal ctor/dtor*/
		LandAnimal();
		LandAnimal(const LandAnimal &other);
		LandAnimal(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
		);
		~LandAnimal() override;

		/*LandAnimal operators*/
		LandAnimal		&operator=(const LandAnimal &other);

		/*LandAnimal methods*/
		virtual void	run() const = 0;
		virtual void	jump() const = 0;
};

class	WaterAnimal : virtual public Animal
{
	public:
		/*WaterAnimal ctor/dtor*/
		WaterAnimal();
		WaterAnimal(const WaterAnimal &other);
		WaterAnimal(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
		);
		~WaterAnimal() override;

		/*WaterAnimal operators*/
		WaterAnimal		&operator=(const WaterAnimal &other);

		/*WaterAnimal methods*/
		virtual void	swim() const = 0;
		virtual void	dive() const = 0;
};

class	Reptile : public WaterAnimal , public LandAnimal
{
	public:
		/*Reptile ctor/dtor*/
		Reptile();
		Reptile(const Reptile &other);
		Reptile(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
		);
		~Reptile() override;

		/*Reptile operators*/
		Reptile			&operator=(const Reptile &other);

		/*Reptile methods*/
		virtual void	crawl() const = 0;
};

class	Frog : public Reptile
{
	public:
		/*Frog ctor/dtor*/
		Frog();
		Frog(const Frog &other);
		Frog(
			const std::string &name, const std::string &breed,
			const std::string &color, int age,
			double weight, double height
		);
		~Frog() override;

		/*Frog operators*/
		Frog			&operator=(const Frog &other);

		/*Frog methods*/
		void			sound() const override;
		void			run() const override;
		void			jump() const override;
		void			swim() const override;
		void			dive() const override;
		void			crawl() const override;
};

#endif