SRCS	=	Weapon.cpp HumanA.cpp HumanB.cpp main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	weapon

.cpp.o:
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

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
