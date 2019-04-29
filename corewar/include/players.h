/*
** EPITECH PROJECT, 2018
** player
** File description:
** struct
*/

typedef struct players_s {
	int carry;
	int pc;
	int pc_start;
	int pc_end;
	int *registers;
	char *path;
	char *prog_name;
	int load_address;
	int prog_number;
	int alive;
	int last_live;
	int cycle;
	struct players_s *next;
} players_t;
