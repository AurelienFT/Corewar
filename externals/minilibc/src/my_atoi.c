/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Converts a string to an int
*/

int my_atoi(const char *s)
{
	int result = 0;
	int sign = 1;

	if (*s == '-') {
		sign = -sign;
		s++;
	}
	for (int i = 0; s[i]; i++) {
		if (s[i] < '0' || s[i] > '9')
			return (result);
		result *= 10;
		result += (s[i] - '0') * sign;
	}
	return (result);
}
