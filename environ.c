#include "shell.h"

/**
 * get_path_count - counts number of directories in PATH
 * @p: PATH string
 *
 * Return: number of directories
 */
int get_path_count(char *p)
{
	int i, len;

	i = 0;
	len = 0;
	while (p[i] != '\0')
	{
		if (p[i] == '=' || p[i] == ':')
			len++;
		i++;
	}

	return (len);
}

/**
 * get_path_array - Array  of PATH directories
 * @env: user environment
 *
 * Return: array of strings
 */


char **get_path_array(char **env)
{
	unsigned int i, j, path_len;
	int comp = 0;
	char *token, *token2,  *mypath;
	char **p_array;

	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		comp = _strcmp(env[i], "PATH");
		if (comp == 0)
		{
			mypath = _strdup(env[i]);
			path_len = get_path_count(mypath);
			token = strtok(mypath, "=");
			token = strtok(NULL, "=");
			p_array = malloc(sizeof(char *) * (path_len + 1));
			if (p_array == NULL)
				return (NULL);
			if (token[0] == ':')
			{
				p_array[j] = _strdup("./");
				j++;
				token2 = strtok(token, ":");
				token2 = strtok(NULL, ":");
			}
			else
				token2 = strtok(token, ":");
			while (j < path_len)
			{
				p_array[j] = _strdup(token2);
				j++;
				token2 = strtok(NULL, ":");
			}
		}
		i++;
	}
	p_array[path_len] = NULL;
	free(mypath);
	return (p_array);
}

/**
 * find_path - find the PATH of a command
 * @p_array: array of directories in PATH
 * @cmds: command to find path for
 *
 * Return: path of command, NULL if it fails
 */
char *find_path(char **p_array, char *cmds)
{
	int i, j, ok_f = 0, ok_x = 0, dir_len, com_len, total_len;
	char *path;

	for (i = 0; p_array[i] != NULL; i++)
	{
		dir_len = _strlen(p_array[i]);
		com_len = _strlen(cmds);
		total_len = dir_len + com_len;
		path = malloc(sizeof(char) * (total_len + 2));
		if (path == NULL)
		{
			free_strings(p_array);
			return (NULL);
		}
		j = 0;
		while (j < dir_len)
		{
			path[j] = p_array[i][j];
			j++;
		}
		path[j] = '/';
		j = 0;
		while (j < com_len)
		{
			path[dir_len + j + 1] = cmds[j];
			j++;
		}
		path[total_len + 1] = '\0';
		ok_f = access(path, F_OK);
		ok_x = access(path, X_OK);
		if (ok_f == 0)
		{
			if (ok_x == 0)
				return (path);
			free(path);
			return ("no_access");
		}
		free(path);
	}
	return (NULL);
}
/**
 * print_env - print environment variables
 * @env: array of environment variables
 */

void print_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
