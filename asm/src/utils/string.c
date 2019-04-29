/*
** EPITECH PROJECT, 2018
** clean_str.c
** File description:
** clean_str.c
*/

#include <stdlib.h>
#include "utils.h"
#include "minilibc.h"

char *start_str(char const *str, int *i, int *nb_space, char *clean_str)
{
	int j = 0;

	for (; clean_str[j] != '\0'; j++);
	if (str[*i] != ' ' && str[*i] != '\t') {
		clean_str = my_realloc(clean_str, 1);
		clean_str[j] = str[*i];
		*nb_space = 0;
	}
	*i = *i + 1;
	return (clean_str);
}

char *check_space(char const *str, int *i, int *nb_space, char *clean_str)
{
	int block = 0;
	int k = 0;

	for (int j = *i; str[j] != '\0'; j++)
		if (str[j] != '\t' && str[j] != ' ')
			block = 1;
	if (block == 1) {
		for (; clean_str[k] != '\0'; k++);
		clean_str = my_realloc(clean_str, 1);
		if (str[*i] == '\t' || str[*i] == ' ') {
			clean_str[k] = ' ';
			*nb_space = 1;
		} else
			clean_str[k] = str[*i];
	}
	*i = *i + 1;
	return (clean_str);
}

char *try_reset_nb_spaces(char const *str, int *i, int *nb_space, char
*clean_str)
{
	int j = 0;

	for (; clean_str[j] != '\0'; j++);
	if (str[*i] != '\t' && str[*i] != ' ') {
		clean_str = my_realloc(clean_str, 1);
		clean_str[j] = str[*i];
		*nb_space = 0;
	}
	*i = *i + 1;
	return (clean_str);
}

char *clean_str(char *str)
{
	char *clean_str = malloc(sizeof(char));

	clean_str[0] = '\0';
	for (int i = 0, nb_space = -1; str[i] != '\0';) {
		if (nb_space == -1)
			clean_str = start_str(str, &i, &nb_space, clean_str);
		else if (nb_space == 0)
			clean_str = check_space(str, &i, &nb_space, clean_str);
		else
			clean_str = try_reset_nb_spaces
				(str, &i, &nb_space, clean_str);
	}
	return (clean_str);
}
