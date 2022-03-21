SRCS	=	newZombie.cpp randomChump.cpp Zombie.cpp main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	brainz

.cpp.o:
	c++ -Wall -Wextra -Werror -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
	c++ -Wall -Wextra -Werror -o $(NAME) $(SRCS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)

re:
	make fclean
	make all
