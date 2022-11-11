#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{

	printf("The address for env is %d\n", **env);
	printf("The address for environ is %d\n", **environ);

	return (0);
}
