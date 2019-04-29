/*
** EPITECH PROJECT, 2018
** minilibc
** File description:
** include
*/

#ifndef MINI_LIBC_H
#define MINI_LIBC_H

int put(const char *s);
int put_err(const char *s);
int my_strcmp(const char *s1, const char *s2);
int my_atoi(const char *s);
char **my_str_to_word_array(const char *s, const char *separator);
int my_strlen(char *str);
int is_num(const char *s);
int my_strcontains(const char *s1, const char *s2);
int is_num_pos(const char *s);
char *my_strcpy(char *, char *);
#endif /* MINI_LIBC_H */
