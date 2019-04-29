/*
** EPITECH PROJECT, 2018
** my_put
** File description:
** hexa
*/

#include "corewar.h"

void my_puthexa(unsigned char arena, char *numbers)
{
	int to_print = arena / 16;

	if (arena == 48) {
		write(1, "0", 1);
		return;
	}
	if (to_print > 0)
		write(1, &numbers[to_print], 1);
	to_print = arena % 16;
	write(1, &numbers[to_print], 1);
}
