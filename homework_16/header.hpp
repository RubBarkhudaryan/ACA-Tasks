#ifndef HEADER_HPP

# define HEADER_HPP

# include <iostream>
# include <ctime>

void	operator delete(void *ptr);
void	*operator new(std::size_t size);
void	*ft_malloc(std::size_t size, std::string msg);

#endif