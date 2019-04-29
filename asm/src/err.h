/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** err msg header
*/

#ifndef	ERR_H
#define	ERR_H

#include "asm.h"
#include "minilibc.h"

#define	err_if(value, err_value, msg1, msg2) do {	\
		if (value == err_value)			\
		{					\
			put_err(msg1);			\
			put_err(msg2);			\
			put_err("\n");			\
			put_err("\033[0m");		\
			return (EXIT_ERROR);		\
		}					\
} while (0);

#define	FILE_ERROR	"\033[1;31mError: cannot open "

#define	HEADER_ERROR	"\033[1;31mError: cannot read header -> "

#define	NAME_ERROR	"\033[1;31mError: .name doesn't exist or bad syntax"

#define	NO_COMMENT_WARN	"\033[1;31mWarning: \033[1;36mNo comment specified."

#define	STATEMENT_ERROR	"\033[1;31mError: cannot read statements -> "

#endif
