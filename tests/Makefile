##
## EPITECH PROJECT, 2018
## corewar
## File description:
## Makefile
##

NAME		=	unit-tests

ASM_DIR		=	../asm/src

SRC_DIR		=	src

EXT_DIR		=	../externals

SRC		=	$(ASM_DIR)/utils/little_to_big_endian.c	\
			$(ASM_DIR)/utils/parse_path.c		\
			$(ASM_DIR)/utils/string.c		\
			$(ASM_DIR)/utils/my_realloc_unsigned.c	\
			$(ASM_DIR)/lexer.c			\
			$(ASM_DIR)/check_statement.c		\
			$(ASM_DIR)/parser.c			\
			$(ASM_DIR)/asm.c			\
			$(ASM_DIR)/header.c			\
			$(ASM_DIR)/write_code.c			\
			$(ASM_DIR)/op_tab.c			\
			$(ASM_DIR)/instruction_handler.c	\
			$(ASM_DIR)/instruction_writer.c		\
			$(ASM_DIR)/mne_params.c			\
			$(ASM_DIR)/my_getnbr.c			\
			$(ASM_DIR)/label.c			\
			$(ASM_DIR)/add_direct_lab.c		\
			$(ASM_DIR)/frees.c			\
			tests_basic_asm.c

include_dirs	=	-I./$(ASM_DIR)					\
			-I./$(EXT_DIR)/minilibc/$(SRC_DIR)/include	\
			-I./$(EXT_DIR)/linked_list/$(SRC_DIR)/include

lib_dirs	=	-L./$(EXT_DIR)/minilibc		\
			-L./$(EXT_DIR)/linked_list

OBJ		=	$(SRC:.c=.o)

CPPFLAGS	+=	$(include_dirs) --coverage

CFLAGS		+=	-W -Wall -Wextra

LDFLAGS		+=	$(lib_dirs) -l:minilibc.a -llinked_list -lcriterion

all:	$(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $(NAME)
	mv ./$(NAME) ..

clean:
	$(RM) $(OBJ)
	$(RM) $(ASM_DIR)/*.gc*
	$(RM) $(ASM_DIR)/utils/*.gc*
	$(RM) ../*.gcov
	$(RM) ../$(NAME)
	$(RM) *.gc*

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
