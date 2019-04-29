##
## EPITECH PROJECT, 2018
## makefile minilib
## File description:
## makefile minilib
##

NAME	=	minilibc.a

SRC	=	src/get_next_line.c		\
		src/my_atoi.c			\
		src/put.c			\
		src/put_err.c			\
		src/my_strcmp.c			\
		src/my_str_to_word_array.c	\
		src/is_num.c			\
		src/my_strlen.c			\
		src/my_strcontains.c		\
		src/is_num_pos.c		\
		src/my_strcpy.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -I./src/include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
