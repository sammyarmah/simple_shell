#include "shell.c"

/**
 * path_count - counts number of directories in PATH
 * @p: PATH string
 *
 * Return: number of directories
 */

int path_count(char *p)
{
	int i, len;

	len = 0;
	for (i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == '=' || p[i] == ':')
			len++;
	}
	return (len);
}

/**
 * path_array - Array  of PATH directories
 * @env: user environment
 *
 * Return: array of strings
 */

char **path_array(char **env)
{
	unsigned int i, j, p_count;
	int comp = 0;
	char *token, *token_2, *mypath;
	char **path_arr;

	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		comp = _strcmp(env[i], "PATH");
		if (com == 0)
		{
			mypath = _strdup(env[i]);
			p_count = path_count(mypath);
			token = strtok(mypath, "=");
			token = strtok(NULL, "=");
			path_arr = malloc(sizeof(char *) * (p_count + 1));
			if (path_arr == NULL)
				return (NULL);
			if (token[0] == ':')
			{
				path_arr[j] = _strdup("./");
				j++;
				token_2 = strtok(token, ":");
				token_2 = strtok(NULL, ":");
			}
			else
				token_2 = strtok(token, ":");
			while (j < p_count)
			{
				path_arr[j] = _strdup(token_2);
				j++;
				token_2 = strtok(NULL, ":");
			}
		}
		i++;
	}
	path_arr[p_count] = NULL;
	free(mypath);
	return (path_arr);
}

/**
 * find_path - find the PATH to a command
 * @array: array of directories in PATH
 * @cmd: command to find path for
 *
 * Return: path of command, NULL if it fails
 */
char *find_path(char **array, char *cmd)
{
	int i, j, dir_len, cmd_len, total_len;
	char *path;

	for (i = 0; array[i] != NULL; i++)
	{
		dir_len = _strlen(array[i]);
		com_len = _strlen(cmd);
		total_len = dir_len + com_len + 2;
		path = (char *)malloc(total_len * sizeof(char));
		if (path == NULL)
		{
			free_strings(array);
			return NULL;
		}
		_strncpy(path, array[i], dir_len);
		path[dir_len] = '/';
		_strncpy(path + dir_len + 1, cmd, cmd_len);
		path[total_len - 1] = '\0';

		if (access(path, F_OK) == 0)
			if (access(path, X_OK) == 0)
				return path;
		free(path);
		return "no_access";
	}
	free(path);
    }
    return NULL;
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
