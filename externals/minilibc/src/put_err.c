/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** puterr
*/

#include <unistd.h>

int put_err(const char *s)
{
	const char *tmp = s;

	while (*tmp)
		tmp++;
	return (write(STDERR_FILENO, s, tmp - s));
}
