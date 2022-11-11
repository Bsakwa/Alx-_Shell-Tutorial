#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
  * main - fork, wait and execv
  *
  * Return: Always zero on Success
  */
int main(void)
{
	pid_t my_pid, mmy_pid;
	pid_t child_pid = 1;
	int i = 0;
	int status;
	char *argv[] = {"/usr/bin/ls", "-l", "/tmp", NULL};

	mmy_pid = getppid();
	my_pid = getpid();
	while (i <= 4 && (child_pid != 0))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("Error encountered");
			return (1);
		}
		wait(&status);
		i++;
	}
	if (child_pid == 0)
	{
		printf("CHILD ID: %u\nPARENT ID: %u\n", my_pid, mmy_pid);
		if (execve(argv[0], argv, NULL) == -1)
			perror("Could not execute");
	}
	return (0);
}

