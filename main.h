#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdarg.h>

typedef struct
{
	char op;
	int (*function)(va_list);
} spec_struct;

int _putchar(char);
int _printf(const char *format, ...);
int string(va_list);
int percent(va_list);
int letter(va_list);
int funcpick(const char, va_list);

#endif
