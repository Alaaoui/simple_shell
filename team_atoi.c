#include "team_shell.h"

/**
 * check_interactive_mode - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int check_interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_custom_delimiter - checks for custom delimeter  in character
 * @c: the char to check
 * @delim_str: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_custom_delimiter(char ch, char *delim_str)
{
	while (*delim_str)
		if (*delim_str ++ == ch)
			return (1);
	return (0);
}

/**
 * is_alphabetic- checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int is_alphabetic(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * team_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int team_atoi(char *s)
{
	int index, sign = 1, flag = 0, result;
	unsigned int result = 0;

	for (index = 0;  s[index] != '\0' && flag != 2; index ++)
	{
		if (s[index] == '-')
			sign *= -1;

		if (s[index] >= '0' && s[index] <= '9')
		{
			flag = 1;
			final_result *= 10;
			final_result += (s[index] - '0');
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
