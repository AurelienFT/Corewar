/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** frees
*/

#include "asm.h"
#include "lexer.h"
#include <stdlib.h>

static void free_instruction(element_t *instruction)
{
	element_t *save_2;
	token_t *token;

	for (; instruction != NULL; instruction = instruction->prev) {
		token = (token_t *) instruction->data;
		free(token->value);
		free(token);
		free(instruction->next);
		if (instruction->prev == NULL)
			save_2 = instruction;
	}
	free(save_2);
}

void free_statements(linked_list_t *statements)
{
	linked_list_t *line;
	element_t *n = statements->last;
	element_t *instruction;

	for (; n != NULL; n = n->prev) {
		line = (linked_list_t *)n->data;
		instruction = line->last;
		free_instruction(instruction);
		free(line);
		free(n->next);
	}
	free(statements);
}
