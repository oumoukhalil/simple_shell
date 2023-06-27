#include "simple_main.h"

/**
 * execute - A function that executes a progname.
 * @progname: The pointer to tokienized progname
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * @fact: Number of executed fact.
 * Return: Nothing.
 */
void execute(char **progname, char *name, char **env, int fact)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(progname[0], "env") != 0)
		print_env(env);
	if (stat(progname[0], &st) == 0)
	{
		if (execve(progname[0], progname, env) < 0)
		{
			perror(name);
			free_exit(progname);
		}
	}
	else
	{
		pathways = _getPATH(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], progname[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, progname, env) < 0)
				{
					perror(name);
					free_rp(pathways);
					free_exit(progname);
				}
				return;
			}
		}
		msgerror(name, fact, progname);
		free_rp(pathways);
	}
}


/**
 * print_env - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 * Return: Nothing.
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * msgerror - A function that prints message not found.
 * @name: The name of the shell.
 * @fact: Number of fact.
 * @progname: The pointer to tokenized progname.
 * Return: Nothing.
 */
void msgerror(char *name, int fact, char **progname)
{
	char c;

	c = fact + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, progname[0], _strlen(progname[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
