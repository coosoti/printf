#include "holberton.h"

/**
 * printchar - prints a character to stdout
 *
 * @a_list: list to increment
 * Return: 1(one character printed)
 */
int printchar(va_list a_list)
{
	char c;

	c = va_arg(a_list, int);
	_putchar(c);

	return (1);
}

/**
 * printstr - prints chars to stdout
 *
 * @a_list:list to args
 *
 * Return: number of char printed
 */
int printstr(va_list a_list)
{
	char *str;
	int i;

	str = va_arg(a_list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
