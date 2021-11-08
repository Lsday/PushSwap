LIBFT = ./libft/libft.a

NAME = push_swap

SRCS =  push_swap_errors.c	\
		push_swap_init.c	\
		push_swap_push.c	\
		push_swap_rotate.c	\
		push_swap_rrotate.c	\
		push_swap_swap.c	\
		push_swap_utils.c	\
		push_swap_utils2.c	\
		push_swap_utils3.c	\
		push_swap_utils4.c	\
		push_swap_main.c	\
		push_swap_solve.c	\
		push_swap_free.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS) ${LIBFT} -o ${NAME}

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all