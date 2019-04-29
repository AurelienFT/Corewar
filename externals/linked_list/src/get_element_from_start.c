/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** get element from linked list
*/

#include <stdio.h>
#include "linked_list.h"

element_t *get_element_from_start(const linked_list_t *list, const int i)
{
	element_t *result = list->first;
	int j = 0;

	while (result != NULL && j < i) {
		if (result->next == NULL)
			return (result);
		result = result->next;
		j++;
	}
	return (result);
}
