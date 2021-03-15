#include <stdlib.h>
#include "holberton.h"
#include <stdarg.h>
/**
 * _specifiers_check - verify if there is a valid format specifier
 *
 * @format - format specifier
 *
 * Return: Null otherwise pointer to a function
 */

static int (*_specifiers_check(const char *format))(va_list)
{

	unsigned int i;
	print_f f[] = {
		{"c", printchar},
		{NULL, NULL}
	};

	for (i = 0; f[i].type != NULL; i++)
	{
		if (*(f[i].type) == *format)
		{
			break;

		}
	}

	return (f[i].funct);
}

/**
 * _printf  - function that produces output according to a format
 *
 * @format - args types passed to the function
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned int i, fcount = 0;
	va_list a_list;
	int (*funct)(va_list);

	if (format == NULL)
		return (-1);

	va_start(a_list, format);

	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			fcount++;

		}
		if (!format[i])
			return (fcount);

		funct = _specifiers_check(&format[i + 1]);
		if (funct != NULL)
		{
			fcount += funct(a_list);
			i += 2;
			continue;

		}

		if (!format[i + 1])
			return (-1);

		_putchar(format[i]);
		fcount++;

		if (format[i + 1] == '%')
			i += 2;
		else
			i++;

	}
	va_end(a_list);
	return (fcount);

}
