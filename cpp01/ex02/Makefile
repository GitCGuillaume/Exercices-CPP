SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	brain

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
