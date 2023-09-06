SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	ex02

.cpp.o:
	c++ -Wall -Wextra -Werror --std=c++98 -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
	c++ -Wall -Wextra -Werror --std=c++98 -o $(NAME) $(OBJS)

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
