/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** Parsing functions
*/

#include "stdlib.h"
#include "linked_list.h"
#include "asm.h"
#include "lexer.h"

int check_syntax(linked_list_t *statement)
{
	token_t *token = (token_t *) statement->last->data;
	element_t *n = statement->last;
	int instruction_index = 0;

	if (token->type == T_TO_LAB) {
		if (n->prev == NULL)
			return (EXIT_SUCCESS);
		else {
			n = n->prev;
			token = (token_t *) n->data;
		}
	}
	if (token->type != T_INSTRUCTION)
		return (EXIT_ERROR);
	instruction_index = find_instruction(token);
	if (instruction_index == -1)
		return (EXIT_ERROR);
	if (verify_syntax_instruction(n, token, instruction_index) == 84)
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

int check_unknown(linked_list_t *statement)
{
	token_t *token = (token_t *) statement->last->data;
	element_t *n = statement->last;

	while (n != NULL) {
		if (token->type == T_UNKNOWN)
			return (EXIT_ERROR);
		n = n->prev;
		if (n == NULL)
			return (EXIT_SUCCESS);
		token = (token_t *) n->data;
	}
	return (EXIT_SUCCESS);
}

linked_list_t *parse(linked_list_t *statement, linked_list_t *statements)
{
	if (statements == NULL) {
		statements = init_list();
		if (statements == NULL)
			return (NULL);
	}
	put_in_list(statements, statement);
	return (statements);
}

linked_list_t *fill_statements(char *s, linked_list_t *statements)
{
	linked_list_t *statement;

	statement = tokenize(s);
	if (statement == NULL ||
	check_statement(statement) == EXIT_ERROR || check_unknown(statement)
	== EXIT_ERROR || check_syntax(statement) == EXIT_ERROR) {
		return (NULL);
	}
	statements = parse(statement, statements);
	return (statements);
}
