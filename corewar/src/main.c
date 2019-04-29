/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "corewar.h"

int main(int ac, char **av)
{
	infos_t *infos = malloc(sizeof(infos_t));
	players_t *players = NULL;
	int ret = 0;

	if (infos == NULL)
		return (84);
	players = gest_error_args(ac, av, infos, players);
	if (players == NULL)
		return (84);
	ret = start_vm(players, infos);
	if (ret == 1) {
		ret = 0;
		my_putstr("No one won ...\n");
	}
	return (ret);
}
