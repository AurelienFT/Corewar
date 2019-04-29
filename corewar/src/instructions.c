/*
** EPITECH PROJECT, 2018
** instructions
** File description:
** 5 firsts
*/

#include "corewar.h"

void live(players_t *player, int player_number)
{
	players_t *temp = player;
	char player_nbr;

	for (; temp && temp->prog_number != player_number; temp = temp->next);
	if (!temp)
		return;
	my_putstr("player ");
	player_nbr = temp->prog_number + '0';
	write(1, &player_nbr, 1);
	my_putstr(" (");
	my_putstr(temp->prog_name);
	my_putstr(") is alive\n");
	temp->alive = 1;
	temp->cycle = 10;
}

void ld(players_t *player, int value, char reg)
{
	player->registers[(int) reg - 1] = value;
	player->carry = 1;
	player->cycle = 5;
}

void st(players_t *player, char reg_one, char reg_two, unsigned char *ind)
{
	if (ind == NULL)
		player->registers[(int) reg_two - 1] =
		player->registers[(int) reg_one - 1];
	else
		ind[0] = player->registers[(int) reg_one - 1];
	player->cycle = 5;
}

void add_sub(players_t *player, char to_add, char dest)
{
	player->registers[(int) dest - 1] = to_add;
	player->carry = 1;
	player->cycle = 10;
}

void and_or_xor(players_t *player, char ret, char dest)
{
	if (dest < 1 || dest > 16) {
		player->carry = 0;
		player->cycle = 6;
		return;
	}
	player->registers[(int)dest] = ret;
	player->carry = 1;
	player->cycle = 6;
}
