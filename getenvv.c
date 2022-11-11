#include <stdio.h>
#include <string.h>
#include "shell.h"

extern char **environ;

int match_var(char *env, const char *name)
{
	int i = 0;

	if (!env || !name)
	{
		return (0);
	}
	for (; env[i]; i++)
	{
		if (env[i] == '=')
			break;
		if (env[i] != name[i])
			return (0);
	}
	return (1);
}

char *getval(char *line)
{
	while (line)
	{
		if (*line == '=')
			return(line + 1);
		line++;
	}
	return (NULL);
}

char *_getenv(const char *name)
{
	char *match_l;

	while (*environ)
	{
		if (match_var(*environ, name))
		{
			match_l = *environ;
			return (getval(match_l));
		}
		environ++;
	}
	return (NULL);
}
