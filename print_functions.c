#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * printchar - function that prints a char
 * @a_list: list of arguments
 *
 * Return: char printed to the the stdout
 */

int printchar(va_list a_list)
{
	char ch = (char)va_arg(a_list, int);

	_putchar(ch);

	return (1);

}


/**
 * printstr - function that prints a string
 *
 * @a_list: list of arguments
 *
 * Return: str printed to stdout
 */

int printstr(va_list a_list)
{
	int i = 0;

	char *str = va_arg(a_list, char *);

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;

	}

	return (i);

}
