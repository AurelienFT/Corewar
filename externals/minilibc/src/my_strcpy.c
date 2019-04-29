/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}