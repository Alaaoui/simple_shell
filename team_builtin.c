#include "team_shell.h"

/**
 *exit_shell - Exits the shell with a given exit status
 * @info: Structure containing potential arguments.
 * Return: if exit argument provided -2, 1 on error.
 */
int exit_shell(info_t *info)
{
int exit_status;

if (info->argv[1])
{
exit_status = _erratoi(info->argv[1]);
if (exit_status == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
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
 * change_directory - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *  Return: 0 on success, 1 on error
 */
int change_directory(info_t *info)
{
char *current_dir, *new_dir
char buffer[1024];
int chdir_ret;

current_dir = getcwd(buffer, 1024);
if (!current_dir)
_puts("getcwd failure");
if (!info->argv[1])
{
new_dir = _getenv(info, "HOME=");
if (!new_dir)
chdir_ret = chdir((new_dir = _getenv(info, "PWD=")) ? new_dir : "/");
else
chdir_ret = chdir(new_dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(current_dir);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = chdir((new_dir = _getenv(info, "OLDPWD=")) ? new_dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "cannot  change directory to ");
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
 * display_help - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int display_help(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("Help function is not yet implemented.\n");
if (0)
_puts(*arg_array);
return (0);
}
