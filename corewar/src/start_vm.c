/*
** EPITECH PROJECT, 2018
** start
** File description:
** vm
*/

#include "corewar.h"

int test_prog_number(int prog_number, players_t *player)
{
	players_t *temp = player;
	int i = 0;

	for (; temp; temp = temp->next)
		if (prog_number == temp->prog_number)
			i++;
	if (i >= 2) {
		my_putstr("double definition of prog_number\n");
		return (84);
	}
	return (0);
}

int test_players(players_t *player)
{
	players_t *temp = player;

	for (; temp; temp = temp->next)
		if (test_prog_number(temp->prog_number, player) == 84)
			return (84);
	return (0);
}

int start_vm(players_t *player, infos_t *infos)
{
	unsigned char *arena;

	if (initialize_player(player) == 84)
		return (84);
	if (test_players(player) == 84)
		return (84);
	arena = initialize_map(player);
	if (arena == NULL)
		return (84);
	return (vm_loop(arena, player, infos));
}
