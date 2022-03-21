SRCS	=	Account.cpp tests.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	account_output

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

.PHONY: all clean fclean re
