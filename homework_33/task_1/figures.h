#ifndef FIGURES_H

# define FIGURES_H

#include <iostream>
#include <string>
#include <utility>

class	Figure
{
	protected:
		std::string			name;
		std::string			color;
		std::pair<int, int>	pos;

	public:
		/* ctor/dtor */
		Figure() = delete;
		Figure(const std::string& name, const std::string& color);
		virtual ~Figure();

		/* methods */
		virtual void	move() = 0;
};

class	King : public Figure
{
	public:
		King(const std::string& name, const std::string& color);
		~King() override;

		void	move() override;
};

class	Queen : public Figure
{
	public:
		Queen(const std::string& name, const std::string& color);
		~Queen() override;

		void	move() override;
};

class	Bishop : public Figure
{
	public:
		Bishop(const std::string& name, const std::string& color);
		~Bishop() override;

		void	move() override;
};

class	Knight : public Figure
{
	public:
		Knight(const std::string& name, const std::string& color);
		~Knight() override;

		void	move() override;
};

class	Rook : public Figure
{
	public:
		Rook(const std::string& name, const std::string& color);
		~Rook() override;

		void	move() override;
};

class	Pawn : public Figure
{
	public:
		Pawn(const std::string& name, const std::string& color);
		~Pawn() override;

		void	move() override;
};

#endif // FIGURES_H