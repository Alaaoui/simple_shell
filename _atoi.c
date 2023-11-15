#include "shell.h"

/**
 * interactive - interactive mode in shell
 * @info: struct value
 *
 * Return: 1 if shell is interactive , else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - verifies if delimiter in char
 * @c:char value
 * @delim:delimiter value
 * Return: 1 if true, else 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - alphabetic char validated
 *@c:char value
 *Return: 1 alphabetic, else 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - string to an integer conversion
 *@s:string value
 *Return: 0 if no numbers to convert.
 */

int _atoi(char *s)
{
	int m, con = 1, up = 0, outcome;
	unsigned int final = 0;

	for (m = 0;  s[m] != '\0' && up != 2; m++)
	{
		if (s[m] == '-')
			con *= -1;

		if (s[m] >= '0' && s[m] <= '9')
		{
			up = 1;
			final *= 10;
			final += (s[m] - '0');
		}
		else if (up == 1)
			up = 2;
	}

	if (con == -1)
		outcome = -final;
	else
		outcome = final;

	return (outcome);
}
