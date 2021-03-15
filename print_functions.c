#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"

/**
*printchar - function that prints a char
*@a_list: list of arguments
*
*Return: char printed to the the stdout
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




/**
 *printd - function that prints a decimal number
 *@num: integer to be printed
 *Return: void
 */

void printd(int num)
{
  unsigned int k = num;

  if (k / 10 != 0)
    printd(k / 10);
  _putchar(k % 10 + '0');

}



/**
 *countint - function to count length of an int
 *@num: int arg
 *Return: length of int
 */

int countint(int num)
{
  unsigned int k = num;
  int count;

  while (k > 0)
    {
      k = k / 10;
      count++;
    }

  return (count);
}





/**
 *printint - function to print an integer
 *@_list: list of argument
 *Return: count of ints digit
 */

int printint(va_list a_list)
{
  int count = 0;
  int num = va_arg(a_list, int);

  if (num < 0)
    {
      num = -(num);
      _putchar('-');
      count++;
    }

  if (num == 0)
    count++;

  count += countint(num);
    printd(num);

    return (count);

}
