/*
** EPITECH PROJECT, 2017
** parse_path.c
** File description:
** parse_path.c
*/

#include <stdlib.h>
#include "asm.h"
#include "utils.h"
#include "minilibc.h"

char *parse_path(char *path)
{
	char *ext = ".cor";
	char *new_path;

	if (my_strcmp(".s", path + my_strlen(path) - 2))
		path[my_strlen(path) - 2] = '\0';
	for (int i = 0, tmp = 0, j = 0; path[i]; i++, tmp++) {
		if (path[i] == '/') {
			path += tmp + 1;
			j += 2;
			tmp = 1 + j;
		}
	}
	new_path = malloc(sizeof(char) * my_strlen(path) + 5);
	for (int i = 0; i < my_strlen(path) + 5; i++)
		new_path[i] = '\0';
	if (new_path == NULL)
		return (NULL);
	new_path = my_strcpy(new_path, path);
	for (int j = 0; ext[j] != '\0'; j++)
		new_path[my_strlen(new_path)] = ext[j];
	return (new_path);
}
