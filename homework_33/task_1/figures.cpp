#include "figures.h"

Figure::Figure(const std::string& name, const std::string& color) : name(name), color(color)
{
	std::cout << "Figure ctor called.\n";
}

Figure::~Figure()
{
	std::cout << "Figure dtor called.\n";
}

King::King(const std::string& name, const std::string& color) : Figure(name, color)
{
	std::cout << "King ctor called.\n";
}

King::~King()
{
	std::cout << "King dtor called.\n";
}

void	King::move()
{
	std::cout << "Moved.\n";
}

Queen::Queen(const std::string& name, const std::string& color) : Figure(name, color)
{
	std::cout << "Queen ctor called.\n";
}

Queen::~Queen()
{
	std::cout << "Queen dtor called.\n";
}

void	Queen::move()
{
	std::cout << "Moved.\n";
}

Bishop::Bishop(const std::string& name, const std::string& color) : Figure(name, color)
{
	std::cout << "Bishop ctor called.\n";
}

Bishop::~Bishop()
{
	std::cout << "Bishop dtor called.\n";
}

void	Bishop::move()
{
	std::cout << "Moved.\n";
}

Knight::Knight(const std::string& name, const std::string& color) : Figure(name, color)
{
	std::cout << "Knight ctor called.\n";
}

Knight::~Knight()
{
	std::cout << "Knight dtor called.\n";
}

void	Knight::move()
{
	std::cout << "Moved.\n";
}

Rook::Rook(const std::string& name, const std::string& color) : Figure(name, color)
{
	std::cout << "Rook ctor called.\n";
}

Rook::~Rook()
{
	std::cout << "Rook dtor called.\n";
}

void	Rook::move()
{
	std::cout << "Moved.\n";
}

Pawn::Pawn(const std::string& name, const std::string& color) : Figure(name, color)
{
	std::cout << "Pawn ctor called.\n";
}

Pawn::~Pawn()
{
	std::cout << "Pawn dtor called.\n";
}

void	Pawn::move()
{
	std::cout << "Moved.\n";
}
