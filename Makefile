NAME = philo

SRC = main.c \
		init.c \
		philo.c \
		utils.c \
		utils2.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread -g

all: $(NAME)

$(NAME):
		make all -C ./libft
		$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)

val: all
		make -C ./ clean
		valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
				./$(NAME) 5 800 200 200 10

clean:
		make clean -C ./libft
		rm -f *.o

fclean: clean
		make fclean -C ./libft
		rm -f *.o
		rm -f $(NAME)

re:		fclean all