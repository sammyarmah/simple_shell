#include "shell.h"

/*
 * f_w_exec - allows for the execution of arbitrary commands and arguments
 * @cmds - array of strings
 * @p_array - Path array
 * @env - environment variables
 * @NAME: program name
 * @u_input: input string
 *
 */
void f_w_exec(char **cmds, char **p_array, char **env, char *NAME, char *u_input)
{
	pid_t pid;
	int status, exec_check;

	status = 0;
	pid = fork();

	if (pid == -1)
	{
		perror(NAME);
		exit_code= 1;
		_exit(1);
	}

	else if (pid == 0)
	{
		exec_check = execve(cmds[0], cmds, env);

		if (exec_check < 0)
		{
			exec_err(NAME, cmds[0]);
			free_strings(p_array);
			free_strings(cmds);
			free(u_input);
			exit_code = 126;
			_exit(126);
		}

		exit_code = 0;
		_exit(0);
	}

	exit_code = 0;
	wait(&status);
}
