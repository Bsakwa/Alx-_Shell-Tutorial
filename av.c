#include <stdio.h>

/**
  * main - prints all the arguments
  *
  * Return - The number of arguments
  */
int main(int ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}

