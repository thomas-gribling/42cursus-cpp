NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror

FILES = megaphone.cpp
OBJECTS = $(FILES:.cpp=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf $(OBJECTS)


fclean: clean
	rm -rf $(NAME)

re: fclean all
