/*
** EPITECH PROJECT, 2018
** free
** File description:
** dead
*/

#include "corewar.h"

players_t *free_dead(players_t *player, players_t *to_free)
{
	players_t *temp = player;

	for (; temp->next != to_free; temp = temp->next);
	temp->next = to_free->next;
	free(to_free->prog_name);
	free(to_free);
	return (temp->next);
}
