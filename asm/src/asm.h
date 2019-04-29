/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** Asm program public header
*/

#ifndef	ASM_H
#define	ASM_H

#include "linked_list.h"
#include "lexer.h"
#include <stdio.h>

#define	USAGE	"USAGE\n\t./asm file_name[.s]\n"\
"\nDESCRIPTION\n\tfile_name\t"			\
"file in assembly language to be converted "	\
"into file_name.cor, an executable "		\
"in the Virtual Machine.\n"

#define	EXIT_SUCCESS	0

#define	EXIT_ERROR	84

#define MEM_SIZE		(6*1024)
#define IDX_MOD			512
#define MAX_ARGS_NUMBER		4

#define COMMENT_CHAR		'#'
#define LABEL_CHAR		':'
#define DIRECT_CHAR		'%'
#define SEPARATOR_CHAR		','

#define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING		".name"
#define COMMENT_CMD_STRING	".comment"

#define REG_NUMBER	16

typedef char args_type_t;

#define T_UNKNOWN 0
#define T_REG	1
#define T_DIR	2
#define T_IND	4
#define T_TO_LAB	8
#define T_INSTRUCTION	16
#define T_A_IND_LAB	32
#define T_A_DIRECT_LAB	64
#define T_DIR_INDEX	128
#define T_A_LAB_INDEX	255

struct op_s
{
	char *mnemonique;
	int nbr_args;
	args_type_t type[MAX_ARGS_NUMBER][2];
	unsigned char code;
	int nbr_cycles;
	char *comment;
};

typedef struct code_s
{
	unsigned char *code;
	size_t length;
} code_t;

typedef struct op_s op_t;

#define REG_SIZE	1
#define IND_SIZE	2
#define DIR_SIZE	4

#define PROG_NAME_LENGTH	128
#define COMMENT_LENGTH		2048

#define COREWAR_EXEC_MAGIC	0xea83f3

struct header_s
{
	int  magic;
	char *prog_name;
	int  prog_size;
	char *comment;
};

typedef struct header_s header_t;

#define CYCLE_TO_DIE    1536
#define CYCLE_DELTA     5
#define NBR_LIVE        40

int get_header(const int fd, header_t *header_ptr);
int get_statements(const int fd, linked_list_t *statements);
int build(linked_list_t *statements);
char *launch_clean_str(char *str);
int add_name(char *s, char *ptr);
int is_comment(char *s);
char *my_realloc(char *str, int nb_malloc);
int add_comment(char *s, char *ptr);
linked_list_t *fill_statements(char *s, linked_list_t *statements);
int get_code(header_t *header, linked_list_t *statements, int fd);
char *parse_path(char *path);
unsigned int little_to_big_endian(int nb);
int find_instruction(token_t *token);
int verify_syntax_instruction(element_t *n, token_t *token, int
place_instruction);
void add_bytecode(int i, unsigned char *bytecode, element_t *arg);
code_t *add_instruction(element_t *instruction, code_t *code,
element_t *n);
code_t *add_register(code_t *code, token_t *token);
code_t *add_indirect(code_t *code, token_t *token);
code_t *add_direct(code_t *code, token_t *token);
int my_getnbr(char *str);
int my_strlen_unsigned(code_t *code);
code_t *add_jump_label(token_t *token, code_t *code, element_t *n);
int get_space_label(element_t *n, char *label);
code_t *add_direct_lab(token_t *token, code_t *code, element_t *n);
void free_statements(linked_list_t *statements);
#endif
