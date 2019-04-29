/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "asm.h"
#include "lexer.h"
#include <fcntl.h>

Test(basic, test_instruction)
{
	linked_list_t *tokens = tokenize("live %1");
	element_t *element = tokens->last;
	token_t *token = (token_t *) element->data;

	cr_assert_eq(token->type, 16, "Find a instruction");
}

Test(basic, a_argument)
{
	linked_list_t *tokens = tokenize("live %1");
	element_t *element = tokens->last->prev;
	token_t *token = (token_t *) element->data;

	token = (token_t *) element->data;
	cr_assert_eq(token->type, 2, "Find the first argument : direct");
}

Test(basic, get_progname)
{
	header_t *header = malloc(sizeof(header_t));
	int fd = open("asm/tests/header.s", O_RDONLY);

	get_header(fd, header);
	cr_assert_str_eq("aurelien", header->prog_name, "Get progname");
}

Test(basic, get_comment)
{
	header_t *header = malloc(sizeof(header_t));
	int fd = open("asm/tests/header.s", O_RDONLY);

	get_header(fd, header);
	cr_assert_str_eq("Best champion", header->comment, "Get comment");
}
