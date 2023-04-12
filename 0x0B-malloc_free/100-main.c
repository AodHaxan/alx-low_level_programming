#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point. Concatenates command line arguments into a string.
 * @ac: Number of command line arguments
 * @av: Array of strings containing the command line arguments
 *
 * Return: 0 on success, 1 on error
 */
char *argstostr(int ac, char **av)
{
	char *s;

	s = argstostr(ac, av);

	if (s == NULL)
	{
	return ((char*)1);
	}

	printf("%s", s);

	free(s);

	return (0);
}
