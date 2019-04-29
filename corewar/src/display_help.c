/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** help
*/

#include "corewar.h"
#include "minilibc.h"

void display_help(void)
{
	my_putstr("USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number]");
	my_putstr(" [-a load_address] prog_name] ...\n\nDESCRIPTION\n\t");
	my_putstr("-dump nbr_cycle dumps the memory after the nbr_cycle exec");
	my_putstr("ution (if the round isn't \n\t\t\talready over) with the");
	my_putstr(" following format: 32 bytes/line in \n\t\t\thexadecimal (");
	my_putstr("AOBCDEFE1DD3...)\n\t-n prog_number sets the next program'");
	my_putstr("s number. By default, the first free number \n\t\t\tin ");
	my_putstr("the ");
	my_putstr("parameter order\n\t-a load_address sets the next loading ");
	my_putstr("address. When no address is \n\t\t\tspecified, optimize t");
	my_putstr("he addresses so that the processes are as far away \n\t\t");
	my_putstr("\tfrom each other as possible.");
	my_putstr(" The addresses are MEM_SIZE modulo\n");
}
