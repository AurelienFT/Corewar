/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** add_a_jump_label.c
*/

#include <stdlib.h>
#include "minilibc.h"
#include "asm.h"
#include "utils/utils.h"

static int count_instruction(linked_list_t *instruction)
{
	element_t *element = instruction->first;
	token_t *token;
	int count = 0;

	for (;element != NULL; element = element->next) {
		token = (token_t *) element->data;
		if (token->type == T_REG || (token->type == T_INSTRUCTION
		&& (my_strcmp(token->value, "live") || my_strcmp(token->value,
		"zjmp") || my_strcmp(token->value, "fork") || my_strcmp
		(token->value, "lfork"))))
			count += 1;
		if (token->type == T_DIR || token->type == T_A_DIRECT_LAB ||
		(token->type == T_INSTRUCTION && !my_strcmp(token->value,
		"live") && !my_strcmp(token->value, "zjmp") && !my_strcmp
		(token->value, "fork") && !my_strcmp(token->value, "lfork")))
			count += 2;
		if (token->type == T_IND || token->type == T_A_IND_LAB ||
		token->type == T_A_LAB_INDEX || token->type == T_DIR_INDEX)
			count += 4;
	}
	return (count);
}

static int to_start_label(element_t *n, char *label)
{
	int space = 0;
	element_t *to_start = n->next;
	linked_list_t *linked;
	element_t *element;
	token_t *token;

	while (to_start != NULL) {
		linked = (linked_list_t *) to_start->data;
		space = space + count_instruction(linked);
		element = linked->last;
		token = (token_t *) element->data;
		if (my_strcmp(token->value, label)) {
			return (-(space + 2));
		}
		to_start = to_start->next;
	}
	return (0);
}

int get_space_label(element_t *n, char *label)
{
	int space = 0;
	element_t *to_end = n->prev;
	linked_list_t *linked;
	element_t *element;
	token_t *token;

	while (to_end != NULL) {
		linked = (linked_list_t *) to_end->data;
		space = space + count_instruction(linked);
		element = linked->last;
		token = (token_t *) element->data;
		if (my_strcmp(token->value, label)) {
			return (space + 1);
		}
		to_end = to_end->prev;
	}
	space = to_start_label(n, label);
	return (space);
}

code_t *add_ind_lab(token_t *token, code_t *code, element_t *n)
{
	char *label = malloc(sizeof(char) * my_strlen(token->value) + 2);
	unsigned short space;

	token->value++;
	code = my_realloc_unsigned(code, 2);
	if (label == NULL || code == NULL)
		return (NULL);
	code->length += 2;
	label[my_strlen(token->value) + 1] = '\0';
	label = my_strcpy(label, token->value);
	label[my_strlen(token->value)] = ':';
	space = (unsigned short) get_space_label(n, label);
	if (space == 0)
		return (NULL);
	code->code[code->length - 1] = (unsigned char) space;
	code->code[code->length - 2] = (unsigned char) ((space >> 8) & 0xff);
	return (code);
}

code_t *add_jump_label(token_t *token, code_t *code, element_t *n)
{
	switch (token->type) {
		case T_A_IND_LAB:
			code = add_ind_lab(token, code, n);
			break;
		case T_A_LAB_INDEX:
			code = add_ind_lab(token, code, n);
			break;
		case T_A_DIRECT_LAB:
			code = add_direct_lab(token, code, n);
			break;
		default:
			break;
	}
	return (code);
}
