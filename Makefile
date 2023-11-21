SRCS = 

OBJS = ${SRCS:.c=.o}

INCS = includes

NAME = libft.a

LIBC = ar rc

LIBR = ranlib

CC			= gcc

RM			= rm -f

CFLAGS = -Wall -Wextra -Werror -I.

%.o: %.c
		${CC} ${CFLAGS} -c -I ${INCS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}
		${LIBR} ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}
fclean : clean
		${RM} ${NAME}

re: fclean all