/*
** EPITECH PROJECT, 2018
** go_to
** File description:
** func
*/

#include "corewar.h"
#include "op.h"

void go_to_func_four(players_t *temp, unsigned char *arena)
{
	switch (arena[temp->pc]) {
	case 12:
		go_to_fork(temp, arena, 1);
		break;
	case 13:
		go_to_ld(temp, arena);
		break;
	case 14:
		go_to_ldi(temp, arena, 0);
		break;
	case 15:
		go_to_fork(temp, arena, 0);
		break;
	case 16:
		go_to_aff(temp, arena);
		break;
	default:
		temp->pc += 1;
		break;
	}
}

void go_to_func_three(players_t *temp, unsigned char *arena)
{
	switch (arena[temp->pc]) {
	case 8:
		go_to_comp(temp, arena, 2);
		break;
	case 9:
		go_to_zjmp(temp, arena);
		break;
	case 10:
		go_to_ldi(temp, arena, 1);
		break;
	case 11:
		go_to_sti(temp, arena);
		break;
	default:
		go_to_func_four(temp, arena);
		break;
	}
}

void go_to_func_two(players_t *temp, unsigned char *arena)
{
	switch (arena[temp->pc]) {
	case 4:
		go_to_add(temp, arena, 0);
		break;
	case 5:
		go_to_add(temp, arena, 1);
		break;
	case 6:
		go_to_comp(temp, arena, 0);
		break;
	case 7:
		go_to_comp(temp, arena, 1);
		break;
	default:
		go_to_func_three(temp, arena);
		break;
	}
}

int go_to_func_one(players_t *player, players_t *temp, unsigned char *arena,
	int nbr_live)
{
	switch (arena[temp->pc % MEM_SIZE]) {
	case 1:
		go_to_live(player, temp, arena);
		nbr_live++;
		break;
	case 2:
		go_to_ld(temp, arena);
		break;
	case 3:
		go_to_st(temp, arena);
		break;
	default:
		go_to_func_two(temp, arena);
		break;
	}
	return (nbr_live);
}
