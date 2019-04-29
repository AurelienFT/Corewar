##
## EPITECH PROJECT, 2018
## linkedlist
## File description:
## Makefile
##

NAME	=	liblinked_list.a

SRC	=	src/free_list.c			\
		src/get_element_from_start.c	\
		src/init_list.c			\
		src/put_in_list.c

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
