NAME = ft_sed

INCLUDE = ./

CC = c++
CFLAGS = -Wall -Wextra -Werror

FILES = main.cpp
OBJECTS = $(FILES:.cpp=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ -I $(INCLUDE)

clean:
	rm -rf $(OBJECTS)


fclean: clean
	rm -rf $(NAME)

re: fclean all
