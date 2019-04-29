/*
** EPITECH PROJECT, 2018
** go_to
** File description:
** ldi
*/

#include "corewar.h"

void fill_new_fork(players_t *new, players_t *player)
{
	new->alive = 0;
	new->last_live = 0;
	new->prog_number = player->prog_number;
	new->prog_name = player->prog_name;
	new->pc = player->pc;
	new->cycle = player->cycle;
	new->next = NULL;
	new->registers = malloc(sizeof(int) * 16);
	if (!new->registers)
		return;
	for (int i = 0; i < 16; ++i)
		new->registers[i] = player->registers[i];
}

int comp(int arg_one, int arg_two, char ind)
{
	if (ind == 0)
		return (arg_one & arg_two);
	if (ind == 1)
		return (arg_one | arg_two);
	if (ind == 2)
		return (arg_one ^ arg_two);
	return (0);
}

int go_to_sti_two(players_t *player,
		unsigned char *arena, int bytecode, int *pc)
{
	int ret = 0;
	int i = get_bytecode(bytecode, 3);

	if (i == 4)
		i = 2;
	for (int j = 0; j < i; j++, pc[0] += 1)
		if (i == 1)
			ret = player->registers[arena[player->pc] + *pc];
		else
			ret = ret * 16 + arena[player->pc + *pc];
	return (ret);
}

void go_to_ldi_two(players_t *player, unsigned char *arena,
		int bytecode, int arg_one)
{
	int args[3] = {arg_one, 0, 0};
	int i = get_bytecode(bytecode, 2);

	if (i == 4)
		i = 2;
	for (int j = 0; j < i; j++, player->pc += 1)
		if (i == 1)
			args[1] = player->registers[arena[player->pc]];
		else
			args[1] = args[1] * 16 + arena[player->pc];
	args[2] = arena[player->pc];
	player->pc += 1;
	ldi(player, arena, args, 0);
}
