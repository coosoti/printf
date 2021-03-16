#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct print - struct containing chrs for comparison with specfiers and
 * selecting appropriate function
 * @type: char to compare
 * @funct: function to print
 *
 */

typedef struct print
{
	char type;
	int (*funct)(va_list);

} print_f;

int _printf(const char *format, ...);
int _putchar(char c);
int printNaN(char c1, char c2);

int printchar(va_list a_list);
int printstr(va_list a_list);

#endif
