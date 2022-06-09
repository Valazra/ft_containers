NAME = map

COMPILER = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

INC_DIR = includes

INCS = map.hpp red_black_tree.hpp node.hpp iterator.hpp pair.hpp make_pair.hpp less.hpp

SRCS = main_map.cpp

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
