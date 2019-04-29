##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

all:
	make -C externals/minilibc/
	make -C externals/linked_list/
	make -C asm/
	make -C corewar/

tests_run:
	make -C externals/minilibc/
	make -C externals/linked_list/
	make -C tests/
	./unit-tests

clean:
	make -C externals/minilibc/ clean
	make -C externals/linked_list/ clean
	make -C asm/ clean
	make -C corewar/ clean
	make -C tests/ clean

fclean:
	make -C externals/minilibc/ fclean
	make -C externals/linked_list/ fclean
	make -C asm/ fclean
	make -C corewar/ fclean
	make -C tests/ fclean

re:	fclean	all

.PHONY: clean fclean re all
