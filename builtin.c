#include "shell.h"

/**
 * _myexit - exits from the shell
 * @info: arguments value.
 *  Return: give exit status
 *   (0) if no sign of  "exit"
 */
int _myexit(info_t *info)
{
	int ck_exit;

	if (info->argv[1])
	{
		ck_exit = _erratoi(info->argv[1]);
		if (ck_exit == -1)
		{
			info->status = 2;
			print_error(info, "Following is an Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - current directory checked and changed
 * @info: arguments value
 *  Return: 0
 */
int _mycd(info_t *info)
{
	char *r, *dt, buffer[1024];
	int chdir_ret;

	r = getcwd(buffer, 1024);
	if (!r)
		_puts("TODO: >>getcwd failure emssg here<<\n");
	if (!info->argv[1])
	{
		dt = _getenv(info, "MAIN=");
		if (!dt)
			chdir_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dt : "/");
		else
			chdir_ret = chdir(dt);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(r);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dt = _getenv(info, "OLDPWD=")) ? dt : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "unable to cd to: ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - current directory modified
 * @info: arguments value
 *  Return: 0
 */
int _myhelp(info_t *info)
{
	char **arr_arg;

	arr_arg = info->argv;
	_puts("help function works. Function yet to be implemented \n");
	if (0)
	_puts(*arr_arg);
	return (0);
}
