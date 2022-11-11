#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
/**
  * main - Opens up a shell and prompts input
  *
  * Return: Always (0) Success
  */
int main(void)
{
	char *av[2] = {NULL, NULL};
	char *buffer = NULL;
	size_t len = 10;
	int id;

	while (1)
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("%s", buffer);

		if (feof(stdin))
		{
			putchar(10);
			break;
		}
		else
		{
			id = fork();

			if (id < 0)
			{
				perror("FORK FAILED\n");
				exit(98);
			}
			if (!id)
			{
				if (buffer[0] == 10)
					continue;
				buffer[strlen(buffer) -1] = 0;
				av[0] = buffer;

				if (execve(av[0], av, NULL) < 0)
				{
					perror("EXECVE FAILED");
					exit(99);
				}
			}
			else
				wait(NULL);
		}
	}
	free(buffer);
	buffer = NULL;
	return (0);
}
