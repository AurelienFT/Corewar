/*
** EPITECH PROJECT, 2018
** instruc
** File description:
** tions
*/

#include "corewar.h"
#include "op.h"

void zjmp(players_t *player, int ind)
{
	if (player->carry == 1)
		player->pc = player->pc + ind % IDX_MOD;
	player->cycle = 20;
}

void ldi(players_t *player, unsigned char *arena, int* indexes, char ind)
{
	int s = indexes[0];

	s += 4;
	if (ind == 0)
		player->registers[indexes[2]] = arena[(player->pc
						+ s % IDX_MOD) % MEM_SIZE];
	else
		player->registers[indexes[2]] =	arena[(player->pc
						+ s) % MEM_SIZE];
	player->carry = 1;
	player->cycle = 10 * (ind * 2);
}

void sti(players_t *player, unsigned char *arena, int res, int place)
{
	int j = 3;
	unsigned char res_temp;

	for (int i = 0; i < 4; i++, j--) {
		res_temp = (unsigned char) (res & 0xFF);
		res = res >> 8;
		arena[(player->pc +
		place % IDX_MOD) % MEM_SIZE + j] = res_temp;
	}
	player->cycle = 25;
}

void forkk(players_t *player, int place, char ind)
{
	players_t *temp = player;
	players_t *new = malloc(sizeof(players_t));

	if (!new)
		return;
	player->cycle = 800 + (ind * 2 * 100);
	fill_new_fork(new, player);
	if (ind == 0)
		new->pc = (player->pc + place) % MEM_SIZE;
	if (ind == 1)
		new->pc	= (player->pc + place) % IDX_MOD % MEM_SIZE;
	for (; temp->next; temp = temp->next);
	temp->next = new;
}

void aff(players_t *player, char reg)
{
	char to_print = player->registers[(int)reg - 1] % 256;

	player->cycle = 2;
	write(1, &to_print, 1);
}
