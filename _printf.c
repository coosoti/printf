#include "holberton.h"

/**
 * _printfunc - get the right function corresponding to format specified
 * @fi: input format
 * Return:pointer to function that corresponds with specified format
 *
 */
int (*_printfunc(char fi))(va_list)
{
	int i = 0;
	print_f f[] = {
		{'c', printchar},
		{'s', printstr},
		{'\0', NULL}
	};
	while (f[i].type)
	{
		if (fi == f[i].type)
		{
			return (f[i].funct);
		}
		i++;

	}
	return (NULL);
}

/**
 * _printf - function that produces output according to format passed
 * @format: character string containing 0 or more directive
 * Return: number of chars printed exluding null byte
 */

int _printf(const char *format, ...)
{
	unsigned int i, k, fcount = 0;
	va_list a_list;

	print_f f[] = {
		{"c", printchar},
		{"s", printstr},
		{"d", printint},
		{"i", printint},
		{NULL, NULL}
	};
	va_start(a_list, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			fcount += _putchar(format[i]);
		else if (format[i + 1] == '%')
		{
			fcount += _putchar('%');
			i++;
		}
		else if (format[i + 1] != 'c' && format[i + 1] != 's'
			 && format[i + 1] != 'd' && format[i + 1] != 'i')
		{
			fcount += _putchar('%');
			fcount += _putchar(format[i + 1]);
			i++;
		}
		else
		{
			for (k = 0; k < 4; k++)
			{
				if (format[i + 1] == *f[k].type)
					fcount += f[k].funct(a_list);
			}
			i++;
		}
	}
	va_end(a_list);
	return (fcount);
}
