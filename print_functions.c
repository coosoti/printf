#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * printchar - function that prints a char
 * @a-list - list of arguments
 *
 * Return: char printed to the the stdout
 */

int printchar(va_list a_list)
{
	char ch = (char)va_arg(a_list, int);

	_putchar(ch);

	return (1);

}
