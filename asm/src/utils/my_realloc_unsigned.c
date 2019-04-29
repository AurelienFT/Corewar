/*
** EPITECH PROJECT, 2017
** my_realloc_unsigned.c
** File description:
** my_realloc_unsigned.c
*/

#include <stdlib.h>
#include "asm.h"
#include <stdio.h>

unsigned char *my_strcpy_unsigned(unsigned char *dest, code_t *src)
{
	size_t i = 0;

	for (; i < src->length; i++)
		dest[i] = src->code[i];
	dest[i] = '\0';
	return (dest);
}

code_t *my_realloc_unsigned(code_t *str, int nb_malloc)
{
	unsigned char *new_str;

	new_str = malloc(sizeof(unsigned char) * str->length + nb_malloc + 1);
	if (new_str == NULL)
		return (NULL);
	for (size_t i = 0; i <= str->length + nb_malloc; i++)
		new_str[i] = '\0';
	new_str = my_strcpy_unsigned(new_str, str);
	free(str->code);
	str->code = new_str;
	return (str);
}
