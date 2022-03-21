SRCS	=	Zombie.cpp ZombieHorde.cpp main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	horde

.cpp.o:
	c++ -Wall -Wextra -Werror -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
	c++ -Wall -Wextra -Werror -o $(NAME) $(SRCS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
	make clean

re:
	make fclean
	make all

.PHONY:	all clean fclean re
