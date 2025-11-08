#include <fstream>
#include <iostream>
#include <vector>
#include "./matrix.h"
#include "./logger.h"

Logger::Logger(const std::string& filename)
{
	this->file.open(filename, std::fstream::in | std::fstream::out);
	this->filename = filename;
}

Logger::~Logger()
{
	this->file.close();
}

void	Logger::write(const std::string& message)
{
	if (!this->file.is_open())
	{
		std::cout << "Unable to open the file\n";
		return ;
	}
	this->file << message << "\n";
}

void	Logger::write(const Matrix& matrix)
{
	if (!this->file.is_open())
	{
		std::cout << "Unable to open the file\n";
		return ;
	}

	std::size_t	rows = matrix.getRows();
	std::size_t	cols = matrix.getCols();
	int			**mat = matrix.getMatrix();

	for (std::size_t i = 0; i < rows; ++i)
	{
		for (std::size_t j = 0; j < cols - 1; ++j)
			this->file << mat[i][j] << " ";
		this->file << mat[i][cols - 1];
		this->file << "\n";
	}
}

std::vector<std::string>	Logger::read()
{
	if (this->file.is_open())
	{
		std::vector<std::string>	data;
		std::string					row;
	
		while (std::getline(this->file, row))
			data.push_back(row);
		return (data);
	}
	else
		return (std::vector<std::string>());
}

void	Logger::replace_file(const std::string& new_filename)
{
	if (this->file.is_open())
		this->file.close();

	this->file.open(new_filename);
	this->filename = new_filename;

	if (!this->file.is_open())
		std::cout << "Unable to open the file\n";
}
