/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** my_putnbr.c
*/

#include "corewar.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putnbr(int nb)
{
	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
		my_putnbr(nb);
	} else if (nb <= 9) {
		my_putchar(nb + 48);
	} else {
		my_putnbr(nb / 10);
		my_putnbr(nb % 10);
	}
}
