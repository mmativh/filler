NAME = libft.a
SRC = 	filler.c filler_read.c filler_heat.c filler_play.c filler_token.c
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc -o filler $(FLAGS) $(SRC) ./libft/libft.a
clean:
	make clean -C ./libft
	rm -f filler
fclean: clean
	make fclean -C ./libft
re: fclean all
	make re -C ./libft
norm:
	norminette filler*.c
	norminette filler.h
