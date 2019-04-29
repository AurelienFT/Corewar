/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** include
*/

#ifndef COREWAR_H_
#define COREWAR_H_
#include <stdlib.h>
#include "players.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct s_infos {
	int nbr_cycles;
} infos_t;

void my_putnbr(int);
players_t *gest_error_args(int, char **, infos_t *, players_t *);
void display_help(void);
void my_putstr(char *);
int my_getnbr(char *);
int check_dump(char **, int, infos_t *);
int initialize_player(players_t *);
unsigned char *initialize_map(players_t *);
int start_vm(players_t *, infos_t *);
int vm_loop(unsigned char *, players_t *, infos_t *);
void live(players_t *, int);
void go_to_live(players_t *, players_t *, unsigned char *);
void ld(players_t *, int, char);
void st(players_t *, char, char, unsigned char *);
void add_sub(players_t *, char, char);
void and_or_xor(players_t *, char, char);
int go_to_func_one(players_t *, players_t *, unsigned char *, int);
void go_to_ld(players_t *, unsigned char *);
void go_to_st(players_t *, unsigned char *);
void go_to_add(players_t *, unsigned char *, char);
void go_to_comp(players_t *, unsigned char *, char);
void go_to_zjmp(players_t *, unsigned char *);
void go_to_ldi(players_t *, unsigned char *, char);
void go_to_ldi_two(players_t *, unsigned char *, int, int);
void go_to_sti(players_t *, unsigned char *);
int go_to_sti_two(players_t *, unsigned char *, int, int *);
void go_to_fork(players_t *, unsigned char *, char);
void go_to_aff(players_t *, unsigned char *);
void zjmp(players_t *, int);
void ldi(players_t *, unsigned char *, int *, char);
void sti(players_t *, unsigned char *, int, int);
void forkk(players_t *, int, char);
void aff(players_t *, char);
int get_bytecode(int, int);
int comp(int, int, char);
void fill_new_fork(players_t *, players_t *);
void my_puthexa(unsigned char, char *);

#endif
