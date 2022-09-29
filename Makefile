
NAME		=	containers

SOURCES_LIST	=	Main.cpp\

CC		= c++
CFLAGS	=	-Werror -Wall -Wextra -MMD

INCLUDES = -I$(HEADERS_DIR)

HEADERS_LIST =	stack.hpp\
				vector.hpp\
				set.hpp\
				map.hpp\
				Utility/is_integral.hpp \
				Utility/iterator_traits.hpp\
				Utility/map_iterator.hpp\
				Utility/node.hpp \
				Utility/pair.hpp\
				Utility/random_access_iterator.hpp \
				Utility/red_black_tree.hpp \
				Utility/reverse_iterator.hpp \
				Utility/utility.hpp\



HEADERS_DIR	=  ./srcs
HEADERS =	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

OBJECTS	=	$(patsubst %.cpp, %.o, $(SOURCES_LIST))

.PHONY:	all clean fclean re

all	: 	$(NAME)

$(NAME): $(OBJECTS)
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)

%.o : %.cpp $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
		@rm -f $(OBJECTS)

fclean:	clean
		@rm -f $(NAME)

re:		fclean all