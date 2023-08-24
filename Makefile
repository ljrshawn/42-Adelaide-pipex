CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INCS = ./inc
SRCS = ./src/*.c
LIBS = ./lib

NAME = pipex

${NAME}: all

all:
	${CC} ${CFLAGS} -I ${INCS} ${SRCS} -o ${NAME} -L${LIBS} -lft -lftprintf

clean:
	${RM} ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re