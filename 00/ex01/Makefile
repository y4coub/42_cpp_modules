CC= c++
CFLAGS= -Wall -Wextra -Werror -std=c++98
NAME= phonebook
SRC= PhoneBook.cpp Contact.cpp 
HEADERS= -I PhoneBook.hpp -I Contact.hpp
OBJ= $(SRC:.cpp=.o)

ifeq ($(DEBUG), 1)
	CFLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re