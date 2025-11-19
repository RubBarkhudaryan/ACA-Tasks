NAME		=	exe

CXX			=	g++
CXXFLAGS	=	-std=c++11

SRCS		=	main.cpp animal.cpp
OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%o : %cpp
	$(CXX) $(CXXFLAGS) -c $> -o $@

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re:
	fclean all

.PHONY: all clean fclean re