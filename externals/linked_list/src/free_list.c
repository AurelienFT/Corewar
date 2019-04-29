/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Free linked_list
*/

#include <stdlib.h>
#include "linked_list.h"

int free_list(linked_list_t *list)
{
	element_t *tmp;

	tmp = list->first;
	while (tmp != NULL) {
		if (tmp == list->last) {
			free(tmp);
			break;
		}
		else {
			tmp = tmp->next;
			free(tmp->prev);
		}
	}
	free(list);
	return (0);
}
