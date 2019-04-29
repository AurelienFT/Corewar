/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** lexer
*/

#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"
#include "minilibc.h"
#include "asm.h"

static void find_type(token_t *data)
{
	switch (data->value[0])	{
	case 'r':
		data->type = T_REG;
		break;
	case DIRECT_CHAR:
		if (data->value[1] == LABEL_CHAR)
			data->type = T_A_DIRECT_LAB;
		else
			data->type = T_DIR;
		break;
	default:
		if (data->value[0] <= '9' && data->value[0] >= '0')
			data->type = T_IND;
		else if (data->value[0] == ':')
			data->type = T_A_IND_LAB;
		else
			data->type = T_UNKNOWN;
		break;
	}
}

static void add_type(linked_list_t *tokens)
{
	element_t *n = tokens->last;
	token_t *data;

	if (n == NULL)
		return;
	data = (token_t *)n->data;
	if (data->value[my_strlen(data->value) - 1] == LABEL_CHAR) {
		data->type = T_TO_LAB;
		if (n->prev != NULL) {
			n = n->prev;
			data = (token_t *) n->data;
		} else
			return;
	}
	data->type = T_INSTRUCTION;
	if (n->prev != NULL)
		n = n->prev;
	for (; n != NULL; n = n->prev) {
		data = (token_t *)n->data;
		find_type(data);
	}
}

static int add_value(linked_list_t *tokens, char *keyword)
{
	token_t *token = malloc(sizeof(token_t));

	if (token == NULL)
		return (EXIT_ERROR);
	token->value = keyword;
	put_in_list(tokens, token);
	return (EXIT_SUCCESS);
}

linked_list_t *tokenize(char *statement)
{
	linked_list_t *tokens = init_list();
	char **keywords = my_str_to_word_array(statement, " ,");

	if (tokens == NULL || keywords == NULL)
		return (NULL);
	for (int i = 0; keywords[i] != NULL; i++) {
		if (add_value(tokens, keywords[i]) == EXIT_ERROR)
			return (NULL);
	}
	add_type(tokens);
	free(keywords);
	return (tokens);
}
