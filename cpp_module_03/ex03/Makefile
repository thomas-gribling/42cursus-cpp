NAME = PiegeDiamant

INCLUDE = ./

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJECTS = $(FILES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ -I $(INCLUDE)

clean:
	rm -rf $(OBJECTS)


fclean: clean
	rm -rf $(NAME)

re: fclean all
