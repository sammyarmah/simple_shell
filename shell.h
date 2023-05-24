#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern int exit_code;
extern int error_count;

/* environ_func */
int get_path_count(char *p);
char **get_path_array(char **env);
char *find_path(char **p_array, char *cmds);
void print_env(char **env);

/* memory_helper */
void free_strings(char **array);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _putchar(char c);

/* Strings */
int _strlen(char *str);

/* parsing inputs */
int arg_c(char *u);
char **p_input(char *u_input, char **p_array, char *NAME);

/* fork_func */
void f_w_exec(char **cmds, char **p_array, char **env, char *NAME, char *u_input);

/* error_function */
void cmd_err(char *NAME, char *cmd);
void exec_err(char *NAME, char *cmd);
void access_err(char *NAME, char *cmd);
void exit_err(char *NAME, char *inputs);

/* exit_command */
int exit_prompt(char *u_input, char *NAME);
int empty_prompt(char *u_input);
int path_prompt(char *cmd);
int env_prompt(char *u_input);

/* number_functions */
int _atoi(char *str);
void print_number(int n);


#endif
