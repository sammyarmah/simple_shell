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
	char *u_input = NULL;
	char **cmds = NULL;
	char **p_array = NULL;
	size_t n = 0;
	ssize_t nchars_read = 0;
	char *NAME = argv[0];
	int atty_is = isatty(0);

	signal(SIGINT, SIG_IGN);

	while (1)
	{
		error_count++;
		if (atty_is)
			write(STDOUT_FILENO, "$ ", 2);
		nchars_read = getline(&u_input, &n, stdin);
		if (nchars_read == -1)
		{
			free(u_input);
			exit(exit_code);
		}
		if (exit_prompt(u_input, NAME) == -1)
			continue;
		if (empty_prompt(u_input) == 1)
			continue;
		if (env_prompt(u_input) == 1)
		{
			print_env(env);
			continue;
		}
		p_array = get_path_array(env);
		cmds = p_input(u_input, p_array, NAME);
		if (cmds != NULL)
		{
			f_w_exec(cmds, p_array, env, NAME, u_input);
			free_strings(cmds);
			free_strings(p_array);
		}
	}
	return (0);
}
	