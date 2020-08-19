#ifndef LIST_H
#define LIST_H
#include "0_principal_header.h"

/**
 * struct token_s - Singly linked list
 * @str: Argument
 * @mlloc: Flag that tells if str has malloc
 * @next: Points to next node
 *
 * Description: Singly linked list node structure
 * to store getline arguments temporaly
 */
typedef struct token_s
{
	char *str;
	int mlloc;
	struct token_s *next;
} token_s;

/**
 * struct pathList - Double linked list
 * @pat: Address to path
 * @next: Points to next node
 * @prev: Points to previous node
 *
 * Description: Double linked list node structure
 * to store path addresses
 */
typedef struct pathList
{
	char *pat;
	struct pathList *next;
	struct pathList *prev;
} path_list;

/* -------------------------- */
/* -------Prototypes--------- */
/* --------------------------- */
token_s *addnode(token_s **head, char *str, int mlloc);
void free_list(token_s **head);
size_t print_token(token_s *s);
int delete_nodeint_at_index(token_s **head, unsigned int index);
path_list *add_path_node(path_list **head, char *str);
void free_path_list(path_list **head);

#endif
