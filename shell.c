#include "shell.h"

int exit_code = 0;
/**
 * main - Simple C shell
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: array of environment variables
 *
 * Return: 0 always
 */

int main(int argc, char **argv, char *envp[])
{
	char  *inputs = NULL;
	size_t n = 0;
	ssize_t nchars_read = 0;
	int atty_is = isatty(0);

	while (1)
	{
		if (atty_is)
			
			write(STDOUT_FILENO, "$ ", 2);
		nchars_read = getline(&inputs, &n, stdin);
		if (nchars_read == -1)
		{
			free(inputs);
			exit(exit_code);
		}


	}

	return (0);
}
