SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = megaphone

.cpp.o:
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re:
	make clean
	make all

.PHONY: all clean fclean re
