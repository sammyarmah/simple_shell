#include "shell.h"

/**
 * _atoi - convert string(s) into an integer
 * @str: string
 *
 * Return: integer
 */
int _atoi(char *str)
{
	int ind, neg_c, num;

	ind = 0;
	neg_c = 0;
	while (!(str[ind] >= '0' && str[ind] <= '9') && str[ind] != '\0')
	{
		if (str[ind] == '-')
			neg_c++;
		ind++;
	}
	num = 0;
	while (str[ind] >= '0' && str[ind] <= '9')
	{
		num = (str[ind] - '0') + (num * 10);
		ind++;
	}
	if (neg_c % 2 != 0)
		num = -num;
	return (num);
}

/**
 * print_number - print an integer to STDOUT
 * @n: integer
 *Return: integer
 */
void print_number(int n)
{
	int digit, sum, last;
	int divisor = 1000000000;
	unsigned int num;

	num = n;
	sum = 0;
	while (divisor > 1)
	{
		digit = (num / divisor) % 10;
		sum += digit;
		if (sum != 0)
			_putchar(digit + '0');
		divisor = divisor / 10;
	}
	last = num % 10;
	_putchar(last + '0');
}
