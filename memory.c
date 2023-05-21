#include "shell.h"

/**
 * free_strings - free an array of strings
 * @array: array to free
 */

void free_strings(char **array)
{
	size_t i;
	int i;

	i = 0;
	while (*array[i] != '\0')
	{
		free(array[i]);
		i++;
	}
	free(array);
}
