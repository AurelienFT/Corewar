/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** put element in list
*/

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int put_in_list(linked_list_t *list, void *data)
{
	element_t *tmp = malloc(sizeof(element_t));

	if (tmp == NULL)
		return (1);
	tmp->data = data;
	tmp->next = list->first;
	if (tmp->next != NULL) {
		tmp->next->prev = tmp;
	} else {
		list->last = tmp;
		tmp->next = NULL;
	}
	list->first = tmp;
	tmp-> prev = NULL;
	return (0);
}
