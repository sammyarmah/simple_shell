#include "shell.h"

/**
 * cmd_err - prints error message when command is not found
 * @NAME: name of program
 * @cmd: command not found
 */
void cmd_err(char *NAME, char *cmd)
{
	fprintf(stderr, "%s: %s: not found\n", NAME, cmd);
	exit_code = 127;
}

/**
 * exec_err - prints error message when command fails to execute
 * @NAME: name of program
 * @cmd: name of command
 */
void exec_err(__attribute__((unused)) char *NAME, char *cmd)
{
	perror(cmd);
	exit_code = 2;
}

/**
 * access_err - prints error message if user does not have execute privileges
 * @NAME: name of program
 * @cmd: name of command
 */
void access_err(char *NAME, char *cmd)
{
	fprintf(stderr, "%s: %s: Permission denied\n", NAME, cmd);
}

/**
 * exit_err - prints message if user inputs an invalid exit status
 * @NAME: name of program
 * @inputs: user input read by program
 */
void exit_err(char *NAME, char *inputs)
{
	char *token;

	token = strtok(inputs, "\n ");
	token = strtok(NULL, "\n ");
	fprintf(stderr, "%s: %d: exit: incorrect number: %s\n", NAME, error_count, token);
}
