/*
** EPITECH PROJECT, 2017
** add_infos.c
** File description:
** add_infos.c
*/

#include <stdlib.h>
#include "minilibc.h"
#include "asm.h"
#include "utils/utils.h"

char *get_key_value(char *s, char *key, char *res)
{
	int i = 0;

	res[i] = '\0';
	res[i + 1] = '\0';
	for (; s[i] == key[i]; i++);
	i++;
	if (s[i] == '"')
		s++;
	else {
		return (NULL);
	}
	for (int j = 0; s[i] != '"' && s[i] != '\0'; i++, j++)
		res[j] = s[i];
	if (s[i] == '\0' || (s[i] == '"' && s[i + 1] != '\0')) {
		return (NULL);
	}
	return (res);
}

int add_name(char *s, char *ptr)
{
	if (my_strcmp(s, "\0") || is_comment(s))
		return (2);
	else if (my_strcontains(s, NAME_CMD_STRING)) {
		ptr = get_key_value(s, NAME_CMD_STRING, ptr);
		if (ptr == NULL)
			return (EXIT_ERROR);
		return (EXIT_SUCCESS);
	} else {
		return (EXIT_ERROR);
	}
}

int add_comment(char *s, char *ptr)
{
	if (my_strcmp(s, "\0") || is_comment(s)) {
		free(s);
		return (2);
	}
	else if (my_strcontains(s, COMMENT_CMD_STRING) == 1) {
		ptr = get_key_value(s, COMMENT_CMD_STRING, ptr);
		if (ptr == NULL)
			return (EXIT_ERROR);
		free(s);
		return (EXIT_SUCCESS);
	} else {
		free(s);
		return (EXIT_ERROR);
	}
}

int is_comment(char *s)
{
	s = clean_str(s);
	if (s[0] == COMMENT_CHAR) {
		free(s);
		return (1);
	} else {
		free(s);
		return (0);
	}
}
