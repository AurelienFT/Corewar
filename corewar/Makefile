##
## EPITECH PROJECT, 2018
## corewar
## File description:
## Makefile
##

NAME		=	corewar

SRC_DIR		=	src

EXT_DIR		=	../externals

SRC		=	$(SRC_DIR)/main.c		\
			$(SRC_DIR)/initialize_vm.c	\
			$(SRC_DIR)/initialize_map.c	\
			$(SRC_DIR)/initialize_players.c	\
			$(SRC_DIR)/display_help.c	\
			$(SRC_DIR)/my_putstr.c		\
			$(SRC_DIR)/my_getnbr.c		\
			$(SRC_DIR)/start_vm.c		\
			$(SRC_DIR)/vm_loop.c		\
			$(SRC_DIR)/do_func_one.c	\
			$(SRC_DIR)/instructions.c	\
			$(SRC_DIR)/go_to_func.c		\
			$(SRC_DIR)/do_func_two.c	\
			$(SRC_DIR)/instructions_two.c	\
			$(SRC_DIR)/get_byte_code.c	\
			$(SRC_DIR)/go_to_ldi_two.c	\
			$(SRC_DIR)/my_putnbr.c		\
			$(SRC_DIR)/my_puthexa.c		\
			$(SRC_DIR)/free_dead.c		\
			$(SRC_DIR)/gest_errors.c

include_dirs	=	-I./include					\
			-I./$(EXT_DIR)/minilibc/$(SRC_DIR)/include	\
			-I./../asm/src/include

lib_dirs	 =	-L./$(EXT_DIR)/minilibc

OBJ		=	$(SRC:.c=.o)

CPPFLAGS	+=	$(include_dirs) $(lib_dirs)

CFLAGS		+=	-W -Wall -Wextra

LDFLAGS		+=	-l:minilibc.a

all:	$(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) src/*.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	clean fclean re
