/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line.c
*/

#include "get_next_line.h"
#include "minilibc.h"
#include <stdlib.h>
#include <unistd.h>

static char *my_strcpy_modif(char *dest, char *src, int referral)
{
	int i = 0;

	if (referral == 0) {
		for (; src[i] != '\0'; i++)
			dest[i] = src[i];
		dest[i] = '\0';
	} else {
		for (; src[i] != '\n'; i++)
			dest[i] = src[i];
		dest[i] = '\0';
	}
	return (dest);
}

char *my_realloc(char *str, int nb_malloc)
{
	int len = 0;
	char *new_str;

	for (;str[len] != '\0'; len++);
	new_str = malloc(sizeof(char) * (size_t)(len + nb_malloc + 1));
	if (new_str == NULL)
		return (NULL);
	for (int i = 0; i <= len + nb_malloc; i++)
		new_str[i] = '\0';
	new_str = my_strcpy_modif(new_str, str, 0);
	free(str);
	return (new_str);
}

static char *read_again(char *buffer, int fd)
{
	int save = 0;
	ssize_t error = 0;

	for (; buffer[save] != '\0'; save++);
	buffer = my_realloc(buffer, READ_SIZE);
	if (buffer == NULL)
		return (NULL);
	error = read(fd, buffer + save, READ_SIZE);
	if (error < 0)
		return (NULL);
	else if (error == 0) {
		for (; buffer[error] != '\0'; error++);
		if (save != 0) {
			buffer = my_realloc(buffer, 1);
			buffer[error] = '\n';
		} else {
			free(buffer);
			return (NULL);
		}
	}
	return (buffer);
}

static char *read_or_not(char *buffer, int fd, int *i, char **to_return)
{
	*i = 0;
	for (; buffer[*i] != '\n' && buffer[*i] != '\0'; (*i)++);
	if (buffer[*i] == '\n') {
		*to_return = malloc(sizeof(char) * (size_t)(*i + 2));
		if (to_return == NULL)
			return (NULL);
		for (int j = 0; j < *i + 2; j++)
			(*to_return)[j] = '\0';
		*to_return = my_strcpy_modif(*to_return, buffer, 1);
		buffer = my_strcpy_modif(buffer, buffer + *i + 1, 0);
		return (buffer);
	} else {
		buffer = read_again(buffer, fd);
		if (buffer == NULL)
			return (NULL);
		buffer = read_or_not(buffer, fd, i, to_return);
	}
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *to_return;
	int i = 0;

	if (buffer == NULL) {
		buffer = malloc(sizeof(char));
		if (buffer == NULL)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = read_or_not(buffer, fd, &i, &to_return);
	if (buffer == NULL || to_return == NULL) {
		return (NULL);
	}
	return (to_return);
}
