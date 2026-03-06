#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

int	main(int argc, char **argv)
{

	int	fd;
	int	default_fd;

	if (argc < 2)
	{
		std::cerr << "Program must have at least two arguments.\n";
		std::cout << "Usage: ./program_name filename [text aruments to insert into file].\n";
		return (1);
	}

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
		std::cerr << "Unable to open the file: " << argv[1] << "\n";
		return (1);
	}

	default_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);

	if (argc == 2)
		std::cout << "Hello world\n";
	else
	{
		for (int i = 2; i < argc; ++i)
			std::cout << argv[i] << std::endl;
	}

	dup2(default_fd, STDOUT_FILENO);
	close(default_fd);
	close(fd);

	return (0);
}