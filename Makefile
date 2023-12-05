
N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  src/ft_printf.c \
		src/ft_print_utils.c\
		src/ft_print_base.c \
		src/ft_gpadidey.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all