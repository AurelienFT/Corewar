/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** create linked_list
*/

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

linked_list_t *init_list(void)
{
	linked_list_t *result;

	result = malloc(sizeof(linked_list_t));
	if (result == NULL)
		return (NULL);
	result->first = NULL;
	result->last = NULL;
	return (result);
}
