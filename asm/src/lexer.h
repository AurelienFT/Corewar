/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** lexer.h
*/

#ifndef LEXER_H
#define LEXER_H

#include "linked_list.h"

typedef struct token {
	char *value;
	unsigned char type;
} token_t;

linked_list_t *tokenize(char *statement);
int check_statement(const linked_list_t *statement);

#endif
