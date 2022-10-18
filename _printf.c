#include <stdio.h>
#include <stdarg.h>

/**
* _printf - produces output according to a format
* @format: output format
* Return: number of chars printed, excluding null byte terminator
*/

int _printf(const char *format, ...)
{
	int char_count;
	va_list p;

	va_start(p, format);
	char_count = vfprintf(stdout, format, p);
	va_end(p);

	return (char_count - 1);
}
