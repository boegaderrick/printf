#include "main.h"

/**
* conversion - selects format specifier
* @spec: char to aid selection
* @p: list of items to print in place of specifier
* Return: lenght of output string
*/

int conversion(const char spec, va_list p)
{
	int len = 0;
	char *s, c;

	if (spec == ' ' || spec == '\0')
	{
		return (-1);
	}
	if (spec == '%')
	{
		_putchar(spec);
		len++;
	}
	if (spec == 'c')
	{
		c = va_arg(p, int);
		_putchar(c);
		len++;
	}
	if (spec == 's')
	{
		s = va_arg(p, char *);
		if (s == NULL)
		{
			len += _printf("(null)");
		}
		else
		{
			while (*s != '\0')
			{
				_putchar(*s);
				s++;
				len++;
			}
		}
	}
	return (len);
}

/**
* _printf - produces output according to format
* @format: mandatory argument for variadic function
* Return: length of output string
*/

int _printf(const char *format, ...)
{
	int (*ptr)(const char, va_list);
	int i, j, len = 0;
	va_list p;

	if (format == NULL || p == NULL)
		return (-1);
	va_start(p, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			ptr = conversion;
			j = ptr(format[i], p);
			if (j != 0)
			{
				return (-1);
			}
			len += j;
		}
		else
		{	_putchar(format[i]);
			len++;
		}
	} va_end(p);
	return (len);
}
