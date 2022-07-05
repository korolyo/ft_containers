
NAME		=	containers

SOURCES_LIST	=	Main.cpp\

CC		= c++
CFLAGS	=	-Werror -Wall -Wextra -std=c++98 -pedantic-errors -MMD

INCLUDES = -I$(HEADERS_DIR)

HEADERS_LIST =	Stack.hpp\
				Vector.hpp\
				Utils.hpp\
				Iterator_traits.hpp\
				Vector_iterator.hpp\
				Map_iterator.hpp\
				Pair.hpp\
				Map.hpp\
				Set.hpp\


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