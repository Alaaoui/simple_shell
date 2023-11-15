#include "shell.h"

/**
 * _erratoi - string to an integer conversion
 * @s: string value
 * Return: 0 if no numbers in string
 */
int _erratoi(char *s)
{
	int p = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (p = 0;  s[p] != '\0'; p++)
	{
		if (s[p] >= '0' && s[p] <= '9')
		{
			outcome *= 10;
			outcome += (s[p] - '0');
			if (outcome > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (outcome);
}

/**
 * print_error - error message displayed
 * @info:specifies& returns info l
 * @estr: string with error type
 * Return: 0 if no numbers in string else -1 for error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - a decimal (integer) number (base 10)
 * @input: input value
 * @fd: the filedescriptor value
 *
 * Return: num of chars
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int r, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		sumit++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (r = 1000000000; r > 1; r /= 10)
	{
		if (_abs_ / r)
		{
			__putchar('0' + current / r);
			sumit++;
		}
		current %= r;
	}
	__putchar('0' + current);
	sumit++;

	return (sumit);
}

/**
 * convert_number - converter function
 * @num: number value
 * @base: base value
 * @flags: flags value
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *arr;
	static char buffer[50];
	char gn = 0;
	char *tp;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		gn = '-';

	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	tp = &buffer[49];
	*tp = '\0';

	do	{
		*--tp = arr[n % base];
		n /= base;
	} while (n != 0);

	if (gn)
		*--tp = gn;
	return (tp);
}

/**
 * remove_comments - first instance of '#' modified with '\0'
 * @buf: address of the string
 * Return: 0;
 */
void remove_comments(char *buf)
{
	int m;

	for (m = 0; buf[m] != '\0'; m++)
		if (buf[m] == '#' && (!m || buf[m - 1] == ' '))
		{
			buf[m] = '\0';
			break;
		}
}
