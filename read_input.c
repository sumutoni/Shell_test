#include "shell.h"
#define BUFSIZE 1024
/**
 * readline - reads in input
 *
 * Return: line read in
 */
char *readline()
{
	char *line;
	size_t buf = BUFSIZE;
	int bytes;

	bytes = getline(&line, &buf, stdin);
	if (bytes < 0)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			printf("Readline Error\n");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
/**
 * splitline - split a line commands and arguments
 * @args: line to split
 *
 * Return: pointer to argument strings
 */
char **splitline(char *args)
{
	char **arguments;
	char *delimiter = " ";
	char *argument;
	int index = 0;

	argument = strtok(args, delimiter);
	while (argument != NULL)
	{
		arguments[index] = argument;
		index++;
		strtok(NULL, delimiter);
	}
	arguments[index] = NULL;
	return (arguments);
}
