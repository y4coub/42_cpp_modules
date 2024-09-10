CC= c++
CFLAGS= -Wall -Wextra -Werror -std=c++98
NAME= account
SRC= Account.cpp tests.cpp
HEADER= Account.hpp
OBJ= $(SRC:.cpp=.o)

ifeq ($(DEBUG), 1)
	DEBUG= -g3 -fsanitize=address
else
	DEBUG=
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DEBUG) $(OBJ) -I$(HEADER) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re