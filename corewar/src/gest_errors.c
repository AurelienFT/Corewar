/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** gest_errors.c
*/

#include "corewar.h"
#include "minilibc.h"

int check_dump(char **av, int i, infos_t *infos)
{
	if (my_strcmp(av[i], "-dump") == 1) {
		if (is_num_pos(av[i + 1]) == 1) {
			infos->nbr_cycles = my_getnbr(av[i + 1]);
			return (0);
		} else {
			my_putstr("Invalid argument in -dump. Please enter a"
				" positive number.\n");
			return (84);
		}
	}
	return (0);
}
