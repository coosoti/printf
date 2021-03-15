#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>

/**
 * struct print - struct to print various formats
 * @type - type to print
 * @funct - function to print
 *
 */

typedef struct print
{
	char *type;
	int (*funct)(va_list);

} print_f;

int _printf(const char *format, ...);
int _putchar(char c);

int printchar(va_list a_list);
int printstr(va_list a_list);
#endif
