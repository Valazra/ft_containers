NAME = vector

COMPILER = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

INC_DIR = includes

INCS = vector.hpp enable_if.hpp is_integral.hpp lexicographical_compare.hpp iterator.hpp

SRCS = main_vector.cpp

OBJ = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -I. -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
		$(COMPILER) $(FLAGS) -I$(INC_DIR) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re make
