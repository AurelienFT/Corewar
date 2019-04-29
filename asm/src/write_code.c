/*
** EPITECH PROJECT, 2017
** write_code.c
** File description:
** write_code.c
*/

#include "asm.h"
#include <stdlib.h>
#include "unistd.h"
#include "minilibc.h"
#include "lexer.h"

static code_t *get_code_string(element_t *n, linked_list_t *statement,
element_t *instruction)
{
	code_t *code = malloc(sizeof(code_t));

	if (code == NULL)
		return (NULL);
	code->code = malloc(sizeof(unsigned char) * 1);
	if (code->code == NULL)
		return (NULL);
	code->code[0] = '\0';
	code->length = 0;
	while (n != NULL) {
		code = add_instruction(instruction, code, n);
		if (code == NULL)
			return (NULL);
		n = n->prev;
		if (n != NULL) {
			statement = (linked_list_t *) n->data;
			instruction = statement->last;
		}
	}
	return (code);
}

static code_t *get_instructions(linked_list_t *statements)
{
	element_t *n = statements->last;
	linked_list_t *statement = (linked_list_t *) n->data;
	element_t *instruction = statement->last;
	token_t *token = (token_t *) instruction->data;
	code_t *code;

	if (token->type == T_TO_LAB) {
		if (instruction->prev == NULL) {
			n = n->prev;
			statement = (linked_list_t *) n->data;
			instruction = statement->last;
		} else
			instruction = instruction->prev;
	}
	code = get_code_string(n, statement, instruction);
	return (code);
}

static int write_header(header_t *header, int fd, code_t *code)
{
	char cha = 0;
	unsigned int magic = little_to_big_endian(COREWAR_EXEC_MAGIC);
	unsigned int length = 0;

	if (code != NULL)
		length = little_to_big_endian((int) code->length);
	write(fd, &magic, sizeof(int));
	write(fd, header->prog_name, my_strlen(header->prog_name));
	for (int i = 0; i < PROG_NAME_LENGTH - my_strlen(header->prog_name) + 4;
	i++)
		write(fd, &cha, 1);
	write(fd, &length, sizeof(int));
	for (int i = 0; header->comment[i] != '\0'; i++)
		write(fd, &header->comment[i], 1);
	for (int i = 0; i < COMMENT_LENGTH - my_strlen(header->comment) + 4;
	i++)
		write(fd, &cha, 1);
	return (0);
}

int get_code(header_t *header, linked_list_t *statements, int fd)
{
	code_t *code = NULL;

	if (statements->last != NULL) {
		code = get_instructions(statements);
		if (code == NULL) {
			close(fd);
			return (84);
		}
	}
	write_header(header, fd, code);
	if (code != NULL) {
		write(fd, code->code, code->length);
		free(code->code);
		free(code);
	}
	close(fd);
	free_statements(statements);
	return (0);
}
