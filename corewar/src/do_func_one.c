/*
** EPITECH PROJECT, 2018
** fo_func
** File description:
** one
*/

#include "corewar.h"
#include "op.h"

void go_to_live(players_t *player, players_t *temp, unsigned char *arena)
{
	int arg = 0;

	temp->pc += 1;
	for (int i = 0; i < 4; temp->pc += 1, i++)
		arg = arg * 16 + arena[temp->pc];
	live(player, arg);
}

void go_to_ld(players_t *player, unsigned char *arena)
{
	int arg_one = 0;
	int arg_two = 0;
	int current_read = arena[player->pc + 1];
	int value = 0;

	player->pc += 2;
	if (current_read == 144)
		for (int i = 0; i < 4; i++, player->pc += 1)
			arg_one = arg_one * 16 + arena[player->pc
			% IDX_MOD % MEM_SIZE];
	else
		for (int i = 0; i < 2; i++, player->pc += 1)
			value = value * 16 + arena[player->pc
			% IDX_MOD % MEM_SIZE];
	arg_two = arena[player->pc % MEM_SIZE];
	if (current_read != 144)
		for (int i = 0; i < REG_SIZE; i++)
			arg_one = arg_one * 16 +
			arena[player->pc - 4 + i % IDX_MOD % MEM_SIZE];
	player->pc += 1;
	ld(player, arg_one, arg_two);
}

void go_to_st(players_t *player, unsigned char *arena)
{
	int arg_one = 0;
	int arg_two = 0;
	int current_read = arena[player->pc + 1 % MEM_SIZE];

	arg_one = arena[(player->pc + 2) % MEM_SIZE];
	player->pc += 3;
	if (current_read == 112)
		for (int i = 0; i < 2; i++, player->pc += 1)
			arg_two = arg_two * 16 + arena[player->pc % MEM_SIZE];
	else {
		arg_two = arena[player->pc % MEM_SIZE];
		player->pc += 1;
	}
	if (current_read == 112)
		st(player, arg_one, 0, &arena[(player->pc +
					arg_two) % IDX_MOD % MEM_SIZE]);
	else
		st(player, arg_one, arg_two, NULL);
}

void go_to_add(players_t *player, unsigned char *arena, char ind)
{
	int arg_one = arena[player->pc + 2 % MEM_SIZE];
	int arg_two = arena[player->pc + 3 % MEM_SIZE];
	int arg_three = arena[player->pc + 4 % MEM_SIZE];

	player->pc += 5;
	if (arg_one > 16 || arg_two > 16 || arg_three > 16 || arg_one
	< 1 || arg_two < 1 || arg_three < 1) {
		player->cycle = 10;
		player->carry = 0;
		return;
	}
	if (ind == 0)
		add_sub(player, player->registers[arg_one - 1] +
			player->registers[arg_two - 1], arg_three);
	if (ind == 1)
		add_sub(player, player->registers[arg_one - 1] -
			player->registers[arg_two - 1], arg_three);
}

void go_to_comp(players_t *player, unsigned char *arena, char ind)
{
	int arg_one = 0;
	int arg_two = 0;
	int arg_three = 0;
	int bytecode = arena[player->pc + 1 % MEM_SIZE];

	for (int i = 0; i < get_bytecode(bytecode, 1); i++, player->pc += 1)
		if (get_bytecode(bytecode, 1) == 1)
			arg_one = player->registers[arena[player->pc
							% MEM_SIZE]];
		else
			arg_one = arg_one * 16 + arena[player->pc % MEM_SIZE];
	for (int i = 0; i < get_bytecode(bytecode, 2); i++, player->pc += 1)
		if (get_bytecode(bytecode, 2) == 1)
			arg_two = player->registers[arena[player->pc
						% MEM_SIZE]];
		else
			arg_two = arg_two * 16 + arena[player->pc % MEM_SIZE];
	arg_three = arena[player->pc % MEM_SIZE];
	player->pc += 3;
	and_or_xor(player, comp(arg_one, arg_two, ind), arg_three);
}
