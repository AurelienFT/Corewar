/*
** EPITECH PROJECT, 2017
** add_args.c
** File description:
** add_args.c
*/

#include "lexer.h"
#include "asm.h"
#include "utils/utils.h"
#include "minilibc.h"

code_t *add_register(code_t *code, token_t *token)
{
	code = my_realloc_unsigned(code, 1);
	if (code == NULL)
		return (NULL);
	code->length += 1;
	code->code[code->length - 1] =
		(unsigned char) my_getnbr(token->value + 1);
	return (code);
}

code_t *add_direct(code_t *code, token_t *token)
{
	int res = my_getnbr(token->value);
	unsigned char res_temp;

	code = my_realloc_unsigned(code, 4);
	if (code == NULL)
		return (NULL);
	code->length += 4;
	for (int i = 0; i < 4; i++) {
		res_temp = (unsigned char) (res & 0xFF);
		res = res >> 8;
		code->code[code->length - i - 1] = res_temp;
	}
	return (code);
}

code_t *add_indirect(code_t *code, token_t *token)
{
	unsigned short res = (unsigned short) my_getnbr(token->value);

	code = my_realloc_unsigned(code, 2);
	if (code == NULL)
		return (NULL);
	code->length += 2;
	code->code[code->length - 1] = (unsigned char) res;
	code->code[code->length - 2] = (unsigned char) ((res >> 8) & 0xff);
	return (code);
}
