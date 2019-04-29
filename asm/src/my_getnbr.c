/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** my_getnbr.c
*/

#include <limits.h>

int check(double nb_final, int sub)
{
	int render = 0;

	nb_final = nb_final * sub;
	if (nb_final < INT_MAX && nb_final > INT_MIN)
		render = nb_final;
	else
		render = 0;
	return (render);
}

void my_getnbr2(char *str, double *nb_final, int *i, int *n)
{
	while (str[*i] > 47 && str[*i] < 58) {
		*nb_final = *nb_final * 10  + (str[*i] - 48);
		*n = 1;
		*i = *i + 1;
	}
}

int my_getnbr(char *str)
{
	int i = 0;
	int n = 0;
	int sub = 1;
	double nb_final = 0;
	int render = 0;

	while (str[i] != '\0' && n == 0) {
		if (str[i] == '-') {
			sub = sub * -1;
		}
		my_getnbr2(str, &nb_final, &i, &n);
		if (n == 1) {
			render = check(nb_final, sub);
		}
		i = i + 1;
	}
	return (render);
}
