#include "shell.h"

/**
 * arg_c - number of arguments to count
 * @u: a string of user input
 *
 * Return: number of arguments
 */

int arg_c(char *u)
{
	int i;
	int args;
	int start;

	args = 1;
	i = 0;
	start = 0;
	while (u[i] != '\0' && u[i] != '\n')
	{
		if (u[i] != ' ')
			start = 1;
		
		if (u[i] == ' ' && u[i + 1] != ' ' && u[i + 1] != '\n' && start == 1)
			args++;
		i++;
	}
	return (args);
}

/**
 * p_input - creates an array of strings
 * @u_input: string to be tokenized
 * @p_array: the path array
 * @Name: program name
 *
 * Return: array of args
 */

char **p_input(char *u_input, char **p_array, char *Name)
{

	int args;
	int i;
	char **cmds;
	char *token;
	char *dir_path;

	args = 1;
	i = 0;
	dir_path = NULL;

	args = arg_counter(u_input);
	cmds = malloc(sizeof(char *) * (args + 1));
	if (cmds == NULL)
	{
		free_array(p_array);
		return (NULL);
	}
	token = strtok(u_input, "\n ");
	if (path_check(token) == -1)
	{
		dir_path = find_path(p_array, token);
		if (dir_path == NULL)
		{
			free(cmds);
			free_array(p_array);
			cmds_error(Name, token);
			exit_code = 100;
			return (NULL);
		}
		else if (_strcmp("no_access", dir_path) == 0)
		{
			free(cmds);
			free_array(p_array);
			access_error(Name, token);
			exit_code = 111;
			return (NULL);
		}
		cmds[0] = _strdup(dir_path);
		free(dir_path);
	}
	else
		cmds[0] = _strdup(token);
	for (i = 1; i < args; i++)
	{
		token = strtok(0, "\n ");
		cmds[i] = _strdup(token);
	}
	cmds[i] = NULL;
	return (cmds);
}
