#include "main.h"

/**
* string - prints string to stdout
* @p: source of string
* Return: lenght of output string
*/

int string(va_list p)
{
	char *s = va_arg(p, char *);
	int len = 0;

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
	return (len);
}

/**
* percent - prints percent sign
* @p: source of sign
* Return: length of print
*/

int percent(__attribute__((unused)) va_list p)
{
	int len = 0;

	_putchar('%');
	len++;
	return (len);
}

/**
* letter - prints single character
* @p: source of character
* Return: length of print
*/

int letter(va_list p)
{
	int len = 0;
	char c = va_arg(p, int);

	_putchar(c);
	len++;
	return (len);
}

/**
* funcpick - selects format specifier
* @spec: char to aid selection
* @p: list of items to print in place of specifier
* Return: lenght of output string
*/

int funcpick(const char spec, va_list p)
{
	int i, len = 0;

	spec_struct specifiers [] = {
		{'%', percent},
		{'s', string},
		{'c', letter},
		{'d', decimal},
		{'i', integer}
	};


	if (spec == ' ' || spec == '\0')
	{
		return (-1);
	}
	for (i = 0; i < 5; i++)
	{
		if (spec == specifiers[i].op)
		{
			return (specifiers[i].function(p));
		}
	}
	_putchar('%');
	_putchar(spec);
	len += 2;
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

	setbuf(stdout, NULL);

	if (format == NULL || p == NULL)
		return (-1);
	va_start(p, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			ptr = funcpick;
			j = ptr(format[i], p);
			if (j == -1)
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
