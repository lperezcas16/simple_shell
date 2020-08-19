 #include "0_principal_header.h"

/**
 * add_node - add new node at the end of the list.
 * @head: head node
 * @str: string to add
 * @mlloc: 1 if malloc, 0 if no malloc
 * Return: New node;
 */
token_s *addnode(token_s **head, char *str, int mlloc)
{
	token_s *last, *new = malloc(sizeof(token_s));
	/* Space for new nodo (token) */
	if (!new)
		return (NULL);
	/* Assign parameters */
	new->str = str;
	new->mlloc = mlloc;
	if (!(*head))
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = NULL;
		last = *head;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (new);
}
/**
 * free_list - free linked list memory
 * @head: head node
 */
void free_list(token_s **head)
{	/*Pointer for free */
	token_s *ptr = NULL;

	while (head && *head)
	{
		if ((*head)->mlloc == 1)
			free((*head)->str);
		ptr = *head;
		*head = (*head)->next;
		free(ptr);
	}
}

/**
 * print_token -  prints all the elements of a list_t list
 * @s_token: head of constant list_t being counted
 * Return: the number of nodes
 */
size_t print_token(token_s *s_token)
{
	int contador = 0;

	while (s_token)
	{
		if (!(*s_token).str)
		{
			write(STDOUT_FILENO, "nil", 3);
			write(STDOUT_FILENO, "\n", 2);
		}
		else
		{
			write(STDOUT_FILENO, s_token->str, _strlen(s_token->str));
			write(STDOUT_FILENO, "\n", 2);
		}
		s_token = s_token->next;
		contador++;
	}
	return (contador);
}
/**
 * delete_nodeint_at_index - Deletes a node.
 * @head: Linked list.
 * @index: Previous node to deleted one.
 * Return: 1 Success, -1 Failed.
 */
int delete_nodeint_at_index(token_s **head, unsigned int index)
{
	unsigned int id;
	token_s *actual = *head, *nodo;

	if (!*head)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next, free(actual);
		return (1);
	}
	else
		for (id = 0; actual != NULL; id++)
		{
			if (id == index - 1)
			{
				nodo = actual;
				nodo = nodo->next;
				actual->next = nodo->next;
				if (nodo->mlloc == 1)
					free(nodo->str);
				free(nodo);
				return (1);
			}
			actual = actual->next;
		}
	return (-1);
}
