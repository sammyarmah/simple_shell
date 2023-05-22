#include "shell.h"

/*
 * exit_prompt - prints exit
 * @u_input: checks if exit is inputed
 * @Name: program name
 *
 * Return: 0 if success, otherwise -1
 */

int exit_prompt(char *u_input, char *Name)
{
	const char *exit_cmd = "exit";
	int len = _strlen(u_input);
	int status = 0;

	if (_strncmp(u_input, exit_cmd, _strlen(exit_cmd)) != 0)
		return (0);

	if (len > _strlen(exit_cmd))
	{
		char *num_1 = u_input + _strlen(exit_cmd);
		char *end_ptr;
		status = _strtol(num_1, &end_ptr, 100);

		if (*end_ptr != '\n' && *end_ptr != ' ')
		{
			exit_err(Name, u_input);
			exit_code = 99;
			return (-1);
		}
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
		return (0);

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
	const char *env_cmd = "env"
	
	if (_strcmp(u_input, env_cmd) == 0)
		return (0);

	return (1);
}

