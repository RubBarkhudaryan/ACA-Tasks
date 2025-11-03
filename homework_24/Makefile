CXX			=	g++
CXXFLAGS	=	-std=c++11
NAME		=	exe

SRCS		=	main.cpp matrix.cpp car.cpp

OBJS		= $(SRCS:%.cpp=%.o)

RM			= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re