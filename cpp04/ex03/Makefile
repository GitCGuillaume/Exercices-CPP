SRCS	=	AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp

OBJS	=	$(SRCS:.cpp=.o)

.cpp.o:
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $(<:.cpp=.o)

NAME	=	character

$(NAME):	$(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY:	all clean fclean re
