SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	ex01

.cpp.o:
	c++ -Wall -Wextra -Werror -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
	c++ -Wall -Wextra -Werror -o $(NAME) $(OBJS)

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
