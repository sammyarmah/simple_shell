#include "shell.h"

int exit_code = 0;
int error_count = 0;
/**
 * main - Simple C shell
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: array of environment variables
 *
 * Return: 0 always
 */

int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char  *inputs = NULL;
	size_t n = 0;
	ssize_t nchars_read = 0;
	int atty_is = isatty(0);
	char **cmds = NULL;
	char **path_arr = NULL;
	char *name = argv[0];

	signal(SIGINT, SIG_IGN);

	while (1)
	{
		error_count++;
		if (atty_is)

			write(STDOUT_FILENO, "$ ", 2);
		nchars_read = getline(&inputs, &n, stdin);
		if (nchars_read == -1)
		{
			free(inputs);
			exit(exit_code);
		}
		if (exit_prompt(inputs, name) == -1)
			continue;
		if (empty_prompt(inputs) == 1)
			continue;
		if (env_prompt(inputs) == 1)
		{
			print_env(env);
			continue;
		}
		path_arr = path_array(env);
		cmds = p_input(inputs, path_arr, name);
		if (cmds != NULL)
		{
			f_w_exec(cmds, path_arr, env, name, inputs);
			free_strings(cmds);
			free_strings(path_arr);
		}
	}

	return (0);
}
