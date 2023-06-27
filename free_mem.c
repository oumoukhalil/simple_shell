#include "simple_main.h"

/**
 * free_rp - A function that frees all the memory allocated for progname.
 * @progname: The pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_rp(char **progname)
{
	size_t j = 0;

	if (progname == NULL)
		return;

	while (progname[j])
	{
		free(progname[j]);
		j++;
	}

	if (progname[j] == NULL)
		free(progname[j]);
	free(progname);
}


/**
 * free_exit - frees all the memory allocated and exit.
 * @progname: allocated progname memory to free.
 * Return: Nothing.
 */
void free_exit(char **progname)
{
	size_t i = 0;

	if (progname == NULL)
		return;

	while (progname[i])
	{
		free(progname[i]);
		i++;
	}

	if (progname[i] == NULL)
		free(progname[i]);
	free(progname);
	exit(EXIT_FAILURE);
}
