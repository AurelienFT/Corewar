/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** my_putstr
*/

#include <unistd.h>
#include "minilibc.h"

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}
