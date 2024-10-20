NAME = cub3d
FLAG = -Wall -Wextra -Werror
SRC = src/main.c
OBJ = $(SRC:.c=.o)
INCLUDE = includes
CC = gcc
XFLAG = -lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -I $(INCLUDE) -o $(NAME) $(OBJ) $(XFLAG)

src/%.o: src/%.cpp
	$(CC) $(FLAG) -I $(INCLUDE) -c $< -o $@ $(XFLAG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
