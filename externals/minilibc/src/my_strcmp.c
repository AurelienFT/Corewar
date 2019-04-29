/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Compare two str
*/

int my_strcmp(const char *s1, const char *s2)
{
	int i = 0;

	for (; s1[i] && s2[i]; i++) {
		if (s1[i] != s2[i])
			return (0);
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (0);
	return (1);
}
