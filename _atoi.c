#include "shell.h"

/**
 * interactive - if shell is interactive mode returns true
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - verifies if character is a delimeter
 * @ch: the char value to check
 * @delim: the delimeter value string
 * Return: 1 if true, 0 otherwise
 */
int is_delim(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	return (0);
}

/**
 *_isalpha - looks for an alphabetic character
 *@ch: character input value
 *Return: 1 if ch is alphabetic, 0 otherwise
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - a string is converted to an integer
 *@s: the string value
 *Return: 0 if no numbers in string, or else converted number
 */

int _atoi(char *s)
{
	int index, sign = 1, flag = 0, result;
	unsigned int final_result = 0;

	for (index = 0;  s[index] != '\0' && flag != 2; index++)
	{
		if (s[index] == '-')
			sign *= -1;

		if (s[index] >= '0' && s[index] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		result = -final_result;
	else
		result = final_result;

	return (result);
}
