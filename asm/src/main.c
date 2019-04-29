/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** Main entry point of asm compilo
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "asm.h"
#include "err.h"
#include "unistd.h"

static void final_free(int fd, char *write, header_t *header)
{
	free(header->prog_name);
	free(header->comment);
	free(header);
	free(write);
	close(fd);
}

int main(int ac, char **av)
{
	int fd;
	header_t *header = malloc(sizeof(header_t));
	linked_list_t *statements = init_list();
	char *write;

	if (ac != 2 || my_strcmp(av[1], "-h")) {
		put(USAGE);
		return (EXIT_SUCCESS);
	}
	if (header == NULL || statements == NULL)
		return (EXIT_ERROR);
	err_if((fd = open(av[1], O_RDONLY)), -1, FILE_ERROR, av[1]);
	write = parse_path(av[1]);
	err_if(get_header(fd, header), EXIT_ERROR, HEADER_ERROR, av[1]);
	err_if(get_statements(fd, statements), EXIT_ERROR,
	STATEMENT_ERROR, av[1]);
	fd = open(write, O_CREAT | O_RDWR | O_TRUNC, 00666);
	err_if(get_code(header, statements, fd), EXIT_ERROR, STATEMENT_ERROR,
	av[1]);
	final_free(fd, write, header);
	return (EXIT_SUCCESS);
}
