#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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
int decimal(va_list);
int integer(va_list);
char *conv_itoa(int, char *, int);
int funcpick(const char, va_list);

#endif
