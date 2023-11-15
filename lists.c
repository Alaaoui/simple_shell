#include "shell.h"

/**
 * add_node -node  added to the start of the list
 * @head: pointer to head node
 * @str: str node
 * @num: node index
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *nod;

	if (!head)
		return (NULL);

	nod = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (nod)
	{
		while (nod->next)
			nod = nod->next;
		nod->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - prints str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: list size
 */
size_t print_list_str(const list_t *h)
{
	size_t r = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		r++;
	}
	return (r);
}

/**
 * delete_node_at_index - deletes node
 * @head: pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, else 0 on error
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *nod, *prv_node;
	unsigned int p = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		nod = *head;
		*head = (*head)->next;
		free(nod->str);
		free(nod);
		return (1);
	}
	nod = *head;
	while (nod)
	{
		if (p == index)
		{
			prv_node->next = nod->next;
			free(nod->str);
			free(nod);
			return (1);
		}
		p++;
		prv_node = nod;
		nod = nod->next;
	}
	return (0);
}

/**
 * free_list - frees nodes of a list
 * @head_ptr: pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *nxt_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = nxt_node;
	}
	*head_ptr = NULL;
}
