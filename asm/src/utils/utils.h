/*
** EPITECH PROJECT, 2018
** asm
** File description:
** utils.h
*/

#ifndef	UTILS_H
#define	UTILS_H

#include "asm.h"

char *parse_path(char *path);
unsigned char *my_strcpy_unsigned(unsigned char *dest, code_t *src);
code_t *my_realloc_unsigned(code_t *str, int nb_malloc);
unsigned int little_to_big_endian(int nb);
char *try_reset_nb_spaces(char const *str, int *i, int *nb_space, char *);
char *clean_str(char *str);
char *check_space(char const *str, int *i, int *nb_space, char *clean_str);
char *start_str(char const *str, int *i, int *nb_space, char *clean_str);
char *my_realloc(char *str, int nb_malloc);

#endif
