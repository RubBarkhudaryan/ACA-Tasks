#ifndef ENGINE_H

# define ENGINE_H

class Engine
{
	private:
		std::string	model;
		std::string	shape;
		std::string	fuel_type;
		int			piston_count;
		int			liter;

	public:
		/*Engine ctor/dtor*/
		Engine();
		Engine(std::string model, std::string shape, std::string fuel_type, int piston_count, int liter);
		~Engine();

		/*Engine methods*/
		void	print();
};

#endif
