#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
* _printf - produces output according to format
* @format: mandatory argument for variadic function
* Return: length of output string
*/

int _printf(const char *format, ...)
{
	char *s;
	int i, c, len = 0;
	va_list p;

	if (format == NULL) 
	{
		return (-1);
	}
	va_start(p, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				_putchar(format[i]);
				len++;
			}
			if (format[i] == 'c')
			{
				c = va_arg(p, int);
				_putchar(c);
				len++;
			}
			if (format[i] == 's')
			{
				s = va_arg(p, char *);
				while (*s != '\0')
				{
					_putchar(*s);
					s++;
					len++;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}
	va_end(p);
	return (len);
}
