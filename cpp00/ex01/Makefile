SRCS	=	./PhoneBook.cpp Contact.cpp ./main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	phonebook

RM	=	rm -f

.cpp.o:
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) $(SRCS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
