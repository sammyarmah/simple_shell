#include "shell.h"

/**
 * free_strings - free an array of strings
 * @array: array to free
 */

void free_strings(char **array)
{
	int i;

	if (array != NULL) {
        for (i = 0; array[i] != NULL; i++) {
            free(array[i]);
        }
        free(array);
    }
}
