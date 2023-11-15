#include "shell.h"

/**
 * _myenv -current environment detection
 * @info:arguments value
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - attains environ variable
 * @info: arguments value
 * @name: var name of environ
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *nd = info->env;
	char *t;

	while (nd)
	{
		t = starts_with(nd->str, name);
		if (t && *t)
			return (t);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * _mysetenv - new enviro variable set or modified,
 * @info: arguments value
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect set of  arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - environment variable deleted
 * @info: arguments value
 *  Return: 0
 */
int _myunsetenv(info_t *info)
{
	int k;

	if (info->argc == 1)
	{
		_eputs("arguments not enough.\n");
		return (1);
	}
	for (k = 1; k <= info->argc; k++)
		_unsetenv(info, info->argv[k]);

	return (0);
}

/**
 * populate_env_list - env linked list to be populated
 * @info:arguments value
 * Return:0
 */
int populate_env_list(info_t *info)
{
	list_t *nd = NULL;
	size_t q;

	for (q = 0; environ[q]; q++)
		add_node_end(&nd, environ[q], 0);
	info->env = nd;
	return (0);
}
