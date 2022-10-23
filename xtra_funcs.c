#include "main.h"

/**
* conv_itoa - converts ints to strings
* @num: number to be converted
* @str: string variable to hold converted number
* @base: base of converted number/string
* Return: string holding number
*/

char *conv_itoa(int num, char *str, int base)
{
	int neg = 0, i = 0, j;
	char array[sizeof(int) * 8 + 1];

	if (num == 0)
	{
		str[i] = '0';
		i++;
		str[i] = '\0';
		return (str);
	}
	if (num < 0 && base == 10)
	{
		num *= -1;
		neg = 1;
	}
	while (num != 0)
	{
		array[i] = num % base + '0';
		i++;
		num /= base;
	}
	if (neg)
	{
		array[i] = '-';
		i++;
	}
	for (j = 0; i >= 0; j++)
	{
		str[j] = array[i - 1];
		i--;
	}
	return (str);
}

/**
* decimal - prints numbers to stdout as string
* @p: source of number to be printed
* Return: length of printed string
*/

int decimal(va_list p)
{
	int i, len = 0, d = va_arg(p, int);
	char buffer[sizeof(int) * 8 + 1];

	conv_itoa(d, buffer, 10);
	for (i = 0; buffer[i] != '\0';  i++)
	{
		_putchar(buffer[i]);
		len++;
	}
	return (len);
}

/**
* integer - prints numbers to stdout as string
* @p: source of number to be printed
* Return: length of printed string
*/

int integer(va_list p)
{
	int i, len = 0, d = va_arg(p, int);
	char buffer[sizeof(int) * 8 + 1];

	conv_itoa(d, buffer, 10);
	for (i = 0; buffer[i] != '\0';  i++)
	{
		_putchar(buffer[i]);
		len++;
	}
	return (len);
}

