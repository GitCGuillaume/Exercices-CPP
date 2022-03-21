SRCS	=	span.cpp main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	ex01

.cpp.o:
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

make:
	make fclean
	make all
