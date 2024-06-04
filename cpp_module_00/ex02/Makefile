NAME = here_is_your_missing_file_boss_now_please_use_git

INCLUDE = ./

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = tests.cpp Account.cpp
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
