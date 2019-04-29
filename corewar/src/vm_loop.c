/*
** EPITECH PROJECT, 2018
** vm 
** File description:
** loop
*/

#include "corewar.h"
#include "op.h"

int reduce_cycle(int *nbr_live, int reduced_cycle)
{
	if (*nbr_live == NBR_LIVE) {
		*nbr_live = 0;
		return (reduced_cycle + 1);
	}
	return (reduced_cycle);
}

int how_much_alive(players_t *player, int *nbr_cycle)
{
	players_t *temp = player;
	int i = 0;

	*nbr_cycle = 0;
	for (; temp; temp = temp->next)
		if (temp->alive == 1) {
			i++;
			temp->last_live = temp->alive;
			temp->alive = 0;
		} else
			temp->last_live = 0;
	return (i);
}

int go_to_func(players_t *players, int nbr_live, unsigned char *arena)
{
	players_t *temp = players;
	static int i = 0;

	for (; temp; temp = temp->next) {
		temp->pc = temp->pc % MEM_SIZE;
		if (temp->cycle != 0) {
			temp->cycle -= 1;
		} else
			nbr_live = go_to_func_one(players,
						temp, arena, nbr_live);
	}
	i++;
	return (nbr_live);
}

void dump_memory(unsigned char *arena, infos_t *infos, int nbr_cycle)
{
	if (infos->nbr_cycles == 0 || nbr_cycle == 0 ||
	infos->nbr_cycles != nbr_cycle)
		return;
	for (int i = 0; i < MEM_SIZE; i++) {
		my_puthexa(arena[i], "0123456789ABCDEF");
		write(1, " ", 1);
		if (i != 0 && i % 32 == 0)
			write(1, "\n", 1);
	}
	write(1, "\n\n", 2);
}

int vm_loop(unsigned char *map, players_t *player, infos_t *infos)
{
	int nbr_player_live = 4;
	int nbr_live = 0;
	int reduced_cycle = 0;
	int nbr_cycle = 0;
	players_t *t = player;

	while (nbr_player_live > 1) {
		if (CYCLE_TO_DIE - (CYCLE_DELTA * reduced_cycle) <= nbr_cycle)
			nbr_player_live = how_much_alive(player, &nbr_cycle);
		dump_memory(map, infos, nbr_cycle);
		nbr_live = go_to_func(player, nbr_live, map);
		reduced_cycle = reduce_cycle(&nbr_live, reduced_cycle);
		nbr_cycle++;
	}
	for (; t && t->last_live != 1; t = t->next);
	if (!t)
		return (1);
	my_putstr("player ");
	my_putnbr(t->prog_number);
	my_putstr(" won\n");
	return (0);
}
