/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** manage_error_instruction
*/

#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"
#include "asm.h"
#include "minilibc.h"
#include "op_tab.h"

static int error_indirect(token_t *token)
{
	if (is_num(token->value) == 0)
		token->type = T_UNKNOWN;
	return (0);
}

static int error_direct(token_t *token)
{
	if (is_num(token->value + 1) == 0)
		token->type = T_UNKNOWN;
	return (0);
}

static int error_register(token_t *token)
{
	if (my_strlen(token->value) != 3 && my_strlen(token->value) != 2) {
		token->type = T_UNKNOWN;
		return (0);
	}
	if (my_atoi(token->value + 1) > REG_NUMBER ||
	my_atoi(token->value + 1) < 1)
		token->type = T_UNKNOWN;
	return (0);
}

static int error_instruction(token_t *token)
{
	int check = 0;

	for (int i = 0; op_tab[i].mnemonique != 0 && check == 0; i++)
		if (my_strcmp(token->value, op_tab[i].mnemonique) == 1) {
			check = 1;
		}
	if (check == 0)
		token->type = T_UNKNOWN;
	return (0);
}

int check_statement(const linked_list_t *statement)
{
	element_t *tmp = statement->last;
	token_t *token;

	for (; tmp != NULL; tmp = tmp->prev) {
		token = (token_t *)tmp->data;
		switch (token->type) {
		case T_INSTRUCTION:
			error_instruction(token);
			break;
		case T_REG:
			error_register(token);
			break;
		case T_DIR:
			error_direct(token);
			break;
		case T_IND:
			error_indirect(token);
		}
	}
	return (0);
}
