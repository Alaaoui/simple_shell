#include "shell.h"

/**
 **_strncpy - copies a string value
 *@dest: destination value
 *@src: source string value
 *@n: the amount of char
 *Return: concatenated string value
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: string value1
 *@src: string value2
 *@n: bytes value
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		 c++;
	while (src[b] != '\0' && d < n)
	{
		dest[a] = src[j];
		a++;
		b++;
	}
	if (d < n)
		dest[d] = '\0';
	return (s);
}

/**
 **_strchr - finds a cha in string
 *@s: string value
 *@c: chara to find
 *Return: s -a pointer to the memory
 */
char *_strchr(char *k, char l)
{
	do {
		if (*k == l)
			return (s);
	} while (*k++ != '\0');

	return (NULL);
}
