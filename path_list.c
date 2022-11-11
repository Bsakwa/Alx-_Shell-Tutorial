#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

list_t *add_path_end(char *dir, list_t **head, list_t  **tail)
{
	list_t *ptr;
	list_t *new_node;

	ptr = *tail;
	new_node = malloc(sizeof(list_t));

	if(!new_node)
		return (NULL);
	new_node->dir = dir;
	new_node->next = NULL;

	if (!*tail)
		*head = *tail = new_node;
	else
	{
		ptr->next =new_node;
		*tail = new_node;
	}

	return (new_node);
}

void load_environ_path( list_t **head, list_t **tail)
{
	char *token;
	char *path;
	(void)head;

	path = _getenv("PATH");
	token = strtok(path, ":");

	while (token)
	{
		add_path_end(token, head, tail);
		token = strtok(NULL, ":");
	}
}

void print_PATH(list_t *head)
{
	list_t *ptr;

	ptr = head;

	while(ptr)
	{
		printf("%s\n", ptr->dir);
		ptr = ptr->next;
	}
}

void free_PATH( list_t *head)
{
	list_t *ptr, *node_b;

	ptr = head;
	while (ptr)
	{
		node_b = ptr;
		ptr = ptr->next;
		free(node_b);
	}
}

int main(void)
{
	list_t *head, *tail;

	head = tail = NULL;

	load_environ_path(&head, &tail);
	print_PATH(head);
	free_PATH(head);
	return (0);
}
