#include "team_shell.h"

/**
 * show_history - displays the command history with line numbers
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int show_history(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * add_alias - sets or adds an alias to string
 * @info: parameter struct
 * @str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int add_alias(info_t *info, char *str)
{
char *param;

param = _strchr(str, '=');
if (!param)
return (1);
if (!*++param)
return (remove_alias(info, str));

remove_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_single_alias - prints an alias string
 * @node: node of the alias
 *
 * Return: Always 0 on success, 1 on error
 */
int print_single_alias(list_t *node)
{
char *param = NULL, *alias_part = NULL;

if (node)
{
param = _strchr(node->str, '=');
for (alias_part = node->str; alias_part <= param; alias_part++)
_putchar(*alias_part);
_putchar('\'');
_puts(param + 1);
_puts("'\n");
return (0);
}
return (1);
}


/**
 * remove_alias - alias value
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int remove_alias(info_t *info, char *str)
{
char *param, temp;
int result;

param = _strchr(str, '=');
if (!param)
return (1);
temp = *param;
*param = 0;
result = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*param = temp;
return (result);
}

/**
 * man_alias - mimics the alias builtin
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int man_alias(info_t *info)
{
int i = 0;
char *param = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
param = _strchr(info->argv[i], '=');
if (param)
add_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}
