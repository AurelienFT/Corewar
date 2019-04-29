/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** Linked list definitions
*/

#ifndef		LINKED_LIST_H
# define	LINKED_LIST_H

typedef struct element {
	void *data;
	struct element *prev;
	struct element *next;
} element_t;

typedef struct linked_list {
	element_t *first;
	element_t *last;
} linked_list_t;

linked_list_t *init_list(void);
int free_list(linked_list_t *list);
int put_in_list(linked_list_t *list, void *data);
void remove_from_list(linked_list_t *list, element_t *node);
int show_list(const linked_list_t *list);
int show_reversed_list(const linked_list_t *list);
element_t *get_element_from_start(const linked_list_t *list, int i);

#endif
