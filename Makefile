SRCS = Authentication.cpp

NAME = auth

OBJ = $(SRCS:.cpp=.o)

HEADER = Authentication.hpp

FLAGS = -Wall -Wextra -Werror -std=c++98

%.o : %.cpp $(HEADER)
	c++ $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all