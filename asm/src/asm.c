/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** Compilo functions
*/

#include <stdlib.h>
#include <stdio.h>
#include "minilibc.h"
#include "get_next_line.h"
#include "asm.h"
#include "linked_list.h"
#include "parser.h"
#include "lexer.h"
#include "err.h"
#include "utils/utils.h"

static int get_name(const int fd, char *ptr)
{
	char *s = get_next_line(fd);
	int return_value = 0;

	while (s != NULL && ptr[0] == '\0') {
		return_value = add_name(s, ptr);
		if (return_value == EXIT_SUCCESS) {
			free(s);
			return (EXIT_SUCCESS);
		} else if (return_value == EXIT_ERROR) {
			free(s);
			return (EXIT_ERROR);
		}
		free(s);
		s = get_next_line(fd);
	}
	return (EXIT_ERROR);
}

static int get_comment(const int fd, char *ptr)
{
	char *s = get_next_line(fd);
	int return_value = 0;

	while (s != NULL) {
		return_value = add_comment(s, ptr);
		if (return_value == EXIT_SUCCESS) {
			return (EXIT_SUCCESS);
		} else if (return_value == EXIT_ERROR) {
			free(s);
			return (EXIT_ERROR);
		}
		free(s);
		s = get_next_line(fd);
	}
	return (EXIT_ERROR);
}

int get_header(const int fd, header_t *header_ptr)
{
	header_ptr->prog_name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
	header_ptr->comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1));
	if (header_ptr->prog_name == NULL || header_ptr->comment == NULL)
		return (EXIT_ERROR);
	for (int i = 0; i < PROG_NAME_LENGTH + 1; i++)
		header_ptr->prog_name[i] = '\0';
	for (int i = 0; i < COMMENT_LENGTH + 1; i++)
		header_ptr->comment[i] = '\0';
	err_if(get_name(fd, header_ptr->prog_name), EXIT_ERROR, NAME_ERROR, "");
	err_if(get_comment(fd, header_ptr->comment), EXIT_ERROR,
	NO_COMMENT_WARN, "\n");
	return (EXIT_SUCCESS);
}

int get_statements(const int fd, linked_list_t *statements)
{
	char *s;

	s = get_next_line(fd);
	while (s != NULL) {
		if (s[0] != '\0')
			s = clean_str(s);
		if (s[0] != '\0' && is_comment(s) == 0)
			statements = fill_statements(s, statements);
		if (statements == NULL) {
			free(s);
			return (EXIT_ERROR);
		}
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	return (EXIT_SUCCESS);
}
