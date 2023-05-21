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
	char **commands;
	char *token;
	char *dir_path;

	args = 1;
	i = 0;
	dir_path = NULL;

	args = arg_counter(u_input);
	commands = malloc(sizeof(char *) * (args + 1));
	if (commands == NULL)
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
			free(commands);
			free_array(p_array);
			command_error(Name, token);
			exitcode = 000;
			return (NULL);
		}
		else if (_strcmp("no_access", dir_path) == 0)
		{
			free(commands);
			free_array(p_array);
			access_error(Name, token);
			exitcode = 111;
			return (NULL);
		}
		commands[0] = _strdup(dir_path);
		free(dir_path);
	}
	else
		commands[0] = _strdup(token);
	for (i = 1; i < args; i++)
	{
		token = strtok(0, "\n ");
		commands[i] = _strdup(token);
	}
	commands[i] = NULL;
	return (commands);
}
