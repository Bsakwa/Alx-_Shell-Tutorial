#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
  * main - Prints the directories in the path
  *
  * Return: Always (0) Success
  */
int main(void)
{
	char *tok;
	char *path;

	path = _getenv("PATH");
	tok = strtok(path, ":");

	while (tok)
	{
		printf("%s\n", tok);
		tok = strtok(NULL, ":");
	}
	return (0);
}

