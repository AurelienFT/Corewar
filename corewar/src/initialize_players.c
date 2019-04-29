/*
** EPITECH PROJECT, 2018
** init
** File description:
** players
*/

#include <fcntl.h>
#include <stdlib.h>
#include "op.h"
#include "corewar.h"

int player_pc(int place, int load_adress, int nbr_player)
{
	if (load_adress == -1)
		return (MEM_SIZE / nbr_player * place);
	return (load_adress);
}

int set_player(players_t *player, int nbr_player)
{
	static int place = 0;

	player->pc = player_pc(place, player->load_address, nbr_player);
	player->registers = malloc(sizeof(REG_SIZE) * (REG_NUMBER + 1));
	if (player->registers == NULL)
		return (84);
	player->carry = 0;
	for (int i = 0; i < REG_NUMBER; i++)
		player->registers[i] = 0;
	player->registers[0] = player->prog_number;
	player->alive = 0;
	player->last_live = 0;
	player->cycle = 0;
	place++;
	return (0);
}

int get_current_player(players_t *player)
{
	int ret = 1;
	players_t *temp = player;

	while (1) {
		for (; temp && temp->prog_number != ret; temp = temp->next);
		if (!temp)
			return (ret);
		ret++;
	}
}

int create_all_players(players_t *player)
{
	players_t *temp = player;

	for (; temp; temp = temp->next) {
		if (temp->prog_number == -1)
			temp->prog_number = get_current_player(player);
		if (set_player(temp, temp->prog_number) == 84)
			return (84);;
	}
	return (0);
}

int initialize_player(players_t *args)
{
	players_t *temp = args;
	int nbr_player = 0;

	for (; temp != NULL; temp = temp->next, nbr_player++);
	if (nbr_player > 4) {
		my_putstr("The number of champion load is above the limit.\n");
		return (84);
	}
	return (create_all_players(args) == 84);
}
