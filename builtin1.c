#include "shell.h"

/**
 * _myhistory - to showcase the history list
 *
 * @info: argument values.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - alias to string appointment
 * @info: struct value
 * @str: string alias value
 *
 * Return: 0 on success, else  1 if error
 */
int unset_alias(info_t *info, char *str)
{
	char *a, b;
	int turn;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	turn = delete_nd_at_index(&(info->alias),
		get_nd_index(info->alias, new_starts_with(info->alias, str, -1)));
	*a = c;
	return (turn);
}

/**
 * set_alias - alias assigned to string datatype
 * @info: struct value
 * @str: string value
 *
 * Return: 0 on success, else 1 if  error occurs
 */
int set_alias(info_t *info, char *str)
{
	char *a;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_nd_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - string alias displayed
 * @node: node value
 *
 * Return: 0 if succeeds, 1 if  error occurs
 */
int print_alias(list_t *node)
{
	char *e = NULL, *f = NULL;

	if (node)
	{
		e = _strchr(node->str, '=');
		for (f = node->str; f <= e; f++)
			_putchar(*f);
		_putchar('\'');
		_puts(e + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - alias builtin imitation
 * @info: potential arguments values
 * Return: 0
 */
int _myalias(info_t *info)
{
	int y = 0;
	char *z = NULL;
	list_t *nd = NULL;

	if (info->argc == 1)
	{
		nd = info->alias;
		while (nd)
		{
			print_alias(nd);
			nd = nd->next;
		}
		return (0);
	}
	for (y = 1; info->argv[y]; y++)
	{
		z = _strchr(info->argv[y], '=');
		if (z)
			set_alias(info, info->argv[y]);
		else
			print_alias(node_starts_with(info->alias, info->argv[y], '='));
	}

	return (0);
}
