#include "shell.h"

/*
 * cmd_err - prints error when incorrect command is entered
 * @Name: program name
 * @cmd: incorrect command
 *
 */

void cmd_err(char *Name, char *cmd)
{
	fprintf(stderr, "%s: %s: incorrect\n", Name, cmd);
	exit_code = 100;
}

void exec_err(char *Name, char *cmd)
{
	p_err(cmd);
	exit_code = 2;
}

void access_err(char *Name, char *cmd)
{
	fprintf(stderr, "%s: %s: Denied Access\n", Name, cmd);
}

void exit_err(char *Name, char *u_input)
{
	char *token = strtok(u_input, "\n ");
	token = strtok(NULL, "\n ");

	fprintf(stderr, "%s: %s: exit: incorrect number: %s\n", Name, cmd, token);
}

