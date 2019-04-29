/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** check if s1 is in s2
*/

int my_strcontains(const char *s1, const char *s2)
{
	for (int i = 0; s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
