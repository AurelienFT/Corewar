##
## EPITECH PROJECT, 2018
## corewar
## File description:
## Makefile
##

NAME		=	asm

SRC_DIR		=	src

EXT_DIR		=	../externals

SRC		=	$(SRC_DIR)/main.c			\
			$(SRC_DIR)/utils/little_to_big_endian.c	\
			$(SRC_DIR)/utils/parse_path.c		\
			$(SRC_DIR)/utils/string.c		\
			$(SRC_DIR)/utils/my_realloc_unsigned.c	\
			$(SRC_DIR)/lexer.c			\
			$(SRC_DIR)/check_statement.c		\
			$(SRC_DIR)/parser.c			\
			$(SRC_DIR)/asm.c			\
			$(SRC_DIR)/header.c			\
			$(SRC_DIR)/write_code.c			\
			$(SRC_DIR)/op_tab.c			\
			$(SRC_DIR)/instruction_handler.c	\
			$(SRC_DIR)/instruction_writer.c		\
			$(SRC_DIR)/mne_params.c			\
			$(SRC_DIR)/my_getnbr.c			\
			$(SRC_DIR)/label.c			\
			$(SRC_DIR)/add_direct_lab.c		\
			$(SRC_DIR)/frees.c

include_dirs	=	-I./$(SRC_DIR)					\
			-I./$(EXT_DIR)/minilibc/$(SRC_DIR)/include	\
			-I./$(EXT_DIR)/linked_list/$(SRC_DIR)/include

lib_dirs	=	-L./$(EXT_DIR)/minilibc		\
			-L./$(EXT_DIR)/linked_list

OBJ		=	$(SRC:.c=.o)

CPPFLAGS	+=	$(include_dirs)

CFLAGS		+=	-W -Wall -Wextra

LDFLAGS		+=	$(lib_dirs) -l:minilibc.a -llinked_list

all:	$(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
