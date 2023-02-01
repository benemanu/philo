NAME = philo

SRC = main.c
		init.c \
		philo.c \
		utils.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		make all -C ./libft
		$(CC) $(CFLAGS) $(NAME) $(SRC) libft/libft.a

val: all
		make -C ./ clean
		valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
				./$(NAME)

clean:
		make clean -C ./libft
		rm -f *.o

fclean: clean
		make fclean -C ./libft
		rm -f *.o
		rm -f $(NAME)

re:		fclean all