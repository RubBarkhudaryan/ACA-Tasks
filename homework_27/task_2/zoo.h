#ifndef ZOO_H

# define ZOO_H

class	Zoo
{
	private:
		std::string	name = "";
		Animal**	animals = nullptr;
		int			capacity = 0;
		int			count = 0;
	public:

		/*Zoo ctor/dtor*/
		Zoo(int capacity);
		Zoo(const Zoo &other);
		~Zoo();

		/*Zoo operators*/
		Zoo&	operator=(const Zoo &other);
		Animal&	operator[](int index) const;

		/*Zoo methods*/
		bool	addAnimal(Animal* animal);
		int		getCount() const;
		Animal*	getAnimal(int index) const;
};

#endif	// ZOO_H