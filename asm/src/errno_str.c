/*
** EPITECH PROJECT, 2017
** errno_str.c
** File description:
** errno_str.c
*/

#include <stdlib.h>

char *errno_str(int err)
{
	switch (err) {
	case 2:
		return (" No such file or directory.");
		break;
	case 21:
		return (" Is a directory.");
		break;
	case 13:
		return (" Permission denied.");
		break;
	default:
		return (" Not handle error.");
		break;
	}
}
