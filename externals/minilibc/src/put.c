/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** put
*/

#include <unistd.h>

int put(const char *s)
{
	const char *tmp = s;

	while (*tmp)
		tmp++;
	return (write(STDOUT_FILENO, s, tmp - s));
}
