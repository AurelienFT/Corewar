/*
** EPITECH PROJECT, 2017
** add_direct_lab.c
** File description:
** add_direct_lab.c
*/

#include <stdlib.h>
#include "minilibc.h"
#include "asm.h"
#include "utils/utils.h"

code_t *add_direct_lab(token_t *token, code_t *code, element_t *n)
{
	char *label = malloc(sizeof(char) * my_strlen(token->value) + 2);
	int space;
	unsigned char res_temp;

	token->value++;
	code = my_realloc_unsigned(code, 4);
	if (label == NULL || code == NULL)
		return (NULL);
	code->length += 4;
	label[my_strlen(token->value) + 1] = '\0';
	label = my_strcpy(label, token->value);
	label[my_strlen(token->value)] = ':';
	space = get_space_label(n, label);
	if (space == 0)
		return (NULL);
	for (int i = 0; i < 4; i++) {
		res_temp = (unsigned char) (space & 0xFF);
		space = space >> 8;
		code->code[code->length - i - 1] = res_temp;
	}
	return (code);
}
