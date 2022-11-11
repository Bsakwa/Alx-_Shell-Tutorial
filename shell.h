#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
  * struct Path - Linked list of directories in user PATH
  * @dir: The name of the directory
  * @next: Pointer to the next directory
  */
typedef struct Path
{
	char *dir;
	struct Path *next;
} list_t;

char *_strtok(char *, char *);
char *_getenv(const char *name);
#endif
