#include "shell.h"

/**
 *_eputs - input string displayed or printed
 * @str:string value
 *
 * Return: 0
 */
void _eputs(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 * _eputchar - character c written to stderr
 * @c: char value
 * Return: On success 1 else -1 on error
 */
int _eputchar(char c)
{
	static int I;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, I);
		I = 0;
	}
	if (c != BUF_FLUSH)
		buf[I++] = c;
	return (1);
}

/**
 * _putfd -char c written to provided fd
 * @c: char value
 * @fd:filedescriptor
 * Return: On success 1 else -1 for error
 */
int _putfd(char a, int fd)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(fd, buf, m);
		m = 0;
	}
	if (a != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}

/**
 *_putsfd - input string value
 * @str: string value
 * @fd: filedescriptor value
 *
 * Return: number of chars
 */
int _putsfd(char *str, int fd)
{
	int p = 0;

	if (!str)
		return (0);
	while (*str)
	{
		p += _putfd(*str++, fd);
	}
	return (p);
}
