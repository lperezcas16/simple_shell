#include "0_principal_header.h"

/**
 * add_path_node - Adds a new node in double list.
 * @head: Double linked list
 * @str: String to add
 * Return: Nodes number.
 */
path_list *add_path_node(path_list **head, char *str)
{
	path_list *new;
	path_list *last = *head;

	new = malloc(sizeof(path_list));
	if (new == NULL)
		return (NULL);

	new->pat = _strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (last->next)
		last = last->next;

	last->next = new;
	new->prev = last;

	return (new);
}

/**
 * free_path_list - Free double linked list.
 * @head: Start of linked list
 */
void free_path_list(path_list **head)
{
	path_list *hold = NULL;

	while (head && *head)
	{
		free((*head)->pat);
		hold = *head;
		*head = (*head)->next;
		free(hold);
	}
}
