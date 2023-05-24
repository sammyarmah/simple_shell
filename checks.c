#include "shell.h"

/*
 * exit_prompt - prints exit
 * @u_input: checks if exit is inputed
 * @Name: program name
 *
 * Return: 0 if success, otherwise -1
 */
int exit_prompt(char *u_input, char *NAME)
{
	int i, j, len, size, status;
	char *num;
	char *check = "exit";

	j = 0;
	len = _strlen(u_input);
	size = len - 5;
	status = 0;
	for (i = 0; i < 4; i++)
	{
		if (check[i] != u_input[i])
			return (0);
	}
	if (u_input[4] != '\n' && u_input[4] != ' ')
		return (0);

	if (len > 5)
	{
		num = malloc(sizeof(char) * size);
		for (i = 5; i < len - 1; i++)
		{
			if (u_input[i] >= '0' && u_input[i] <= '9')
			{
				num[j] = u_input[i];
				j++;
			}
			else
			{
				exit_err(NAME, u_input);
				free(num);
				exit_code = 2;
				return (-1);
			}
		}
		num[j] = '\0';
		status = _atoi(num);
		free(num);
	}
	free(u_input);
	exit(status);
}
/**
 * empty_prompt - checks empty user input
 * @u_input: compares string
 *
 * Return: 0 if success, otherwise 1
 */

int empty_prompt(char *u_input)
{
	if (u_input[0] == '\n')
		return (1);

	return (0);
}

/**
 * path_prompt - checks path
 * @cmd: string path
 *
 * Return: 0 is success, otherwise -1
 */

int path_prompt(char *cmd)
{
	if (cmd[0] == '/')
		return (0);


	return (-1);
}

/**
 * env_prompt - command env
 * @u_input: string that compares to enc
 *
 * Return: 0 success, otherwise 1
 */

int env_prompt(char *u_input)
{
	int i = 0;
	char *env = "env";

	if (_strlen(u_input) != 4)
		return (0);

	while (env[i] != '\0')
	{
		if (env[i] != u_input[i])
			return (0);
		i++;
	}
	return (1);
}