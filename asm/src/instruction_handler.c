/*
** EPITECH PROJECT, 2017
** check_instruction.c
** File description:
** check_instruction.c
*/

#include "lexer.h"
#include "op_tab.h"
#include "minilibc.h"
#include <stdlib.h>

int verify_syntax_instruction(element_t *n, token_t *token,
int instruction_index)
{
	int i = 0;
	int j = 0;

	for (element_t *count = n; count->prev != NULL; count = count->prev,
	i++);
	if (i != op_tab[instruction_index].nbr_args)
		return (EXIT_ERROR);
	for (element_t *args = n; j < i; j++) {
		args = args->prev;
		token = (token_t *) args->data;
		char test = token->type & op_tab[instruction_index].type[j][0];
		if (test != token->type)
			return (EXIT_ERROR);
	}
	return (EXIT_SUCCESS);
}

int find_instruction(token_t *token)
{
	for (int i = 0; op_tab[i].nbr_cycles != 0; i++) {
		if (my_strcmp(op_tab[i].mnemonique, token->value))
			return (i);
	}
	return (-1);
}
