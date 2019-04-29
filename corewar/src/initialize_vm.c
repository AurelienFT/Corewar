/*
** EPITECH PROJECT, 2018
** init
** File description:
** vm
*/

#include "corewar.h"
#include "minilibc.h"

int add_flags(players_t *n, char **av, int i)
{
	if (my_strcmp(av[i], "-a") == 1) {
		if (is_num_pos(av[i + 1]) == 1)
			n->load_address = my_getnbr(av[i + 1]);
		else {
			my_putstr("Bad parameter for -a enter a valid memory"
			" offset.\n");
			return (84);
		}
	} else if (my_strcmp(av[i], "-n") == 1) {
		if (is_num_pos(av[i + 1]) == 1)
			n->prog_number = my_getnbr(av[i + 1]);
		else
			return (84);
	} else {
		my_putstr("Bad flag\n");
		return (84);
	}
	return (0);
}

int add_options_champion(players_t *n, char **av, int i)
{
	n->prog_number = -1;
	n->load_address = -1;
	if (i < 2)
		return (0);
	i -= 2;
	for (; i > 0 && av[i][0] == '-'; i -= 2) {
		if (my_strcmp(av[i], "-dump") == 1)
			return (0);
		if (add_flags(n, av, i) == 84)
			return (84);
	}
	return (0);
}

players_t *add_champion(players_t *players, char **av, int i, int fd)
{
	players_t *n;
	players_t *save = players;
	char *test = malloc(2);

	if (test == NULL || read(fd, test, 1) == -1) {
		return (NULL);
	}
	close(fd);
	n = malloc(sizeof(players_t));
	if (players == NULL)
		players = n;
	else {
		while (save->next != NULL)
			save = save->next;
		save->next = n;
	}
	n->path = av[i];
	n->next = NULL;
	if (add_options_champion(n, av, i) == 84)
		return (NULL);
	return (players);
}

players_t *parser_error(char **av, infos_t *infos, players_t *players)
{
	int returned = 0;
	int fd = 0;

	for (int i = 1; av[i] != NULL; i++) {
		fd = open(av[i], O_RDONLY);
		if (av[i][0] != '-' && fd != -1) {
			players = add_champion(players, av, i, fd);
			if (players == NULL)
				return (NULL);
		}
		close(fd);
		if (av[i][0] == '-') {
			returned = check_dump(av, i, infos);
			i++;
		} else if (infos->nbr_cycles == 0)
			infos->nbr_cycles = 0;
		if (returned == 84)
			return (NULL);
	}
	return (players);
}

players_t *gest_error_args(int ac, char **av, infos_t *infos,
			players_t *players)
{
	infos->nbr_cycles = 0;
	if (ac == 2 && my_strlen(av[1]) == 2 &&
	av[1][0] == '-' && av[1][1] == 'h') {
		display_help();
		return (0);
	}
	if (ac <= 2) {
		display_help();
		return (NULL);
	}
	return (parser_error(av, infos, players));
}
