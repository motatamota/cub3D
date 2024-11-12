NAME = cub3D
LIB = libft/libft.a
FLAG = -Wall -Wextra -Werror
SRC = $(wildcard src/*.c)
OBJ = $(SRC:%.c=%.o)
INCLUDE = includes
CC = gcc
XFLAG = -lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAG) -I $(INCLUDE) -o $(NAME) $(OBJ) $(LIB) $(XFLAG)

$(LIB):
	make -C libft

src/%.o: src/%.c
	$(CC) $(FLAG) -I $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
