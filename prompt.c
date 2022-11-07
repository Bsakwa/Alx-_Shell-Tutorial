#include <stdio.h>
#include <stdlib.h>

/**
  * main - Prints"$" and waits for user to enter command
  *
  * Return: 0 on success
  */
int main(void)
{
	char *buffer = NULL;
	size_t len = 0;

	if (getline(&buffer, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("$ ");
			getline(&buffer, &len, stdin);
			printf("%s", buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(EXIT_FAILURE);
			return (-1);
		}
	}
	return (*buffer);
}
