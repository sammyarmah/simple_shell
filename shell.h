#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern int exit_code;

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

#endif
