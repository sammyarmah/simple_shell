#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/hold.h>


extern int exit_code;
extern int error_count;

/* environ_func */
int path_count(char *p);
char **path_array(char **env);
char *find_path(char **array, char *token);
void print_env(char **env);

/* memory_helper */
void free_strings(char **array);

/* Strings helper functions */
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _putchar(char c);

/* parsing inputs */
int arg_c(char *u);
char **p_input(char *u_input, char **p_array, char *Name);

/* fork_func */
void f_w_exec(char **cmds, char **p_array, char **env, char *Name, char *u_input);

#endif
