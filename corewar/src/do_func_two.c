/*
** EPITECH PROJECT, 2018
** do_func
** File description:
** twu
*/

#include "corewar.h"
#include "op.h"

void go_to_zjmp(players_t *player, unsigned char *arena)
{
	int arg = (signed char) arena[player->pc + 1] *
	16 + (signed char) arena[player->pc + 2];

	if (arena[player->pc + 1] == 255)
		arg += 16;
	zjmp(player, arg);
}

void go_to_ldi(players_t *player, unsigned char *arena, char ind)
{
	int arg_one = 0;
	int bytecode = arena[player->pc + 1];
	int i = get_bytecode(bytecode, 1);
	int s = 0;

	player->pc += 2;
	for (int j = 0; j < i && j < 2; j++, player->pc += 1)
		if (i == 1)
			arg_one = player->registers[arena[player->pc]];
		else
			arg_one = arg_one * 16 + arena[player->pc];
	if (ind == 0)
		for (int i = 0; i < IND_SIZE; i++)
			s = s * 16 + arena[(player->pc + arg_one)
			% MEM_SIZE];
	else
		for (int i = 0; i < IND_SIZE; i++)
			s = s * 16 + arena[(player->pc + IND_SIZE +
			arg_one % IDX_MOD) % MEM_SIZE];
	go_to_ldi_two(player, arena, bytecode, s);
}

void go_to_sti(players_t *player, unsigned char *arena)
{
	int arg_two = 0;
	int arg_three = 0;
	int bytecode = arena[player->pc + 1];
	int i = get_bytecode(bytecode, 2);
	int arg_one = player->registers[arena[player->pc + 2] - 1];
	int pc = 3;

	if (i == 4)
		i = 2;
	for (int j = 0; j < i; j++, pc++)
		if (i == 1)
			arg_two = player->registers[arena[
				player->pc + pc] - 1];
		else
			arg_two = arg_two * 16 + arena[player->pc + pc];
	arg_three = go_to_sti_two(player, arena, bytecode, &pc);
	sti(player, arena, arg_one, arg_two + arg_three);
	player->pc += pc;
}

void go_to_fork(players_t *player, unsigned char *arena, char ind)
{
	int arg = arena[player->pc + 1] * 16 + arena[player->pc + 2];

	forkk(player, arg, ind);
	player->pc += 3;
}

void go_to_aff(players_t *player, unsigned char *arena)
{
	int arg = arena[player->pc + 2];

	player->pc += 3;
	aff(player, arg);
}
