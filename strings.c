#include "shell.h"

/**
 *_strlen - Get the length of a string
 *@s: string
 *Return: len
 */
int _strlen(char *s)
{
	int len;

	len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 *_strcmp - used to compare 2 strings
 *@s1: string 1
 *@s2: string 2
 *Return: void
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}
/**
  *_strdup - returns a pointer to a newly allocated space in memory
  *@str: string
  *Return: dest
  */
char *_strdup(char *str)
{
	char *dest;
	unsigned int len, i;

	if (str == NULL)
	{
		return (NULL);
	}
	len = _strlen(str) + 1;
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
/**
* _putchar - prints a single character to stdout
* @c: The character to print
*
* Return: 1 if successful, -1 otherwise
*/

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 *_strncpy - Copy src string to dest string
 *@dest: destination string
 *@src: source string
 *@n: int
 *Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
