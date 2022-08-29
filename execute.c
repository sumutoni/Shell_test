#include "shell.h"
#define SIZE 5

/**
 * execute - execute command passed to the shell
 * @args: pointer to line containing command and arguments
 */
int execute(char **args)
{
	com commands[SIZE];
	int i, result;

	if (args[0] == NULL)
		return (1);
	for (i = 0; i < SIZE; i++)
	{
		if (strcmp(args[0], commands[i].name) == 0)
		{
			result = commands[i].pointer(args);
		}
		else
			result = -1;
	}
	return (result);
}
