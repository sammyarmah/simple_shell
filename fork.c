#include "shell.h"

/*
 * f_w_exec - allows for the execution of arbitrary commands and arguments
 * @cmds - array of strings
 * @p_array - Path array
 * @env - environment variables
 * @Name: program name
 * @u_input: input string
 *
 */
void f_w_exec(char **cmds, char **p_array, char **env, char *Name, char *u_input)
{
	int exit_status;
	int execute_check;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror(Name);
		exit_code = 1;
		_exit(1);
	}

	else if (pid == 0)
	{
		execute_check = execve(cmds[0], cmds, env);

		if (execute_check < 0)
		{
			exec_err(Name, cmds[0]);
			free_strings(p_array);
			free_strings(cmds);
			free(u_input);
			exit_code = 111;
			_exit(111);
		}

		exit_code = 0;
		_exit(0);
	}

	exit_code = 0;
	wait(&exit_status);
}

