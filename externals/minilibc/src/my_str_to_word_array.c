/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
**
*/

#include <stdlib.h>
#include <stdio.h>
#include "minilibc.h"

static int is_alpha_numeric(const char c, const char *separator)
{
	for (int i = 0; separator[i]; i++) {
		if (c == separator[i])
			return (0);
	}
	return (1);
}

static int my_get_words_nb(const char *str, const char *separator)
{
	int result = 1;

	for (int i = 0; str[i]; i++)
		if (!is_alpha_numeric(str[i], separator))
			result++;
	return (result);
}

static int str_len(const char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char **my_str_to_word_array(const char *str, const char *separator)
{
	int k = 0;
	int size = my_get_words_nb(str, separator);
	char **result = malloc(sizeof(char *) * (size + 1));

	if (result == NULL)
		return (NULL);
	for (;is_alpha_numeric(str[k], separator) == 0; k++);
	for (int i = 0, j = 0; i < size; i++) {
		result[i] = malloc(sizeof(char) * (str_len(str) + 1));
		for (int n = 0; n < str_len(str) + 1; n++)
			result[i][n] = '\0';
		if (result[i] == NULL)
			return (NULL);
		for (; is_alpha_numeric(str[k], separator) == 1 && str[k];
		k++, j++)
			result[i][j] = str[k];
		for (; is_alpha_numeric(str[k], separator) == 0; k++);
		j = 0;
	}
	result[size] = NULL;
	return (result);
}
