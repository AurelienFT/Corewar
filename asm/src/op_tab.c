/*
** EPITECH PROJECT, 2017
** op_tab.c
** File description:
** op_tab.c
*/

#include "asm.h"

op_t op_tab[] =
{
	{"live", 1, {{T_DIR, 0}}, 1, 10, "alive"},
	{"ld", 2, {{T_DIR | T_IND | T_A_DIRECT_LAB | T_A_IND_LAB, 0}, {T_REG,
	0}}, 2, 5, "load"},
	{"st", 2, {{T_REG, 0}, {T_IND | T_A_IND_LAB | T_REG, 0}}, 3, 5,
	"store"},
	{"add", 3, {{T_REG, 0}, {T_REG, 0}, {T_REG, 0}}, 4, 10, "addition"},
	{"sub", 3, {{T_REG, 0}, {T_REG, 0}, {T_REG, 0}}, 5, 10, "soustraction"},
	{"and", 3, {{T_REG | T_DIR | T_IND | T_A_DIRECT_LAB | T_A_IND_LAB, 0}
	, {T_REG | T_IND | T_DIR | T_A_DIRECT_LAB | T_A_IND_LAB, 0}, {T_REG,
	0}}, 6, 6, "et (and  r1, r2, r3   r1&r2 -> r3"},
	{"or", 3, {{T_REG | T_DIR | T_IND | T_A_DIRECT_LAB | T_A_IND_LAB, 0}
	, {T_REG | T_IND | T_DIR | T_A_DIRECT_LAB | T_A_IND_LAB, 0}, {T_REG,
	0}}, 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
	{"xor", 3, {{T_REG | T_DIR | T_IND | T_A_DIRECT_LAB | T_A_IND_LAB, 0}
	, {T_REG | T_IND | T_DIR | T_A_DIRECT_LAB | T_A_IND_LAB, 0}, {T_REG,
	0}}, 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3"},
	{"zjmp", 1, {{T_DIR | T_A_DIRECT_LAB, 1}}, 9, 20, "jump if zero"},
	{"ldi", 3, {{T_REG | T_DIR | T_IND | T_A_DIRECT_LAB | T_A_IND_LAB, 1},
	{T_DIR | T_REG, 1}, {T_REG, 0}}, 10, 25, "load index"},
	{"sti", 3, {{T_REG, 0}, {T_REG | T_DIR | T_A_DIRECT_LAB | T_IND |
	T_A_IND_LAB , 1}, {T_DIR | T_REG | T_A_DIRECT_LAB, 1}}, 11, 25,
	"store index"},
	{"fork", 1, {{T_DIR | T_A_DIRECT_LAB, 1}}, 12, 800, "fork"},
	{"lld", 2, {{T_DIR | T_IND | T_A_DIRECT_LAB | T_A_IND_LAB, 0},
	{T_REG, 0}}, 13, 10, "long load"},
	{"lldi", 3, {{T_REG | T_DIR | T_IND | T_A_DIRECT_LAB | T_A_IND_LAB, 1},
	{T_DIR | T_REG | T_A_DIRECT_LAB, 1}, {T_REG, 0}}, 14, 50,
	"long load index"},
	{"lfork", 1, {{T_DIR | T_A_DIRECT_LAB, 1}}, 15, 1000, "long fork"},
	{"aff", 1, {{T_REG, 0}}, 16, 2, "aff"},
	{0, 0, {{0, 0}}, 0, 0, 0}
};
