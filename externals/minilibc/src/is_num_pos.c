/*
** EPITECH PROJECT, 2018
** is_num.c
** File description:
** is_num.c
*/

int is_num_pos(const char *s)
{
	for (int i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (0);
	return (1);
}
