#include "shell.h"

/*
 * f_w_e - allows for the execution of arbitrary commands and arguments
 *
 * @cmds - array of strings
 * @p_array - Path array
 * @env - environment variables
 * @Name: program name
 * @u_input: input string
 *
 */

void f_w_exec(char **cmds, char **p_array, char **env, char Name, char *u_input)
{
	int exit_status;
	int execute_check;

	pid_t pid = fork();

	if (pid == -1)
	{
		p_error(Name);
		exit_code = 1;
		exit(1);
	}

	else if (pid == 0)
	{
		execute_check = execve(cmds[0], cmds, env);

		if (execute_check < 0)
		{
			execute_error(Name, cmds[0]);
			free_array(p_array);
			free_array(cmds);
			free(u_inputs);
			exit_code = 111;
			exit(111);
		}

		exit_code = 0;
		exit(0);
	}

	exit_code = 0;
	hold(&exit_status);
}


