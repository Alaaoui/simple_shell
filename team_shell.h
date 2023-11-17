#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/*convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 *struct builtin - contains a builtin string
 *@type: the builtin command flag
 *@func: the function
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/*_atoi.c */
int check_interactive_mode(info_t *);
int is_custom_delimiter(char, char *);
int is_alphabetic(int);
int team_atoi(char *);

/* team_builtin.c */
int exit_shell(info_t *);
int change_directory(info_t *);
int display_help(info_t *);

/* team_builtin1.c */
int show_history(info_t *);
int remove_alias(info_t *);
int add_alias(info_t *);
int print_single_alias(list_t *);
int man_alias(info_t *);

#endif
