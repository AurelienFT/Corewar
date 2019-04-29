/*
** EPITECH PROJECT, 2017
** corewar
** File description:
** get_bytecode.c
*/

#include <stdlib.h>
#include "asm.h"
#include "utils/utils.h"
#include "op_tab.h"
#include "minilibc.h"

static code_t *add_arg(token_t *token, code_t *code)
{
	switch (token->type) {
		case T_REG:
			code = add_register(code, token);
			break;
		case T_DIR:
			code = add_direct(code, token);
			break;
		case T_IND:
			code = add_indirect(code, token);
			break;
		case T_DIR_INDEX:
			code = add_indirect(code, token);
			break;
		default:
			break;
	}
	return (code);
}

static code_t *add_args(element_t *instruction, int i, code_t
*code, element_t *n)
{
	token_t *token;

	for (int j = 0; instruction != NULL; j++) {
		token = (token_t *) instruction->data;
		if (op_tab[i].type[j][1] == 1 && token->type == T_DIR)
			token->type = T_DIR_INDEX;
		if (op_tab[i].type[j][1] == 1 && token->type == T_A_DIRECT_LAB)
			token->type = T_A_LAB_INDEX;
		if (token->type != T_A_DIRECT_LAB && token->type !=
			T_A_IND_LAB && token->type != T_A_LAB_INDEX)
			code = add_arg(token, code);
		else
			code = add_jump_label(token, code, n);
		if (code == NULL)
			return (NULL);
		instruction = instruction->prev;
	}
	return (code);
}

static unsigned char get_bytecode_number(element_t *instruction)
{
	unsigned char bytecode = 0;
	element_t *arg = instruction->prev;

	for (int i = 0; arg != NULL; arg = arg->prev, i++) {
		add_bytecode(i, &bytecode, arg);
	}
	return (bytecode);
}

code_t *add_instruction(element_t *instruction, code_t *code,
element_t *n)
{
	int i = 0;

	i = find_instruction((token_t *)instruction->data);
	if (i == -1)
		return (NULL);
	if (i == 0 || i == 8 || i == 11 || i == 14) {
		code = my_realloc_unsigned(code, 1);
		if (code == NULL)
			return (NULL);
		code->length += 1;
		code->code[code->length - 1] = op_tab[i].code;
	} else {
		code = my_realloc_unsigned(code, 2);
		if (code == NULL)
			return (NULL);
		code->length += 2;
		code->code[code->length - 2] = op_tab[i].code;
		code->code[code->length - 1] = get_bytecode_number(instruction);
	}
	code = add_args(instruction->prev, i, code, n);
	return (code);
}

void add_bytecode(int i, unsigned char *bytecode, element_t *arg)
{
	unsigned char tab_possiblities_number[5][2] = {{T_REG, 64}, {T_DIR,
	128}, {T_A_DIRECT_LAB, 128}, {T_IND, 192}, {T_A_IND_LAB, 192}};
	token_t *token = (token_t *) arg->data;

	for (; i != 0; i--) {
		for (int j = 0; j < 5; j++) {
			tab_possiblities_number[j][1] = tab_possiblities_number
			[j][1] >> 2;
		}
	}
	for (int j = 0; j < 5; j++) {
		if (tab_possiblities_number[j][0] == token->type)
			*bytecode = *bytecode + tab_possiblities_number[j][1];
	}
}
