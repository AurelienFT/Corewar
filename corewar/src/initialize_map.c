/*
** EPITECH PROJECT, 2018
** init
** File description:
** map
*/

#include "corewar.h"
#include "op.h"

int test_filling_instructions(unsigned char map, int j,
			int nbr_player, int prog_n)
{
	if (j >= MEM_SIZE / nbr_player) {
		my_putstr("Too gros player\n");
		return (84);
	}
	if (map != '0') {
		my_putstr("Player wants to ecraser le autres\n");
		return (84);
	}
	if (prog_n > 4)
		return (84);
	return (0);
}

int get_name(players_t *player, int fd)
{
	unsigned char *buf = malloc(sizeof(char));
	int i = 0;

	if (buf == NULL)
		return (84);
	read(fd, buf, 1);
	player->prog_name = malloc(sizeof(char) * MEM_SIZE);
	if (player->prog_name == NULL)
		return (84);
	for (; buf[0] != 0; read(fd, buf, 1), i++)
		player->prog_name[i] = buf[0];
	player->prog_name[i] = '\0';
	for (; buf[0] == 0; read(fd, buf, 1));
	return (0);
}

int get_header(int fd, players_t *player)
{
	unsigned char *buf = malloc(sizeof(char) * 4);
	char *temp = malloc(sizeof(char) *MEM_SIZE);

	if (temp == NULL || buf == NULL)
		return (84);
	read(fd, buf, 4);
	if (buf[0] != 0 || buf[1] != 234 || buf[2] != 131 || buf[3] != 243) {
		my_putstr("Wrong executable magic number.\n");
		free(buf);
		free(temp);
		return (84);
	}
	if (get_name(player, fd) == 84)
		return (84);
	read(fd, buf, 1);
	for (; buf[0] != 0; read(fd, buf, 1));
	while (buf[0] == 0 && read(fd, buf, 1) == 1);
	player->pc = buf[0];
	free(buf);
	free(temp);
	return (0);
}

unsigned char *put_player(unsigned char *map, players_t *player,
			int nbr_player)
{
	int fd = open(player->path, O_RDONLY);
	unsigned char *buf = malloc(sizeof(char));
	int i = player->pc;

	if (!buf || fd == -1 || get_header(fd, player) == 84)
		return (NULL);
	map[i] = player->pc;
	player->pc = i;
	i++;
	for (int j = 0; read(fd, buf, 1) > 0; j++, i++) {
		if (test_filling_instructions(map[i], j,
		nbr_player, player->prog_number) == 84)
			return (NULL);
		map[i] = buf[0];
		if (i == MEM_SIZE - 1)
			i = -1;
	}
	player->pc_end = i;
	close(fd);
	return (map);
}

unsigned char *initialize_map(players_t *player)
{
	players_t *temp = player;
	int nbr_player = 0;
	unsigned char *map = malloc(sizeof(char) * (MEM_SIZE + 1));

	if (map == NULL)
		return (NULL);
	for (; temp; temp = temp->next, nbr_player++);
	temp = player;
	for (int i = 0; i < MEM_SIZE; i++)
		map[i] = '0';
	map[MEM_SIZE] = '\0';
	for (; temp; temp = temp->next) {
		map = put_player(map, temp, nbr_player);
		if (map == NULL)
			return (NULL);
		temp->pc_start = temp->pc;
	}
	return (map);
}
